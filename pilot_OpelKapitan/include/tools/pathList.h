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
 * @file pathList.h
 * @brief This file contains all the prototype of the pathList algo.
 * @author PICQUE Kylian <kylian.picque@ecole.ensicaen.fr>
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 2.0.2
 * @date 22 janvier 2022
 */

#ifndef __FILE_H__
#define __FILE_H__

#include <stdlib.h>
#include <stdio.h>
#include "./util.h"

/**
 * @brief path_list_element type declaration 
 */
typedef POSITION path_list_element;

/**
 * @brief A structure to represent a cell object 
 */
typedef struct _cell {
    path_list_element contents;     /**< the element that the cell contains */
    struct _cell* followingCell;    /**< the following cell */
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
 * @return PATH_LIST the created list
 */
PATH_LIST createPathList ();

/**
 * @brief If the list is empty
 * 
 * @param list the list to test
 * @return boolean true if the list is empty
 */
boolean isEmptyPathList ( PATH_LIST list );

/**
 * @brief Add an element into the list
 * 
 * @param list the list to update
 * @param value the element to add
 * @return PATH_LIST the updated list
 */
PATH_LIST addHeadElementPathList ( PATH_LIST list, path_list_element value );

/**
 * @brief Remove a path_list_element from a list
 * 
 * @param list the list to update
 * @param result the removed element
 * @return PATH_LIST the updated list
 */
PATH_LIST removeHeadElementPathList ( PATH_LIST list, path_list_element* result );

/**
 * @brief Reset the current pointer to the head of the list
 * 
 * @param list the list to update
 * @return PATH_LIST the updated list
 */
PATH_LIST resetCurrentPathList ( PATH_LIST list );

/**
 * @brief If the current is equal to the head of a list
 * 
 * @param list the list to test
 * @return boolean true if they are equals
 */
boolean currentEqualsHead ( PATH_LIST list );

/**
 * @brief Get the Current Path List object
 * 
 * @param list the current list
 * @return path_list_element the current element
 */
path_list_element getCurrentPathListElement ( PATH_LIST list );

/**
 * @brief Move the current pointer to the next element
 * 
 * @param list the list to update
 * @return PATH_LIST the updated list
 */
PATH_LIST moveCurrentPathList ( PATH_LIST list );

/**
 * @brief Get the head element without poping it
 * 
 * @param list the current list
 * @return path_list_element the head element
 */
path_list_element examineHeadPathList ( PATH_LIST list );

/**
 * @brief Get the Next Current Path List object
 * 
 * @param list the current list 
 * @return path_list_element the next current element of the list
 */
path_list_element getNextCurrentPathList ( PATH_LIST list );

/**
 * @brief If the current is equal to NULL
 * 
 * @param list the current list
 * @return boolean true if the current is NULL
 */
boolean isCurrentNull ( PATH_LIST list );

/**
 * @brief Destroy a PathList object
 * 
 * @param list the list to destroy
 */
void destroyPathList ( PATH_LIST list );

#endif /* __FILE_H__ */