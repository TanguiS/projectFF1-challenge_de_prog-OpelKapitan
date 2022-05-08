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
 * @version 1.0.0
 * @date 22 janvier 2022
 */

#include "lifo.h"

static CELL createCell ( lifoElement x );
static boolean destroyCell ( CELL cell );

LIFO createLifo () 
{
    LIFO newLifo;
    newLifo.head = NULL;
    return newLifo;
}

boolean isEmpty ( LIFO lifo )
{
    if ( lifo.head == NULL ) {
        return true;
    }
    return false;
}

static CELL createCell ( lifoElement x)
{
    CELL newCell;

    newCell =  ( CELL ) malloc ( sizeof ( _cell ) );
    newCell->contents[0] = x[0];
    newCell->contents[1] = x[1];
    newCell->followingCell = NULL;
    return newCell;
}

LIFO addElementLifo ( LIFO lifo, lifoElement x )
{
    CELL newCell;

    newCell = createCell ( x );
    if ( isEmpty ( lifo ) ) {
        lifo.head = newCell;
        return lifo;
    }
    newCell->followingCell = lifo.head;
    lifo.head = newCell;
    return lifo;
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

LIFO removeElementLifo ( LIFO lifo, lifoElement* result )
{
    CELL previousHead;
    
    if ( isEmpty ( lifo ) ) {
        return lifo;
    }
    result[0][0] = lifo.head->contents[0]; 
    result[0][1] = lifo.head->contents[1];
    previousHead = lifo.head;
    lifo.head = lifo.head->followingCell;
    destroyCell ( previousHead );
    return lifo;
}

void destroyLifo ( LIFO lifo )
{
    coord trash;
    while ( !isEmpty ( lifo ) ) {
        lifo = removeElementLifo ( lifo, &trash );
    }
}
