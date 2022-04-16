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
    *xAcc = -getXSpeedPilot(pilot) +ACTION;
    *yAcc = -getYSpeedPilot(pilot);
}


void goLeft ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) -ACTION;
    *yAcc = -getYSpeedPilot(pilot);
}



void goUp ( PILOT* pilot, short* xAcc, short* yAcc  ) {
    *xAcc = -getXSpeedPilot(pilot);
    *yAcc = -getYSpeedPilot(pilot) -ACTION;
}


void goDown ( PILOT* pilot, short* xAcc, short* yAcc  ) {
    *xAcc = -getXSpeedPilot(pilot);
    *yAcc = -getYSpeedPilot(pilot) +ACTION;
}


void stop ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot);
    *yAcc = -getYSpeedPilot(pilot);
}


void goRightUp ( PILOT* pilot, short* xAcc, short* yAcc ) { 
    *xAcc = -getXSpeedPilot(pilot) +ACTION;
    *yAcc = -getYSpeedPilot(pilot) -ACTION;
}


void goLeftUp ( PILOT* pilot, short* xAcc, short* yAcc ) {  
    *xAcc = -getXSpeedPilot(pilot) -ACTION;
    *yAcc = -getYSpeedPilot(pilot) -ACTION;
}


void goRightDown ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) +ACTION;
    *yAcc = -getYSpeedPilot(pilot) +ACTION;
}


void goLeftDown ( PILOT* pilot, short* xAcc, short* yAcc ) { 
    *xAcc = -getXSpeedPilot(pilot) -ACTION;
    *yAcc = -getYSpeedPilot(pilot) +ACTION;
}


void boostRight ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) +BOOSTED_ACTION;
    *yAcc = -getYSpeedPilot(pilot);
}

void boostLeft ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) -BOOSTED_ACTION;
    *yAcc = -getYSpeedPilot(pilot);
}


void boostUp ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot);
    *yAcc = -getYSpeedPilot(pilot) -BOOSTED_ACTION;
}


void boostDown ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot);
    *yAcc = -getYSpeedPilot(pilot) +BOOSTED_ACTION;
}


void boostRRightUUp ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) +BOOSTED_ACTION;
    *yAcc = -getYSpeedPilot(pilot) -BOOSTED_ACTION;  
}


void boostLLeftUUp ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) -BOOSTED_ACTION;
    *yAcc = -getYSpeedPilot(pilot) -BOOSTED_ACTION;    
}


void boostRRightDDown ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) +BOOSTED_ACTION;
    *yAcc = -getYSpeedPilot(pilot) +BOOSTED_ACTION;   
}


void boostLLeftDDown ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) -BOOSTED_ACTION;
    *yAcc = -getYSpeedPilot(pilot) +BOOSTED_ACTION;   
}


void boostLeftDDown ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) -ACTION;
    *yAcc = -getYSpeedPilot(pilot) +BOOSTED_ACTION; 
}

void boostLLeftDown ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) -BOOSTED_ACTION;
    *yAcc = -getYSpeedPilot(pilot) +ACTION; 
}

void boostRightDDown ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) +ACTION;
    *yAcc = -getYSpeedPilot(pilot) +BOOSTED_ACTION; 
}

void boostRRightDown ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) +BOOSTED_ACTION;
    *yAcc = -getYSpeedPilot(pilot) +ACTION; 
}

void boostLeftUUp ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) -ACTION;
    *yAcc = -getYSpeedPilot(pilot) -BOOSTED_ACTION; 
} 

void boostLLeftUp ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) -BOOSTED_ACTION;
    *yAcc = -getYSpeedPilot(pilot) -ACTION; 
}

void boostRightUUp ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) +ACTION;
    *yAcc = -getYSpeedPilot(pilot) -BOOSTED_ACTION; 
}

void boostRRightUp ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) +BOOSTED_ACTION;
    *yAcc = -getYSpeedPilot(pilot) -ACTION; 
}

void choiceDirection ( PILOT* pilot, direction choice, short* xAcc, short* yAcc )
{
    directionFct* tabDirection[NUMBER_DIRECTION] = {
                                                    goRight,
                                                    goLeft
    };
}