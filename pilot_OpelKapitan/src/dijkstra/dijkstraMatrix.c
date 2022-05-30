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
 * @file dijkstraMatrix.c
 * @brief This file contains prototypes and declarations to manage a Dijkstra's matrix.
 * @author PICQUE Kylian <kylian.picque@ecole.ensicaen.fr>
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.0
 * @date 06 mai 2022
 */


#include "../../include/dijkstra/dijkstraMatrix.h"


short getWidthDijkstra(DIJKSTRA* dijkstra) {
    return dijkstra->width;
}

short getHeigthDijkstra(DIJKSTRA* dijkstra) {
    return dijkstra->height;
}


elementdij getElementDijkstra(DIJKSTRA* dijkstra, short x, short y) {
    return dijkstra->matrix[x][y];
}

void setElementDijkstra(DIJKSTRA* dijkstra, short x, short y, elementdij values) {
    setPathLength ( dijkstra, x, y, values.pathLength );
    setPredecessor ( dijkstra, x, y, values.predecessor );
}


short getPathLength(DIJKSTRA* dijkstra, short x, short y) {
    return dijkstra->matrix[x][y].pathLength;
}

void setPathLength(DIJKSTRA* dijkstra, short x, short y, short newPathLength) {
    dijkstra->matrix[x][y].pathLength = newPathLength;
}

void getPredecessor(DIJKSTRA* dijkstra, short x, short y, POSITION* result) {
    result->Y = dijkstra->matrix[x][y].predecessor.Y;
    result->X = dijkstra->matrix[x][y].predecessor.X;
}

void setPredecessor(DIJKSTRA* dijkstra, short x, short y, POSITION newPredecessor) {
    dijkstra->matrix[x][y].predecessor.X = newPredecessor.X;
    dijkstra->matrix[x][y].predecessor.Y = newPredecessor.Y;
}

void setFlag ( DIJKSTRA* dijkstra, POSITION node, flagNode flag )
{
    dijkstra->matrix[node.X][node.Y].flag = flag;
}

boolean isNodeWhite ( DIJKSTRA* dijkstra, POSITION nodeToTest )
{
    return dijkstra->matrix[nodeToTest.X][nodeToTest.Y].flag == white;
}

boolean isNodeBlack ( DIJKSTRA* dijkstra, POSITION nodeToTest )
{
    return dijkstra->matrix[nodeToTest.X][nodeToTest.Y].flag == black;
}

boolean isNodeGray ( DIJKSTRA* dijkstra, POSITION nodeToTest )
{
    return dijkstra->matrix[nodeToTest.X][nodeToTest.Y].flag == gray;
}

DIJKSTRA createDijkstraMatrix(short width, short heigth) {
    int i;

    DIJKSTRA dijkstra;
    dijkstra.height = heigth;
    dijkstra.width = width;
    dijkstra.matrix = (elementdij**)malloc(width*sizeof(elementdij*));
    for (i=0; i<width; i++) {
        dijkstra.matrix[i] = (elementdij*)malloc(heigth*sizeof(elementdij));
    }
    return dijkstra;
}

void destroyDijkstraMatrix(DIJKSTRA dijkstra) {
    int i;

    for (i=0; i<getWidthDijkstra(&dijkstra); i++) {
        free(dijkstra.matrix[i]);
    }
    free(dijkstra.matrix);
}