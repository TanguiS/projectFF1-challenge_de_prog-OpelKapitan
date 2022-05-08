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
 * @version 1.0.0
 * @date 22 janvier 2022
 */

#ifndef __FILE_H__
#define __FILE_H__

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "util.h"
#include "graphMadj.h"
#include "pilotManagement.h"
#include "pilotDirection.h"
#include "util.h"
#include "dijkstraMatrix.h"
#include "../include/dijkstraAlgo.h"


/* typedef coord fifo_element; */

typedef coord fifo_element;

typedef struct _cell {
    fifo_element contents;
    struct _cell* followingCell;
} _cell; typedef struct _cell *CELL;

typedef struct _file {
    CELL head;
    CELL tail;
} _file; typedef struct _file *FIFO;

FIFO createFile ();

boolean isEmpty ( FIFO file_to_test );

boolean thread ( FIFO file, fifo_element x );

fifo_element unthread ( FIFO file );

boolean displayFile ( FIFO file );

boolean destroyFile ( FIFO file );

FIFO copyFifo ( FIFO file );

boolean concatFile ( FIFO file_head, FIFO file_tail );

boolean destroyFileHeadTail ( FIFO file );

boolean idemFifo ( FIFO file_1, FIFO file_2 );



#endif /* __FILE_H__ */