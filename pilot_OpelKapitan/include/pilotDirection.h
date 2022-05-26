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
#include "actionModificator.h"
#include "util.h"
#include "pathList.h"
#include "graph.h"
#include "follow_line.h"

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
 * @brief If the positions A, B and C are aligned
 * 
 * @param A a postion
 * @param B another position
 * @param C and another one
 * @return boolean true if are aligned
 */
boolean areAligned ( POSITION A, POSITION B, POSITION C );

/**
 * @brief Which direction is the straight line
 * 
 * @param startPosition the current position
 * @param goalPosition the position to arrive
 * @return straightDirection the line that will be followed
 */
straightDirection lineToFollow ( 
                                POSITION startPosition, 
                                POSITION goalPosition 
                                );

/**
 * @brief If position A is equal to position B
 * 
 * @param A a position
 * @param B another position
 * @return boolean true if are equals
 */
boolean areEqualsPosition ( POSITION A, POSITION B );

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
                            short remainingFuel,
                            int round
                           );

#endif /* __PILOT_DIERCTION__ */