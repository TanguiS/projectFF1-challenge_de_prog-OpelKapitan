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
 * @file pilotDirection.h
 * @brief This file contains the prototypes / declarations used to choose the pilot's direction.
 */

/**
 * @author PICQUE Kylian <kylian.picque@ecole.ensicaen.fr>
 * @version 1.0.0
 * @date 15 avril 2022
 */



#ifndef __PILOT_DIERCTION__
#define __PILOT_DIRECTION__

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "pilotManagement.h"
#include "util.h"
/* #include "dijkstraMatrix.h"
#include "dijkstraAlgo.h" */
#include "pathList.h"
#include "graphMadj.h"
#ifndef DEBUG
#include "debugMode.h"
#endif

#define NUMBER_DIRECTION 8
#define NUMBER_PEDAL 2

typedef enum {
    right, 
    left,
    up,
    down,

    boostRight,
    boostLeft,
    boostUp,
    boostDown

    /* straight */
} direction;

typedef enum {
    slower,
    faster
} pedal;

typedef void directionFct ( ACCELERATION* action );

typedef PATH_LIST actionDeterminator ( PATH_LIST , POSITION , SPEED , ACCELERATION* );

void goRight ( ACCELERATION* action ); 

void goLeft ( ACCELERATION* action );

void goUp ( ACCELERATION* action );

void goDown ( ACCELERATION* action );

void goBoostRight ( ACCELERATION* action );

void goBoostLeft ( ACCELERATION* action );

void goBoostUp ( ACCELERATION* action );

void goBoostDown ( ACCELERATION* action );

void goStraight ( ACCELERATION* action );

void slowDown ( POSITION goalPosition, SPEED speed, ACCELERATION* action );

void accelerate ( POSITION goalPosition, SPEED speed, ACCELERATION* action );

void choiceDirection ( direction choice, ACCELERATION* action );



boolean nextActionRedirector ( PATH_LIST* path, POSITION positionPilot, SPEED speedPilot, ACCELERATION* nextAction, boolean* flag );



boolean floorDistance ( short length, short* indexFloor );
void classicAction ( short indexFloor );



PATH_LIST nextActionBasic ( PATH_LIST path, POSITION positionPilot, SPEED speedPilot, ACCELERATION* nextAction );

PATH_LIST nextActionLigne ( PATH_LIST path, POSITION positionPilot, SPEED speedPilot, ACCELERATION* nextAction, int* midLength );

PATH_LIST nextAction2 ( PATH_LIST path, POSITION pilotPosition, SPEED pilotSpeed, ACCELERATION* nextAction );



#endif