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
 * @file diagonalAction.h
 * @brief This file contains the functions's prototype used to modify the diagonal action.
 * @author PICQUE Kylian <kylian.picque@ecole.ensicaen.fr>
 * @author STEIMETZ Tangui <tangui.steimetz@ecole.ensicaen.fr>
 * @version 1.0.0
 * @date 28 mai 2022
 */

#ifndef __DIAGONAL_ACTION__
#define __DIAGONAL_ACTION__

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "./pilotManagement.h"
#include "./actionModificator.h"
#include "../tools/util.h"
#include "../tools/pathList.h"
#include "../race/graph.h"
#include "./follow_line.h"


/**
 * @brief vector between two positions
 * 
 * @param finalPosition the final position
 * @param startPosition  the first position
 * @return POSITION the vector
 */
POSITION positionVector ( POSITION finalPosition, POSITION startPosition );

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
 * @brief Equilibrate the X-speed of a pilot
 * 
 * @param pilotPositionX : the X-position of a pilot
 * @param nextPositionX : the X-next position of the path
 * @param positionToGoX : the X-position to go
 * @param pilotSpeedX : the X-speed of a pilot
 * @param nextAction : the next action to determine
 */
void equilibrateSpeedX ( 
                                short pilotPositionX, short nextPositionX, 
                                short positionToGoX, short pilotSpeedX, 
                                ACCELERATION* nextAction 
                              );

/**
 * @brief Equilibrate the Y-speed of a pilot
 * 
 * @param positionPilotY : the Y-position of a pilot
 * @param nextPositionY : the Y-next position of the path
 * @param positionToGoY : the Y-position to go
 * @param pilotSpeedY : the Y-speed of a pilot
 * @param nextAction : the next action to determine
 */
void equilibrateSpeedY ( 
                                short positionPilotY, short nextPositionY, 
                                short positionToGoY, short pilotSpeedY, 
                                ACCELERATION* nextAction 
                              );

/**
 * @brief Equilibrate the speed of the pilote to enter properly in a diagonal
 * 
 * @param path : the path to follow
 * @param pilotPosition : the current postion of the pilot
 * @param pilotSpeed : the current pilot speed
 * @param nextAction : the action to determine
 * @return PATH_LIST : the updated path
 */
PATH_LIST equilibrateSpeedForStraightLine ( 
                                                    PATH_LIST path, 
                                                    POSITION pilotPosition, 
                                                    SPEED pilotSpeed, 
                                                    ACCELERATION* nextAction 
                                                  );


/**
 * @brief Try to increase the speed inside diagonals
 * 
 * @param length length between the current node and the goal node
 * @param currentSpeed the current speed
 * @param startingIndex an index
 * @param startPosition the current position
 * @param finalPosition the goal poition
 * @param actions the accelration
 */
void addActionToGroupDiagonal ( 
                            short length, short currentSpeed, 
                            short startingIndex, POSITION startPosition, 
                            POSITION finalPosition, ACCELERATION* actions 
                              );





#endif /* __DIAGONAL_ACTION__ */