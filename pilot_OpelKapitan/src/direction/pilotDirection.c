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
 * @file pilotDirection.c
 * @brief This file contains the functions used to choose the pilot's direction/action.
 * @author PICQUE Kylian <kylian.picque@ecole.ensicaen.fr>
 * @author STEIMETZ Tangui <tangui.steimetz@ecole.ensicaen.fr>
 * @version 1.1.11
 * @date 15 avril 2022
 */

#include "../../include/direction/pilotDirection.h"

/**
 * @brief if the speed is null
 * 
 * @param pilotSpeed the current pilot speed
 * @return boolean true if speed is null
 */
static boolean speedIsNull ( SPEED pilotSpeed );


/**
 * @brief Correct the action in case off the trajectory is impossible
 * 
 * @param graph the graph of the race
 * @param pilotPosition the current pilot position
 * @param nextPosition the next position in the path to follow
 * @param pilotSpeed the current pilot speed
 * @param nextAction the next action
 */
static void trajectoryCorrection ( 
                                    GRAPH* graph, POSITION pilotPosition, 
                                    POSITION nextPosition, SPEED pilotSpeed, 
                                    ACCELERATION* nextAction 
                                  );


static boolean speedIsNull ( SPEED pilotSpeed )
{
    return ( pilotSpeed.X == 0 && pilotSpeed.Y == 0 );
}


static void trajectoryCorrection ( 
                                    GRAPH* graph, POSITION pilotPosition, 
                                    POSITION nextPosition, SPEED pilotSpeed, 
                                    ACCELERATION* nextAction 
                                  )
{
    POSITION goalPosition;
    goalPosition.X = pilotPosition.X + pilotSpeed.X + nextAction->X;
    goalPosition.Y = pilotPosition.Y + pilotSpeed.Y + nextAction->Y;
    if ( isInGraph ( graph, goalPosition.X, goalPosition.Y ) ) {
        if ( isWall ( graph, goalPosition ) ) {
            if ( lineToFollow (pilotPosition, nextPosition ) == towardsX ) {
                slowDownDecrementY ( pilotSpeed, nextAction);
            } else {
                slowDownDecrementX ( pilotSpeed, nextAction);
            }
        } else if ( isSand ( graph, goalPosition ) ) {
            if ( lineToFollow ( pilotPosition, goalPosition ) == towardsX ) {
                fprintf ( stderr, "pb sand x\n" );
            } else {
                fprintf ( stderr, "pb sable y\n" );
            }
        }
    }
}


boolean areEqualsPosition ( POSITION A, POSITION B )
{
    return A.X == B.X && A.Y == B.Y;
}

PATH_LIST examineNextPosition ( 
                                PATH_LIST path, POSITION pilotPosition, 
                                SPEED pilotSpeed, ACCELERATION* nextAction 
                              )
{
    path_list_element nextPosition;
    POSITION positionToGo;
    nextPosition = getCurrentPathListElement ( path );
    path = moveCurrentPathList ( path );
    positionToGo = hypotheticalNextPosition ( 
                                                nextPosition, 
                                                pilotPosition, 
                                                pilotSpeed 
                                            );
    basicNextAction ( positionToGo, nextAction );
    return path;
}

PATH_LIST choiceNextAction ( 
                            PATH_LIST path, POSITION pilotPosition, 
                            SPEED pilotSpeed, ACCELERATION* nextAction, 
                            GRAPH* graph, short remainingFuel,
                            int round 
                           )
{
    static ACCELERATION* actionTab = NULL;
    static short countAction = 1;
    boolean flag = false;
    static actionDeterminator* redirectTab[3] = 
            {
                nextActionForNextPosition,
                groupNextAction,
                nextActionBoostedForNextPosition
            };
    if ( actionTab == NULL ) {
        actionTab = ( ACCELERATION* ) malloc ( 255 * sizeof ( ACCELERATION ) );
    }
    if ( speedIsNull ( pilotSpeed ) ) {
        if ( round == 1 ) {
            path = BetterBoostForNextPosition( graph, path, pilotPosition, pilotSpeed, actionTab );
        } else {
            if ( !isSand ( graph, pilotPosition ) ) {
                path = redirectTab[2]( path, pilotPosition, pilotSpeed, actionTab );
            } else {
                path = redirectTab[1]( path, pilotPosition, pilotSpeed, actionTab );
                return path;
            }
        }
        if ( !isEmptyPathList ( path ) ) {
            trajectoryCorrection ( graph, pilotPosition, examineHeadPathList ( path ), pilotSpeed, nextAction );
        }
        nextAction->X = actionTab->X;
        nextAction->Y = actionTab->Y;
        return path;
    } 
    if ( !isEnoughFuel ( graph, remainingFuel, pilotPosition, pilotSpeed, path ) ) {
        path = redirectTab[flag](path, pilotPosition, pilotSpeed, actionTab ); 
    } else {
        flag = updatePathListIfstraightLine ( &path, pilotPosition, graph );
        path = redirectTab[flag](path, pilotPosition, pilotSpeed, actionTab ); 
    }
    if ( flag ) {
        nextAction->X = actionTab[countAction].X;   
        nextAction->Y = actionTab[countAction].Y;
        if ( !isEmptyPathList ( path ) ) {
            trajectoryCorrection ( graph, pilotPosition, examineHeadPathList ( path ), pilotSpeed, nextAction );
        }
        return path;
    }
    nextAction->X = actionTab->X;
    nextAction->Y = actionTab->Y;
    if ( !isEmptyPathList ( path ) ) {
        trajectoryCorrection ( graph, pilotPosition, examineHeadPathList ( path ), pilotSpeed, nextAction );
    }
    return path;
}