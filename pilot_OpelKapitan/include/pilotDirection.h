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

#define NUMBER_DIRECTION 8

typedef enum {
    goRight, 
    goLeft,
    goUp,
    goDown,
    goRightUp,
    goRightDown,
    goLeftUp,
    goLeftDown
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


void boostRight(PILOT* pilot);

void boostLeft(PILOT* pilot);

void boostUp(PILOT* pilot);

void boostDown(PILOT* pilot);

void boostRRightUUp(PILOT* pilot);

void boostLLeftUUp(PILOT* pilot);

void boostRRightDDown(PILOT* pilot);

void boostLLeftDDown(PILOT* pilot);

void boostLeftDDown(PILOT* pilot);

void boostLLeftDown(PILOT* pilot);

void boostRightDDown(PILOT* pilot);

void boostRRightDown(PILOT* pilot);

void boostLeftUUp(PILOT* pilot);

void boostLLeftUp(PILOT* pilot);

void boostRightUUp(PILOT* pilot);

void choiceDirection ( PILOT* pilot, direction choice, short* xAcc, short* yAcc );


#endif