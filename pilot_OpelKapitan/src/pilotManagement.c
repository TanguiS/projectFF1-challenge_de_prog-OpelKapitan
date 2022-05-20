/**
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */

/**
 * @file pilotManagement.h
 * @brief This file contains the functions used to manage a pilot.
 */

/**
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.2
 * @date 07 avril 2022
 */

#include "pilotManagement.h"
#include "pilotDirection.h"

#define FUEL_SAFETY 5

/**
 * @brief Set the Position Pilot object
 * 
 * @param pilot 
 * @param position 
 */
static void setPositionPilot ( PILOT* pilot, short x, short y );

/**
 * @brief Set the Speed Pilot object
 * 
 * @param pilot 
 * @param speed 
 */
static void setSpeedPilot ( PILOT* pilot, short x, short y );

/**
 * @brief Set the Action Pilot object
 * 
 * @param pilot 
 * @param action 
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
 * @brief Update the position of the three pilot
 * 
 * @param myPilot : our pilot
 * @param secondPilot : the second pilot
 * @param thirdPilot : the third pilot
 */
static void updatePositionPilotFromGDC ( PILOT* myPilot, PILOT* secondPilot, PILOT* thirdPilot );

/**
 * @brief Update the speed of our pilot
 * 
 * @param pilot : the PILOT object
 */
static void updateSpeedPilot ( PILOT* pilot );

static boolean actionIsBoosted ( ACCELERATION action );

static short fuelConsumption ( POSITION position, SPEED speed, ACCELERATION action, GRAPH* graph);

/**
 * @brief Update the gas remaining of our pilot
 * 
 * @param pilot : the PILOT object
 */
static void updateGasPilot ( PILOT* pilot, GRAPH* graph );

static void updateBoostsPilot ( PILOT* pilot );

/**
 * @brief Deliver the action to the GDP
 * 
 * @param action : the action to deliver
 */
static void deliverAction ( char* action ); /* action du type : x y */

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
    pilot->gasLvl = newGasLvl;
}

static void setBoostsRemainingPilot ( PILOT* pilot, short boostsRemaining )
{
    pilot->boostsRemaining = boostsRemaining;
}

static void initNewPilot ( PILOT* pilot )
{
    /* 
    on pourrait tenter une fonctions pour partir avec un boost dans la bonne direction directement 
    */
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

static void updatePositionPilotFromGDC ( PILOT* myPilot, PILOT* secondPilot, PILOT* thirdPilot )
{
    char buf[MAX_LINE_LENGTH];
    char* trash;
    POSITION myPosition, secoundPosition, thirdPosition;

    trash = fgets ( buf, MAX_LINE_LENGTH, stdin );
    fprintf ( stderr, "\n\nLECTURE TEST BUFFER >>>>>>>>>>>>< : %s\n\n", buf );
    fflush ( stdin );
    sscanf ( buf, "%hd %hd %hd %hd %hd %hd",
                    &myPosition.X,      &myPosition.Y,
                    &secoundPosition.X, &secoundPosition.Y,
                    &thirdPosition.X,   &thirdPosition.Y
            );
    setPositionPilot ( myPilot, myPosition.X, myPosition.Y );
    setPositionPilot ( secondPilot, secoundPosition.X, secoundPosition.Y);
    setPositionPilot ( thirdPilot, thirdPosition.X, thirdPosition.Y );
    trash = trash;
}

void updatePositionPilot ( POSITION myPosition, POSITION secoundPosition, POSITION thirdPosition, PILOT* myPilot, PILOT* secondPilot, PILOT* thirdPilot )
{
    setPositionPilot ( myPilot, myPosition.X, myPosition.Y );
    setPositionPilot ( secondPilot, secoundPosition.X, secoundPosition.Y);
    setPositionPilot ( thirdPilot, thirdPosition.X, thirdPosition.Y );
}


static boolean actionIsBoosted ( ACCELERATION action )
{
    if ( abs ( action.X ) == 2 || abs ( action.Y ) == 2 ) {
        return true;
    }
    return false;
}

static void updateBoostsPilot ( PILOT* pilot )
{
    if ( actionIsBoosted ( getAccelerationPilot ( pilot ) ) ) {
        setBoostsRemainingPilot ( pilot, getBoostsRemainingPilot ( pilot ) - 1 );
    }
    DEBUG_INT ( "> nombre de Boost restant : ", getBoostsRemainingPilot ( pilot ) );
}

static short fuelConsumption ( POSITION position, SPEED speed, ACCELERATION action,GRAPH* graph )
{
    short norme1;
    short squareRoot;
    #ifndef DEBUG
    char buf[100];
    sprintf ( buf, "speed : (%hd %hd), acc : (%hd %hd)", speed.X, speed.Y, action.X, action.Y );
    #endif

    DEBUG_STRING ( "> fuelConsumption donnée envoyé : " , buf );

    norme1 = ( action.X * action.X ) + ( action.Y * action.Y );
    squareRoot = (short)(sqrt((double)speed.X * (double)speed.X + (double)speed.Y * (double)speed.Y) * 3.0 / 2.0); 

   

    if ( isSand(graph, position) ) {
        fprintf ( stderr, ">>> resultat calcul, fuel used, sable : %d\n", norme1 + squareRoot + 1 );
        return ( norme1 + squareRoot + 1. );
    }
    fprintf ( stderr, ">>> resultat calcul, fuel used : %d\n", norme1 + squareRoot );
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
    fprintf ( stderr, "> gas lvl : %d\n", getGasLvlPilot ( pilot ) );
}

static void deliverAction ( char action[SIZE_ACTION] )
{
    fprintf ( stdout, "%s", action );
    fflush ( stdout );                /* CAUTION : This is necessary  */
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
    return pilot->gasLvl;
}

short getBoostsRemainingPilot ( PILOT* pilot )
{
    return pilot->boostsRemaining;
}

boolean isEnoughFuel ( GRAPH* graph, short fuelLeft, POSITION pilotPosition, SPEED pilotSpeed, PATH_LIST path )
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
        fprintf ( stderr, "> Position : %d %d\n", pilotPosition.X, pilotPosition.Y );
    } while ( !isCurrentNull ( path ) );
    fprintf ( stderr, ">>Consommation théorique : %d\n", usedFuel );
    if ( usedFuel + FUEL_SAFETY >= fuelLeft ) {
        return false;
    }
    return true;
}

PILOT createPilot ( short gasLvl )
{
    PILOT newPilot;
    setGasLvlPilot ( &newPilot, gasLvl );
    initNewPilot ( &newPilot );

    return newPilot;
}

/**
 * @TODO : trouver l'action avant de calculer la vitesse pour trouver la future position pour etre à jour 
 * sur le statut actuel de la course et non un tour en retard
 * @TODO predire l'essence utilise pour eviter de griller nimporte comment
 */

void updatePilots ( PILOT* myPilot, PILOT* secondPilot, PILOT* thirdPilot, GRAPH* graph, GRAPH* referenceGraph, dijkstraMatrix* dijkstra )
{
    static int round = 0;
    char action[SIZE_ACTION];
    POSITION myCar, secoundCar, thirdCar;
    POSITION trash;
    ACCELERATION nextAction;

    SPEED speed;
    static POSITION previousSecound[5] = {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}};
    static POSITION previousThird[5] = {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}};
    PATH_LIST path = createPathList();

    round++;

    /* faire un reverse graph pour remettre à un les ancienne position des pilote */

    secoundCar = getPositionPilot ( secondPilot );
    thirdCar = getPositionPilot ( thirdPilot );
    reverseGraph ( graph, referenceGraph, previousSecound, previousThird );
    
    /* nouvelle 1ere action, mettre a jour le graph on doit avoir les position au depart */
    updatePositionPilotFromGDC ( myPilot, secondPilot, thirdPilot );

    myCar = getPositionPilot ( myPilot );
    secoundCar = getPositionPilot ( secondPilot );
    thirdCar = getPositionPilot ( thirdPilot );

    updateGraph ( graph, myCar, secoundCar, thirdCar, previousSecound, previousThird );
    #ifndef DEBUG
    displayGraph ( graph );
    #endif

    /* 1ere etape : choisir une action */
    path = givePath ( dijkstra, graph, myCar );


    fprintf ( stderr, "\n\n>>>APPEL choix de l'action suivante\n" );
    if ( areEqualPosition ( examineHeadPathList ( path ), myCar ) ) {
        fprintf ( stderr, "\n\n> EQUALS POSITION\n\n" );
        removeHeadElementPathList ( path, &trash );
    }
    path = choiceNextAction ( path, myCar, getSpeedPilot ( myPilot ), &nextAction, graph, getGasLvlPilot ( myPilot ) );
    fprintf ( stderr, "     action : %hd, %hd\n\n>>> FIN <<<\n\n", nextAction.X, nextAction.Y );
    destroyPathList ( path );



    /* 2e etape : mettre a jour les donnees dans cet ordre : acc -> speed -> position */
    setActionPilot ( myPilot, nextAction.X, nextAction.Y );
    updateGasPilot ( myPilot, graph );
    updateBoostsPilot ( myPilot );
    updateSpeedPilot ( myPilot );

    speed = getSpeedPilot ( myPilot );
    myCar.X += speed.X;
    myCar.Y += speed.Y;
    myCar = getPositionPilot ( myPilot );
    fprintf ( stderr, ">UPDATE PILOT : Position : (%d, %d); Speed : (%d, %d); Acc : (%d, %d)\n", myCar.X, myCar.Y, speed.X, speed.Y, nextAction.X, nextAction.Y );
    /* 3e etape : on transmet l'action au GDP */
    sprintf ( action, "%hd %hd", nextAction.X, nextAction.Y );
    fprintf ( stderr, "\n>>>NEXT ACTION après la mise en STRING : %s\n\n", action );
    deliverAction ( action );
}