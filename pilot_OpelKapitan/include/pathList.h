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
 * @brief path_list_element type declaration 
 */
typedef POSITION path_list_element;

/**
 * @brief A structure to represent a cell object 
 */
typedef struct _cell {
    path_list_element contents;           /**< the element that the cell contains */
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
PATH_LIST addHeadElementPathList ( PATH_LIST list, path_list_element value );

/**
 * @brief Remove a path_list_element from the list
 * 
 * @param list 
 * @param result : the removed element
 * @return PATH_LIST 
 */
PATH_LIST removeHeadElementPathList ( PATH_LIST list, path_list_element* result );

/**
 * @brief reset
 * 
 * @param list 
 * @return PATH_LIST 
 */
PATH_LIST resetCurrentPathList ( PATH_LIST list );

/**
 * @brief next element
 * 
 * @param list 
 * @param result 
 * @return PATH_LIST 
 */
PATH_LIST nextElementPathList ( PATH_LIST list, path_list_element* result );

/**
 * @brief if current equal head
 * 
 * @param list 
 * @return boolean 
 */
boolean currentEqualsHead ( PATH_LIST list );

/**
 * @brief Get the Current Path List object
 * 
 * @param list 
 * @return path_list_element* 
 */
path_list_element getCurrentPathList ( PATH_LIST list );

PATH_LIST moveCurrentPathList ( PATH_LIST list );

path_list_element examineHeadPathList ( PATH_LIST list );

boolean nextCurrentEqualsHead ( PATH_LIST list );

path_list_element getNextCurrentPathList ( PATH_LIST list );

/**
 * @brief Destroy a PathList object
 * 
 * @param list 
 */
void destroyPathList ( PATH_LIST list );

#endif /* __FILE_H__ */