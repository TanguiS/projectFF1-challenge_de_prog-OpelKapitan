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
 * @author STEIMETZ Tangui <tangui.steimetz@ecole.ensicaen.fr>
 * @version 1.1.8
 * @date 15 avril 2022
 */

#ifndef __PILOT_DIERCTION__
#define __PILOT_DIRECTION__

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "pilotManagement.h"
#include "util.h"
#include "pathList.h"
#include "graphMadj.h"

#define NUMBER_DIRECTION 8  /**< the number of basic directions */

/**
 * @brief Enumeration of a direction type.
 */
typedef enum {
    right,                  /**< the right direction */
    left,                   /**< the left direction */
    up,                     /**< the up direction */
    down,                   /**< the down direction */

    boostRight,             /**< the right direction with a boost */
    boostLeft,              /**< the left direction with a boost */
    boostUp,                /**< the up direction with a boost */
    boostDown               /**< the down direction with a boost */
} direction;

/**
 * @brief Enumeration of a straight direction type
 */
typedef enum {
    towardsX,               /**< the straight direction to follow is towards X */
    towardsY,               /**< the straight direction to follow is towards Y */
    diagonal                /**< the straight direction to follow is a diagonal */
} straightDirection;

/**
 * @brief Declaration of a function pointer to redirect 
 *        to the correct function to calculate the next action
 * 
 * @param action the next determined action 
 * @return void 
 */
typedef void directionFunction ( ACCELERATION* action );

/**
 * @brief Declaration of a function pointer to redirect
 *        to the correct function to optimize the next action
 * 
 * @param path the path to follow for a pilot
 * @param pilotPosition the current pilot position
 * @param pilotSpeed the current pilot speed
 * @param nextAction the next action to determined
 * @return PATH_LIST the updated path list
 */
typedef PATH_LIST actionDeterminator ( 
                                        PATH_LIST path, 
                                        POSITION pilotPosition, 
                                        SPEED pilotSpeed, 
                                        ACCELERATION* nextAction 
                                      );

/**
 * @brief If position A is equal to position B
 * 
 * @param A a position
 * @param B another position
 * @return boolean true if are equals
 */
boolean areEqualPosition ( POSITION A, POSITION B );

/**
 * @brief Finds the theoretical next action for the information it receives.
 * 
 * @param path the path to follow for a pilot
 * @param pilotPosition the pilot position
 * @param pilotSpeed the speed pilot
 * @param nextAction the theoretical next action to determined
 * @return PATH_LIST the updated path list
 */
PATH_LIST examineNextPosition ( 
                                PATH_LIST path, 
                                POSITION pilotPosition, 
                                SPEED pilotSpeed, 
                                ACCELERATION* nextAction 
                              );

/**
 * @brief Choices the assumed best action for the next round
 * 
 * @param path the path to follow for a pilot
 * @param positionPilot the current position of a pilot
 * @param speedPilot the current speed of a pilot
 * @param nextAction the next action to determined
 * @param graph the graph of the race map
 * @param remainingFuel the remaining fuel of a pilot
 * @return PATH_LIST the updated path list
 */
PATH_LIST choiceNextAction ( 
                            PATH_LIST path, 
                            POSITION positionPilot, 
                            SPEED speedPilot, 
                            ACCELERATION* nextAction, 
                            GRAPH* graph, 
                            short remainingFuel 
                           );

#endif /* __PILOT_DIERCTION__ */