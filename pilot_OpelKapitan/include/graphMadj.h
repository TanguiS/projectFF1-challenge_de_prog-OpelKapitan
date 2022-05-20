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
#include "list.h"

#define SIZE_TAB_FINISH_LINE 100

typedef enum {
    roadGraph = 1,
    wallGraph = 0,
    finishLineGraph = 1,
    sandGraph = 3,
    carGraph = 0,
    aroundCarGraph = 2
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
 * @return short : the width of a Graph object
 */
short getWidthGraph ( GRAPH* graph );

/**
 * @brief Get the Height Graph object
 * 
 * @param graph 
 * @return short : the height of a Graph object
 */
short getHeightGraph ( GRAPH* graph );

/**
 * @brief Get the Size Finish Line object
 * 
 * @param graph 
 * @return char : the number of finish line in the Graph object
 */
char getSizeFinishLine ( GRAPH* graph );

/**
 * @brief Get the Coord Finish Line object
 * 
 * @param graph 
 * @param index : the index of the finish line wanted
 * @param result : the position of the finish line
 */
void getCoordFinishLine ( GRAPH* graph, short index, POSITION* result );

/**
 * @brief Get the Closest Finish Line object
 * 
 * @param graph 
 * @param result : The position of the closest finish line 
 */
void getClosestFinishLine ( GRAPH* graph, POSITION* result );

boolean isSand ( GRAPH* graph, POSITION coord );

boolean isRoad ( GRAPH* graph, POSITION coord );

boolean isCar ( GRAPH* graph, POSITION coord );

boolean isWall ( GRAPH* graph, POSITION coord );

boolean isInGraph ( GRAPH* graph, short x, short y );


/**
 * @brief Get the Element Graph object
 * 
 * @param graph 
 * @param coord : the position of the element wanted
 * @return element 
 */
element getElementGraph ( GRAPH* graph, POSITION coord );

/**
 * @brief Set the Element Graph object
 * 
 * @param graph 
 * @param value : the value to insert
 * @param x : the x-axis coordinate
 * @param y  : the y-axis coordinate
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
 * @brief Update the cases of the opposite cars
 * 
 * @param graph 
 * @param myPilot 
 * @param secoundPilot 
 * @param thirdPilot 
 */
void updateGraph ( GRAPH* graph, POSITION myPilot, POSITION secoundPilot, POSITION thirdPilot, POSITION previousSecound[5], POSITION previousThird[5] );

void reverseGraph ( GRAPH* graph, GRAPH* referenceGraph, POSITION previousSecound[5], POSITION previousThird[5] );

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