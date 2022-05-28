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
 * @file list.c
 * @brief This list  contains all the functions of the lisalgo.
 * @author PICQUE kylian <kylian.picque@ecole.ensicaen.fr>
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.2
 * @date 22 janvier 2022
 */

#include "../../include/tools/list.h"

/**
 * @brief Create a Cell object
 * 
 * @param x : the new element 
 * @return LISTE_CELL 
 */
static LIST_CELL createCell ( listElement x );

/**
 * @brief Destroy a Cell object
 * 
 * @param cell : the cell to destroy
 * @return boolean 
 */
static boolean destroyCell ( LIST_CELL cell );

static LIST_CELL createCell ( listElement x)
{
    LIST_CELL newCell;

    newCell =  (LIST_CELL) malloc ( sizeof ( struct _list_cell) );
    newCell->contents.X = x.X;
    newCell->contents.Y = x.Y;
    newCell->followingCell = NULL;
    return newCell;
}

static boolean destroyCell ( LIST_CELL cell )
{
    if ( cell != NULL ) {
        free(cell);
        cell = NULL;
        return true;
    }
    return false;
}

boolean compareElement(listElement* element1, listElement* element2) {
    if (element1->X == element2->X && element1->Y == element2->Y) {
        return true;
    }
    return false;
}

LIST createList () 
{
    LIST newlist;
    newlist.head = NULL;
    newlist.tail = NULL;
    newlist.size = 0;
    return newlist;
}

boolean isEmptyList ( LIST list )
{
    if ( list.head == NULL ) {
        return true;
    }
    return false;
}

LIST addElementList ( LIST list, listElement x )
{
    LIST_CELL newCell;

    

    newCell = createCell(x);
    if ( isEmptyList(list) ) {
        list.head = newCell;
        list.tail = newCell;
        list.size++;
        return list; 
    }

    list.tail->followingCell = newCell;
    list.tail = newCell;
    list.size++;
    return list; 
}

LIST removeElementListCoord ( LIST list, listElement* result , POSITION* removeCoord)
{
    LIST_CELL previousHead;
    LIST_CELL current;
    
    if ( isEmptyList(list) ) {
        return list; 
    }

    current = list.head;
    previousHead = NULL;
    while ( current != NULL && !compareElement(removeCoord, &(current->contents)) ) {
        previousHead = current;
        current = current->followingCell;
    }

    if(current==NULL) {
        return list;
    }

    result->X = current->contents.X; 
    result->Y = current->contents.Y;

    if (current == list.head) {
        list.head = current->followingCell;
    }
    
    if ( current == list.tail) {
        list.tail = previousHead;
    }
    
    if(previousHead!=NULL) {
        previousHead->followingCell = current->followingCell;
    }
    destroyCell ( current );
    list.size--;
    return list; 
}



LIST removeElementList ( LIST list,  listElement* result )
{
    LIST_CELL previousHead;
    
    if ( isEmptyList(list) ) {
        return list; 
    }

    result->X = list.head->contents.X; 
    result->Y = list.head->contents.Y;

    previousHead = list.head;
    if(list.tail==list.head) {      /*if there is only one elmt in the list*/
        list.head = NULL;
        list.tail = NULL;
    } else {
        list.head = previousHead->followingCell;
    }

    destroyCell ( previousHead );
    list.size--;
    return list; 
}


void destroyList(LIST list)
{
    POSITION trash;
    while ( !isEmptyList( list  ) ) {
        list = removeElementList ( list, &trash );
    }
}



boolean getElementList ( LIST list,  listElement* result, int position) {
    LIST_CELL current;
    int i = 0;

    if (isEmptyList(list)) {
        return false;
    }
    if(list.size<=position) {
        return false;
    }

    current = list.head;
    while (i<position && current!=NULL) {
        current = current->followingCell;
        i++;
    } 
    if(current==NULL) {
        return false;
    }

    result->X = current->contents.X; 
    result->Y = current->contents.Y;

    return true;
}

boolean getNextElementList ( LIST list,  listElement* result, listElement* refElement) {
    LIST_CELL current;

    if (isEmptyList(list) || list.head == list.tail) {  /*if there is only 0 or 1 elmt in the list*/
        return false;
    }

    current = list.head;
    while (!compareElement(refElement, &(current->contents)) && current!= NULL) {
        current = current->followingCell;
    }
    if (current == NULL) {
        return false;
    }
    if (current->followingCell==NULL) {
        return false;
    }
    current = current->followingCell;
    result->X = current->contents.X; 
    result->Y = current->contents.Y;
    
    return true;
}
