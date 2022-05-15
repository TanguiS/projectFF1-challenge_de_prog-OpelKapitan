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

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "util.h"
#include "readMap.h"
#include "pathList.h"
#include "list.h"
#include "dijkstraAlgo.h"
#include "dijkstraMatrix.h"

#ifndef DEBUG
#include "debugMode.h"
#endif

#define SIZE_ACTION 10

typedef struct _dataPilot {
    POSITION position;
    SPEED speed;
    ACCELERATION acceleration;
    double gasLvl;
    short boostsRemaining;
} _dataPilot;
typedef struct _dataPilot PILOT;

/**
 * @brief Get the Position Pilot object
 * 
 * @param pilot 
 * @return POSITION 
 */
POSITION getPositionPilot ( PILOT* pilot );

/**
 * @brief Get the Speed Pilot object
 * 
 * @param pilot 
 * @return SPEED 
 */
SPEED getSpeedPilot ( PILOT* pilot );

/**
 * @brief Get the Acceleration Pilot object
 * 
 * @param pilot 
 * @return ACCELERATION 
 */
ACCELERATION getAccelerationPilot ( PILOT* pilot );

/**
 * @brief Get the Gas Lvl of a Pilot object
 * 
 * @param pilot : the PILOT object
 * @return short : the gas level
 */
double getGasLvlPilot ( PILOT* pilot );

/**
 * @brief Get the Boosts Remaining of a pilot 
 * 
 * @param pilot : the PILOT object
 * @return short : the boosts remaining
 */
short getBoostsRemainingPilot ( PILOT* pilot );

/**
 * @brief Create a Pilot object
 * 
 * @param gasLvl : the gasLvl at start
 * @return PILOT : the new pilot
 */
PILOT createPilot ( short gasLvl );

/**
 * @brief Updates the data from the tree pilots
 * 
 * @param myPilot : Our pilot
 * @param secondPilot : the second pilot 
 * @param thirdPilot : the third pilot
 * @param map : the race circuit
 */
void updatePilots ( PILOT* myPilot, PILOT* secondPilot, PILOT* thirdPilot, DATA_MAP* map, GRAPH* graph, dijkstraMatrix* dijkstra );

#endif /* __PILOT_MANAGEMENT_HH__ */