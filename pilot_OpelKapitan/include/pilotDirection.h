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
#ifndef DEBUG
#include "debugMode.h"
#endif

#define NUMBER_DIRECTION 9

typedef enum {
    right, 
    left,
    up,
    down,

    boostRight,
    boostLeft,
    boostUp,
    boostDown,

    straight
} direction;

typedef void directionFct ( short*, short* );

void goRight ( short* xAcc, short* yAcc ); 

void goLeft ( short* xAcc, short* yAcc );

void goUp ( short* xAcc, short* yAcc );

void goDown ( short* xAcc, short* yAcc );

void goStraight ( short* xAcc, short* yAcc );

void goBoostRight ( short* xAcc, short* yAcc );

void goBoostLeft ( short* xAcc, short* yAcc );

void goBoostUp ( short* xAcc, short* yAcc );

void goBoostDown ( short* xAcc, short* yAcc );

void slowDown ( PILOT* pilot, short* xAcc, short* yAcc );

void choiceDirection ( direction choice, short* xAcc, short* yAcc );


#endif