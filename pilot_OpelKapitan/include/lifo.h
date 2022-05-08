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
 * @file file.h
 * @brief This file contains all the prototype of the file algo.
 */

/**
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.1
 * @date 22 janvier 2022
 */

#ifndef __FILE_H__
#define __FILE_H__

#include <stdlib.h>
#include <stdio.h>
#include "util.h"

/**
 * @brief lifoElement type declaration 
 */
typedef coord lifoElement;

/**
 * @brief A structure to represent a cell object 
 */
typedef struct _cell {
    lifoElement contents;           /**< the element that the cell contains */
    struct _cell* followingCell;    /**< the following cell */
} _cell; 
/**
 * @brief Cell object declaration 
 */
typedef struct _cell *CELL;

/**
 * @brief A structure to represent a lifo object 
 */
typedef struct _lifo {
    CELL head;                      /**< the head of the lifo */
} _lifo; 
/**
 * @brief Lifo object declaration 
 */
typedef struct _lifo LIFO;

/**
 * @brief Create a Lifo object
 * 
 * @return LIFO 
 */
LIFO createLifo ();

/**
 * @brief If the lifo is empty
 * 
 * @param lifo 
 * @return boolean 
 */
boolean isEmpty ( LIFO lifo );

/**
 * @brief Add a lifo element int the lifo
 * 
 * @param file 
 * @param x : the element to add
 * @return LIFO 
 */
LIFO addElementLifo ( LIFO file, lifoElement x );

/**
 * @brief Remove a lifo element from the lifo
 * 
 * @param file 
 * @param result : the removed element
 * @return LIFO 
 */
LIFO removeElementLifo ( LIFO file, lifoElement* result );

/**
 * @brief Destroy a Lifo Object
 * 
 * @param file 
 */
void destroyLifo ( LIFO file );

#endif /* __FILE_H__ */