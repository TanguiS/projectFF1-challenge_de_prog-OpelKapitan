/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This list is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */

/**
 * @list pathList.h
 * @brief This list contains all the prototype of the pathList algo.
 */

/**
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.2
 * @date 22 janvier 2022
 */

#ifndef __FILE_H__
#define __FILE_H__

#include <stdlib.h>
#include <stdio.h>
#include "util.h"

/**
 * @brief pathListElement type declaration 
 */
typedef POSITION pathListElement;

/**
 * @brief A structure to represent a cell object 
 */
typedef struct _cell {
    pathListElement contents;           /**< the element that the cell contains */
    struct _cell* followingCell;        /**< the following cell */
} _cell; 
/**
 * @brief Cell object declaration 
 */
typedef struct _cell *CELL;

/**
 * @brief A structure to represent a pathList object 
 */
typedef struct _pathList {
    CELL head;                      /**< the head of the list */
    CELL current;                   /**< the current element of the list */
} _pathList; 
/**
 * @brief pathList object declaration 
 */
typedef struct _pathList PATH_LIST;

/**
 * @brief Create a pathList object
 * 
 * @return PATH_LIST 
 */
PATH_LIST createPathList ();

/**
 * @brief If the list is empty
 * 
 * @param lifo 
 * @return boolean 
 */
boolean isEmptyPathList ( PATH_LIST lifo );

/**
 * @brief Add an element into the list
 * 
 * @param list 
 * @param value : the element to add
 * @return PATH_LIST 
 */
PATH_LIST addHeadElementPathList ( PATH_LIST list, pathListElement value );

/**
 * @brief Remove a pathListElement from the list
 * 
 * @param list 
 * @param result : the removed element
 * @return PATH_LIST 
 */
PATH_LIST removeHeadElementPathList ( PATH_LIST list, pathListElement* result );

PATH_LIST resetCurrentPathList ( PATH_LIST list );

PATH_LIST nextElementPathList ( PATH_LIST list, pathListElement* result );

/**
 * @brief Destroy a PathList object
 * 
 * @param list 
 */
void destroyPathList ( PATH_LIST list );

#endif /* __FILE_H__ */