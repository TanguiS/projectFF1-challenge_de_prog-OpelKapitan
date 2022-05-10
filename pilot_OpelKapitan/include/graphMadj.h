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
#include "matrix.h"
#include "util.h"
#include "debugMode.h"

#define SIZE_TAB_FINISH_LINE 100

typedef enum {
    roadGraph = 1,
    wallGraph = 0,
    finishLineGraph = 1,
    sandGraph = 5,
    carGraph = 0
} graphValues;

typedef struct _mAdj {
    char sizeFinishLine;
    POSITION finishLineCoord[SIZE_TAB_FINISH_LINE];
    POSITION closestFinishLine;
    MATRIX graph;
} _mAdj;
typedef struct _mAdj GRAPH;

/**
 * @brief Get the Width Graph object
 * 
 * @param graph 
 * @return short 
 */
short getWidthGraph ( GRAPH* graph );

/**
 * @brief Get the Height Graph object
 * 
 * @param graph 
 * @return short 
 */
short getHeightGraph ( GRAPH* graph );

/**
 * @brief Get the Size Finish Line object
 * 
 * @param graph 
 * @return char 
 */
char getSizeFinishLine ( GRAPH* graph );

/**
 * @brief Get the Coord Finish Line object
 * 
 * @param graph 
 * @param indice 
 * @param result 
 */
void getCoordFinishLine ( GRAPH* graph, short indice, POSITION result );

/**
 * @brief Get the Closest Finish Line object
 * 
 * @param graph 
 * @param result 
 */
void getClosestFinishLine ( GRAPH* graph, POSITION* result );
/* 
coord* getSuccessorGraph ( GRAPH* graph, POSITION );
 */


element getElementGraph ( GRAPH* graph, POSITION coord );

/**
 * @brief Set the Element Graph object
 * 
 * @param graph 
 * @param value 
 * @param x 
 * @param y 
 */
void setElementGraph ( GRAPH* graph, element value, short x, short y );

/**
 * @brief Create a Graph object
 * 
 * @param width 
 * @param height 
 * @return GRAPH 
 */
GRAPH createGraph ( short width, short height );

/**
 * @brief Update a Graph object
 * 
 * @param graph 
 * @param myPilot 
 * @param secoundPilot 
 * @param thirdPilot 
 */
void updateGraph ( GRAPH* graph, POSITION myPilot, POSITION secoundPilot, POSITION thirdPilot );

/**
 * @brief Update the Finish Line object from a graph
 * 
 * @param graph 
 * @param newFinishLine 
 * @param index 
 */
void updateCoordFinishLine ( GRAPH* graph, POSITION newFinishLine, int index );

#ifndef DEBUG
void displayGraph ( GRAPH* graph );
#endif

/**
 * @brief Destroy a Graph object
 * 
 * @param graphToDestoy 
 */
void destroyGraph (GRAPH graphToDestoy );



#endif /* __GRAPH_M_ADJ_H__ */