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


void goRight ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) +1;
    *yAcc = -getYSpeedPilot(pilot);
}


void goLeft ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) -1;
    *yAcc = -getYSpeedPilot(pilot);
}



void goUp ( PILOT* pilot, short* xAcc, short* yAcc  ) {
    *xAcc = -getXSpeedPilot(pilot);
    *yAcc = -getYSpeedPilot(pilot) -1;
}


void goDown ( PILOT* pilot, short* xAcc, short* yAcc  ) {
    *xAcc = -getXSpeedPilot(pilot);
    *yAcc = -getYSpeedPilot(pilot) +1;
}


void stop ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot);
    *yAcc = -getYSpeedPilot(pilot);
}


void goRightUp ( PILOT* pilot, short* xAcc, short* yAcc ) { 
    *xAcc = -getXSpeedPilot(pilot) +1;
    *yAcc = -getYSpeedPilot(pilot) -1;
}


void goLeftUp ( PILOT* pilot, short* xAcc, short* yAcc ) {  
    *xAcc = -getXSpeedPilot(pilot) -1;
    *yAcc = -getYSpeedPilot(pilot) -1;
}


void goRightDown ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) +1;
    *yAcc = -getYSpeedPilot(pilot) +1;
}


void goLeftDown ( PILOT* pilot, short* xAcc, short* yAcc ) { 
    *xAcc = -getXSpeedPilot(pilot) -1;
    *yAcc = -getYSpeedPilot(pilot) +1;
}


void boostRight ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) +2;
    *yAcc = -getYSpeedPilot(pilot);
}

void boostLeft ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) -2;
    *yAcc = -getYSpeedPilot(pilot);
}


void boostUp ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot);
    *yAcc = -getYSpeedPilot(pilot) -2;
}


void boostDown ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot);
    *yAcc = -getYSpeedPilot(pilot) +2;
}


void boostRRightUUp ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) +2;
    *yAcc = -getYSpeedPilot(pilot) -2;  
}


void boostLLeftUUp ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) -2;
    *yAcc = -getYSpeedPilot(pilot) -2;    
}


void boostRRightDDown ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) +2;
    *yAcc = -getYSpeedPilot(pilot) +2;   
}


void boostLLeftDDown ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) -2;
    *yAcc = -getYSpeedPilot(pilot) +2;   
}


void boostLeftDDown ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) -1;
    *yAcc = -getYSpeedPilot(pilot) +2; 
}

void boostLLeftDown ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) -2;
    *yAcc = -getYSpeedPilot(pilot) +1; 
}

void boostRightDDown ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) +1;
    *yAcc = -getYSpeedPilot(pilot) +2; 
}

void boostRRightDown ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) +2;
    *yAcc = -getYSpeedPilot(pilot) +1; 
}

void boostLeftUUp ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) -1;
    *yAcc = -getYSpeedPilot(pilot) -2; 
} 

void boostLLeftUp ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) -2;
    *yAcc = -getYSpeedPilot(pilot) -1; 
}

void boostRightUUp ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) +1;
    *yAcc = -getYSpeedPilot(pilot) -2; 
}

void boostRRightUp ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) +2;
    *yAcc = -getYSpeedPilot(pilot) -1; 
}

void choiceDirection ( PILOT* pilot, direction choice, short* xAcc, short* yAcc )
{
    directionFct* tabDirection[NUMBER_DIRECTION] = 
    {
        goRight, goLeft, goUp, goDown,
        goRightUp, goRightDown, goLeftUp, goLeftDown
    };
    tabDirection[choice]( pilot, xAcc, yAcc );
}
