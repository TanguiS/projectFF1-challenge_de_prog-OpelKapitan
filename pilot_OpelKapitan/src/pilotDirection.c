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
    *yAcc = -getYSpeedPilot(pilot) +1;
}


void goLeftUp ( PILOT* pilot, short* xAcc, short* yAcc ) {  
    *xAcc = -getXSpeedPilot(pilot) -1;
    *yAcc = -getYSpeedPilot(pilot) +1;
}


void goRightDown ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = -getXSpeedPilot(pilot) +1;
    *yAcc = -getYSpeedPilot(pilot) -1;
}


void goLeftDown ( PILOT* pilot, short* xAcc, short* yAcc ) { 
    *xAcc = -getXSpeedPilot(pilot) -1;
    *yAcc = -getYSpeedPilot(pilot) -1;
}


void boostRight ( PILOT* pilot ) {
    pilot->xAcc = -pilot->xSpeed +2;
    pilot->yAcc = -pilot->ySpeed;
}

void boostLeft ( PILOT* pilot ) {
    pilot->xAcc = -pilot->xSpeed -2;
    pilot->yAcc = -pilot->ySpeed;
}


void boostUp ( PILOT* pilot ) {
    pilot->xAcc = -pilot->xSpeed;
    pilot->yAcc = -pilot->ySpeed + 2;
}


void boostDown ( PILOT* pilot ) {
    pilot->xAcc = -pilot->xSpeed;
    pilot->yAcc = -pilot->ySpeed - 2;
}


void boostRRightUUp ( PILOT* pilot ) {
    pilot->xAcc = -pilot->xSpeed +2;
    pilot->yAcc = -pilot->ySpeed +2;   
}


void boostLLeftUUp ( PILOT* pilot ) {
    pilot->xAcc = -pilot->xSpeed -2;
    pilot->yAcc = -pilot->ySpeed +2;   
}


void boostRRightDDown ( PILOT* pilot ) {
    pilot->xAcc = -pilot->xSpeed +2;
    pilot->yAcc = -pilot->ySpeed -2;   
}


void boostLLeftDDown ( PILOT* pilot ) {
    pilot->xAcc = -pilot->xSpeed -2;
    pilot->yAcc = -pilot->ySpeed -2;   
}


void boostLeftDDown ( PILOT* pilot ) {
    pilot->xAcc = -pilot->xSpeed -1;
    pilot->yAcc = -pilot->ySpeed -2;
}

void boostLLeftDown ( PILOT* pilot ) {
    pilot->xAcc = -pilot->xSpeed -2;
    pilot->yAcc = -pilot->ySpeed -1;
}

void boostRightDDown ( PILOT* pilot ) {
    pilot->xAcc = -pilot->xSpeed +1;
    pilot->yAcc = -pilot->ySpeed -2;
}

void boostRRightDown ( PILOT* pilot ) {
    pilot->xAcc = -pilot->xSpeed +2;
    pilot->yAcc = -pilot->ySpeed -1;
}

void boostLeftUUp ( PILOT* pilot ) {
    pilot->xAcc = -pilot->xSpeed -1;
    pilot->yAcc = -pilot->ySpeed +2;
} 

void boostLLeftUp ( PILOT* pilot ) {
    pilot->xAcc = -pilot->xSpeed -2;
    pilot->yAcc = -pilot->ySpeed +1;
}

void boostRightUUp ( PILOT* pilot ) {
    pilot->xAcc = -pilot->xSpeed +1;
    pilot->yAcc = -pilot->ySpeed +2;
}

void boostRRightUp ( PILOT* pilot ) {
    pilot->xAcc = -pilot->xSpeed +2;
    pilot->yAcc = -pilot->ySpeed +1;
}