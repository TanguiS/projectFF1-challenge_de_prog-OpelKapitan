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
 * @file pilotDirection.h
 * @brief This file contains the prototypes / declarations used to choose the pilot's direction.
 */

/**
 * @author PICQUE Kylian <kylian.picque@ecole.ensicaen.fr>
 * @version 1.0.0
 * @date 15 avril 2022
 */



#ifndef __PILOT_DIERCTION__
#define __PILOT_DIRECTION__

#include <stdlib.h>
#include <stdio.h>
#include "pilotManagement.h"

#define NUMBER_DIRECTION 24

typedef enum {
    right, 
    left,
    up,
    down,

    rightUp,
    rightDown,
    leftUp,
    leftDown,

    boostRight,
    boostLeft,
    boostUp,
    boostDown,

    boostRightUp,
    boostRightDown,
    boostLeftUp,
    boostLeftDown,

    boostRightBoostUp,
    boostRightBoostDown,
    boostLeftBoostUp,
    boostLeftBoostDown,

    rightBoostUp,
    rightBoostDown,
    leftBoostUp,
    leftBoostDown
} direction;

typedef void directionFct ( PILOT*, short*, short* );

/**
 * @brief turn the pilot on the right the next round
 * 
 * @param pilot the pilot 
 */ 
void goRight ( PILOT* pilot, short* xAcc, short* yAcc ); 

/**
 * @brief turn the pilot on the left the next round
 * 
 * @param pilot the pilot 
 */ 
void goLeft(PILOT* pilot, short* xAcc, short* yAcc );

/**
 * @brief turn up the pilot the next round
 * 
 * @param pilot the pilot 
 */ 
void goUp(PILOT* pilot, short* xAcc, short* yAcc );

/**
 * @brief turn down the pilot the next round
 * 
 * @param pilot the pilot 
 */ 
void goDown(PILOT* pilot, short* xAcc, short* yAcc );

/**
 * @brief stop the pilot the next round
 * 
 * @param pilot the pilot 
 */ 
void stop ( PILOT* pilot, short* xAcc, short* yAcc );

/**
 * @brief turn on the diagonal right up
 * 
 * @param pilot the pilot 
 */ 
void goRightUp ( PILOT* pilot, short* xAcc, short* yAcc );

/**
 * @brief turn on the diagonal left up
 * 
 * @param pilot the pilot 
 */ 
void goLeftUp(PILOT* pilot, short* xAcc, short* yAcc);

/**
 * @brief turn on the diagonal right down
 * 
 * @param pilot the pilot 
 */ 
void goRightDown(PILOT* pilot, short* xAcc, short* yAcc);

/**
 * @brief turn on the diagonal left down
 * 
 * @param pilot the pilot 
 */ 
void goLeftDown(PILOT* pilot, short* xAcc, short* yAcc);


void goBoostRight(PILOT* pilot, short* xAcc, short* yAcc);

void goBoostLeft(PILOT* pilot, short* xAcc, short* yAcc);

void goBoostUp(PILOT* pilot, short* xAcc, short* yAcc);

void goBoostDown(PILOT* pilot, short* xAcc, short* yAcc);

void goBoostRightBoostUp(PILOT* pilot, short* xAcc, short* yAcc);

void goBoostLeftBoostUp(PILOT* pilot, short* xAcc, short* yAcc);

void goBoostRightBoostDown(PILOT* pilot, short* xAcc, short* yAcc);

void goBoostLeftBoostDown(PILOT* pilot, short* xAcc, short* yAcc);

void goLeftBoostDown(PILOT* pilot, short* xAcc, short* yAcc);

void goBoostLeftDown(PILOT* pilot, short* xAcc, short* yAcc);

void goRightBoostDown(PILOT* pilot, short* xAcc, short* yAcc);

void goBoostRightDown(PILOT* pilot, short* xAcc, short* yAcc);

void goLeftBoostUp(PILOT* pilot, short* xAcc, short* yAcc);

void goBoostLeftUp(PILOT* pilot, short* xAcc, short* yAcc);

void goRightBoostUp(PILOT* pilot, short* xAcc, short* yAcc);

void goBoostRightUp ( PILOT* pilot, short* xAcc, short* yAcc );

void choiceDirection ( PILOT* pilot, direction choice, short* xAcc, short* yAcc );


#endif