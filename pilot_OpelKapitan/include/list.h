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
 * @file list.h
 * @brief This file contains all the prototype of the liste algo.
 * @author PICQUE Kylian <picque.kylian@ecole.ensicaen.fr>
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.1
 * @date 22 janvier 2022
 */

#ifndef __LIST_H__
#define __LIST_H__

#include <stdlib.h>
#include <stdio.h>
#include "util.h"

/**
 * @brief listElement type declaration 
 */
typedef POSITION listElement;

/**
 * @brief A structure to represent a cell object 
 */
typedef struct _list_cell {
    listElement contents;                   /**< the element that the cell contains */
    struct _list_cell* followingCell;       /**< the following cell */
} *LIST_CELL;

/**
 * @brief A structure to represent a lifo object 
 */
typedef struct _list {
    int size;                               /**< the size of the list */
    LIST_CELL head;                         /**< the head of the list */
    LIST_CELL tail;                         /**< the tail of the list */
} _list; 
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

/**
 * @brief Compare two list elements. 
 * 
 * @param element1 
 * @param element2 
 * @return boolean 
 */
boolean compareElement(listElement* element1, listElement* element2);

/**
 * @brief Add a lifo element int the lifo
 * 
 * @param file 
 * @param x : the element to add
 * @return LIST 
 */
LIST addElementList ( LIST list, listElement x );


/**
 * @brief remove removeCoord from the list.  
 * 
 * @param list the liste
 * @param result stock the removed element 
 * @param removeCoord the position of the element to remove
 * @return LIST 
 */
LIST removeElementListCoord ( LIST list, listElement* result , POSITION* removeCoord);


/**
 * @brief Remove the first list element from the list
 * 
 * @param list 
 * @param result : the removed element
 * @return LIST 
 */
LIST removeElementList ( LIST list, listElement* result );


/**
 * @brief Destroy a Lifo Object
 * 
 * @param list 
 */
void destroyList ( LIST list );


/**
 * @brief Get the Element List object
 * 
 * @param list 
 * @param result stock the removed element 
 * @param position the ranking of the element
 * @return boolean if the ranking is greater than the list length
 */
boolean getElementList ( LIST list, listElement* result, int position);

/**
 * @brief Get the Next Element List object from the reference element
 * 
 * @param list 
 * @param result stock the removed element
 * @param refElement reference element
 * @return boolean if the next element or the reference element exist
 */
boolean getNextElementList ( LIST list, listElement* result, listElement* refElement);


#endif /* __LISTE_H__ */