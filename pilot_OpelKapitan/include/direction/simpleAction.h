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
 * @file simpleAction.h
 * @brief This file contains the prototypes / declarations used to do simple pilot actions.
 * @author PICQUE Kylian <kylian.picque@ecole.ensicaen.fr>
 * @author STEIMETZ Tangui <tangui.steimetz@ecole.ensicaen.fr>
 * @version 1.1.8
 * @date 28 mai 2022
 */

#ifndef __SIMPLE_ACTION__
#define __SIMPLE_ACTION__

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
 * @brief Determine the correct action for a step by step movement 
 * 
 * @param path the path to follow
 * @param pilotPosition the current position of a pilot
 * @param pilotSpeed the current speed of a pilot
 * @param nextAction the determined action
 * @return PATH_LIST the updated list
 */
PATH_LIST nextActionForNextPosition ( 
                                            PATH_LIST path, 
                                            POSITION pilotPosition, 
                                            SPEED pilotSpeed, 
                                            ACCELERATION* nextAction 
                                           );


#endif 