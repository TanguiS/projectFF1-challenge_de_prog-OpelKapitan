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
 * @file boostAction.c
 * @brief This file contains the functions used to apply boost.
 * @author PICQUE Kylian <kylian.picque@ecole.ensicaen.fr>
 * @author STEIMETZ Tangui <tangui.steimetz@ecole.ensicaen.fr>
 * @version 1.1.8
 * @date 28 mai 2022
 */

#include "../../include/direction/boostAction.h"
#include "../../include/direction/pilotDirection.h"

/**
 * @brief Informs if node between start and stop can be crossed
 * 
 * @param graph the path to follow
 * @param start the position of the beginning
 * @param stop the position of the end
 * @param goalPosition position where is stoked the second node between start and stop
 * @return boolean 
 */
static boolean isApprochable ( GRAPH* graph, POSITION start,  POSITION stop, POSITION* goalPosition );

/**
 * @brief Set the correct action with a boost to go to the wanted position
 * 
 * @param positionToGo the wanted position
 * @param nextAction the determined action
 */
static void boostNextAction ( POSITION positionToGo, ACCELERATION* nextAction );

/**
 * @brief Adapts the boost if there is a car on the next node
 * 
 * @param graph the path to follow
 * @param path the path to follow
 * @param pilotPosition the pilot position
 * @param goalPosition the position to go 
 * @param nextAction the next acceleration
 * @param pilotSpeed the pilot speed
 */
static void adaptPilot (
                GRAPH* graph, PATH_LIST path,
                POSITION pilotPosition,
                POSITION goalPosition,
                ACCELERATION* nextAction,
                SPEED pilotSpeed );

static void boostNextAction ( POSITION positionToGo, ACCELERATION* nextAction )
{
    if ( positionToGo.X > 0 ) {
        if ( positionToGo.X == 1 ) {
            choiceDirection ( right, nextAction );
        } else {
            choiceDirection ( boostRight, nextAction );
        }
    } else if ( positionToGo.X == 0 ) {
        goStraightX ( nextAction );
    } else {
        if ( positionToGo.X == -1 ) {
            choiceDirection ( left, nextAction );
        } else {
            choiceDirection ( boostLeft, nextAction );
        }
    }
    if ( positionToGo.Y > 0 ) {
        if ( positionToGo.Y == 1 ) {
            choiceDirection ( down, nextAction );
        } else {
            choiceDirection ( boostDown, nextAction );
        }
    } else if ( positionToGo.Y == 0 ) {
        nextAction->Y = 0;
        goStraightY ( nextAction );
    } else {
        if ( positionToGo.Y == -1 ) {
            choiceDirection ( up, nextAction );
        } else {
            choiceDirection ( boostUp, nextAction );
        }
    }
}

static boolean isApprochable ( 
                                GRAPH* graph, POSITION start,  
                                POSITION stop, POSITION* goalPosition 
                             )
{
  POSITION transition;
  InfoLine vline;
  int count = 0;
  initLine(start.X, start.Y, stop.X, stop.Y, &vline);
  while (nextPoint(&vline, &transition, +1) > 0) {
    if (transition.X == start.X && transition.Y == start.Y) {
        continue;
    }
    count++;
    if ( count == 2 ) {
        *goalPosition = transition;
    }
    if ( isInGraph ( graph, transition.X, transition.Y ) ) {
        if ( isWall (graph, transition) || isSand ( graph, transition ) ) {
            return false;
        }
    } else {
        return false;
    }
  }
  return true;
}

static void adaptPilot (
                        GRAPH* graph, PATH_LIST path,
                        POSITION pilotPosition,
                        POSITION goalPosition,
                        ACCELERATION* nextAction,
                        SPEED pilotSpeed 
                        ) {
    path_list_element nextPosition;
    if ( !isCar ( graph, goalPosition ) ) {
        return;
    }
    nextPosition = examineHeadPathList ( path );
    pilotSpeed.X += nextAction->X;
    pilotSpeed.Y += nextAction->Y;
    if ( lineToFollow ( pilotPosition, nextPosition ) == towardsX ) {
        if ( pilotSpeed.Y != 0 ) {
            while ( isCar( graph, goalPosition ) || isSand ( graph, goalPosition ) ) {
            slowDownDecrementY ( pilotSpeed, nextAction );
            goalPosition.X = pilotPosition.X + nextAction->X;
            goalPosition.Y = pilotPosition.Y + nextAction->Y;
            }
        } else {
            goStraightY ( nextAction );
        }
    } else if ( lineToFollow ( pilotPosition, nextPosition ) == towardsY ) {
        if ( pilotSpeed.X != 0) {
            while ( isCar ( graph, goalPosition ) || isSand ( graph, goalPosition) ) {
                slowDownDecrementX ( pilotSpeed, nextAction ); 
                goalPosition.X = pilotPosition.X + nextAction->X;
                goalPosition.Y = pilotPosition.Y + nextAction->Y;
            }
        } else {
            goStraightX ( nextAction );
        }
    } else {
        path = nextActionBoostedForNextPosition ( path, pilotPosition, pilotSpeed, nextAction);
    }
}

PATH_LIST nextActionBoostedForNextPosition ( 
                                                    PATH_LIST path, 
                                                    POSITION pilotPosition, 
                                                    SPEED pilotSpeed, 
                                                    ACCELERATION* nextAction 
                                                  )
{
    path_list_element nextPosition;
    POSITION positionToGo;
    if ( currentEqualsHead ( path ) ) {
        path = moveCurrentPathList ( path );
    }
    path = removeHeadElementPathList ( path, &nextPosition );
    nextPosition = examineHeadPathList ( path );
    positionToGo = hypotheticalNextPosition ( nextPosition, pilotPosition, pilotSpeed );
    boostNextAction ( positionToGo, nextAction );
    return path;
}

PATH_LIST BetterBoostForNextPosition ( 
                                        GRAPH* graph,   
                                        PATH_LIST path,
                                        POSITION pilotPosition,
                                        SPEED pilotSpeed,
                                        ACCELERATION* nextAction
                                        ) 
{
    path_list_element nextCurrent;
    path_list_element current;
    POSITION goalPosition;

    updatePathListIfstraightLine ( &path, pilotPosition, graph);
    current = getCurrentPathListElement ( path);
    nextCurrent = getNextCurrentPathList ( path );

    while ( isApprochable ( graph, pilotPosition, nextCurrent, &goalPosition ) ) {
        path = moveCurrentPathList ( path );
        nextCurrent = getNextCurrentPathList ( path);
    }
    current = getCurrentPathListElement( path );
    boostNextAction ( hypotheticalNextPosition ( current, pilotPosition, pilotSpeed ), nextAction );
    goalPosition.X = pilotPosition.X + pilotSpeed.X + nextAction->X;
    goalPosition.Y = pilotPosition.Y + pilotSpeed.Y + nextAction->Y;
    adaptPilot ( graph, path, pilotPosition, goalPosition, nextAction, pilotSpeed );
    return path;
}