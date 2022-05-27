/*
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
 * @author PICQUE Kylian <picque.kylian@ecole.ensicaen.fr>
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.0
 * @date 06 mai 2022
 */

#ifndef __MATRIX_HH__
#define __MATRIX_HH__

#include "./util.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief A structure to represent a matrix object
 */
typedef struct _matrix {
    /*@{*/
    short width;            /**< the width size of the matrix */
    short height;           /**< the height size of the matrix */
    element** matrix;       /**< the matrix which contains 'element' */
    /*@}*/
}_matrix;
/**
 * @brief the MATRIX object from a _matrix structure 
 */
typedef struct _matrix MATRIX;

/**
 * @brief Get the Width Matrix object
 * 
 * @param matrix
 * @return short : the width of the matrix
 */
short getWidthMatrix ( MATRIX* matrix );

/**
 * @brief Get the Height Matrix object
 * 
 * @param matrix 
 * @return short : the height of the matrix
 */
short getHeightMatrix ( MATRIX* matrix );

/**
 * @brief Get the Element Matrix object
 * 
 * @param matrix 
 * @param x : the x coordinate
 * @param y : the y coordinate
 * @return element : the element of the matrix at x and y coordinates
 */
element getElementMatrix ( MATRIX* matrix, short x, short y );

/**
 * @brief Set the Element Matrix object
 * 
 * @param matrix 
 * @param x : the x coordinate
 * @param y  : the y coordinate
 * @param value : the value to add at the x and y coordinates of the matrix
 */
void setElementMatrix ( MATRIX* matrix, short x, short y, element value );

/**
 * @brief Create a Matrix object
 * 
 * @param width : the width of the new matrix
 * @param height : the height of the new matrix
 * @return MATRIX : the MATRIX object initialised and allocated
 */
MATRIX createMatrix ( short width, short height );

/**
 * @brief Destroy a Matrix object
 * 
 * @param matrixToDestroy 
 */
void destroyMatrix ( MATRIX matrixToDestroy );

#endif /* __MATRIX_HH__ */