/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This lifo is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */

/**
 * @lifo lifo.c
 * @brief This lifo contains all the functions of the lifo algo.
 */

/**
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.2
 * @date 22 janvier 2022
 */

#include "pathList.h"

/**
 * @brief Create a Cell object
 * 
 * @param value : the new element 
 * @return CELL 
 */
static CELL createCell ( pathListElement value );
/**
 * @brief Destroy a Cell object
 * 
 * @param cell : the cell to destroy
 * @return boolean 
 */
static boolean destroyCell ( CELL cell );

static CELL createCell ( pathListElement value )
{
    CELL newCell;

    newCell =  ( CELL ) malloc ( sizeof ( _cell ) );
    newCell->contents.X = value.X;
    newCell->contents.Y = value.Y;
    newCell->followingCell = NULL;
    return newCell;
}

static boolean destroyCell ( CELL cell )
{
    if ( cell != NULL ) {
        free ( cell );
        cell = NULL;
        return true;
    }
    return false;
}

PATH_LIST createPathList () 
{
    PATH_LIST newLifo;
    newLifo.head = NULL;
    newLifo.current = NULL;
    return newLifo;
}

boolean isEmptyPathList ( PATH_LIST lifo )
{
    if ( lifo.head == NULL ) {
        return true;
    }
    return false;
}

PATH_LIST addElementPathList ( PATH_LIST lifo, pathListElement value )
{
    CELL newCell;

    newCell = createCell ( value );
    if ( isEmptyPathList ( lifo ) ) {
        lifo.head = newCell;
        lifo.current = lifo.head;
        return lifo;
    }
    newCell->followingCell = lifo.head;
    lifo.head = newCell;
    return lifo;
}

PATH_LIST removeHeadElementPathList ( PATH_LIST lifo, pathListElement* result )
{
    CELL previousHead;
    
    if ( isEmptyPathList ( lifo ) ) {
        return lifo;
    }
    result->X = lifo.head->contents.X;
    result->Y = lifo.head->contents.Y;
    previousHead = lifo.head;
    lifo.head = lifo.head->followingCell;
    destroyCell ( previousHead );
    return lifo;
}

PATH_LIST resetCurrentPathList ( PATH_LIST list )
{
    list.current = list.head;
    return list;
}

PATH_LIST nextElementPathList ( PATH_LIST list, pathListElement* result )
{
    if ( list.current == NULL ) {
        list = resetCurrentPathList ( list );
        result->X = list.current->contents.X;
        result->Y = list.current->contents.Y;
        return list;
    }
    result->X = list.current->followingCell->contents.X;
    result->Y = list.current->followingCell->contents.Y;
    return list;
}

void destroyPathList ( PATH_LIST lifo )
{
    pathListElement* trash;
    while ( !isEmptyPathList ( lifo ) ) {
        lifo = removeHeadElementPathList ( lifo, trash );
    }
}
