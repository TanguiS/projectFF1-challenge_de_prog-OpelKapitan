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


/* typedef coord lifoElement; */

typedef coord lifoElement;

typedef struct _cell {
    lifoElement contents;
    struct _cell* followingCell;
} _cell; typedef struct _cell *CELL;

typedef struct _lifo {
    CELL head;
} _lifo; typedef struct _lifo LIFO;

LIFO createLifo ();

boolean isEmpty ( LIFO lifo );

LIFO addElementLifo ( LIFO file, lifoElement x );

LIFO removeElementLifo ( LIFO file, lifoElement* result );

void destroyLifo ( LIFO file );

#endif /* __FILE_H__ */