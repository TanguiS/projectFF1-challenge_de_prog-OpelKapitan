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
#define MAX_SPEED 3


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

void slowDown ( POSITION goalPosition, ACCELERATION* action )
{
    if ( goalPosition.X > 0 ) {
        goLeft ( action );
    } else if ( goalPosition.X == 0 ) {
        action->X = 0;
    }  else {
        goRight ( action );
    }
    if ( goalPosition.Y > 0 ) {
        goUp ( action );
    } else if ( goalPosition.Y == 0 ) {
        action->Y = 0;
    }  else {
        goDown ( action );
    }
}

void slowDownX ( SPEED speed, ACCELERATION* action )
{
    if ( speed.X > 0 ) {
        goLeft ( action );
    }  else {
        goRight ( action );
    }
}

void slowDownY ( SPEED speed, ACCELERATION* action )
{
    if ( speed.Y > 0 ) {
        goUp ( action );
    } else {
        goDown ( action );
    }
}

void accelerate ( POSITION goalPosition, ACCELERATION* action )
{
    if ( goalPosition.X > 0 ) {
        goRight ( action );
    } else if ( goalPosition.X == 0 ) {
        action->X = 0;
    } else {
        goLeft ( action );
    }
    if ( goalPosition.Y > 0 ) {
        goDown ( action );
    } else if ( goalPosition.Y == 0 ) {
        action->Y = 0;
    } else {
        goUp ( action );
    } 
}

void choiceDirection ( direction choice, ACCELERATION* action )
{
    static directionFct* tabDirection[NUMBER_DIRECTION] = 
    {
        goRight, goLeft, goUp, goDown,
        goBoostRight, goBoostLeft, goBoostUp, goBoostDown
    };
    tabDirection[choice]( action );
}

static void basicNextAction ( POSITION diffPosition, ACCELERATION* nextAction )
{
    if ( diffPosition.X > 0 ) {
        choiceDirection ( right, nextAction );
    } else if ( diffPosition.X == 0 ) {
        nextAction->X = 0; /* faire une fonction straight X */
    } else {
        choiceDirection ( left, nextAction );
    }
    if ( diffPosition.Y > 0 ) {
        choiceDirection ( down, nextAction );
    } else if ( diffPosition.Y == 0 ) {
        nextAction->Y = 0;
    } else {
        choiceDirection ( up, nextAction );
    }
}

/* static boolean 
 */
static void boostNextAction ( POSITION diffPosition, ACCELERATION* nextAction )
{

    if ( diffPosition.X > 0 ) {
        choiceDirection ( boostRight, nextAction );
    } else if ( diffPosition.X == 0 ) {
        nextAction->X = 0; /* faire une fonction straight X */
    } else {
        choiceDirection ( boostLeft, nextAction );
    }
    if ( diffPosition.Y > 0 ) {
        choiceDirection ( boostDown, nextAction );
    } else if ( diffPosition.Y == 0 ) {
        nextAction->Y = 0;
    } else {
        choiceDirection ( boostUp, nextAction );
    }
}

static POSITION hypotheticalNextPosition ( POSITION nextPosition, POSITION currentPosition, SPEED speed )
{
    nextPosition.X =  nextPosition.X - currentPosition.X - speed.X;
    nextPosition.Y =  nextPosition.Y - currentPosition.Y - speed.Y;
    return nextPosition;
}

PATH_LIST nextActionForNextPosition ( PATH_LIST path, POSITION positionPilot, SPEED speedPilot, ACCELERATION* nextAction )
{
    path_list_element nextPosition;
    POSITION diffPosition;
    if ( currentEqualsHead ( path ) ) {
        path = moveCurrentPathList ( path );
    }
    path = removeHeadElementPathList ( path, &nextPosition );
    fprintf ( stderr, "> NEXT_ACTION_BASIC, nextPosition : (%hd, %hd)\n", nextPosition.X, nextPosition.Y );
    diffPosition = hypotheticalNextPosition ( nextPosition, positionPilot, speedPilot );
    /* version boost et non boosted */
    basicNextAction ( diffPosition, nextAction );
    return path;
}

static boolean areAligned ( POSITION pos1, POSITION pos2, POSITION pos3 ) 
{
    return  (pos3.Y - pos1.Y) * (pos2.X - pos1.X) - (pos2.Y - pos1.Y) * (pos3.X - pos1.X ) == 0; 
}

static boolean updatePathListIfstraightLine ( PATH_LIST* path, POSITION currentPosition )
{
    POSITION nextPosition;
    POSITION goalPosition;
    POSITION prevGoalPosition;

    *path = resetCurrentPathList ( *path );
    nextPosition = getCurrentPathList ( *path ); /* get head ca marche aussi */
    if ( nextPosition.X == -1 ) {
        return false;
    }
    goalPosition = getNextCurrentPathList ( *path );
    if ( goalPosition.X == -1 ) {
        return false;
    }
    prevGoalPosition = goalPosition;
    while ( goalPosition.X != -1 && areAligned ( currentPosition, nextPosition, goalPosition ) ) {
        *path = moveCurrentPathList ( *path );
        prevGoalPosition = goalPosition;
        fprintf ( stderr, ">>>GOALLLLLLLLLL : %d %d\n", prevGoalPosition.X, prevGoalPosition.Y );
        goalPosition = getNextCurrentPathList ( *path );
    }
    return areAligned ( currentPosition, nextPosition, prevGoalPosition );
}

static POSITION positionVector ( POSITION p1, POSITION p2 )
{
    p1.X = p1.X - p2.X;
    p1.Y = p1.Y - p2.Y;
    return p1;
}

void addActionToGroup ( short length, short speedInit, short count, POSITION start, POSITION goal, ACCELERATION* action )
{
    int i;
    short decelerationPosition = 0; /* ATTENTION SI BOOST */
    short hypoteticalPosition = 0;
    short hypoteticalSpeed = abs ( speedInit );

    short remainingDistance;
    short numberStraightAction;

    while ( decelerationPosition + hypoteticalPosition + hypoteticalSpeed < length - ( hypoteticalPosition + decelerationPosition + hypoteticalSpeed ) ) {
        hypoteticalSpeed++;
        hypoteticalPosition += hypoteticalSpeed;
        decelerationPosition += hypoteticalSpeed - 1;
        accelerate ( positionVector ( goal, start ), &action[count] );
        count++;
        fprintf ( stderr, "1 " );
        if ( hypoteticalSpeed == MAX_SPEED ) {
            break;
        }
    }
    remainingDistance = length - ( hypoteticalPosition + decelerationPosition );

    if ( remainingDistance >= hypoteticalSpeed ) {
        numberStraightAction = (short) ( (float) ( remainingDistance ) / (float)(hypoteticalSpeed) );
        for ( i = 0; i < numberStraightAction; i++ ) {
            goStraight ( &action[count] );
            count++;
            fprintf ( stderr, "0 " );
        }
        remainingDistance -= hypoteticalSpeed * numberStraightAction;
        hypoteticalPosition += hypoteticalSpeed * numberStraightAction;
    }
    for ( i = 1; i < hypoteticalSpeed; i++ ) {
        if ( remainingDistance == hypoteticalSpeed - i ) {
            hypoteticalPosition += 2 * (hypoteticalSpeed - i);
            fprintf ( stderr, "-1 0 " );
            slowDown ( positionVector ( goal, start ), &action[count] );
            count++;
            goStraight ( &action[count] );
            count++;
        } else {
            fprintf ( stderr, "-1 " );
            slowDown ( positionVector ( goal, start ), &action[count] );
            count++;
            hypoteticalPosition += hypoteticalSpeed - i;

        }
    }
    fprintf ( stderr, "\n                                                  --> longueur parcouru : %d\n", hypoteticalPosition );
    action[0].X = count;
}

goalDirection lineToFollow ( POSITION start, POSITION goal )
{
    POSITION line;
    line = positionVector ( goal, start );
    if ( line.X == 0 ) {
        return towardsY;
    }
    if ( line.Y == 0 ) {
        return towardsX;
    }
    return diagonal;
}

boolean areEqualPosition ( POSITION pos1, POSITION pos2 )
{
    return pos1.X == pos2.X && pos1.Y == pos2.Y;
}

PATH_LIST updatePathToGoalPosition ( PATH_LIST path, POSITION goal )
{
    POSITION trash = {-1, -1};
    if ( areEqualPosition ( examineHeadPathList ( path ), goal ) ) {
        path = removeHeadElementPathList ( path, &trash );
        return path;
    }
    do {
        path = removeHeadElementPathList ( path, &trash );
    } while ( !areEqualPosition ( trash, goal ) );
    return path;
}


PATH_LIST equilibrateSpeedForStraightLine ( PATH_LIST path, POSITION positionPilot, SPEED speedPilot, ACCELERATION* nextAction )
{
    path_list_element nextPosition;
    POSITION diffPosition;
    if ( currentEqualsHead ( path ) ) {
        path = moveCurrentPathList ( path );
    }
    path = removeHeadElementPathList ( path, &nextPosition );
    fprintf ( stderr, "> NEXT_ACTION_BASIC, nextPosition : (%hd, %hd)\n", nextPosition.X, nextPosition.Y );
    diffPosition = hypotheticalNextPosition ( nextPosition, positionPilot, speedPilot );
    if ( positionPilot.X + speedPilot.X != nextPosition.X ) {
        if ( diffPosition.X > 0 ) {
            choiceDirection ( right, nextAction );
        } else if ( diffPosition.X == 0 ) {
            nextAction->X = 0; /* faire une fonction straight X */
        } else {
            choiceDirection ( left, nextAction );
        }
    } else {
        goStraightX ( nextAction );
    }
    if ( positionPilot.Y + speedPilot.Y != nextPosition.Y ) {
        if ( diffPosition.Y > 0 ) {
            choiceDirection ( down, nextAction );
        } else if ( diffPosition.Y == 0 ) {
            nextAction->Y = 0;
        } else {
            choiceDirection ( up, nextAction );
        }
    } else {
        goStraightY ( nextAction );
    }
    return path;
}


PATH_LIST groupNextAction ( PATH_LIST path, POSITION positionPilot, SPEED speedPilot, ACCELERATION* nextAction )
{
    POSITION positionGoal;
    goalDirection directionLine;
    int i;

    positionGoal = getCurrentPathList ( path );
    directionLine = lineToFollow ( positionPilot, positionGoal );
    if ( directionLine == towardsX ) {
        addActionToGroup ( abs ( positionVector ( positionGoal, positionPilot ).X ), speedPilot.X, 1, positionPilot, positionGoal, nextAction );
        if ( speedPilot.Y != 0 ) {
            slowDownY ( speedPilot, &nextAction[1] );
        }
    } else if ( directionLine == towardsY ) {
        addActionToGroup ( abs ( positionVector ( positionGoal, positionPilot ).Y ), speedPilot.Y, 1, positionPilot, positionGoal, nextAction );
        if ( speedPilot.X != 0 ) {
            slowDownX ( speedPilot, &nextAction[1] );
        }
    } else { /* c'est une diagonale */
        fprintf ( stderr, "diagonal\n" );
        /* etape 1 : on se met sur la diagonale */
        path = nextActionForNextPosition ( path, positionPilot, speedPilot, &nextAction[1] );
        fprintf ( stderr, ">>>diag : action n°1 : %d %d\n", nextAction[1].X, nextAction[1].Y );
        /* etape 2 : equilibrer les deux actions */
        speedPilot.X += nextAction[1].X;
        speedPilot.Y += nextAction[1].Y;
        positionPilot.X += speedPilot.X;
        positionPilot.Y += speedPilot.Y;
        path = equilibrateSpeedForStraightLine ( path, positionPilot, speedPilot, &nextAction[2] );
        fprintf ( stderr, ">>>diag : action n°2 : %d %d\n", nextAction[2].X, nextAction[2].Y );
        /* etape 3 on calcul le reste du chemin a faire en diagnoal */
        speedPilot.X += nextAction[2].X;
        speedPilot.Y += nextAction[2].Y;
        positionPilot.X += speedPilot.X;
        positionPilot.Y += speedPilot.Y;
        addActionToGroup ( abs ( positionVector ( positionGoal, positionPilot ).X ), speedPilot.X, 3, positionPilot, positionGoal, nextAction );
    }
    for ( i = 1; i < nextAction[0].X; i++ ) {
        fprintf ( stderr, "Action recupered : %d %d\n", nextAction[i].X, nextAction[i].Y );
    }
    if ( !currentEqualsHead ( path ) ) {
        path = updatePathToGoalPosition ( path, positionGoal );
    }
    return path;
}




/* avec un flag en statique pour pas qu'il soit mis à jour a chaque fois mais qu'une seul fois */
PATH_LIST choiceNextAction ( PATH_LIST path, POSITION positionPilot, SPEED speedPilot, ACCELERATION* nextAction )
{
    static ACCELERATION* actionTab = NULL;
    static short countAction = 0;
    static boolean flag = false;
    static actionDeterminator* redirectTab[2] = 
            {
                nextActionForNextPosition,
                groupNextAction
            };
    if ( actionTab == NULL ) {
        actionTab = ( ACCELERATION* ) malloc ( 30 * sizeof ( ACCELERATION ) );
    }
    if ( !flag ) {
        flag = updatePathListIfstraightLine ( &path, positionPilot ); /* savoir si c'est une ligne droite */
        path = redirectTab[flag](path, positionPilot, speedPilot, actionTab ); /* savoir si c'est un groupe d'action */
    }
    if ( flag ) {
        countAction++;
        if ( countAction == actionTab[0].X ) {
            countAction = 0;
            flag = false;
            path = choiceNextAction ( path, positionPilot, speedPilot, nextAction );
            return path;
        }
        nextAction->X = actionTab[countAction].X;   
        nextAction->Y = actionTab[countAction].Y;   
        return path;
    }
    nextAction->X = actionTab->X;
    nextAction->Y = actionTab->Y;
    return path;
}