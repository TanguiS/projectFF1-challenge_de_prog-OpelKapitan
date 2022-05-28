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
 * @file simpleAction.c
 * @brief This file contains the functions used to do simple pilot actions.
 * @author PICQUE Kylian <kylian.picque@ecole.ensicaen.fr>
 * @author STEIMETZ Tangui <tangui.steimetz@ecole.ensicaen.fr>
 * @version 1.1.8
 * @date 28 mai 2022
 */


#include "../../include/direction/simpleAction.h"
#include "../../include/direction/pilotDirection.h"

PATH_LIST nextActionForNextPosition ( 
                                            PATH_LIST path, 
                                            POSITION pilotPosition, 
                                            SPEED pilotSpeed, 
                                            ACCELERATION* nextAction 
                                           )
{
    path_list_element nextPosition;
    POSITION positionToGo;
    nextPosition = examineHeadPathList ( path );
    positionToGo = hypotheticalNextPosition ( 
                                                nextPosition, 
                                                pilotPosition, 
                                                pilotSpeed 
                                            );
    basicNextAction ( positionToGo, nextAction );
    return path;
}
