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
 * @file pathList.c
 * @brief This file contains all the functions of the path list algo.
 * @author PICQUE Kylian <kylian.picque@ecole.ensicaen.fr>
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 2.0.2
 * @date 22 janvier 2022
 */

#include "../../include/tools/pathList.h"

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

path_list_element getNextCurrentPathList ( PATH_LIST list )
{
    static path_list_element tmp = {-1, -1};
    if ( list.current->followingCell == NULL ) {
        return tmp;
    }
    return list.current->followingCell->contents;
}

boolean currentEqualsHead ( PATH_LIST list )
{
    return list.current == list.head;
}

path_list_element examineHeadPathList ( PATH_LIST list )
{
    return list.head->contents;
}

PATH_LIST moveCurrentPathList ( PATH_LIST list )
{
    if ( list.current->followingCell == NULL ) {
        list.current = NULL;
        return list;
    }
    list.current = list.current->followingCell;
    return list;
}

boolean isCurrentNull ( PATH_LIST list )
{
    return list.current == NULL;
}

path_list_element getCurrentPathListElement ( PATH_LIST list )
{
    static path_list_element tmp = {-1, -1};
    if ( list.current == NULL ) {
        return tmp;
    }
    return list.current->contents;
}

void destroyPathList ( PATH_LIST list )
{
    path_list_element trash;
    while ( !isEmptyPathList ( list ) ) {
        list = removeHeadElementPathList ( list, &trash );
    }
}