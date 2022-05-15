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
 * @list listc
 * @brief This list  contains all the functions of the lisalgo.
 */

/**
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.2
 * @date 22 janvier 2022
 */

#include "list.h"

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

    newCell =  ( LIST_CELL ) malloc ( sizeof ( _list_cell ) );
    newCell->contents.X = x.X;
    newCell->contents.Y = x.Y;
    newCell->followingCell = NULL;
    return newCell;
}

static boolean destroyCell ( LIST_CELL cell )
{
    if ( cell != NULL ) {
        free ( cell );
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

    newCell = createCell ( x );
    if ( isEmptyList( list  ) ) {
        list.head = newCell;
        list.tail = newCell;
        return list; 
    }

    list.tail->followingCell = newCell;
    list.tail = newCell;
    return list; 
}

LIST removeElementListCoord ( LIST list, listElement* result , POSITION* removeCoord)
{
    LIST_CELL previousHead;
    LIST_CELL current;
    
    if ( isEmptyList( list  ) ) {
        return list; 
    }
    current = list.head;
    while ( current != NULL && !compareElement(removeCoord, &(current->contents)) ) {
        previousHead = current;
        current = current->followingCell;
    }
    if (current == NULL) {
        return list; 
    }
    result->X = current->contents.X; 
    result->Y = current->contents.Y;
    if (current == list. head) {
        list.head = current->followingCell;
    } else if ( current == list. tail) {
        list.tail = previousHead;
    } else {
        previousHead->followingCell = current->followingCell;
    }
    destroyCell ( current );
    return list; 
}



LIST removeElementList ( LIST list,  listElement* result )
{
    LIST_CELL previousHead;
    
    if ( isEmptyList( list  ) ) {
        return list; 
    }
    result->X = list.head->contents.X; 
    result->Y = list.head->contents.Y;
    previousHead = list.head;
    list.head = list.head->followingCell;
    destroyCell ( previousHead );
    return list; 
}


void destroyList ( LIST list)
{
    POSITION trash;
    while ( !isEmptyList( list  ) ) {
        list = removeElementList ( list, &trash );
    }
}



boolean getElementList ( LIST list,  listElement* result, int position) {
    LIST_CELL current;
    int i = 1;

    if (isEmptyList(list)) {
        return false;
    }
    current = list.head;
    while (i<position && current!= NULL) {
        current = current->followingCell;
        i++;
    } if (current == NULL) {
        return false;
    }
    result->X = current->contents.X; 
    result->Y = current->contents.Y;
    return true;
}

boolean getNextElementList ( LIST list,  listElement* result, listElement* refElement) {
    LIST_CELL current;

    if (isEmptyList(list) || list.head == list.tail) {
        return false;
    }

    current = list.head;
    while (!compareElement(refElement, &(current->contents)) && current!= NULL) {
        current = current->followingCell;
    }
    if (current == NULL) {
        return false;
    }
    current = current->followingCell;
    result->X = current->contents.X; 
    result->Y = current->contents.Y;
    if (current == list.tail) {
        return false;
    }
    return true;
}

#ifndef DEBUG
void displaylist (LIST list) {
    POSITION sommet;
    boolean i;

    if (!isEmptyList(list)) {
        i = getElementList(list,&sommet, 0);
    }
    while (i)
    {
        i = getNextElementList(list, &sommet, &sommet);
    }

    while ( !isEmptyList(list))
    {
        list = removeElementList(list, &sommet);
    }
}
#endif
