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


PATH_LIST groupNextAction ( 
                                    PATH_LIST path, POSITION pilotPosition, 
                                    SPEED pilotSpeed, ACCELERATION* nextAction 
                                 )
{
    POSITION goalPosition;
    straightDirection directionLine;

    goalPosition = getCurrentPathListElement ( path );
    directionLine = lineToFollow ( pilotPosition, goalPosition );
    if ( directionLine == towardsX ) {
        addActionToGroup ( 
                        abs ( positionVector ( goalPosition, pilotPosition ).X ), 
                        pilotSpeed.X, 
                        1, 
                        pilotPosition, 
                        goalPosition, 
                        nextAction 
                            );
        if ( pilotSpeed.Y != 0 ) {
            slowDownY ( pilotSpeed, &nextAction[1] );
        }
    } else if ( directionLine == towardsY ) {
        addActionToGroup ( 
                        abs ( positionVector ( goalPosition, pilotPosition ).Y ), 
                        pilotSpeed.Y, 
                        1, 
                        pilotPosition, 
                        goalPosition, 
                        nextAction 
                            );
        if ( pilotSpeed.X != 0 ) {
            slowDownX ( pilotSpeed, &nextAction[1] );
        }
    } else { /* c'est une diagonale */
        fprintf ( stderr, "diagonal\n" );
        if ( abs ( pilotSpeed.X ) != abs ( pilotSpeed.Y ) ) {
            fprintf ( stderr, "to equilibrate\n" );

            path = equilibrateSpeedForStraightLine ( path, pilotPosition, pilotSpeed, &nextAction[1] );
            return path;
        }
        addActionToGroupDiagonal ( abs ( positionVector ( goalPosition, pilotPosition ).X ), pilotSpeed.X, 1, pilotPosition, goalPosition, nextAction );
    }
    return path;
}