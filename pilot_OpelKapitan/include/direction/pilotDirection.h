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
 * @file pilotDirection.h
 * @brief This file contains the prototypes / declarations used to choose the pilot's direction.
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
#include "./pilotManagement.h"
#include "./actionModificator.h"
#include "../tools/util.h"
#include "../tools/pathList.h"
#include "../graph.h"
#include "./follow_line.h"
#include "./straightAction.h"
#include "./boostAction.h"
#include "./simpleAction.h"

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
boolean areEqualsPosition ( POSITION A, POSITION B );

/**
 * @brief vector between two positions
 * 
 * @param finalPosition the final position
 * @param startPosition  the first position
 * @return POSITION the vector
 */
POSITION positionVector ( POSITION finalPosition, POSITION startPosition );

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
 * @brief Determine the hypotetical next position according to current data
 * 
 * @param nextPosition The next position to follow
 * @param currentPosition the current position of a pilot
 * @param currentSpeed The current speed of a pilot
 * @return POSITION The next position
 */
POSITION hypotheticalNextPosition( 
                                            POSITION nextPosition, 
                                            POSITION currentPosition, 
                                            SPEED currentSpeed 
                                         );

/**
 * @brief Determine the correct function to set the action
 * 
 * @param choice the direction wanted
 * @param action the action determined
 */
void choiceDirection ( direction choice, ACCELERATION* action );

/**
 * @brief Choices the assumed best action for the next round
 * 
 * @param path the path to follow for a pilot
 * @param positionPilot the current position of a pilot
 * @param speedPilot the current speed of a pilot
 * @param nextAction the next action to determined
 * @param graph the graph of the race map
 * @param remainingFuel the remaining fuel of a pilot
 * @param round the round number
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