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

#define UNCHANGED_ACTION "keep_value"
#define STRAIGHT_ACTION "straight"
#define DEFAULT_ACTION "default"
#define NEW_ACTION "new"
#define DONT_CARE_ACTION 0
#define ACTION_IS_UNCHANGED(choice) strcmp ( choice, UNCHANGED_ACTION ) == 0 ? true : false
#define ACTION_IS_STRAIGHT(choice) strcmp ( choice, STRAIGHT_ACTION ) == 0 ? true : false
#define ACTION_IS_DEFAULT(choice) strcmp ( choice, DEFAULT_ACTION ) == 0 ? true : false
/*
A changer probablement
*/
#define X "x"
#define Y "y"
#define VALUE_DEFAULT_ACTION(i) ( strcmp ( i, X ) == 0 ) ? 1 : 0

/**
 * @brief Set the Position Pilot object
 * 
 * @param pilot : the PILOT object
 * @param xPosition : the x-axis position
 * @param yPosition : the y-axis position 
 */
static void setPositionPilot ( PILOT* pilot, short xPosition, short yPosition );

/**
 * @brief Set the Speed Pilot object
 * 
 * @param pilot : the PILOT object
 * @param xSpeed : the x-axis speed
 * @param ySpeed : the y-axis speed
 */
static void setSpeedPilot ( PILOT* pilot, short xSpeed, short ySpeed );

/**
 * @brief Set the Gas Lvl Pilot object
 * 
 * @param pilot : the PILOT object
 * @param newGasLvl : the gas level
 */
static void setGasLvlPilot ( PILOT* pilot, short newGasLvl );

/**
 * @brief Set the Action Pilot object
 * 
 * @param pilot : the PILOT object
 * @param newXAcc : the x-axis acceleration
 * @param newYAcc : the y-axis acceleration
 */
static void setActionPilot ( PILOT* pilot, short newXAcc, short newYAcc );

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
static void updatePositionPilot ( PILOT* myPilot, PILOT* secondPilot, PILOT* thirdPilot );

/**
 * @brief Update the speed of our pilot
 * 
 * @param pilot : the PILOT object
 */
static void updateSpeedPilot ( PILOT* pilot );

static boolean actionIsBoosted ( short xAcc, short yAcc );

static void updateActionPilot ( PILOT* pilot, short newXAcc, short newYAcc, char* modeChosen );

static short fuelConsumption ( short xSpeed, short ySpeed, short newXAcc, short newYAcc );

/**
 * @brief Update the gas remaining of our pilot
 * 
 * @param pilot : the PILOT object
 */
static void updateGasPilot ( PILOT* pilot );

static void updateBoostsPilot ( PILOT* pilot );

/**
 * @brief Deliver the action to the GDP
 * 
 * @param action : the action to deliver
 */
static void deliverAction ( char* action ); /* action du type : x y */

static void setPositionPilot ( PILOT* pilot, short xPosition, short yPosition )
{
    pilot->xPosition = xPosition;
    pilot->yPosition = yPosition;
}

static void setSpeedPilot ( PILOT* pilot, short xSpeed, short ySpeed )
{
    pilot->xSpeed = xSpeed;
    pilot->ySpeed = ySpeed;
}

static void setGasLvlPilot ( PILOT* pilot, short newGasLvl )
{
    pilot->gasLvl = newGasLvl;
}

static void setActionPilot ( PILOT* pilot, short newXAcc, short newYAcc )
{
    pilot->xAcc = newXAcc;
    pilot->yAcc = newYAcc;
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
    setActionPilot ( pilot, VALUE_DEFAULT_ACTION(X), VALUE_DEFAULT_ACTION(Y) );
    setBoostsRemainingPilot ( pilot, BOOSTS_AT_START );
}

static void updateSpeedPilot ( PILOT* pilot )
{
    setSpeedPilot ( pilot, getXSpeedPilot ( pilot ) + getXAccPilot ( pilot ), 
                           getYSpeedPilot ( pilot ) + getYAccPilot ( pilot ) );
}

static void updatePositionPilot ( PILOT* myPilot, PILOT* secondPilot, PILOT* thirdPilot )
{
    char buf[MAX_LINE_LENGTH];
    short myXPosition, myYPosition;
    short secondXPosition, secondYPosition;
    short thirdXPosition, thirdYPosition;

    fgets ( buf, MAX_LINE_LENGTH, stdin );
    fflush ( stdin );
    sscanf ( buf, "%hd %hd %hd %hd %hd %hd",
                    &myXPosition,       &myYPosition,
                    &secondXPosition,   &secondYPosition,
                    &thirdXPosition,    &thirdYPosition
            );
    setPositionPilot ( myPilot, myXPosition, myYPosition );
    setPositionPilot ( secondPilot, secondXPosition, secondYPosition);
    setPositionPilot ( thirdPilot, thirdXPosition, thirdYPosition );
}

static boolean actionIsBoosted ( short xAcc, short yAcc )
{
    if ( abs ( xAcc ) == 2 ) {
        return true;
    } if ( abs ( yAcc ) == 2 ) {
        return true;
    }
    return false;
}

static void updateBoostsPilot ( PILOT* pilot )
{
    if ( actionIsBoosted ( getXAccPilot ( pilot ), getYAccPilot ( pilot ) ) ) {
        setBoostsRemainingPilot ( pilot, getBoostsRemainingPilot ( pilot ) - 1 );
    }
    DEBUG_INT ( "> nombre de Boost restant : ", getBoostsRemainingPilot ( pilot ) );
}

static void updateActionPilot ( PILOT* pilot, short newXAcc, short newYAcc, char* modeChosen )
{
    if ( ACTION_IS_UNCHANGED ( modeChosen ) ) {
        DEBUG_STRING ( "====> update action : ", "ne rien faire" );
    } else if ( ACTION_IS_STRAIGHT ( modeChosen ) ) {
        DEBUG_STRING ( "====> update action : ", "garder sa vitesse actuelle" );
        setActionPilot ( pilot, (short) 0, (short) 0 );
    } else if ( ACTION_IS_DEFAULT ( modeChosen ) ) {
        DEBUG_STRING ( "====> update action : ", "en mode default (1 0)" );
        setActionPilot ( pilot, VALUE_DEFAULT_ACTION(X), VALUE_DEFAULT_ACTION(Y) );
    } else {
        DEBUG_STRING ( "====> update action : ", "Changement d'acc" );
        setActionPilot ( pilot, newXAcc, newYAcc );
    }
}

static short fuelConsumption ( short xSpeed, short ySpeed, short newXAcc, short newYAcc )
{
    short norme1;
    short squareRoot;
    #ifndef DEBUG
    char buf[100];
    sprintf ( buf, "speed : (%hd %hd), acc : (%hd %hd)", xSpeed, ySpeed, newXAcc, newYAcc );
    #endif

    DEBUG_STRING ( "> fuelConsumption : " , buf );

    norme1 = ( newXAcc * newXAcc ) + ( newYAcc * newYAcc );
    squareRoot =  (short) ( sqrt ( ( 3. * ( (float) ( xSpeed * xSpeed ) + (float) ( ySpeed * ySpeed ) ) ) / 2. ) );

    DEBUG_INT ( "> Consommation , norme1: ", norme1 );
    DEBUG_INT ( "> Consommation , squareRoot: ", squareRoot );

    DEBUG_INT ( "> Consommation : ", norme1 + squareRoot );
    return ( - ( norme1 + squareRoot ) );
}

static void updateGasPilot ( PILOT* pilot )
{
    setGasLvlPilot ( pilot, getGasLvlPilot ( pilot ) 
                            + 
                            fuelConsumption ( getXSpeedPilot ( pilot ), 
                                              getYSpeedPilot ( pilot ), 
                                              getXAccPilot ( pilot ), 
                                              getYAccPilot ( pilot ) 
                                            ) 
                    );
    DEBUG_INT ( "> gas left : ", getGasLvlPilot ( pilot ) );
}

static void deliverAction ( char action[SIZE_ACTION] )
{
    fprintf ( stdout, "%s", action );
    fflush ( stdout );                /* CAUTION : This is necessary  */
}

short getXPositionPilot ( PILOT* pilot )
{
    return pilot->xPosition;
}

short getYPositionPilot ( PILOT* pilot )
{
    return pilot->yPosition;
}

short getXSpeedPilot ( PILOT* pilot )
{
    return pilot->xSpeed;
}

short getYSpeedPilot ( PILOT* pilot )
{
    return pilot->ySpeed;
}

short getGasLvlPilot ( PILOT* pilot )
{
    return pilot->gasLvl;
}

short getXAccPilot ( PILOT* pilot )
{
    return pilot->xAcc;
}

short getYAccPilot ( PILOT* pilot )
{
    return pilot->yAcc;
}

short getBoostsRemainingPilot ( PILOT* pilot )
{
    return pilot->boostsRemaining;
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

void updatePilots ( PILOT* myPilot, PILOT* secondPilot, PILOT* thirdPilot, DATA_MAP* map )
{
    short newXAcc = 2, newYAcc = 0; /* pour la demonstration du boost */
    static int round = 0;
    char* mode;
    char action[SIZE_ACTION];

    round++;
    /* 1ere etape : choisir une action */
    if ( round == 1 ) {
        mode = NEW_ACTION;
        choiceDirection ( right, &newXAcc, &newYAcc );
    } else if ( round == 3 ) {
        mode = NEW_ACTION;
        choiceDirection ( boostRight, &newXAcc, &newYAcc );
        choiceDirection ( up, &newXAcc, &newYAcc );
    } else if ( round == 5 ) {
        mode = NEW_ACTION;
        choiceDirection ( down, &newXAcc, &newYAcc );
        choiceDirection ( right, &newXAcc, &newYAcc );
    } else if ( round == 7 ) {
        mode = NEW_ACTION;
        choiceDirection ( right, &newXAcc, &newYAcc );
        /*newXAcc = (-1);*/ /* Permet de ralentir si la vitesse est supérieur à 0 */
        /*newYAcc = 0;*/
    } else if ( round == 6 ) {
        mode = NEW_ACTION;
        slowDown ( myPilot, &newXAcc, &newYAcc ); /* on pourrait tester si la vitesse cumulée des deux directions est trop grandes */
    } else {
        mode = STRAIGHT_ACTION;
    }
    /* 2e etape : mettre a jour les donnees dans cet ordre : acc -> speed -> position */
    updateActionPilot ( myPilot, newXAcc, newYAcc, mode );
    updateBoostsPilot ( myPilot );
    updateSpeedPilot ( myPilot );
    updateGasPilot ( myPilot );
    updatePositionPilot ( myPilot, secondPilot, thirdPilot );
    /* 3e etape : on transmet l'action au GDP */
    sprintf ( action, "%hd %hd", getXAccPilot ( myPilot ), getYAccPilot ( myPilot ) );
    deliverAction ( action );
}