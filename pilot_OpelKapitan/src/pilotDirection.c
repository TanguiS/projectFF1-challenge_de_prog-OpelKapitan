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

#define ACTION 1
#define BOOSTED_ACTION 2
#define MAX_SPEED 5

void goRight ( ACCELERATION* action ) {
    action->X = 0 + ACTION;
}

void goLeft ( ACCELERATION* action ) {
    action->X = 0 - ACTION;
}

void goUp ( ACCELERATION* action  ) {
    action->Y = 0 - ACTION;
}

void goDown ( ACCELERATION* action  ) {
    action->Y = 0 + ACTION;
}

void goStraight ( ACCELERATION* action ) {
    action->X = 0;
    action->Y = 0;
}

void goStraightX ( ACCELERATION* action ) {
    action->X = 0;
}

void goStraightY ( ACCELERATION* action ) {
    action->Y = 0;
}

void goBoostRight ( ACCELERATION* action ) {
    action->X = 0 + BOOSTED_ACTION;
}

void goBoostLeft ( ACCELERATION* action ) {
    action->X = 0 - BOOSTED_ACTION;
}

void goBoostUp ( ACCELERATION* action ) {
    action->Y = 0 - BOOSTED_ACTION;
}

void goBoostDown ( ACCELERATION* action ) {
    action->Y = 0 + BOOSTED_ACTION;
}

void slowDown ( POSITION directionToSlow, ACCELERATION* action )
{
    if ( directionToSlow.X > 0 ) {
        goLeft ( action );
    } else if ( directionToSlow.X == 0 ) {
        action->X = 0;
    }  else {
        goRight ( action );
    }
    if ( directionToSlow.Y > 0 ) {
        goUp ( action );
    } else if ( directionToSlow.Y == 0 ) {
        action->Y = 0;
    }  else {
        goDown ( action );
    }
}

void slowDownX ( SPEED speedToSlow, ACCELERATION* action )
{
    if ( speedToSlow.X > 0 ) {
        goLeft ( action );
    }  else {
        goRight ( action );
    }
}

void slowDownXAccordingToPosition ( POSITION directionToSlow, ACCELERATION* action )
{
    if ( directionToSlow.X > 0 ) {
        goLeft ( action );
    } else if ( directionToSlow.X == 0 ) {
        action->X = 0;
    }  else {
        goRight ( action );
    }
}

void slowDownYAccordingToPosition ( POSITION directionToSlow, ACCELERATION* action )
{
    if ( directionToSlow.Y > 0 ) {
        goUp ( action );
    } else if ( directionToSlow.Y == 0 ) {
        action->Y = 0;
    }  else {
        goDown ( action );
    }
}

void slowDownY ( SPEED speedToSlow, ACCELERATION* action )
{
    if ( speedToSlow.Y > 0 ) {
        goUp ( action );
    } else {
        goDown ( action );
    }
}

void accelerate ( POSITION directionToAccelerate, ACCELERATION* action )
{
    if ( directionToAccelerate.X > 0 ) {
        goRight ( action );
    } else if ( directionToAccelerate.X == 0 ) {
        action->X = 0;
    } else {
        goLeft ( action );
    }
    if ( directionToAccelerate.Y > 0 ) {
        goDown ( action );
    } else if ( directionToAccelerate.Y == 0 ) {
        action->Y = 0;
    } else {
        goUp ( action );
    } 
}

void accelerateX ( POSITION directionToAccelerate, ACCELERATION* action )
{
    if ( directionToAccelerate.X > 0 ) {
        goRight ( action );
    } else if ( directionToAccelerate.X == 0 ) {
        action->X = 0;
    } else {
        goLeft ( action );
    }
}

void accelerateY ( POSITION directionToAccelerate, ACCELERATION* action )
{
    if ( directionToAccelerate.Y > 0 ) {
        goDown ( action );
    } else if ( directionToAccelerate.Y == 0 ) {
        action->Y = 0;
    } else {
        goUp ( action );
    }  
}

void choiceDirection ( direction choice, ACCELERATION* action )
{
    static directionFunction* directionTab[NUMBER_DIRECTION] = 
    {
        goRight, goLeft, goUp, goDown,
        goBoostRight, goBoostLeft, goBoostUp, goBoostDown
    };
    directionTab[choice]( action );
}

static void basicNextAction ( POSITION positionToGo, ACCELERATION* nextAction )
{
    if ( positionToGo.X > 0 ) {
        choiceDirection ( right, nextAction );
    } else if ( positionToGo.X == 0 ) {
        goStraightX ( nextAction );
    } else {
        choiceDirection ( left, nextAction );
    }
    if ( positionToGo.Y > 0 ) {
        choiceDirection ( down, nextAction );
    } else if ( positionToGo.Y == 0 ) {
        goStraightY ( nextAction );
    } else {
        choiceDirection ( up, nextAction );
    }
}

static void boostNextAction ( POSITION positionToGo, ACCELERATION* nextAction )
{
    fprintf ( stderr, "> Boost test, position to go : %hd, %hd\n", positionToGo.X, positionToGo.Y );
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
    fprintf ( stderr, "> Action boosted : %hd, %hd\n", nextAction->X, nextAction->Y );
}

static POSITION hypotheticalNextPosition ( POSITION nextPosition, POSITION currentPosition, SPEED currentSpeed )
{
    nextPosition.X =  nextPosition.X - currentPosition.X - currentSpeed.X;
    nextPosition.Y =  nextPosition.Y - currentPosition.Y - currentSpeed.Y;
    return nextPosition;
}

PATH_LIST examineNextPosition ( PATH_LIST path, POSITION pilotPosition, SPEED pilotSpeed, ACCELERATION* nextAction )
{
    path_list_element nextPosition;
    POSITION positionToGo;
    nextPosition = getCurrentPathList ( path );
    path = moveCurrentPathList ( path );
    positionToGo = hypotheticalNextPosition ( nextPosition, pilotPosition, pilotSpeed );
    basicNextAction ( positionToGo, nextAction );
    return path;
}

PATH_LIST nextActionForNextPosition ( PATH_LIST path, POSITION pilotPosition, SPEED pilotSpeed, ACCELERATION* nextAction )
{
    path_list_element nextPosition;
    POSITION positionToGo;
    path = removeHeadElementPathList ( path, &nextPosition );
    path = resetCurrentPathList ( path );
    fprintf ( stderr, "> NEXT_ACTION_BASIC, nextPosition : (%hd, %hd)\n", nextPosition.X, nextPosition.Y );
    positionToGo = hypotheticalNextPosition ( nextPosition, pilotPosition, pilotSpeed );
    /* version boost et non boosted */
    basicNextAction ( positionToGo, nextAction );
    return path;
}

PATH_LIST nextActionBoostedForNextPosition ( PATH_LIST path, POSITION pilotPosition, SPEED pilotSpeed, ACCELERATION* nextAction )
{
    path_list_element nextPosition;
    POSITION positionToGo;
    if ( currentEqualsHead ( path ) ) {
        path = moveCurrentPathList ( path );
    }
    path = removeHeadElementPathList ( path, &nextPosition );
    path = removeHeadElementPathList ( path, &nextPosition );
    fprintf ( stderr, "> NEXT_ACTION_BOOST, nextPosition : (%hd, %hd)\n", nextPosition.X, nextPosition.Y );
    positionToGo = hypotheticalNextPosition ( nextPosition, pilotPosition, pilotSpeed );
    /* version boost et non boosted */
    boostNextAction ( positionToGo, nextAction );
    fprintf ( stderr, "> Action boosted : %hd, %hd\n", nextAction->X, nextAction->Y );
    return path;
}

static boolean areAligned ( POSITION A, POSITION B, POSITION C ) 
{
    return  (C.Y - A.Y) * (B.X - A.X) - (B.Y - A.Y) * (C.X - A.X ) == 0; 
}

static boolean updatePathListIfstraightLine ( PATH_LIST* path, POSITION currentPosition, GRAPH* graph )
{
    POSITION nextPosition;
    POSITION goalPosition;
    POSITION previousGoalPosition;

    if ( isSand ( graph, currentPosition ) ) {
        return false;
    }

    *path = resetCurrentPathList ( *path );
    nextPosition = getCurrentPathList ( *path ); /* get head ca marche aussi */
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
    while ( goalPosition.X != -1 && areAligned ( currentPosition, nextPosition, goalPosition ) ) {
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

static POSITION positionVector ( POSITION finalPosition, POSITION startPosition )
{
    finalPosition.X = finalPosition.X - startPosition.X;
    finalPosition.Y = finalPosition.Y - startPosition.Y;
    return finalPosition;
}

short addActionToGroup ( short length, short currentSpeed, short startingIndex, POSITION startPosition, POSITION finalPosition, ACCELERATION* actions )
{
    int i;
    short decelerationPosition; /* ATTENTION SI BOOST */
    short nextHypoteticalPosition = 0;
    short hypoteticalSpeed = abs ( currentSpeed );
    short remainingDistance;
    short numberStraightAction;

    if ( hypoteticalSpeed == 0 ) {
        decelerationPosition = 0;
    } else {
        decelerationPosition = hypoteticalSpeed - 1;
    }

    while ( (decelerationPosition + nextHypoteticalPosition + hypoteticalSpeed < length - ( nextHypoteticalPosition + decelerationPosition + hypoteticalSpeed )) && ( hypoteticalSpeed != MAX_SPEED ) ) {
        hypoteticalSpeed++;
        nextHypoteticalPosition += hypoteticalSpeed;
        decelerationPosition += hypoteticalSpeed - 1;
        accelerate ( positionVector ( finalPosition, startPosition ), &actions[startingIndex] );
        startingIndex++;
    }
    remainingDistance = length - ( nextHypoteticalPosition + decelerationPosition + hypoteticalSpeed );
    if ( remainingDistance >= hypoteticalSpeed ) {
        numberStraightAction = (short) ( (float) ( remainingDistance ) / (float)(hypoteticalSpeed) );
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
            slowDown ( positionVector ( finalPosition, startPosition ), &actions[startingIndex] );
            startingIndex++;
            goStraight ( &actions[startingIndex] );
            startingIndex++;
        } else {
            slowDown ( positionVector ( finalPosition, startPosition ), &actions[startingIndex] );
            startingIndex++;
            nextHypoteticalPosition += hypoteticalSpeed - i;
        }
    }
    actions[0].X = startingIndex;
    actions[0].Y = 0;
    return nextHypoteticalPosition;
}

goalDirection lineToFollow ( POSITION startPosition, POSITION goalPosition )
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

boolean areEqualPosition ( POSITION A, POSITION B )
{
    return A.X == B.X && A.Y == B.Y;
}

PATH_LIST updatePathToGoalPosition ( PATH_LIST path, POSITION goalPosition )
{
    POSITION trash;
    if ( areEqualPosition ( examineHeadPathList ( path ), goalPosition ) ) {
        path = removeHeadElementPathList ( path, &trash );
        return path;
    }
    do {
        path = removeHeadElementPathList ( path, &trash );
    } while ( !areEqualPosition ( trash, goalPosition ) );
    return path;
}

PATH_LIST groupNextAction ( PATH_LIST path, POSITION pilotPosition, SPEED pilotSpeed, ACCELERATION* nextAction )
{
    POSITION goalPosition;
    goalDirection directionLine;
    short length = 0;
    int i;

    goalPosition = getCurrentPathList ( path );
    directionLine = lineToFollow ( pilotPosition, goalPosition );
    if ( directionLine == towardsX ) {
        length = addActionToGroup ( abs ( positionVector ( goalPosition, pilotPosition ).X ), pilotSpeed.X, 1, pilotPosition, goalPosition, nextAction );
        if ( pilotSpeed.Y != 0 ) {
            slowDownY ( pilotSpeed, &nextAction[1] );
        }
    } else if ( directionLine == towardsY ) {
        length = addActionToGroup ( abs ( positionVector ( goalPosition, pilotPosition ).Y ), pilotSpeed.Y, 1, pilotPosition, goalPosition, nextAction );
        if ( pilotSpeed.X != 0 ) {
            slowDownX ( pilotSpeed, &nextAction[1] );
        }
    } else { /* c'est une diagonale */
        fprintf ( stderr, "diagonal\n" );
         path = nextActionForNextPosition ( path, pilotPosition, pilotSpeed, &nextAction[1] );
        fprintf ( stderr, ">>>diag : action n°1 : %d %d\n", nextAction[1].X, nextAction[1].Y );
    }
    for ( i = 1; i < nextAction[0].X; i++ ) {
        fprintf ( stderr, "Action recupered : %d %d\n", nextAction[i].X, nextAction[i].Y );
    }
    if ( length > 0 ) {
        path = updatePathToGoalPosition ( path, goalPosition );
    }
    return path;
}

boolean speedIsNull ( SPEED pilotSpeed )
{
    return ( pilotSpeed.X == 0 && pilotSpeed.Y == 0 );
}

/* avec un flag en statique pour pas qu'il soit mis à jour a chaque fois mais qu'une seul fois */
PATH_LIST choiceNextAction ( PATH_LIST path, POSITION pilotPosition, SPEED pilotSpeed, ACCELERATION* nextAction, GRAPH* graph, short remainingFuel )
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
    if ( speedIsNull ( pilotSpeed ) && updatePathListIfstraightLine ( &path, pilotPosition, graph ) ) {
        path = redirectTab[2](path, pilotPosition, pilotSpeed, actionTab );
        nextAction->X = actionTab->X;
        nextAction->Y = actionTab->Y;
        fprintf ( stderr, "> Action boosted : %hd, %hd\n", nextAction->X, nextAction->Y );
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