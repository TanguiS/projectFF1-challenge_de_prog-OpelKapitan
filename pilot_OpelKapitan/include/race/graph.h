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
 * @file graph.h
 * @brief This file contains the prototypes / declarations used to process a graph.
 * @author PICQUE Kylian <picque.kylian@ecole.ensicaen.fr>
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.2
 * @date 19 avril 2022
 */

#ifndef __GRAPH_M_ADJ_H__
#define __GRAPH_M_ADJ_H__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <math.h>
#include "./tools/matrix.h"
#include "./tools/util.h"
#include "./tools/list.h"

#define SIZE_TAB_FINISH_LINE 100                            /**< the size of the finish line tab */

/**
 * @brief Declaration of the graph's values enumeration 
 */
typedef enum {
    wallGraph           = 0,                                /**< the value of a wall in the graph */
    carGraph            = 0,                                /**< the value of a car in the graph */
    roadGraph           = 1,                                /**< the value of the road in the graph */
    finishLineGraph     = 1,                                /**< the value of the finish line in the graph */
    aroundCarGraph      = 1,                                /**< the value around an opposite car in the graph */
    sandGraph           = 3                                 /**< the value of the sand in the graph */
} graphValues;

/**
 * @brief Declaration of a structure for a graph object 
 */
typedef struct _mAdj {
    char sizeFinishLine;                                    /**< the number of finish line */
    POSITION finishLineCoord[SIZE_TAB_FINISH_LINE];         /**< the finish line tab */
    POSITION closestFinishLine;                             /**< the closest finish to our driver */
    MATRIX graph;                                           /**< the matrix of our graph */
} _mAdj;
/**
 * @brief Declaration of the GRAPH object 
 */
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

/**
 * @brief If the element is a road
 * 
 * @param graph the graph of the race
 * @param coord the coordinate to test
 * @return boolean true if it is a road
 */
boolean isSand ( GRAPH* graph, POSITION coord );

/**
 * @brief If the element is sand
 * 
 * @param graph the graph of the race
 * @param coord the coordinate to test
 * @return boolean true if it is sand
 */
boolean isRoad ( GRAPH* graph, POSITION coord );

/**
 * @brief If the element is a car
 * 
 * @param graph the graph of the race
 * @param coord the coordinate to test
 * @return boolean true if it is a car
 */
boolean isCar ( GRAPH* graph, POSITION coord );

/**
 * @brief If the element is a wall
 * 
 * @param graph the graph of the race
 * @param coord the coordinate to test
 * @return boolean true if it is a wall
 */
boolean isWall ( GRAPH* graph, POSITION coord );

/**
 * @brief If the element is arround a car.
 * 
 * @param graph the graph of the race.
 * @param coord the coordinate to test.
 * @return boolean true if it is around a car.
 */
boolean isAroundCar ( GRAPH* graph, POSITION coord );

/**
 * @brief If the coordinate is in the matrix
 * 
 * @param graph the graph of the race 
 * @param x the x-axis
 * @param y the y-axis
 * @return boolean true if the coordinate is inside the matrix
 */
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
 * @brief Update the graph according to the coordinate of the opposite car
 * 
 * @param graph the graph of the race
 * @param secoundPilot the position of the second pilot
 * @param thirdPilot the position of the third pilot
 * @param previousSecound the table to follow
 * @param previousThird the table to follow
 */
void updateGraph ( 
                    GRAPH* graph, POSITION secoundPilot, 
                    POSITION thirdPilot, POSITION previousSecound[5], 
                    POSITION previousThird[5] 
                 );

/**
 * @brief Reverse the operation of the updateGraph function
 * 
 * @param graph the graph of the race
 * @param referenceGraph the reference graph of the race, unchanged one
 * @param previousSecound the table to follow
 * @param previousThird the table to follow
 */
void reverseGraph ( 
                    GRAPH* graph, GRAPH* referenceGraph, 
                    POSITION previousSecound[5], POSITION previousThird[5] 
                  );

/**
 * @brief Update the Finish Line object from a graph
 * 
 * @param graph the graph of the race
 * @param newFinishLine a position to add
 * @param index the index of the new finish line
 */
void updateCoordFinishLine ( GRAPH* graph, POSITION newFinishLine, int index );

/**
 * @brief Update the closest finish line according to out pilot position
 * 
 * @param graph the graph of the race
 * @param pilotPosition the current pilot position
 */
void updateClosetFinishLine ( GRAPH* graph, POSITION pilotPosition );

/**
 * @brief Destroy a Graph object
 * 
 * @param graphToDestoy 
 */
void destroyGraph (GRAPH graphToDestoy );

#endif /* __GRAPH_M_ADJ_H__ */