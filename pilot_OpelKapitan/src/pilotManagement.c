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
 * @version 1.0.0
 * @date 07 avril 2022
 */

#include "pilotManagement.h"

#define ON "on"
#define DEFAULT_MODE(i) ( strcmp ( i, ON ) == 0 ) ? true : false
#define DEFAULT_ACTION "1 0"
#define UNCHANGED_ACTION "yes"
#define CHANGE_ACTION(i) ( strcmp ( i, UNCHANGED_ACTION ) == 0 ) ? true : false

static void putXPositionPilot ( PILOT* pilot, short newX );

static void putYPositionPilot ( PILOT* pilot, short newY );

static void putGasLvlPilot ( PILOT* pilot, short newGasLvl );

static void putActionPilot ( PILOT* pilot, char newAction[SIZE_ACTION] );

static PILOT initNewPilot ( PILOT pilot, short newX, short newY, short newGasLvl );

static void updatePilot ( PILOT* pilot, short newX, short newY, short newGasLvl, char newAction[SIZE_ACTION] );

static void putXPositionPilot ( PILOT* pilot, short newX )
{
    pilot->xPosition = newX;
}

static void putYPositionPilot ( PILOT* pilot, short newY )
{
    pilot->yPosition = newY;
}

static void putGasLvlPilot ( PILOT* pilot, short newGasLvl )
{
    pilot->GasLvl = newGasLvl;
}

static void putActionPilot ( PILOT* pilot, char newAction[SIZE_ACTION] )
{
    sprintf ( pilot->action, "%d %d", (int) newAction[0], (int) newAction[2] );
}

static PILOT initNewPilot ( PILOT pilot, short newX, short newY, short newGasLvl )
{
    /* 
    on pourrait tenter une fonctions pour partir avec un boost dans la bonne direction directement 
    */
    putXPositionPilot ( &pilot, newX );
    putYPositionPilot ( &pilot, newY );
    putGasLvlPilot ( &pilot, newGasLvl );
    putActionPilot ( &pilot, DEFAULT_ACTION );

    return pilot;
}

static void updatePilot ( PILOT* pilot, short newX, short newY, short newGasLvl, char newAction[SIZE_ACTION] )
{
    putXPositionPilot ( pilot, newX );
    putYPositionPilot ( pilot, newY );
    putGasLvlPilot ( pilot, newGasLvl );
    if ( DEFAULT_MODE ( newAction ) ) {
        putActionPilot ( pilot, DEFAULT_ACTION );
    } else if ( CHANGE_ACTION ( newAction ) ) {
    } else {
        putActionPilot ( pilot, newAction );
    }
}

short getXPositionPilot ( PILOT pilot )
{
    return pilot.xPosition;
}

short getYPositionPilot ( PILOT pilot )
{
    return pilot.yPosition;
}

short getGasLvlPilot ( PILOT pilot )
{
    return pilot.GasLvl;
}

char* getActionPilot ( PILOT pilot )
{
    return pilot.action;
}

PILOT createpilot ()
{
    PILOT newPilot;

    newPilot = initNewPilot ( newPilot, 0, 0, 0 );

    return newPilot;
}

void readPilotsPosition ( PILOT* myPilot, PILOT* secondPilot, PILOT* thirdPilot )
{
    char buf[MAX_LINE_LENGTH];
    short myXPosition, myYPosition;
    short secondXPosition, secondYPosition;
    short thirdXPosition, thirdYPosition;

    fgets ( buf, MAX_LINE_LENGTH, stdin );
    sscanf ( buf, "%hd %hd %hd %hd %hd %hd",
                    &myXPosition, &myYPosition,
                    &secondXPosition, &secondYPosition,
                    &thirdXPosition, &thirdYPosition
            );
    updatePilot ( myPilot, myXPosition, myYPosition, 0, UNCHANGED_ACTION );
    updatePilot ( secondPilot, secondXPosition, secondYPosition, 0, UNCHANGED_ACTION );
    updatePilot ( thirdPilot, thirdXPosition, thirdYPosition, 0, UNCHANGED_ACTION );
}