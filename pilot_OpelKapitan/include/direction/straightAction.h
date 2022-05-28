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
 * @file straightAction.h
 * @brief This file contains the functions's prototype used to determine action for a straight line.
 * @author PICQUE Kylian <kylian.picque@ecole.ensicaen.fr>
 * @author STEIMETZ Tangui <tangui.steimetz@ecole.ensicaen.fr>
 * @version 1.0.0
 * @date 28 mai 2022
 */

#ifndef __STRAIGHT_ACTION_HH__
#define __STRAIGHT_ACTION_HH__

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "./pilotManagement.h"
#include "./actionModificator.h"
#include "../tools/util.h"
#include "../tools/pathList.h"
#include "../graph.h"
#include "./follow_line.h"

/**
 * @brief Enumeration of a straight direction type
 */
typedef enum {
    towardsX,               /**< the straight direction to follow is towards X */
    towardsY,               /**< the straight direction to follow is towards Y */
    diagonal                /**< the straight direction to follow is a diagonal */
} straightDirection;

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
 * @brief Update the path to follow if the path is straight
 * 
 * @param path the path to follow
 * @param currentPosition the current position of a pilot
 * @param graph the race graph
 * @return boolean true if the path has been updated
 */
boolean updatePathListIfstraightLine ( 
                                                PATH_LIST* path, 
                                                POSITION currentPosition, 
                                                GRAPH* graph 
                                            );

/**
 * @brief Redirect to the correct function to determine a group of action if the path if straight
 * 
 * @param path the path to follow
 * @param pilotPosition the current pilot position
 * @param pilotSpeed the current pilot speed
 * @param nextAction the group of action
 * @return PATH_LIST the updated path list
 */
PATH_LIST groupNextAction ( 
                                    PATH_LIST path, POSITION pilotPosition, 
                                    SPEED pilotSpeed, ACCELERATION* nextAction 
                                 );

/**
 * @brief Add action to a queue if the direction is straight
 * 
 * @param length the length to travel
 * @param currentSpeed the current speed of a pilot
 * @param startingIndex the starting index to add actions
 * @param startPosition the current position
 * @param finalPosition the final position of the straight line
 * @param actions a group of action to follow
 * @return short the length 
 */
void addActionToGroup ( 
                            short length, short currentSpeed, 
                            short startingIndex, POSITION startPosition, 
                            POSITION finalPosition, ACCELERATION* actions 
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

#endif /* __STRAIGHT_ACTION_HH__ */