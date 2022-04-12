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
 * @version 1.0.1
 * @date 07 avril 2022
 */

#include "pilotManagement.h"

#define UNCHANGED_ACTION "keep_value"
#define STRAIGHT_ACTION "straight"
#define DEFAULT_ACTION "default"
#define NEW_ACTION "new"
#define ACTION_IS_UNCHANGED(choice) strcmp ( choice, UNCHANGED_ACTION ) == 0 ? true : false
#define ACTION_IS_STRAIGHT(choice) strcmp ( choice, STRAIGHT_ACTION ) == 0 ? true : false
#define ACTION_IS_DEFAULT(choice) strcmp ( choice, DEFAULT_ACTION ) == 0 ? true : false
#define X "x"
#define Y "y"
#define VALUE_DEFAULT_ACTION(i) ( strcmp ( i, X ) == 0 ) ? 1 : 0
#define DONT_CARE_ACTION 0

/*
static void putXPositionPilot ( PILOT* pilot, short newX );

static void putYPositionPilot ( PILOT* pilot, short newY );
*/

static void putPositionPilot ( PILOT* pilot, short xPosition, short yPosition );

/*
static void putXSpeedPilot ( PILOT* pilot, short newXSpeed );

static void putYSpeedPilot ( PILOT* pilot, short neuYSpeed );
*/

static void putSpeedPilot ( PILOT* pilot, short xSpeed, short ySpeed );

static void putGasLvlPilot ( PILOT* pilot, short newGasLvl );

static void putActionPilot ( PILOT* pilot, short newXAcc, short newYAcc );

static void initNewPilot ( PILOT* pilot );

/* static void instantSpeed ( short newXPosition, short newYPosition, short previousXPosition, short previousYPosition, short* xSpeed, short* ySpeed ); */

static void updatePositionPilot ( PILOT* myPilot, PILOT* secondPilot, PILOT* thirdPilot );

static void updateSpeedPilot ( PILOT* pilot );

static void updateActionPilot ( PILOT* pilot, short newXAcc, short newYAcc, char* modeChosen );

static short fuelConsumption ( short xSpeed, short ySpeed, short newXAcc, short newYAcc );

static void updateGasPilot ( PILOT* pilot );

static void deliverAction ( char* action ); /* action du type : x y */

/*
static void putXPositionPilot ( PILOT* pilot, short newX )
{
    pilot->xPosition = newX;
}

static void putYPositionPilot ( PILOT* pilot, short newY )
{
    pilot->yPosition = newY;
}
*/

static void putPositionPilot ( PILOT* pilot, short xPosition, short yPosition )
{
    pilot->xPosition = xPosition;
    pilot->yPosition = yPosition;
}

static void putSpeedPilot ( PILOT* pilot, short xSpeed, short ySpeed )
{
    pilot->xSpeed = xSpeed;
    pilot->ySpeed = ySpeed;
}

static void putGasLvlPilot ( PILOT* pilot, short newGasLvl )
{
    pilot->gasLvl = newGasLvl;
}

static void putActionPilot ( PILOT* pilot, short newXAcc, short newYAcc )
{
    pilot->xAcc = newXAcc;
    pilot->yAcc = newYAcc;
}

static void initNewPilot ( PILOT* pilot )
{
    /* 
    on pourrait tenter une fonctions pour partir avec un boost dans la bonne direction directement 
    */
    putPositionPilot ( pilot, 0, 0 );
    putSpeedPilot ( pilot, 0, 0 );
    putActionPilot ( pilot, VALUE_DEFAULT_ACTION(X), VALUE_DEFAULT_ACTION(Y) );
}

/*
static void instantSpeed ( short newXPosition, short newYPosition, short previousXPosition, short previousYPosition, short* xSpeed, short* ySpeed )
{
    DEBUG_CHAR ( "===> Calcul de la vitesse = ", ' ' );
    DEBUG_INT ( "Valeur nouvelle position x = ", (int) newXPosition );
    DEBUG_INT ( "Valeur ancienne position x = ", (int) previousXPosition );
    DEBUG_INT ( "Valeur nouvelle position y = ", (int) newYPosition );
    DEBUG_INT ( "Valeur ancienne position y = ", (int) previousYPosition );
    *xSpeed = newXPosition - previousXPosition;
    *ySpeed = newYPosition - previousYPosition;
}
*/

static void updateSpeedPilot ( PILOT* pilot )
{
    putSpeedPilot ( pilot, getXSpeedPilot ( pilot ) + getXAccPilot ( pilot ), 
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
    putPositionPilot ( myPilot, myXPosition, myYPosition );
    putPositionPilot ( secondPilot, secondXPosition, secondYPosition);
    putPositionPilot ( thirdPilot, thirdXPosition, thirdYPosition );
}

static void updateActionPilot ( PILOT* pilot, short newXAcc, short newYAcc, char* modeChosen )
{
    if ( ACTION_IS_UNCHANGED ( modeChosen ) ) {
        DEBUG_STRING ( "====> update action : ", "ne rien faire" );
    } else if ( ACTION_IS_STRAIGHT ( modeChosen ) ) {
        DEBUG_STRING ( "====> update action : ", "ne pas changer sa direction, ni son acc" );
        putActionPilot ( pilot, (short) 0, (short) 0 );
    } else if ( ACTION_IS_DEFAULT ( modeChosen ) ) {
        DEBUG_STRING ( "====> update action : ", "en mode default (1 0)" );
        putActionPilot ( pilot, VALUE_DEFAULT_ACTION(X), VALUE_DEFAULT_ACTION(Y) );
    } else {
        DEBUG_STRING ( "====> update action : ", "Changement d'acc" );
        putActionPilot ( pilot, newXAcc, newYAcc );
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
    putGasLvlPilot ( pilot, getGasLvlPilot ( pilot ) 
                            + 
                            fuelConsumption ( getXSpeedPilot ( pilot ), 
                                              getYSpeedPilot ( pilot ), 
                                              getXAccPilot ( pilot ), 
                                              getYAccPilot ( pilot ) 
                                            ) 
                    );
    DEBUG_INT ( "> gas left : ", getGasLvlPilot ( pilot ) );
}
/*
static void updatePilot ( PILOT* pilot, short newX, short newY, short newGasLvl, short newXAcc, short newYAcc, char* modeChosen )
{
    putXPositionPilot ( pilot, newX );
    putYPositionPilot ( pilot, newY );
    putGasLvlPilot ( pilot, newGasLvl );

    if ( ACTION_IS_UNCHANGED ( modeChosen ) ){
        DEBUG_STRING ( "====> update action : ", "ne rien faire" );
    } else if ( ACTION_IS_STRAIGHT ( modeChosen ) ) {
        DEBUG_STRING ( "====> update action : ", "ne pas changer sa direction, ni son acc" );
        putActionPilot ( pilot, (short) 0, (short) 0 );
    } else if ( ACTION_IS_DEFAULT ( modeChosen ) ) {
        DEBUG_STRING ( "====> update action : ", "en mode default (1 0)" );
        putActionPilot ( pilot, (short) 1, (short) 0 );
    } else {
        DEBUG_STRING ( "====> update action : ", "Changement d'acc" );
        putActionPilot ( pilot, newXAcc, newYAcc );
    }
}
*/

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

PILOT createPilot ()
{
    PILOT newPilot;
    initNewPilot ( &newPilot );

    return newPilot;
}

/**
 * @TODO : trouver l'action avant de calculer la vitesse pour trouver la future position pour etre à jour 
 * sur le statut actuel de la course et non un tour en retard
 * @TODO predire l'essence utilise pour eviter de griller nimporte comment
 */

void updatePilots ( PILOT* myPilot, PILOT* secondPilot, PILOT* thirdPilot )
{
    short newXAcc = 2, newYAcc = 0; /* pour la demonstration du boost */
    static int round = 0;
    char* mode;
    char action[SIZE_ACTION];

    round++;
    /* 1ere etape : choisir une action */
    if ( round == 1 ) {
        mode = DEFAULT_ACTION;
    } else if ( round == 2 ) {
        mode = UNCHANGED_ACTION;
    } else if ( round == 4 ) {
        mode = NEW_ACTION;
    } else if ( round == 6 ) {
        mode = NEW_ACTION;
        newXAcc = (-1); /* Permet de ralentir si la vitesse est supérieur à 0 */
        newYAcc = 0;
    } else {
        mode = STRAIGHT_ACTION;
    }
    /* 2e etape : mettre a jour les donnees dans cet ordre : acc -> speed -> position */
    updateActionPilot ( myPilot, newXAcc, newYAcc, mode );
    updateSpeedPilot ( myPilot );
    updateGasPilot ( myPilot );
    updatePositionPilot ( myPilot, secondPilot, thirdPilot );
    /* 3e etape : on transmet l'action au GDP */
    sprintf ( action, "%hd %hd", getXAccPilot ( myPilot ), getYAccPilot ( myPilot ) );
    deliverAction ( action );
}

/*
void readPilotsPosition ( PILOT* myPilot, PILOT* secondPilot, PILOT* thirdPilot )
{
    char buf[MAX_LINE_LENGTH];
    short myXPosition, myYPosition;
    short secondXPosition, secondYPosition;
    short thirdXPosition, thirdYPosition;
    short myXSpeed, myYSpeed;
    short xAcc, yAcc;
    int gasConsumption;
    static short round = 0;

    round++;

    fgets ( buf, MAX_LINE_LENGTH, stdin );
    fflush ( stdin );
    sscanf ( buf, "%hd %hd %hd %hd %hd %hd",
                    &myXPosition, &myYPosition,
                    &secondXPosition, &secondYPosition,
                    &thirdXPosition, &thirdYPosition
            );

    xAcc = getXAccPilot ( myPilot );
    yAcc = getYAccPilot ( myPilot );
    
    DEBUG_CHAR ( "====> lecture Position : ", ' ' );
    DEBUG_INT ( "Position mon pilot : x = ", (int) myXPosition );
    DEBUG_INT ( "Position mon pilot : y = ", (int) myYPosition );
    DEBUG_INT ( "Valeur acc x = ", (int) xAcc );
    DEBUG_INT ( "Valeur acc y = ", (int) yAcc );

    if ( round == 1 ) {
        instantSpeed ( myXPosition, myYPosition, myXPosition, myYPosition, &myXSpeed, &myYSpeed );
    } else {
        instantSpeed ( myXPosition, myYPosition, getXPositionPilot ( myPilot ), getYPositionPilot ( myPilot ), &myXSpeed, &myYSpeed );
    }

    gasConsumption = fuelConsumption ( myXSpeed, myYSpeed, xAcc, yAcc );

    DEBUG_CHAR ( "====> Calcul vitesse et fuel : ", ' ' );
    DEBUG_INT ( "Vitesse mon pilot : x = ", (int) myXSpeed );
    DEBUG_INT ( "Vitesse mon pilot : y = ", (int) myYSpeed );
    DEBUG_INT ( "Delta Fuel mon pilot = ", (int) gasConsumption );

    if ( round == 1 ) {
        updatePilot ( myPilot, myXPosition, myYPosition, getGasLvlPilot ( myPilot ) - gasConsumption, 0, 0, DEFAULT_ACTION );
    } else if ( round == 2 ) {
        updatePilot ( myPilot, myXPosition, myYPosition, getGasLvlPilot ( myPilot ) - gasConsumption, 0, 0, UNCHANGED_ACTION );
    } else if ( round == 4 ) {
        updatePilot ( myPilot, myXPosition, myYPosition, getGasLvlPilot ( myPilot ) - gasConsumption, 2, 0, NEW_ACTION );
    } else {
        updatePilot ( myPilot, myXPosition, myYPosition, getGasLvlPilot ( myPilot ) - gasConsumption, 2, 0, STRAIGHT_ACTION );
    }
    */
    /* Inutile le temps de debug, les msg c'est chiant;
    updatePilot ( secondPilot, secondXPosition, secondYPosition, 0, 0, 0, UNCHANGED_ACTION );
    updatePilot ( thirdPilot, thirdXPosition, thirdYPosition, 0, 0, 0, UNCHANGED_ACTION );
    */
/*
}
*/