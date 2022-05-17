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
 * @brief This file contains the functions used to choose the pilot's direction .
 */

/**
 * @author PICQUE Kylian <kylian.picque@ecole.ensicaen.fr>
 * @version 1.0.0
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
        nextAction->X = 0; /* faire une fonction straight X */
    } else {
        choiceDirection ( left, nextAction );
    }
    if ( positionToGo.Y > 0 ) {
        choiceDirection ( down, nextAction );
    } else if ( positionToGo.Y == 0 ) {
        nextAction->Y = 0;
    } else {
        choiceDirection ( up, nextAction );
    }
}

static void boostNextAction ( POSITION positionToGo, ACCELERATION* nextAction )
{
    if ( positionToGo.X > 0 ) {
        choiceDirection ( boostRight, nextAction );
    } else if ( positionToGo.X == 0 ) {
        nextAction->X = 0; /* faire une fonction straight X */
    } else {
        choiceDirection ( boostLeft, nextAction );
    }
    if ( positionToGo.Y > 0 ) {
        choiceDirection ( boostDown, nextAction );
    } else if ( positionToGo.Y == 0 ) {
        nextAction->Y = 0;
    } else {
        choiceDirection ( boostUp, nextAction );
    }
}

static POSITION hypotheticalNextPosition ( POSITION nextPosition, POSITION currentPosition, SPEED currentSpeed )
{
    nextPosition.X =  nextPosition.X - currentPosition.X - currentSpeed.X;
    nextPosition.Y =  nextPosition.Y - currentPosition.Y - currentSpeed.Y;
    return nextPosition;
}

PATH_LIST nextActionForNextPosition ( PATH_LIST path, POSITION pilotPosition, SPEED pilotSpeed, ACCELERATION* nextAction )
{
    path_list_element nextPosition;
    POSITION positionToGo;
    if ( currentEqualsHead ( path ) ) {
        path = moveCurrentPathList ( path );
    }
    path = removeHeadElementPathList ( path, &nextPosition );
    fprintf ( stderr, "> NEXT_ACTION_BASIC, nextPosition : (%hd, %hd)\n", nextPosition.X, nextPosition.Y );
    positionToGo = hypotheticalNextPosition ( nextPosition, pilotPosition, pilotSpeed );
    /* version boost et non boosted */
    basicNextAction ( positionToGo, nextAction );
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
    fprintf ( stderr, ">Position courante : %d %d\n", currentPosition.X, currentPosition.Y );
    nextPosition = getCurrentPathList ( *path ); /* get head ca marche aussi */
    fprintf ( stderr, ">Position next : %d %d\n", nextPosition.X, nextPosition.Y );
    fprintf ( stderr, "> Value du graph : %d\n", getElementGraph ( graph, nextPosition ) );
    if ( nextPosition.X == -1 ) {
        return false;
    } else if ( isSand ( graph, nextPosition ) ) {
        fprintf ( stderr, "> Du sable from nextPosition\n" );
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
        fprintf ( stderr, ">>>GOALLLLLLLLLL : %d %d\n", previousGoalPosition.X, previousGoalPosition.Y );
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
    short decelerationPosition = 0; /* ATTENTION SI BOOST */
    short nextHypoteticalPosition = abs ( currentSpeed );
    short hypoteticalSpeed = abs ( currentSpeed );

    short remainingDistance;
    short numberStraightAction;

    fprintf ( stderr, ">AddActionToGroup : longueur = %d\n", length );
    fprintf ( stderr, "> HypoteticalPosition = %d\n", decelerationPosition + nextHypoteticalPosition + hypoteticalSpeed );
    while ( (decelerationPosition + nextHypoteticalPosition + hypoteticalSpeed < length - ( nextHypoteticalPosition + decelerationPosition + hypoteticalSpeed )) && ( hypoteticalSpeed != MAX_SPEED ) ) {
        hypoteticalSpeed++;
        nextHypoteticalPosition += hypoteticalSpeed;
        decelerationPosition += hypoteticalSpeed - 1;
        fprintf ( stderr, "> HypoteticalPosition dans while = %d\n", decelerationPosition + nextHypoteticalPosition + hypoteticalSpeed );
        accelerate ( positionVector ( finalPosition, startPosition ), &actions[startingIndex] );
        startingIndex++;
    }
    remainingDistance = length - ( nextHypoteticalPosition + decelerationPosition );
    fprintf ( stderr, "> Distance restante : %d\n", remainingDistance );

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
    fprintf ( stderr, "\n                                                  --> longueur parcouru : %d\n", nextHypoteticalPosition );
    actions[0].X = startingIndex;
    actions[0].Y = 0;
    return nextHypoteticalPosition;
}

short addActionXToGroup ( short length, short currentSpeed, short startingIndex, POSITION startPosition, POSITION finalPosition, ACCELERATION* actions )
{
    int i;
    short decelerationPosition = 0; /* ATTENTION SI BOOST */
    short hypoteticalPosition = 0;
    short hypoteticalSpeed = abs ( currentSpeed );

    short remainingDistance;
    short numberStraightAction;

    while ( decelerationPosition + hypoteticalPosition + hypoteticalSpeed < length - ( hypoteticalPosition + decelerationPosition + hypoteticalSpeed ) ) {
        hypoteticalSpeed++;
        hypoteticalPosition += hypoteticalSpeed;
        decelerationPosition += hypoteticalSpeed - 1;
        /* accelerate ( positionVector ( finalPosition, startPosition ), &actions[startingIndex] ); */
        accelerateX ( positionVector ( finalPosition, startPosition ), &actions[startingIndex] );
        startingIndex++;
        fprintf ( stderr, "x : 1 " );
        if ( hypoteticalSpeed == MAX_SPEED ) {
            break;
        }
    }
    remainingDistance = length - ( hypoteticalPosition + decelerationPosition );

    if ( remainingDistance >= hypoteticalSpeed ) {
        numberStraightAction = (short) ( (float) ( remainingDistance ) / (float)(hypoteticalSpeed) );
        for ( i = 0; i < numberStraightAction; i++ ) {
            /* goStraight ( &actions[startingIndex] ); */
            goStraightX ( &actions[startingIndex] );
            startingIndex++;
            fprintf ( stderr, "x : 0 " );
        }
        remainingDistance -= hypoteticalSpeed * numberStraightAction;
        hypoteticalPosition += hypoteticalSpeed * numberStraightAction;
    }
    for ( i = 1; i < hypoteticalSpeed; i++ ) {
        if ( remainingDistance == hypoteticalSpeed - i ) {
            hypoteticalPosition += 2 * (hypoteticalSpeed - i);
            fprintf ( stderr, "x : -1 0 " );
            /* slowDown ( positionVector ( finalPosition, startPosition ), &actions[startingIndex] ); */
            slowDownXAccordingToPosition ( positionVector ( finalPosition, startPosition ), &actions[startingIndex] );
            startingIndex++;
            /* goStraight ( &actions[startingIndex] ); */
            goStraightX ( &actions[startingIndex] );
            startingIndex++;
        } else {
            fprintf ( stderr, "x : -1 " );
            /* slowDown ( positionVector ( finalPosition, startPosition ), &actions[startingIndex] ); */
            slowDownXAccordingToPosition ( positionVector ( finalPosition, startPosition ), &actions[startingIndex] );
            startingIndex++;    
            hypoteticalPosition += hypoteticalSpeed - i;
        }
    }
    fprintf ( stderr, "\n                                                  --> longueur parcouru : %d\n", hypoteticalPosition );
    actions[0].X = startingIndex;
    actions[0].Y = 0;
    return hypoteticalPosition;
}

short addActionYToGroup ( short length, short currentSpeed, short startingIndex, POSITION startPosition, POSITION finalPosition, ACCELERATION* actions )
{
    int i;
    short decelerationPosition = 0; /* ATTENTION SI BOOST */
    short hypoteticalPosition = 0;
    short hypoteticalSpeed = abs ( currentSpeed );

    short remainingDistance;
    short numberStraightAction;

    while ( decelerationPosition + hypoteticalPosition + hypoteticalSpeed < length - ( hypoteticalPosition + decelerationPosition + hypoteticalSpeed ) ) {
        hypoteticalSpeed++;
        hypoteticalPosition += hypoteticalSpeed;
        decelerationPosition += hypoteticalSpeed - 1;
        /* accelerate ( positionVector ( finalPosition, startPosition ), &actions[startingIndex] ); */
        accelerateY ( positionVector ( finalPosition, startPosition ), &actions[startingIndex] );
        startingIndex++;
        fprintf ( stderr, "y : 1 " );
        if ( hypoteticalSpeed == MAX_SPEED ) {
            break;
        }
    }
    remainingDistance = length - ( hypoteticalPosition + decelerationPosition );

    if ( remainingDistance >= hypoteticalSpeed ) {
        numberStraightAction = (short) ( (float) ( remainingDistance ) / (float)(hypoteticalSpeed) );
        for ( i = 0; i < numberStraightAction; i++ ) {
            /* goStraight ( &actions[startingIndex] ); */
            goStraightY ( &actions[startingIndex] );
            startingIndex++;
            fprintf ( stderr, "y : 0 " );
        }
        remainingDistance -= hypoteticalSpeed * numberStraightAction;
        hypoteticalPosition += hypoteticalSpeed * numberStraightAction;
    }
    for ( i = 1; i < hypoteticalSpeed; i++ ) {
        if ( remainingDistance == hypoteticalSpeed - i ) {
            hypoteticalPosition += 2 * (hypoteticalSpeed - i);
            fprintf ( stderr, "y : -1 0 " );
            /* slowDown ( positionVector ( finalPosition, startPosition ), &actions[startingIndex] ); */
            slowDownYAccordingToPosition ( positionVector ( finalPosition, startPosition ), &actions[startingIndex] );
            startingIndex++;
            /* goStraight ( &actions[startingIndex] ); */
            goStraightY ( &actions[startingIndex] );
            startingIndex++;
        } else {
            fprintf ( stderr, "y : -1 " );
            /* slowDown ( positionVector ( finalPosition, startPosition ), &actions[startingIndex] ); */
            slowDownYAccordingToPosition ( positionVector ( finalPosition, startPosition ), &actions[startingIndex] );
            startingIndex++;    
            hypoteticalPosition += hypoteticalSpeed - i;
        }
    }
    fprintf ( stderr, "\n                                                  --> longueur parcouru : %d\n", hypoteticalPosition );
    actions[0].Y = startingIndex;
    return hypoteticalPosition;
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

void equilibrateSpeedX ( short pilotPositionX, short nextPositionX, short positionToGoX, short pilotSpeedX, ACCELERATION* nextAction )
{
    if ( pilotPositionX + pilotSpeedX != nextPositionX ) {
        if ( positionToGoX > 0 ) {
            choiceDirection ( right, nextAction );
        } else if ( positionToGoX == 0 ) {
            goStraightX ( nextAction );
        } else {
            choiceDirection ( left, nextAction );
        }
    } else {
        goStraightX ( nextAction );
    }
}

void equilibrateSpeedY ( short positionPilotY, short nextPositionY, short positionToGoY, short pilotSpeedY, ACCELERATION* nextAction )
{
    if ( positionPilotY + pilotSpeedY != nextPositionY ) {
        if ( positionToGoY > 0 ) {
            choiceDirection ( down, nextAction );
        } else if ( positionToGoY == 0 ) {
            goStraightY ( nextAction );
        } else {
            choiceDirection ( up, nextAction );
        }
    } else {
        goStraightY ( nextAction );
    }
}

PATH_LIST equilibrateSpeedForStraightLine ( PATH_LIST path, POSITION pilotPosition, SPEED pilotSpeed, ACCELERATION* nextAction )
{
    path_list_element nextPosition;
    POSITION positionToGo;
    if ( currentEqualsHead ( path ) ) {
        path = moveCurrentPathList ( path );
    }
    path = removeHeadElementPathList ( path, &nextPosition );
    fprintf ( stderr, "> NEXT_ACTION_BASIC, nextPosition : (%hd, %hd)\n", nextPosition.X, nextPosition.Y );
    positionToGo = hypotheticalNextPosition ( nextPosition, pilotPosition, pilotSpeed );
    equilibrateSpeedX ( pilotPosition.X, nextPosition.X, positionToGo.X, pilotSpeed.X, nextAction );
    equilibrateSpeedY ( pilotPosition.X, nextPosition.Y, positionToGo.Y, pilotSpeed.Y, nextAction );
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
/*         pilotSpeed.X += nextAction[1].X;
        pilotSpeed.Y += nextAction[1].Y;
        pilotPosition.X += pilotSpeed.X;
        pilotPosition.Y += pilotSpeed.Y;
        path = equilibrateSpeedForStraightLine ( path, pilotPosition, pilotSpeed, &nextAction[1] );
        fprintf ( stderr, ">>>diag : action n°2 : %d %d\n", nextAction[1].X, nextAction[1].Y );
        pilotSpeed.X += nextAction[1].X;
        pilotSpeed.Y += nextAction[1].Y;
        pilotPosition.X += pilotSpeed.X;
        pilotPosition.Y += pilotSpeed.Y;
        length = addActionToGroup ( abs ( positionVector ( goalPosition, pilotPosition ).X ), pilotSpeed.X, 2, pilotPosition, goalPosition, nextAction ); */
    }
    for ( i = 1; i < nextAction[0].X; i++ ) {
        fprintf ( stderr, "Action recupered : %d %d\n", nextAction[i].X, nextAction[i].Y );
    }
    if ( length > 0 ) {
        path = updatePathToGoalPosition ( path, goalPosition );
    }
    return path;
}

/* avec un flag en statique pour pas qu'il soit mis à jour a chaque fois mais qu'une seul fois */
PATH_LIST choiceNextAction ( PATH_LIST path, POSITION pilotPosition, SPEED pilotSpeed, ACCELERATION* nextAction, GRAPH* graph )
{
    static ACCELERATION* actionTab = NULL;
    static short countAction = 1;
    boolean flag = false;
    static actionDeterminator* redirectTab[2] = 
            {
                nextActionForNextPosition,
                groupNextAction
            };
    if ( actionTab == NULL ) {
        actionTab = ( ACCELERATION* ) malloc ( 255 * sizeof ( ACCELERATION ) );
    }
    flag = updatePathListIfstraightLine ( &path, pilotPosition, graph ); /* savoir si c'est une ligne droite */
    path = redirectTab[flag](path, pilotPosition, pilotSpeed, actionTab ); /* savoir si c'est un groupe d'action */
    if ( flag ) {
        nextAction->X = actionTab[countAction].X;   
        nextAction->Y = actionTab[countAction].Y;   
        return path;
    }
/*     if ( flag ) {
        countAction++;
        if ( countAction == actionTab[0].X ) {
            countAction = 0;
            flag = false;
            path = choiceNextAction ( path, pilotPosition, pilotSpeed, nextAction );
            return path;
        }
        nextAction->X = actionTab[countAction].X;   
        nextAction->Y = actionTab[countAction].Y;   
        return path;
    } */
    nextAction->X = actionTab->X;
    nextAction->Y = actionTab->Y;
    return path;
}