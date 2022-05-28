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
 * @file dijkstraMatrix.h
 * @brief This file contains prototypes and declarations to manage a Dijkstra's matrix.
 * @author PICQUE Kylian <kylian.picque@ecole.ensicaen.fr>
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.0
 * @date 06 mai 2022
 */

#ifndef __DIJ_MATRIX_HH__
#define __DIJ_MATRIX_HH__

#include <limits.h>

#include "../tools/util.h"
#include "../graph.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Enumaration of a boolean type for the node inside the dijkstra matrix.
 */
typedef enum {
    white,                              /**< The node is not visited */
    gray,                               /**< The node is not visited but it is stocked in the list*/
    black                               /**< The node is visited */
} flagNode;  

/**
 * @brief An element of the dijkstra matrix
 */
typedef struct _elementDijkstra {
    POSITION predecessor;               /**< The predecessor of the current node  */
    short pathLength;                   /**< The length to arrive at the current node */
    flagNode flag;                      /**< The flag to know the status of the current node */
}elementdij;

/**
 * @brief The stucture to represent the dijkstraMatrix object.
 */
typedef struct _dijkstraMatrix {
    short width;                        /**< The width of the martix */
    short height;                       /**< The height of the matrix */
    elementdij** matrix;                /**< The matrix */
}DIJKSTRA;


/**
 * @brief Get the Width Dijkstra object.
 * 
 * @param dijkstra The dijkstra matrix.
 * @return short The width of the dijkstra matrix.
 */
short getWidthDijkstra(DIJKSTRA* dijkstra);

/**
 * @brief Get the Heigth Dijkstra object.
 * 
 * @param dijkstra The dijkstra matix.
 * @return short The heigth of the dijkstra matrix.
 */
short getHeigthDijkstra(DIJKSTRA* dijkstra);

/**
 * @brief Get the Element Dijkstra object
 * 
 * @param dijkstra The dijkstra matix.
 * @param x The column of the element.
 * @param y The line of the element.
 * @return elementdij The element of the matrix.
 */
elementdij getElementDijkstra(DIJKSTRA* dijkstra, short x, short y);

/**
 * @brief Get the Path Length object
 * 
 * @param dijkstra The dijkstra matix.
 * @param x The column of the element.
 * @param y The line of the element.
 * @return short The element's length.
 */
short getPathLength(DIJKSTRA* dijkstra, short x, short y);

/**
 * @brief Set the Path Length object
 * 
 * @param dijkstra The dijkstra matix.
 * @param x The column of the element.
 * @param y The line of the element.
 * @param newPathLength The length whith will be set for the element. 
 */
void setPathLength(DIJKSTRA* dijkstra, short x, short y, short newPathLength);

/**
 * @brief Set the Element Dijkstra object.
 * 
 * @param dijkstra The dijkstra matix.
 * @param x The column of the element.
 * @param y The line of the element.
 * @param values The element to set in the matrix.
 */
void setElementDijkstra(DIJKSTRA* dijkstra, short x, short y, elementdij values);

/**
 * @brief Set the Predecessor object
 * 
 * @param dijkstra The dijkstra matix.
 * @param x The column of the element.
 * @param y The line of the element.
 * @param newPredecessor The predecessor of the element. 
 */
void setPredecessor(DIJKSTRA* dijkstra, short x, short y, POSITION newPredecessor);

/**
 * @brief Get the Predecessor object
 * 
 * @param dijkstra The dijkstra matix.
 * @param x The column of the element.
 * @param y The line of the element.
 * @param result The precessor of the element.
 */
void getPredecessor(DIJKSTRA* dijkstra, short x, short y, POSITION* result);

/**
 * @brief Set the Flag object
 * 
 * @param dijkstra The dijkstra matix.
 * @param node The position of the element.
 * @param flag The futur status of the element.
 */
void setFlag ( DIJKSTRA* dijkstra, POSITION node, flagNode flag );

/**
 * @brief Tests if the element's flag is white.
 *
 * @param dijkstra The dijkstra matix.
 * @param nodeToTest The position of the element.
 * @return boolean The inform if the flag is white.
 */
boolean isNodeWhite ( DIJKSTRA* dijkstra, POSITION nodeToTest );

/**
 * @brief Tests if the element's flag is black.
 * 
 * @param dijkstra The dijkstra matix.
 * @param nodeToTest The position of the element.
 * @return boolean The inform if the flag is black.
 */
boolean isNodeBlack ( DIJKSTRA* dijkstra, POSITION nodeToTest );

/**
 * @brief Tests if the element's flag is gray.
 * 
 * @param dijkstra The dijkstra matix.
 * @param nodeToTest The position of the element.
 * @return boolean The inform if the flag is gray.
 */
boolean isNodeGray ( DIJKSTRA* dijkstra, POSITION nodeToTest );

/**
 * @brief Create a Dijkstra Matrix object
 * 
 * @param width The width of the matrix.
 * @param heigth The heigth of the matrix.
 * @return DIJKSTRA The dijkstra matrix created.
 */
DIJKSTRA createDijkstraMatrix(short width, short heigth);

/**
 * @brief Destroy and free the dijkstra matrix.
 * 
 * @param dijkstra The dijkstra matrix.
 */
void destroyDijkstraMatrix(DIJKSTRA dijkstra);

#endif 