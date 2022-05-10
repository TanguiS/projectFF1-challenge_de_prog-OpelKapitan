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


void goRight ( short* xAcc, short* yAcc ) {
    *xAcc = 0 + ACTION;
    *yAcc = *yAcc;
}


void goLeft ( short* xAcc, short* yAcc ) {
    *xAcc = 0 - ACTION;
    *yAcc = *yAcc;
}


void goUp ( short* xAcc, short* yAcc  ) {
    *xAcc = *xAcc;
    *yAcc = 0 - ACTION;
}


void goDown ( short* xAcc, short* yAcc  ) {
    *xAcc = *xAcc;
    *yAcc = 0 + ACTION;
}


void goStraight ( short* xAcc, short* yAcc ) {
    *xAcc = 0;
    *yAcc = 0;
}


void goBoostRight ( short* xAcc, short* yAcc ) {
    *xAcc = 0 + BOOSTED_ACTION;
    *yAcc = *yAcc;
}

void goBoostLeft ( short* xAcc, short* yAcc ) {
    *xAcc = 0 - BOOSTED_ACTION;
    *yAcc = *yAcc;
}

void goBoostUp ( short* xAcc, short* yAcc ) {
    *xAcc = *xAcc;
    *yAcc = 0 - BOOSTED_ACTION;
}


void goBoostDown ( short* xAcc, short* yAcc ) {
    *xAcc = *xAcc;
    *yAcc = 0 + BOOSTED_ACTION;
}


void slowDown ( PILOT* pilot, short* xAcc, short* yAcc )
{
    SPEED speed = getSpeedPilot ( pilot );
    goStraight ( xAcc, yAcc );
    if ( speed.X > 0 ) {
        *xAcc = - ACTION;
    } else if ( speed.X < 0 ) {
        *xAcc = - ACTION;
    }
    if ( speed.Y > 0 ) {
        *yAcc = + ACTION;
    } else if ( speed.Y < 0 ) {
        *yAcc = + ACTION;
    } 
}



void choiceDirection ( direction choice, short* xAcc, short* yAcc )
{
    static directionFct* tabDirection[NUMBER_DIRECTION] = 
    {
        goRight, goLeft, goUp, goDown,
        goBoostRight, goBoostLeft, goBoostRight, goBoostDown,
        goStraight
    };
    DEBUG_INT ( ">Choix de direction : ", choice );
    tabDirection[choice]( xAcc, yAcc );
    DEBUG_INT ( ">choix : ", *xAcc );
    DEBUG_INT ( ">choix : ", *yAcc );
}


/* void nextStep(short* xAcc, short* yAcc, GRAPH* graph, short currentx, short currenty, short finalx, short finaly,short xSpeed, short ySpeed) {
    LIFO stack; 
    dijkstraMatrix dijkstra;
    coord firstSommet;
    firstSommet[0] = finalx;
    firstSommet[1] = finaly;

    dijkstra = createDijkstraMatrix(getWidthGraph(graph), getHeightGraph(graph));

    stack = givePath(&dijkstra, graph, currentx, currenty, finalx, finaly);
} */