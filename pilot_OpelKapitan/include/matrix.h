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
 * @file matrix.h
 * @brief This file contains prototypes and declarations to manage a matrix.
 */

/**
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.0
 * @date 06 mai 2022
 */

#ifndef __MATRIX_HH__
#define __MATRIX_HH__

#include "matrix.h"
#include "util.h"
#include "debugMode.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct _matrix {
    short width;
    short height;
    element** matrix;
}_matrix;
typedef struct _matrix MATRIX;

short getWidthMatrix ( MATRIX* matrix );

short getHeightMatrix ( MATRIX* matrix );

element getElementMatrix ( MATRIX* matrix, short x, short y );

void setElementMatrix ( MATRIX* matrix, short x, short y, element value );

MATRIX createMatrix ( short width, short height );

void destroyMatrix ( MATRIX matrixToDestroy );



#endif /* __MATRIX_HH__ */