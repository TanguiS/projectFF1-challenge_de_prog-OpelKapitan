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


void slowDown ( SPEED speedPilot, ACCELERATION* action )
{
    if ( speedPilot.X > 0 ) {
        goLeft ( action );
    } else {
        goRight ( action );
    }
    if ( speedPilot.Y > 0 ) {
        goUp ( action );
    } else {
        goDown ( action );
    }
}

void accelerate ( SPEED speedPilot, ACCELERATION* action )
{
    if ( speedPilot.X > 0 ) {
        goRight ( action );
    } else {
        goLeft ( action );
    }
    if ( speedPilot.Y > 0 ) {
        goDown ( action );
    } else {
        goUp ( action );
    } 
}



void choiceDirection ( direction choice, ACCELERATION* action )
{
    static directionFct* tabDirection[NUMBER_DIRECTION] = 
    {
        goRight, goLeft, goUp, goDown,
        goBoostRight, goBoostLeft, goBoostRight, goBoostDown
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
    return (pos3.Y - pos1.Y) * (pos2.X - pos1.X) - (pos2.Y - pos1.Y) * (pos3.X - pos1.X ) == 0; 
}

static int length ( POSITION first, POSITION secound )
{
    return ( ( ( first.X - secound.X ) * ( first.X - secound.X ) ) + ( ( first.Y - secound.Y ) * ( first.Y - secound.Y ) ) );
}

static POSITION midlePosition ( POSITION first, POSITION secound )
{
    first.X = (short) ceil ( (double) ( first.X - secound.X ) / 2. );
    first.Y = (short) ceil ( (double) ( first.Y - secound.Y ) / 2. );
    return first;
}

static boolean isMaxSpeed ( SPEED speed )
{
    return ( speed.X == MAX_SPEED || speed.Y == MAX_SPEED );
}


PATH_LIST nextActionLigne ( PATH_LIST path, POSITION positionPilot, SPEED speedPilot, ACCELERATION* nextAction, int* count ) /* -1 */
{
    int internCount = 0;
    int remainingLength = 0;
    POSITION nextPosition;
    POSITION midPosition;
    POSITION* nextNextPosition;
    POSITION* goalPosition;

/*     if ( internCount >= *count ) {

    } */




    /* si le courrant c'est pas la tete c'est qu'on est pas arrive a la fin de la ligne droite */
    if ( !currentEqualsHead ( path ) ) {
        goalPosition = getCurrentPathList ( path );
        /* mettre à jour la tete suivant le chemin parcouru, potentiellement plusieurs points en même temps */
        /* tant que la future position n'est pas la prochaine à celle actuel */



        /* on test si la longueur entre la position du pilot et la position du milieu estimé est toujours upérieur à 0 */
        if ( ( length ( positionPilot, midlePosition ( positionPilot, *goalPosition ) ) > 0 ) ) {


            /* on peut pas aller plus vite mec */
            if ( isMaxSpeed ( speedPilot ) ) {
                goStraight ( nextAction );
                return path;
            }
            accelerate ( speedPilot, nextAction );
            return path;
        }
        /* on ralenti si on a depassé le mid */
        slowDown ( speedPilot, nextAction );
        return path;

    }

    path = removeHeadElementPathList ( path, &nextPosition );
    path = nextElementPathList ( path, nextNextPosition );
    if ( nextNextPosition == NULL ) {
        /* der element */
        /* avance classique */
        return path;
    }
    internCount++;
    path = nextElementPathList ( path, goalPosition );
    if ( goalPosition == NULL ) {
        /* au prochain tour sera le der element */
        /* Boost de fin */
        return path;
    }
    internCount++;
    while ( areAligned ( nextPosition, *nextNextPosition, *goalPosition ) ) {
        path = nextElementPathList ( path, goalPosition );
        internCount++;
    }

    if ( internCount == 2 ) {
        internCount = 0;
        /* avance classique */
    }









    return path;
}