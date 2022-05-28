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

boolean isApprochable ( 
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
        goalPosition->X = transition.X;
        goalPosition->Y = transition.Y;
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

void adaptPilot (
                GRAPH* graph, PATH_LIST path,
                POSITION pilotPosition,
                POSITION goalPosition,
                ACCELERATION* nextAction,
                SPEED pilotSpeed ) {
    path_list_element nextPosition;
    if ( !isCar ( graph, goalPosition ) ) {
        return;
    }
    nextPosition = examineHeadPathList ( path );
    pilotSpeed.X += nextAction->X;
    pilotSpeed.Y += nextAction->Y;
    if ( lineToFollow ( pilotPosition, nextPosition ) == towardsX ) {
        if ( pilotSpeed.Y != 0 ) {
            while ( isCar( graph, goalPosition ) ) {
            slowDownDecrementY ( pilotSpeed, nextAction );
            goalPosition.X = pilotPosition.X + nextAction->X;
            goalPosition.Y = pilotPosition.Y + nextAction->Y;
            }
        } else {
            goStraightY ( nextAction );
        }
    } else if ( lineToFollow ( pilotPosition, nextPosition ) == towardsY ) {
        if ( pilotSpeed.X != 0) {
            while ( isCar ( graph, goalPosition ) ) {
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