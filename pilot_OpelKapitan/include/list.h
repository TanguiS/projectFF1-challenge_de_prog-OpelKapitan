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
 * @brief listElement type declaration 
 */
typedef coord listElement;

/**
 * @brief A structure to represent a cell object 
 */
typedef struct _list_cell {
    listElement contents;                 /**< the element that the cell contains */
    struct _list_cell* followingCell;    /**< the following cell */
} _list_cell; 
/**
 * @brief Cell object declaration 
 */
typedef struct _list_cell *LIST_CELL;

/**
 * @brief A structure to represent a lifo object 
 */
typedef struct _list {
    LIST_CELL head;                      /**< the head of the list */
    LIST_CELL tail;                      /**< the tail of the list */
    /*int size;*/                             /**< the size of the list */
} _lifo; 
/**
 * @brief Lifo object declaration 
 */
typedef struct _list LIST;


/**
 * @brief Create a Lifo object
 * 
 * @return LIST 
 */
LIST createList ();

/**
 * @brief If the lifo is empty
 * 
 * @param lifo 
 * @return boolean 
 */
boolean isEmptyList ( LIST list );


boolean compareElement(listElement* element1, listElement* element2);

/**
 * @brief Add a lifo element int the lifo
 * 
 * @param file 
 * @param x : the element to add
 * @return LIST 
 */
LIST addElementList ( LIST list, listElement x );



LIST removeElementListCoord ( LIST list, listElement* result , coord* removeCoord);


/**
 * @brief Remove a lifo element from the lifo
 * 
 * @param file 
 * @param result : the removed element
 * @return LIST 
 */
LIST removeElementList ( LIST list, listElement* result );

/**
 * @brief Destroy a Lifo Object
 * 
 * @param file 
 */
void destroyList ( LIST list );




boolean getElementList ( LIST list, listElement* result, int position);

boolean getNextElementList ( LIST list, listElement* result, listElement* refElement);

#ifndef DEBUG
void displaylist (LIST list);
#endif

#endif /* __FILE_H__ */