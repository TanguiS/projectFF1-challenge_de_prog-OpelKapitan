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
#include "util.h"
#include <math.h>
#include "util.h"
#include "readMap.h"

#ifndef DEBUG
#include "debugMode.h"
#endif

#define SIZE_ACTION 10

typedef struct _dataPilot {
    short xPosition;
    short yPosition;
    short xSpeed;
    short ySpeed;
    short xAcc;
    short yAcc;
    short gasLvl;
    short boostsRemaining;
} _dataPilot;
typedef struct _dataPilot PILOT;

/**
 * @brief get the x coordinate position of a pilot
 * 
 * @param pilot : the PILOT object
 * @return short : the coordinate
 */
short getXPositionPilot ( PILOT* pilot );

/**
 * @brief get the y coordinate position of a pilot
 * 
 * @param pilot : the PILOT object
 * @return short : the coordinate
 */
short getYPositionPilot ( PILOT* pilot );

/**
 * @brief Get the Gas Lvl of a Pilot object
 * 
 * @param pilot : the PILOT object
 * @return short : the gas level
 */
short getGasLvlPilot ( PILOT* pilot );

/**
 * @brief Get the x-axis speed of a pilot
 * 
 * @param pilot : the PILOT object
 * @return short : the speed
 */
short getXSpeedPilot ( PILOT* pilot );

/**
 * @brief Get the y-axis speed of a pilot 
 * 
 * @param pilot : the PILOT object
 * @return short : the speed
 */
short getYSpeedPilot ( PILOT* pilot );

/**
 * @brief Get the x-axis acceleration of a pilot
 * 
 * @param pilot : the PILOT object
 * @return short : the acceleration
 */
short getXAccPilot ( PILOT* pilot );

/**
 * @brief Get the y-axis acceleration of a pilot 
 * 
 * @param pilot : the PILOT object
 * @return short : the acceleraion
 */
short getYAccPilot ( PILOT* pilot );

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
void updatePilots ( PILOT* myPilot, PILOT* secondPilot, PILOT* thirdPilot, DATA_MAP* map );

#endif /* __PILOT_MANAGEMENT_HH__ */