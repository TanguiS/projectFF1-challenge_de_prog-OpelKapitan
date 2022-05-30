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
 * @file boostAction.h
 * @brief This file contains the prototypes / declarations used to apply boost.
 * @author PICQUE Kylian <kylian.picque@ecole.ensicaen.fr>
 * @author STEIMETZ Tangui <tangui.steimetz@ecole.ensicaen.fr>
 * @version 1.1.8
 * @date 28 mai 2022
 */

#ifndef __BOOST_ACTION__
#define __BOOST_ACTION__

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



/**
 * @brief Determine the correct action for a step by step movement with a boost
 * 
 * @param path the path to follow
 * @param pilotPosition the current position of a pilot
 * @param pilotSpeed the current speed of a pilot
 * @param nextAction the determined next action
 * @return PATH_LIST the updated list
 */
PATH_LIST nextActionBoostedForNextPosition ( 
                                                    PATH_LIST path, 
                                                    POSITION pilotPosition, 
                                                    SPEED pilotSpeed, 
                                                    ACCELERATION* nextAction 
                                                  );






/**
 * @brief Adapts the boost for the next position.
 * 
 * @param graph the path to follow
 * @param path the path to follow
 * @param pilotPosition the pilot position
 * @param pilotSpeed the pilot speed
 * @param nextAction the next acceleration
 * @return PATH_LIST the path to follow
 */
PATH_LIST BetterBoostForNextPosition ( 
                                        GRAPH* graph,   
                                        PATH_LIST path,
                                        POSITION pilotPosition,
                                        SPEED pilotSpeed,
                                        ACCELERATION* nextAction
                                        );

#endif 