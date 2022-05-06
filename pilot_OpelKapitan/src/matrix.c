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
 * @brief This file contains functions to manage a matrix.
 */

/**
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.0
 * @date 06 mai 2022
 */

#include "matrix.h"

static void initMatrix ( MATRIX* matrix, short width, short height );

static void setWidthMatrix ( MATRIX* matrix, short width );

static void setHeightMatrix ( MATRIX* matrix, short height );

static void setWidthMatrix ( MATRIX* matrix, short width )
{
    matrix->width = width;
}

static void setHeightMatrix ( MATRIX* matrix, short height )
{
    matrix->height = height;
}

static void initMatrix ( MATRIX* matrix, short width, short height )
{
    setWidthMatrix ( matrix, width );
    setHeightMatrix ( matrix, height );
    matrix->matrix = NULL;
}





short getWidthMatrix ( MATRIX* matrix )
{
    return matrix->width;
}

short getHeightMatrix ( MATRIX* matrix )
{
    return matrix->height;
}

element getElementMatrix ( MATRIX* matrix, short x, short y )
{
    return matrix->matrix[x][y];
}

void setElementMatrix ( MATRIX* matrix, short x, short y, element value )
{
    matrix->matrix[x][y] = value;
}

MATRIX createMatrix ( short width, short height )
{
    MATRIX newMatrix;
    int i;
    initMatrix ( &newMatrix, width, height );
    newMatrix.matrix = (element**) malloc ( width * sizeof ( element* ) );
    for ( i = 0; i < width; i++ ) {
        newMatrix.matrix[i] = (element*) malloc ( height * sizeof ( element ) );
    }
    return newMatrix;
}