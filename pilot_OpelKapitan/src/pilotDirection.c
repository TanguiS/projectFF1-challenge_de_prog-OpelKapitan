/**
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
 */

/**
 * @author PICQUE Kylian <kylian.picque@ecole.ensicaen.fr>
 * @author STEIMETZ Tangui <tangui.steimetz@ecole.ensicaen.fr>
 * @version 1.1.11
 * @date 15 avril 2022
 */

#include "pilotDirection.h"

#define ACTION 1            /**< the classic Action value */
#define BOOSTED_ACTION 2    /**< the boost Action value */
#define STRAIGHT_ACTION 0   /**< the straight Action value */
#define MAX_SPEED 5         /**< the maximum speed that we fixed */

/**
 * @brief Set action to right
 * 
 * @param action the action determined
 */
static void goRight ( ACCELERATION* action ) {
    action->X = STRAIGHT_ACTION + ACTION;
}

/**
 * @brief Set action to left
 * 
 * @param action the action determined
 */
static void goLeft ( ACCELERATION* action ) {
    action->X = STRAIGHT_ACTION - ACTION;
}

/**
 * @brief Set action to up
 * 
 * @param action the action determined
 */
static void goUp ( ACCELERATION* action  ) {
    action->Y = STRAIGHT_ACTION - ACTION;
}

/**
 * @brief Set action to down
 * 
 * @param action the action determined
 */
static void goDown ( ACCELERATION* action  ) {
    action->Y = STRAIGHT_ACTION + ACTION;
}

/**
 * @brief Set action to straight
 * 
 * @param action the action determined
 */
static void goStraight ( ACCELERATION* action ) {
    action->X = STRAIGHT_ACTION;
    action->Y = STRAIGHT_ACTION;
}

/**
 * @brief Set action to straight towards X
 * 
 * @param action the action determined
 */
static void goStraightX ( ACCELERATION* action ) {
    action->X = STRAIGHT_ACTION;
}

/**
 * @brief Set action to straight towards Y
 * 
 * @param action the action determined
 */
static void goStraightY ( ACCELERATION* action ) {
    action->Y = STRAIGHT_ACTION;
}

/**
 * @brief Set action to right with a boost
 * 
 * @param action the action determined
 */
static void goBoostRight ( ACCELERATION* action ) {
    action->X = STRAIGHT_ACTION + BOOSTED_ACTION;
}

/**
 * @brief Set action to left with a boost
 * 
 * @param action the action determined
 */
static void goBoostLeft ( ACCELERATION* action ) {
    action->X = STRAIGHT_ACTION - BOOSTED_ACTION;
}

/**
 * @brief Set action to up with a boost
 * 
 * @param action the action determined
 */
static void goBoostUp ( ACCELERATION* action ) {
    action->Y = STRAIGHT_ACTION - BOOSTED_ACTION;
}

/**
 * @brief Set action to down with a boost
 * 
 * @param action the action determined
 */
static void goBoostDown ( ACCELERATION* action ) {
    action->Y = STRAIGHT_ACTION + BOOSTED_ACTION;
}

/**
 * @brief Determine the correct function to set the action
 * 
 * @param choice the direction wanted
 * @param action the action determined
 */
static void choiceDirection ( direction choice, ACCELERATION* action )
{
    static directionFunction* directionTab[NUMBER_DIRECTION] = 
    {
        goRight, goLeft, goUp, goDown,
        goBoostRight, goBoostLeft, goBoostUp, goBoostDown
    };
    directionTab[choice]( action );
}

/**
 * @brief Set action to slow down but it keeps the direction
 * 
 * @param directionToSlow the direction of the pilot
 * @param action the action determined
 */
static void slowDown ( POSITION directionToSlow, ACCELERATION* action )
{
    if ( directionToSlow.X > STRAIGHT_ACTION ) {
        goLeft ( action );
    } else if ( directionToSlow.X == STRAIGHT_ACTION ) {
        action->X = STRAIGHT_ACTION;
    }  else {
        goRight ( action );
    }
    if ( directionToSlow.Y > STRAIGHT_ACTION ) {
        goUp ( action );
    } else if ( directionToSlow.Y == STRAIGHT_ACTION ) {
        action->Y = STRAIGHT_ACTION;
    }  else {
        goDown ( action );
    }
}

/**
 * @brief Set action to slow down towards X
 * 
 * @param speedToSlow the speed of the pilot to remove
 * @param action the action determined
 */
static void slowDownX ( SPEED speedToSlow, ACCELERATION* action )
{
    if ( speedToSlow.X > STRAIGHT_ACTION ) {
        goLeft ( action );
    }  else {
        goRight ( action );
    }
}

/**
 * @brief Set action to slow down towards Y
 * 
 * @param speedToSlow the speed of the pilot to remove
 * @param action the action determined
 */
static void slowDownY ( SPEED speedToSlow, ACCELERATION* action )
{
    if ( speedToSlow.Y > STRAIGHT_ACTION ) {
        goUp ( action );
    } else {
        goDown ( action );
    }
}

/**
 * @brief Set action to accelerate towards the direction
 * 
 * @param directionToAccelerate the direction of the pilot
 * @param action the action determined
 */
static void accelerate ( POSITION directionToAccelerate, ACCELERATION* action )
{
    if ( directionToAccelerate.X > STRAIGHT_ACTION ) {
        goRight ( action );
    } else if ( directionToAccelerate.X == STRAIGHT_ACTION ) {
        action->X = STRAIGHT_ACTION;
    } else {
        goLeft ( action );
    }
    if ( directionToAccelerate.Y > STRAIGHT_ACTION ) {
        goDown ( action );
    } else if ( directionToAccelerate.Y == STRAIGHT_ACTION ) {
        action->Y = STRAIGHT_ACTION;
    } else {
        goUp ( action );
    } 
}

/**
 * @brief Set the correct action to go to the wanted position
 * 
 * @param positionToGo the wanted position
 * @param nextAction the determined action
 */
static void basicNextAction ( POSITION positionToGo, ACCELERATION* nextAction )
{
    if ( positionToGo.X > STRAIGHT_ACTION ) {
        choiceDirection ( right, nextAction );
    } else if ( positionToGo.X == STRAIGHT_ACTION ) {
        goStraightX ( nextAction );
    } else {
        choiceDirection ( left, nextAction );
    }
    if ( positionToGo.Y > STRAIGHT_ACTION ) {
        choiceDirection ( down, nextAction );
    } else if ( positionToGo.Y == STRAIGHT_ACTION ) {
        goStraightY ( nextAction );
    } else {
        choiceDirection ( up, nextAction );
    }
}

/**
 * @brief Set the correct action with a boost to go to the wanted position
 * 
 * @param positionToGo the wanted position
 * @param nextAction the determined action
 */
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

/**
 * @brief Determine the hypotetical next position according to current data
 * 
 * @param nextPosition The next position to follow
 * @param currentPosition the current position of a pilot
 * @param currentSpeed The current speed of a pilot
 * @return POSITION The next position
 */
static POSITION hypotheticalNextPosition ( 
                                            POSITION nextPosition, 
                                            POSITION currentPosition, 
                                            SPEED currentSpeed 
                                         )
{
    nextPosition.X =  nextPosition.X - currentPosition.X - currentSpeed.X;
    nextPosition.Y =  nextPosition.Y - currentPosition.Y - currentSpeed.Y;
    return nextPosition;
}

/**
 * @brief Determine the correct action for a step by step movement 
 * 
 * @param path the path to follow
 * @param pilotPosition the current position of a pilot
 * @param pilotSpeed the current speed of a pilot
 * @param nextAction the determined action
 * @return PATH_LIST the updated list
 */
static PATH_LIST nextActionForNextPosition ( 
                                            PATH_LIST path, 
                                            POSITION pilotPosition, 
                                            SPEED pilotSpeed, 
                                            ACCELERATION* nextAction 
                                           )
{
    path_list_element nextPosition;
    POSITION positionToGo;
    path = removeHeadElementPathList ( path, &nextPosition );
    path = resetCurrentPathList ( path );
    positionToGo = hypotheticalNextPosition ( nextPosition, pilotPosition, pilotSpeed );
    basicNextAction ( positionToGo, nextAction );
    fprintf ( stderr, "> NEXT_ACTION_BASIC, nextPosition : (%hd, %hd)\n", nextPosition.X, nextPosition.Y );
    fprintf ( stderr, "     action determined : %hd %hd\n", nextAction->X, nextAction->Y );
    fprintf ( stderr, "         positionToGo : %d %d\n", positionToGo.X, positionToGo.Y );
    fprintf ( stderr, "             pilot position : %d %d\n", pilotPosition.X, pilotPosition.Y );
    fprintf ( stderr, "                 pilot position : %d %d\n", pilotSpeed.X, pilotSpeed.Y );
    return path;
}

/**
 * @brief Determine the correct action for a step by step movement with a boost
 * 
 * @param path the path to follow
 * @param pilotPosition the current position of a pilot
 * @param pilotSpeed the current speed of a pilot
 * @param nextAction the determined next action
 * @return PATH_LIST the updated list
 */
static PATH_LIST nextActionBoostedForNextPosition ( 
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
    path = removeHeadElementPathList ( path, &nextPosition );
    positionToGo = hypotheticalNextPosition ( nextPosition, pilotPosition, pilotSpeed );
    /* version boost et non boosted */
    boostNextAction ( positionToGo, nextAction );
    fprintf ( stderr, "> NEXT_ACTION_BOOST, nextPosition : (%hd, %hd)\n", nextPosition.X, nextPosition.Y );
    fprintf ( stderr, "     action determined : %hd %hd\n", nextAction->X, nextAction->Y );
    fprintf ( stderr, "         positionToGo : %d %d\n", positionToGo.X, positionToGo.Y );
    return path;
}



/**
 * @brief Update the path to follow if the path is straight
 * 
 * @param path the path to follow
 * @param currentPosition the current position of a pilot
 * @param graph the race graph
 * @return boolean true if the path has been updated
 */
static boolean updatePathListIfstraightLine ( 
                                                PATH_LIST* path, 
                                                POSITION currentPosition, 
                                                GRAPH* graph 
                                            )
{
    POSITION nextPosition;
    POSITION goalPosition;
    POSITION previousGoalPosition;

    if ( isSand ( graph, currentPosition ) ) {
        return false;
    }
    *path = resetCurrentPathList ( *path );
    nextPosition = getCurrentPathListElement ( *path ); /* get head ca marche aussi */
    if ( nextPosition.X == -1 ) {
        return false;
    } else if ( isSand ( graph, nextPosition ) ) {
        return false;
    }
    goalPosition = getNextCurrentPathList ( *path );
    if ( goalPosition.X == -1 ) {
        return false;
    }
    previousGoalPosition = goalPosition;
    while ( goalPosition.X != -1 
                    && 
            areAligned ( currentPosition, nextPosition, goalPosition ) ) {
        *path = moveCurrentPathList ( *path );
        previousGoalPosition = goalPosition;
        goalPosition = getNextCurrentPathList ( *path );
        if ( isInGraph ( graph, goalPosition.X, goalPosition.Y ) ) {
            if ( isSand ( graph, goalPosition ) ) {
                break;
            }
        }
    }
    return areAligned ( currentPosition, nextPosition, previousGoalPosition );
}

/**
 * @brief Update the lidt to the current position
 * 
 * @param path the list to update
 * @param goalPosition the goal position
 * @return PATH_LIST the updated path list
 */
static PATH_LIST updatePathToGoalPosition ( PATH_LIST path, POSITION goalPosition )
{
    POSITION trash;
    if ( areEqualsPosition ( examineHeadPathList ( path ), goalPosition ) ) {
        path = removeHeadElementPathList ( path, &trash );
        return path;
    }
    do {
        path = removeHeadElementPathList ( path, &trash );
    } while ( !areEqualsPosition ( trash, goalPosition ) );
    return path;
}

/*
boolean isApproachable ( GRAPH* graph, POSITION pilotPosition, POSITION nextPosition ) 
{
    POSITION transition;
    transition.X = pilotPosition.X;
    transition.Y = pilotPosition.Y;

    fprintf(stderr, "hello1\n");
    while ( transition.X != nextPosition.X && transition.Y != nextPosition.Y ) {
        fprintf ( stderr, "le boucle while\n");

        if ( nextPosition.X - transition.X < 0 ) {
            transition.X += -1;
        } else if ( nextPosition.X - transition.X > 0 ) {
            transition.X += 1;
        } else {
            transition.X += 0;
        }

        if ( nextPosition.Y - transition.Y < 0 ) {
            transition.Y += -1;
        } else if ( nextPosition.X - transition.Y > 0 ) {
            transition.Y += 1;
        } else {
            transition.Y += 0;
        }
        if ( isWall ( graph, transition ) || isSand ( graph, transition )) {
            return false;
        }
    }
    return true; 
}
*/

static boolean traverse ( GRAPH* graph, POSITION start,  POSITION stop, POSITION* goalPosition )
{
  POSITION transition;
  InfoLine vline;
  int count = 0;
  initLine(start.X, start.Y, stop.X, stop.Y, &vline);
  fprintf ( stderr, " hello\n");
  while (nextPoint(&vline, &transition, +1) > 0) {
      
    if (transition.X == start.X && transition.Y == start.Y) {
        
        continue;
    }
    count++;
    if ( count == 2 ) {
        goalPosition->X = transition.X;
        goalPosition->Y = transition.Y;
        fprintf ( stderr, " la transition %d %d \n", transition.X, transition.Y);
    }
    
    if ( isWall (graph, transition) || isSand ( graph, transition ) ) {
        return false;
    }
  }
  return true;
}

void AdptPilots (
                GRAPH* graph, PATH_LIST path,
                POSITION pilotPosition,
                POSITION goalPosition,
                ACCELERATION* nextAction,
                SPEED pilotSpeed ) {
    path_list_element nextPosition;
    fprintf ( stderr, "les positions goal %d %d\n", goalPosition.X, goalPosition.Y );
    if ( !isCar ( graph, goalPosition ) ) {
        return;
    }
    fprintf ( stderr, "il y a une voiture\n");
    nextPosition = examineHeadPathList ( path );
    pilotSpeed.X += nextAction->X;
    pilotSpeed.Y += nextAction->Y;
    if ( lineToFollow ( pilotPosition, nextPosition ) == towardsX ) {
        if ( pilotSpeed.Y != 0 ) {
            slowDownY ( pilotSpeed, nextAction );
        } else {
            goStraightY ( nextAction );
        }
    } else if ( lineToFollow ( pilotPosition, nextPosition ) == towardsY ) {
        if ( pilotSpeed.X != 0) {
            slowDownX ( pilotSpeed, nextAction );
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

    while ( traverse ( graph, pilotPosition, nextCurrent, &goalPosition ) ) {
        path = moveCurrentPathList ( path );
        nextCurrent = getNextCurrentPathList ( path);
    }
    current = getCurrentPathListElement( path );
    boostNextAction ( hypotheticalNextPosition ( current, pilotPosition, pilotSpeed ), nextAction );
    goalPosition.X = pilotPosition.X + pilotSpeed.X + nextAction->X;
    goalPosition.Y = pilotPosition.Y + pilotSpeed.Y + nextAction->Y;
    AdptPilots ( graph, path, pilotPosition, goalPosition, nextAction, pilotSpeed );

    return path;
}



/**
 * @brief vector between two positions
 * 
 * @param finalPosition the final position
 * @param startPosition  the first position
 * @return POSITION the vector
 */
static POSITION positionVector ( POSITION finalPosition, POSITION startPosition )
{
    finalPosition.X = finalPosition.X - startPosition.X;
    finalPosition.Y = finalPosition.Y - startPosition.Y;
    return finalPosition;
}

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
static short addActionToGroup ( 
                            short length, short currentSpeed, 
                            short startingIndex, POSITION startPosition, 
                            POSITION finalPosition, ACCELERATION* actions 
                              )
{
    int i;
    short decelerationPosition;
    short nextHypoteticalPosition = 0;
    short hypoteticalSpeed = abs ( currentSpeed );
    short remainingDistance;
    short numberStraightAction;
    short distanceHypoteticalyDriven;

    if ( hypoteticalSpeed == 0 ) {
        decelerationPosition = 0;
    } else {
        decelerationPosition = hypoteticalSpeed - 1;
    }
    distanceHypoteticalyDriven = decelerationPosition + nextHypoteticalPosition 
                                    + hypoteticalSpeed;
    while ( (distanceHypoteticalyDriven < length - distanceHypoteticalyDriven ) 
                                        && ( hypoteticalSpeed != MAX_SPEED ) ) {
        hypoteticalSpeed++;
        nextHypoteticalPosition += hypoteticalSpeed;
        decelerationPosition += hypoteticalSpeed - 1;
        distanceHypoteticalyDriven = decelerationPosition 
                                        + nextHypoteticalPosition 
                                        + hypoteticalSpeed;
        accelerate ( 
                    positionVector ( finalPosition, startPosition ), 
                    &actions[startingIndex] 
                   );
        startingIndex++;
    }
    remainingDistance = length - distanceHypoteticalyDriven;
    if ( remainingDistance >= hypoteticalSpeed ) {
        numberStraightAction = 
            (short) ( (float) ( remainingDistance ) / (float)(hypoteticalSpeed) );
        for ( i = 0; i < numberStraightAction; i++ ) {
            goStraight ( &actions[startingIndex] );
            startingIndex++;
        }
        remainingDistance -= hypoteticalSpeed * numberStraightAction;
        nextHypoteticalPosition += hypoteticalSpeed * numberStraightAction;
    }
    for ( i = 1; i < hypoteticalSpeed; i++ ) {
        if ( remainingDistance == hypoteticalSpeed - i ) {
            nextHypoteticalPosition += 2 * (hypoteticalSpeed - i);
            slowDown ( 
                        positionVector ( finalPosition, startPosition ), 
                        &actions[startingIndex] 
                     );
            startingIndex++;
            goStraight ( &actions[startingIndex] );
            startingIndex++;
        } else {
            slowDown ( 
                        positionVector ( finalPosition, startPosition ), 
                        &actions[startingIndex] 
                     );
            startingIndex++;
            nextHypoteticalPosition += hypoteticalSpeed - i;
        }
    }
    actions[0].X = startingIndex;
    actions[0].Y = 0;
    return nextHypoteticalPosition;
}



/**
 * @brief Redirect to the correct function to determine a group of action if the path if straight
 * 
 * @param path the path to follow
 * @param pilotPosition the current pilot position
 * @param pilotSpeed the current pilot speed
 * @param nextAction the group of action
 * @return PATH_LIST the updated path list
 */
static PATH_LIST groupNextAction ( 
                                    PATH_LIST path, POSITION pilotPosition, 
                                    SPEED pilotSpeed, ACCELERATION* nextAction 
                                 )
{
    POSITION goalPosition;
    straightDirection directionLine;
    short length = 0;

    goalPosition = getCurrentPathListElement ( path );
    directionLine = lineToFollow ( pilotPosition, goalPosition );
    if ( directionLine == towardsX ) {
        length = addActionToGroup ( 
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
        length = addActionToGroup ( 
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
         path = nextActionForNextPosition ( 
                                            path, 
                                            pilotPosition, 
                                            pilotSpeed, 
                                            &nextAction[1] 
                                          );
        fprintf ( stderr, "     action determined : %hd %hd\n", nextAction->X, nextAction->Y );
    }
    if ( length > 0 ) {
        path = updatePathToGoalPosition ( path, goalPosition );
    }
    return path;
}

/**
 * @brief if the speed is null
 * 
 * @param pilotSpeed the current pilot speed
 * @return boolean true if speed is null
 */
static boolean speedIsNull ( SPEED pilotSpeed )
{
    return ( pilotSpeed.X == 0 && pilotSpeed.Y == 0 );
}

boolean areAligned ( POSITION A, POSITION B, POSITION C ) 
{
    return  (C.Y - A.Y) * (B.X - A.X) - (B.Y - A.Y) * (C.X - A.X ) == 0; 
}

straightDirection lineToFollow ( 
                                POSITION startPosition, 
                                POSITION goalPosition 
                                )
{
    POSITION line;
    line = positionVector ( goalPosition, startPosition );
    if ( line.X == 0 ) {
        return towardsY;
    }
    if ( line.Y == 0 ) {
        return towardsX;
    }
    return diagonal;
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
                            GRAPH* graph, short remainingFuel 
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
    if ( speedIsNull ( pilotSpeed ) 
            /*&& updatePathListIfstraightLine ( &path, pilotPosition, graph )*/ ) {
        path = /*redirectTab[2]*/BetterBoostForNextPosition( graph, path, pilotPosition, pilotSpeed, actionTab );
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
        return path;
    }
    nextAction->X = actionTab->X;
    nextAction->Y = actionTab->Y;
    return path;
}