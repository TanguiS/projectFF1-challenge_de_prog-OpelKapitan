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
 * @file pilotManagement.h
 * @brief This file contains the prototypes / declarations used to manage a pilot.
 * @author PICQUE Kylian <picque.kylian@ecole.ensicaen.fr>
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.2
 * @date 07 avril 2022
 */

#ifndef __PILOT_MANAGEMENT_HH__
#define __PILOT_MANAGEMENT_HH__

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "./tools/util.h"
#include "./communicatorWithGDC.h"
#include "./tools/pathList.h"
#include "./tools/list.h"
#include "./dijkstra/dijkstraAlgo.h"
#include "./dijkstra/dijkstraMatrix.h"

/**
 * @brief Declaration of a structure for a pilot object 
 */
typedef struct _dataPilot {
    POSITION position;                  /**< the current position of a pilot */
    SPEED speed;                        /**< the current speed of a pilot */
    ACCELERATION acceleration;          /**< the current acceleration of a pilot */
    short fuelLevel;                    /**< the current fuel level of a pilot */
    short boostsRemaining;              /**< the boosts remaining of a pilot */
} _dataPilot;
/**
 * @brief Declaration of a PILOT object 
 */
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
short getGasLvlPilot ( PILOT* pilot );

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
 * @param fuelLevel : the fuelLevel at start
 * @return PILOT : the new pilot
 */
PILOT createPilot ( short fuelLevel );

/**
 * @brief Updates the data from the tree pilots.
 * 
 * @param myPilot : Our pilot.
 * @param secondPilot : The second pilot. 
 * @param thirdPilot : The third pilot.
 * @param graph : The graph of the race.
 * @param referenceGraph : The graph of the beginnig of the race.
 * @param dijkstra : The dijkstra matrix.
 */
void updatePilots ( 
                    PILOT* myPilot, PILOT* secondPilot, PILOT* thirdPilot, 
                    GRAPH* graph, GRAPH* referenceGraph, DIJKSTRA* dijkstra 
                   );

/**
 * @brief If there is enough full to finish the race
 * 
 * @param graph the graph of the race
 * @param fuelLeft the fuel left in a pilot
 * @param pilotPosition the current position of a pilot
 * @param pilotSpeed the current speed of a pilot
 * @param path the path to follow
 * @return boolean  true if there is enough fuel
 */
boolean isEnoughFuel ( 
                        GRAPH* graph, short fuelLeft, POSITION pilotPosition, 
                        SPEED pilotSpeed, PATH_LIST path 
                     );

#endif /* __PILOT_MANAGEMENT_HH__ */