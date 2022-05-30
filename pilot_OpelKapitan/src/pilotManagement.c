/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */

/**
 * @file pilotManagement.c
 * @brief This file contains the functions used to manage a pilot.
 * @author PICQUE Kylian <picque.kylian@ecole.ensicaen.fr>
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.2
 * @date 07 avril 2022
 */

#include "../include/pilotManagement.h"
#include "../include/direction/pilotDirection.h"

#define FUEL_SAFETY 13              /**< safety operation */

/**
 * @brief Set the Position Pilot object
 * 
 * @param pilot the pilote to update 
 * @param x the X-coordinate to set
 * @param y the Y-coordinate to set
 */
static void setPositionPilot ( PILOT* pilot, short x, short y );

/**
 * @brief Set the Speed Pilot object
 * 
 * @param pilot the pilote to update
 * @param x the X-coordinate to set
 * @param y the Y-coordinate to set
 */
static void setSpeedPilot ( PILOT* pilot, short x, short y );

/**
 * @brief Set the Action Pilot object
 * 
 * @param pilot the pilot to update 
 * @param x the new X-coordinate to set
 * @param y the new Y-coordinate to set
 */
static void setActionPilot ( PILOT* pilot, short x, short y );

/**
 * @brief Set the Gas Lvl Pilot object
 * 
 * @param pilot : the PILOT object
 * @param newGasLvl : the gas level
 */
static void setGasLvlPilot ( PILOT* pilot, short newGasLvl );

/**
 * @brief Set the Boosts Remaining Pilot object
 * 
 * @param pilot : the PILOT object
 * @param boostsRemaining : the boosts remaining 
 */
static void setBoostsRemainingPilot ( PILOT* pilot, short boostsRemaining );

/**
 * @brief Initialize the pilot object
 * 
 * @param pilot : the PILOT object
 */
static void initNewPilot ( PILOT* pilot );

/**
 * @brief Update the speed of our pilot
 * 
 * @param pilot : the PILOT object
 */
static void updateSpeedPilot ( PILOT* pilot );

/**
 * @brief Update the position to the correct pilot's object
 * 
 * @param myPosition the position of our pilot
 * @param secoundPosition the position of the second pilot
 * @param thirdPosition the position of the third pilot
 * @param myPilot our pilot
 * @param secondPilot the second pilot
 * @param thirdPilot the third pilot
 */
static void updatePositionPilot ( 
                                POSITION myPosition, POSITION secoundPosition, 
                                POSITION thirdPosition, PILOT* myPilot, 
                                PILOT* secondPilot, PILOT* thirdPilot 
                                );

/**
 * @brief If the action is boosted
 * 
 * @param action the action to test
 * @return boolean true if it is boosted
 */
static boolean isActionBoosted ( ACCELERATION action );

/**
 * @brief The fuel consumption according to current speed, current position and the demanded action
 * 
 * @param position the current position of a pilot
 * @param speed the current speed of a pilot
 * @param action the demanded action
 * @param graph the graph of the race
 * @return short the fuel consumption for this round
 */
static short fuelConsumption ( 
                                POSITION position, SPEED speed, 
                                ACCELERATION action, GRAPH* graph
                             );

/**
 * @brief Update the gas remaining of our pilot
 * 
 * @param pilot : the PILOT object
 * @param graph : the graph of the race.
 */
static void updateGasPilot ( PILOT* pilot, GRAPH* graph );

/**
 * @brief if there is an error of position during the race
 * 
 * @param pilot the pilot to test
 * @param newPosition the next position of teh current round
 * @return boolean true if there is an error 
 */
static boolean isErrorFromPilot ( PILOT* pilot, POSITION newPosition );

/**
 * @brief Put to 0 the speed of our pilot
 * 
 * @param pilot the pilot to reset
 */
static void resetSpeed ( PILOT* pilot );

/**
 * @brief Update the remaining boost
 * 
 * @param pilot a pilot to update
 */
static void updateBoostsPilot ( PILOT* pilot );

static void setPositionPilot ( PILOT* pilot, short x, short y )
{
    pilot->position.X = x;
    pilot->position.Y = y; 
}

static void setSpeedPilot ( PILOT* pilot, short x, short y )
{
    pilot->speed.X = x;
    pilot->speed.Y = y;
}

static void setActionPilot ( PILOT* pilot, short x, short y )
{
    pilot->acceleration.X = x;
    pilot->acceleration.Y = y;
}

static void setGasLvlPilot ( PILOT* pilot, short newGasLvl )
{
    pilot->fuelLevel = newGasLvl;
}

static void setBoostsRemainingPilot ( PILOT* pilot, short boostsRemaining )
{
    pilot->boostsRemaining = boostsRemaining;
}

static void initNewPilot ( PILOT* pilot )
{
    setPositionPilot ( pilot, 0, 0 );
    setSpeedPilot ( pilot, 0, 0 );
    setActionPilot ( pilot, 0, 0 );
    setBoostsRemainingPilot ( pilot, BOOSTS_AT_START );
}

static void updateSpeedPilot ( PILOT* pilot )
{
    SPEED speed = getSpeedPilot ( pilot );
    ACCELERATION acc = getAccelerationPilot ( pilot );
    setSpeedPilot ( pilot, speed.X + acc.X, 
                           speed.Y + acc.Y );
}

static void updatePositionPilot ( 
                            POSITION myPosition, POSITION secoundPosition, 
                            POSITION thirdPosition, PILOT* myPilot, 
                            PILOT* secondPilot, PILOT* thirdPilot 
                         )
{
    setPositionPilot ( myPilot, myPosition.X, myPosition.Y );
    setPositionPilot ( secondPilot, secoundPosition.X, secoundPosition.Y);
    setPositionPilot ( thirdPilot, thirdPosition.X, thirdPosition.Y );
}


static boolean isActionBoosted ( ACCELERATION action )
{
    if ( abs ( action.X ) == 2 || abs ( action.Y ) == 2 ) {
        return true;
    }
    return false;
}

static void updateBoostsPilot ( PILOT* pilot )
{
    if ( isActionBoosted ( getAccelerationPilot ( pilot ) ) ) {
        setBoostsRemainingPilot ( pilot, getBoostsRemainingPilot ( pilot ) - 1 );
    }
}

static short fuelConsumption ( 
                                POSITION position, SPEED speed, 
                                ACCELERATION action,GRAPH* graph 
                             )
{
    short norme1;
    short squareRoot;
    norme1 = ( action.X * action.X ) + ( action.Y * action.Y );
    squareRoot = (short)(sqrt((double)speed.X * (double)speed.X 
                    + (double)speed.Y * (double)speed.Y) * 3.0 / 2.0); 
    if ( isSand(graph, position) ) {
        return ( norme1 + squareRoot + 1. );
    }
    return ( norme1 + squareRoot );
}

static void updateGasPilot ( PILOT* pilot, GRAPH* graph )
{
    setGasLvlPilot ( pilot, getGasLvlPilot ( pilot ) 
                            - 
                            fuelConsumption ( getPositionPilot ( pilot ),
                                              getSpeedPilot ( pilot ),
                                              getAccelerationPilot ( pilot ),
                                              graph 
                                            ) 
                    );
}

static boolean isErrorFromPilot ( PILOT* pilot, POSITION newPosition )
{
    return ( areEqualsPosition ( getPositionPilot ( pilot ), newPosition ) );
}

static void resetSpeed ( PILOT* pilot ) 
{
    setSpeedPilot ( pilot, 0, 0 );
}

POSITION getPositionPilot ( PILOT* pilot )
{
    return pilot->position;
}

SPEED getSpeedPilot ( PILOT* pilot )
{
    return pilot->speed;
}

ACCELERATION getAccelerationPilot ( PILOT* pilot )
{
    return pilot->acceleration;
}

short getGasLvlPilot ( PILOT* pilot )
{
    return pilot->fuelLevel;
}

short getBoostsRemainingPilot ( PILOT* pilot )
{
    return pilot->boostsRemaining;
}

boolean isEnoughFuel ( 
                        GRAPH* graph, short fuelLeft, POSITION pilotPosition, 
                        SPEED pilotSpeed, PATH_LIST path 
                     )
{
    ACCELERATION tmp;
    short usedFuel = 0;

    path = resetCurrentPathList ( path );
    do {
        path = examineNextPosition ( path, pilotPosition, pilotSpeed, &tmp );
        usedFuel += fuelConsumption ( pilotPosition, pilotSpeed, tmp, graph );
        pilotSpeed.X += tmp.X;
        pilotSpeed.Y += tmp.Y;
        pilotPosition.X += pilotSpeed.X;
        pilotPosition.Y += pilotSpeed.Y;
    } while ( !isCurrentNull ( path ) );
    if ( usedFuel + FUEL_SAFETY >= fuelLeft ) {
        return false;
    }
    return true;
}

PILOT createPilot ( short fuelLevel )
{
    PILOT newPilot;
    setGasLvlPilot ( &newPilot, fuelLevel );
    initNewPilot ( &newPilot );

    return newPilot;
}

void updatePilots ( 
                    PILOT* myPilot, PILOT* secondPilot, PILOT* thirdPilot, 
                    GRAPH* graph, GRAPH* referenceGraph, DIJKSTRA* dijkstra 
                  )
{
    static int round = 0;
    POSITION myPosition, secondPosition, thirdPosition;
    POSITION trash;
    ACCELERATION nextAction;
    static POSITION previousSecound[5] = {
                                        {-1, -1}, {-1, -1}, 
                                        {-1, -1}, 
                                        {-1, -1}, {-1, -1}
                                         };
    static POSITION previousThird[5] = {
                                        {-1, -1}, {-1, -1}, 
                                        {-1, -1}, 
                                        {-1, -1}, {-1, -1}
                                       };
    PATH_LIST path = createPathList();
    round++;
    reverseGraph ( graph, referenceGraph, previousSecound, previousThird );
    updatePositionPilotFromGDC ( &myPosition, &secondPosition, &thirdPosition );
    if ( isErrorFromPilot ( myPilot, myPosition ) ) {
        resetSpeed ( myPilot );
    }
    updatePositionPilot ( 
                            myPosition, secondPosition, thirdPosition, 
                            myPilot, secondPilot, thirdPilot 
                        );
    updateGraph ( 
                    graph, secondPosition, thirdPosition, 
                    previousSecound, previousThird 
                );

    path = pathToFollow ( dijkstra, graph, myPosition );

    if ( areEqualsPosition ( examineHeadPathList ( path ), myPosition ) ) {
        fprintf ( stderr, "\n\n> EQUALS POSITION\n\n" );
        removeHeadElementPathList ( path, &trash );
    }
    path = choiceNextAction ( 
                                path, myPosition, 
                                getSpeedPilot ( myPilot ), 
                                &nextAction, 
                                graph, 
                                getGasLvlPilot ( myPilot ),
                                round 
                            );
    destroyPathList ( path );
    setActionPilot ( myPilot, nextAction.X, nextAction.Y );
    updateGasPilot ( myPilot, graph );
    updateBoostsPilot ( myPilot );
    updateSpeedPilot ( myPilot );
    deliverAction ( nextAction );
}