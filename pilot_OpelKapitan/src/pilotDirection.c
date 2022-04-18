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
    *xAcc = 0 + ACTION;
    *yAcc = 0;
}


void goLeft ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = 0 - ACTION;
    *yAcc = 0;
}


void goUp ( PILOT* pilot, short* xAcc, short* yAcc  ) {
    *xAcc = 0;
    *yAcc = 0 - ACTION;
}


void goDown ( PILOT* pilot, short* xAcc, short* yAcc  ) {
    *xAcc = 0;
    *yAcc = 0 + ACTION;
}


void stop ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = 0;
    *yAcc = 0;
}


void goRightUp ( PILOT* pilot, short* xAcc, short* yAcc ) { 
    *xAcc = 0 + ACTION;
    *yAcc = 0 - ACTION;
}


void goLeftUp ( PILOT* pilot, short* xAcc, short* yAcc ) {  
    *xAcc = 0 - ACTION;
    *yAcc = 0 - ACTION;
}


void goRightDown ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = 0 + ACTION;
    *yAcc = 0 + ACTION;
}


void goLeftDown ( PILOT* pilot, short* xAcc, short* yAcc ) { 
    *xAcc = 0 - ACTION;
    *yAcc = 0 + ACTION;
}


void goBoostRight ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = 0 + BOOSTED_ACTION;
    *yAcc = 0;
}

void goBoostLeft ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = 0 - BOOSTED_ACTION;
    *yAcc = 0;
}


void goBoostUp ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = 0;
    *yAcc = 0 - BOOSTED_ACTION;
}


void goBoostDown ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = 0;
    *yAcc = 0 + BOOSTED_ACTION;
}


void goBoostRightBoostUp ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = 0 + BOOSTED_ACTION;
    *yAcc = 0 - BOOSTED_ACTION;  
}


void goBoostLeftBoostUp ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = 0 - BOOSTED_ACTION;
    *yAcc = 0 - BOOSTED_ACTION;    
}


void goBoostRightBoostDown ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = 0 + BOOSTED_ACTION;
    *yAcc = 0 + BOOSTED_ACTION;   
}


void goBoostLeftBoostDown ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = 0 - BOOSTED_ACTION;
    *yAcc = 0 + BOOSTED_ACTION;   
}


void goLeftBoostDown ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = 0 - ACTION;
    *yAcc = 0 + BOOSTED_ACTION; 
}

void goBoostLeftDown ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = 0 - BOOSTED_ACTION;
    *yAcc = 0 + ACTION; 
}

void goRightBoostDown ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = 0 + ACTION;
    *yAcc = 0 + BOOSTED_ACTION; 
}

void goBoostRightDown ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = 0 + BOOSTED_ACTION;
    *yAcc = 0 + ACTION; 
}

void goLeftBoostUp ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = 0 - ACTION;
    *yAcc = 0 - BOOSTED_ACTION; 
} 

void goBoostLeftUp ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = 0 - BOOSTED_ACTION;
    *yAcc = 0 - ACTION; 
}

void goRightBoostUp ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = 0 + ACTION;
    *yAcc = 0 - BOOSTED_ACTION; 
}

void goBoostRightUp ( PILOT* pilot, short* xAcc, short* yAcc ) {
    *xAcc = 0 + BOOSTED_ACTION;
    *yAcc = 0 - ACTION; 
}

void choiceDirection ( PILOT* pilot, direction choice, short* xAcc, short* yAcc )
{
    static directionFct* tabDirection[NUMBER_DIRECTION] = 
    {
        goRight, goLeft, goUp, goDown,
        goRightUp, goRightDown, goLeftUp, goLeftDown,
        goBoostRight, goBoostLeft, goBoostRight, goBoostDown,
        goBoostRightUp, goBoostRightDown, goBoostLeftUp, goBoostLeftDown,
        goBoostRightBoostUp, goBoostRightBoostDown, goBoostLeftBoostUp, goBoostLeftBoostDown,
        goRightBoostUp, goRightBoostDown, goLeftBoostUp, goLeftBoostDown,
        stop
    };
    DEBUG_INT ( ">Choix de direction : ", choice );
    tabDirection[choice]( pilot, xAcc, yAcc );
    DEBUG_INT ( ">choix : ", *xAcc );
    DEBUG_INT ( ">choix : ", *yAcc );
}
