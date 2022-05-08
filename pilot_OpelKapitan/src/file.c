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
 * @file file.c
 * @brief This file contains all the functions of the file algo.
 */

/**
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.0
 * @date 22 janvier 2022
 */

#include "file.h"

static CELL createCell ( fifo_element x );
static boolean destroyCell ( CELL cell );
static boolean displayCell ( CELL cell );
boolean destroyFileHeadTail ( FIFO file );

FIFO createFile () 
{
    FIFO file_to_create = NULL;

    file_to_create = ( FIFO ) malloc ( 2 * sizeof ( CELL ) );

    file_to_create->head = NULL;
    file_to_create->tail = NULL;

    return file_to_create;
}

boolean isEmpty ( FIFO file_to_test )
{

    assert ( file_to_test );

    if ( file_to_test->head == NULL && file_to_test->tail == NULL ) {
        return true;
    }
    return false;
}

static CELL createCell ( fifo_element x)
{
    CELL cell_to_create;

    cell_to_create =  ( CELL ) malloc ( sizeof ( _cell ) );

    cell_to_create->contents = x;
    cell_to_create->followingCell = NULL;

    return cell_to_create;
}

boolean thread ( FIFO file, fifo_element x )
{
    CELL new_cell;
    CELL save_cell;

    if ( file != NULL ) {
        new_cell = createCell ( x );
        if ( isEmpty ( file ) ) {
            file->head = new_cell;
            file->tail = new_cell;
        } else {
            save_cell = file->tail;
            file->tail = new_cell;
            save_cell->followingCell = file->tail;
        }
        return true;
    }
    return false;
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

fifo_element unthread ( FIFO file )
{
    CELL old_head;
    fifo_element x;

    if ( isEmpty ( file ) == false ) {
        x = file->head->contents;
        old_head = file->head;
        file->head = file->head->followingCell;
        destroyCell ( old_head );
        if ( file->head == NULL ) {
            file->tail = NULL;
        }
        return x;
    }
    return x;
}


static boolean displayCell ( CELL cell )
{
    if ( cell != NULL ) {
        printf ( "[ %d ]", cell->contents.root->contents );
        return true;
    }
    return false;
}

boolean displayFile ( FIFO file )
{
    CELL display_cell;
    if ( isEmpty ( file ) == false ) {
        display_cell = file->head;
        printf ( "[" );
        while ( displayCell ( display_cell ) ) {
            display_cell = display_cell->followingCell;
        }
        printf ( "]\n" );
        return true;
    } 
    return false;
}


boolean destroyFileHeadTail ( FIFO file )
{
    if ( file != NULL ) {
        free ( file );
        file = NULL;
        return true;
    }
    return false;
}

boolean destroyFile ( FIFO file )
{
    if ( file != NULL ) {

        while ( isEmpty ( file ) == false ) {
            unthread ( file );
        }
        return true;
    }
    return false;
}

FIFO copyFifo ( FIFO file )
{
    CELL cell_copied;
    FIFO file_copied;

    file_copied = createFile ();
    

    if ( isEmpty ( file ) ) {
        return file_copied;
    } else {
        cell_copied = file->head;
        while ( cell_copied != NULL ) {
            thread ( file_copied, cell_copied->contents );
            cell_copied = cell_copied->followingCell;
        }
    }
    return file_copied;
}

boolean concatFile ( FIFO file_head, FIFO file_tail )
{

    if ( file_head == NULL || file_tail == NULL ) {
        return false;
    }

    if ( isEmpty ( file_head ) ) {
        if ( isEmpty ( file_tail ) == false ) {
            file_head->head = file_tail->head;
            file_head->tail = file_tail->tail;
            return true;
        } else {
            return true;
        }
    }

    file_head->tail->followingCell = file_tail->head;
    file_head->tail = file_tail->tail;

    return true;
}
