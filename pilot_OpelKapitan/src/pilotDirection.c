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


void slowDown ( POSITION goalPosition, SPEED speed, ACCELERATION* action )
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

void accelerate ( POSITION goalPosition, SPEED speed, ACCELERATION* action )
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


/* void nextStep(ACCELERATION* action, GRAPH* graph, short currentx, short currenty, short finalx, short finaly,short xSpeed, short ySpeed) {
    LIFO stack; 
    dijkstraMatrix dijkstra;
    coord firstSommet;
    firstSommet[0] = finalx;
    firstSommet[1] = finaly;

    dijkstra = createDijkstraMatrix(getWidthGraph(graph), getHeightGraph(graph));

    stack = givePath(&dijkstra, graph, currentx, currenty, finalx, finaly);
} */


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


PATH_LIST nextActionBasic ( PATH_LIST path, POSITION positionPilot, SPEED speedPilot, ACCELERATION* nextAction )
{
    path_list_element nextPosition;
    POSITION diffPosition;

    path = removeHeadElementPathList ( path, &nextPosition );
    diffPosition.X = nextPosition.X - positionPilot.X - speedPilot.X;
    diffPosition.Y = nextPosition.Y - positionPilot.Y - speedPilot.Y;
    fprintf ( stderr, "> NEXT_ACTION_BASIC, nextPosition : (%hd, %hd)\n", nextPosition.X, nextPosition.Y );

    /* faire une fonction de cette merde pour l'utiliser en bas */
    /* version boost et non boosted */
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


    return path;
}

static boolean areAligned ( POSITION pos1, POSITION pos2, POSITION pos3 ) 
{
    return  (pos3.Y - pos1.Y) * (pos2.X - pos1.X) - (pos2.Y - pos1.Y) * (pos3.X - pos1.X ) == 0; 
}

static int length ( POSITION first, POSITION secound )
{
    printf ( "LONGUEUR = %d\n", ( ( ( first.X - secound.X ) * ( first.X - secound.X ) ) + ( ( first.Y - secound.Y ) * ( first.Y - secound.Y ) ) ) );
    return ( ( ( first.X - secound.X ) * ( first.X - secound.X ) ) + ( ( first.Y - secound.Y ) * ( first.Y - secound.Y ) ) );
}

static POSITION midlePosition ( POSITION first, POSITION secound )
{

    first.X = ceil ( fabs ( (double) ( first.X - secound.X ) / 2. ) );
    first.Y = ceil ( fabs ( (double) ( first.Y - secound.Y ) / 2. ) );
    return first;
}

static boolean isMaxSpeed ( SPEED speed )
{
    return ( speed.X == MAX_SPEED || speed.Y == MAX_SPEED );
}

static boolean areSamePosition ( POSITION pos1, POSITION pos2 )
{
    return ( pos1.X == pos2.X && pos1.Y == pos2.Y );
}

static POSITION diffPosition ( POSITION nextPosition, POSITION currentPosition, SPEED speed )
{
    nextPosition.X =  nextPosition.X - currentPosition.X - speed.X;
    nextPosition.Y =  nextPosition.Y - currentPosition.Y - speed.Y;
    return nextPosition;
}

static int norme1 ( POSITION position )
{
    return position.X * position.X + position.Y * position.Y;
}

PATH_LIST nextActionLigne ( PATH_LIST path, POSITION positionPilot, SPEED speedPilot, ACCELERATION* nextAction, int* midLenght ) /* -1 */
{
    int internCount = 0;
    int remainingLength = 0;
    POSITION nextPosition;
    POSITION tmp;
    POSITION nextNextPosition;
    POSITION goalPosition;

/*     if ( internCount >= *count ) {

    } */




    /* si le courrant c'est pas la tete c'est qu'on est pas arrive a la fin de la ligne droite */
    if ( !currentEqualsHead ( path ) ) {
        goalPosition = getCurrentPathList ( path );
        /* mettre à jour la tete suivant le chemin parcouru, potentiellement plusieurs points en même temps */
        /* tant que la future position n'est pas la prochaine à celle actuel */

        if ( areSamePosition ( goalPosition, positionPilot ) ) {
            do {
                path = removeHeadElementPathList ( path, &nextPosition );
            } while ( !nextCurrentEqualsHead ( path ) );
        }





        /* on test si la longueur entre la position du pilot et la position du milieu estimé est toujours supérieur à 0 */
        if ( ( length ( positionPilot, goalPosition ) > *midLenght ) ) {


            /* on peut pas aller plus vite mec */
            if ( isMaxSpeed ( speedPilot ) ) {
                goStraight ( nextAction );
                return path;
            }
            accelerate ( diffPosition ( goalPosition, positionPilot, speedPilot ), speedPilot, nextAction );
            return path;
        }
        /* on ralenti si on a depassé le mid */
        if ( isMaxSpeed ( speedPilot ) || nextAction->X == 1 || nextAction->Y == 1 ) {
            goStraight ( nextAction );
            return path;
        }
        slowDown ( diffPosition ( goalPosition, positionPilot, speedPilot ), speedPilot, nextAction );
        return path;

    }
    path = resetCurrentPathList ( path );
    nextPosition = getCurrentPathList ( path );
    path = moveCurrentPathList ( path );
    nextNextPosition = getCurrentPathList ( path );
    if ( nextNextPosition.X == -1 ) {
        /* der element */
        /* avance classique */
        basicNextAction ( diffPosition ( nextPosition, positionPilot, speedPilot ), nextAction );
        return path;
    }
    internCount++;
    path = moveCurrentPathList ( path );
    goalPosition = getCurrentPathList ( path );
    if ( goalPosition.X == -1 ) {
        /* au prochain tour sera le der element */
        /* Boost de fin */
        boostNextAction ( diffPosition ( nextPosition, positionPilot, speedPilot ), nextAction );
        return path;
    }
    internCount++;
/*     while ( areAligned ( nextPosition, nextNextPosition, goalPosition ) ) {
        path = moveCurrentPathList ( path );
        goalPosition = getCurrentPathList ( path );
        internCount++;
    } */

    tmp = goalPosition;
    while ( areAligned ( nextPosition, nextNextPosition, tmp ) ) {
        goalPosition = tmp;
        path = moveCurrentPathList ( path );
        tmp = getNextCurrentPathList ( path );
        internCount++;  
    }

    if ( internCount == 2 ) {
        internCount = 0;
        /* avance classique */
    }
    *midLenght = ceil ( (double) length ( goalPosition, positionPilot ) / 2. );
    path = nextActionLigne ( path, positionPilot, speedPilot, nextAction, midLenght );









    return path;
}




PATH_LIST nextAction2 ( PATH_LIST path, POSITION pilotPosition, SPEED pilotSpeed, ACCELERATION* nextAction )
{
    POSITION nextPosition;
    POSITION tmp;
    POSITION nextNextPosition;
    POSITION goalPosition;



    path = resetCurrentPathList ( path );
    nextPosition = getCurrentPathList ( path );
    path = moveCurrentPathList ( path );
    nextNextPosition = getCurrentPathList ( path );
    if ( nextNextPosition.X == -1 ) {
        /* der element */
        /* avance classique */
        basicNextAction ( diffPosition ( nextPosition, pilotPosition, pilotSpeed ), nextAction );
        return path;
    }
    path = moveCurrentPathList ( path );
    goalPosition = getCurrentPathList ( path );
    if ( goalPosition.X == -1 ) {
        /* au prochain tour sera le der element */
        /* Boost de fin */
        boostNextAction ( diffPosition ( nextPosition, pilotPosition, pilotSpeed ), nextAction );
        return path;
    }



    tmp = goalPosition;
    while ( areAligned ( nextPosition, nextNextPosition, tmp ) ) {
        goalPosition = tmp;
        path = moveCurrentPathList ( path );
        tmp = getNextCurrentPathList ( path );
    }
}