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
 * @brief This file contains the prototypes / declarations used to manage a pilot.
 */

/**
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.1
 * @date 06 avril 2022
 */

#ifndef __PILOT_MANAGEMENT_HH__
#define __PILOT_MANAGEMENT_HH__

#include "util.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define SIZE_ACTION 4

typedef struct _dataPilot {
    short xPosition;
    short yPosition;
    short GasLvl;
    char action[SIZE_ACTION];
} _dataPilot;
typedef struct _dataPilot PILOT;

short getXPositionPilot ( PILOT pilot );

short getYPositionPilot ( PILOT pilot );

short getGasLvlPilot ( PILOT pilot );

char* getActionPilot ( PILOT pilot );

PILOT createpilot ();

void readPilotsPosition ( PILOT* myPilot, PILOT* secondPilot, PILOT* thirdPilot );




#endif /* __PILOT_MANAGEMENT_HH__ */