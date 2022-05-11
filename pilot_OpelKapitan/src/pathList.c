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
 * @list list.c
 * @brief This list contains all the functions of the list algo.
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
static CELL createCell ( path_list_element value );
/**
 * @brief Destroy a Cell object
 * 
 * @param cell : the cell to destroy
 * @return boolean 
 */
static boolean destroyCell ( CELL cell );

static CELL createCell ( path_list_element value )
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

boolean isEmptyPathList ( PATH_LIST list )
{
    if ( list.head == NULL ) {
        return true;
    }
    return false;
}

PATH_LIST addHeadElementPathList ( PATH_LIST list, path_list_element value )
{
    CELL newCell;

    newCell = createCell ( value );
    if ( isEmptyPathList ( list ) ) {
        list.head = newCell;
        list.current = list.head;
        return list;
    }
    newCell->followingCell = list.head;
    list.head = newCell;
    return list;
}

PATH_LIST removeHeadElementPathList ( PATH_LIST list, path_list_element* result )
{
    CELL previousHead;
    
    if ( isEmptyPathList ( list ) ) {
        return list;
    }
    result->X = list.head->contents.X;
    result->Y = list.head->contents.Y;
    previousHead = list.head;
    list.head = list.head->followingCell;
    destroyCell ( previousHead );
    return list;
}

PATH_LIST resetCurrentPathList ( PATH_LIST list )
{
    list.current = list.head;
    return list;
}

PATH_LIST nextElementPathList ( PATH_LIST list, path_list_element* result )
{
/*     if ( list.current == NULL ) {
        list = resetCurrentPathList ( list );
        result = &(list.head->contents);
        return list;
    } */
    result = &(list.current->followingCell->contents);
    return list;
}

boolean currentEqualsHead ( PATH_LIST list )
{
    return list.current == list.head;
}

path_list_element* getCurrentPathList ( PATH_LIST list )
{
    return &(list.current->contents);
}

void destroyPathList ( PATH_LIST list )
{
    path_list_element* trash = NULL;
    while ( !isEmptyPathList ( list ) ) {
        list = removeHeadElementPathList ( list, trash );
    }
}
