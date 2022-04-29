/**
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */

/**
 * @file graph.h
 * @brief This file contains the prototypes / declarations used to choose the pilot's direction.
 */

/**
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.0
 * @date 19 avril 2022
 */

#ifndef __GRAPH_M_ADJ_H__
#define __GRAPH_M_ADJ_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include "util.h"
#include "debugMode.h"

#define SIZE_COORD 2

#define SIZE_TAB_FINISH_LINE 100

typedef char element;

typedef short coord[SIZE_COORD];

typedef enum {
    roadGraph = 1,
    wallGraph = 0,
    finishLineGraph = 1,
    sandGraph = 5,
    carGraph = 0
} graphValues;

typedef struct _mAdj {
    short width;
    short height;
    char sizeFinishLine;
    coord finishLineCoord[SIZE_TAB_FINISH_LINE];
    coord closestFinishLine;
    element** graph;
} _mAdj;
typedef struct _mAdj GRAPH;

short getWidthGraph ( GRAPH* graph );

short getHeightGraph ( GRAPH* graph );

char getSizeFinishLine ( GRAPH* graph );

void getCoordFinishLine ( GRAPH* graph, short indice, coord* result );

void getClosestFinishLine ( GRAPH* graph, coord* result );

element getElementGraph ( GRAPH* graph, short x, short y );

GRAPH createGraph ( short width, short height );

void updateGraph ( GRAPH* graph, coord myPilot, coord secoundPilot, coord thirdPilot );

void updateCoordFinishLine ( GRAPH* graph, coord newFinishLine, int index );

#ifndef DEBUG
void displayGraph ( GRAPH* graph );
#endif




boolean destroyGraph ( GRAPH graphToDestoy );



#endif /* __GRAPH_M_ADJ_H__ */