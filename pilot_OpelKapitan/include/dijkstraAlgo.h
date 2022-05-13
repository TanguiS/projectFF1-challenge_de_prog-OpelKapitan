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
 * @file dijkstraAlgo.h
 * @brief This file contains the prototypes / declarations to implement the Dijstra's algo.
 */

/**
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.0
 * @date 29 avril 2022
 */

#ifndef __DIJKSTRA_ALGO_HH__
#define __DIJKSTRA_ALGO_HH__

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graphMadj.h"
#include "pilotManagement.h"
#include "util.h"
#include "dijkstraMatrix.h"
#include "pathList.h"
#include "list.h"


void initDijkstraLenght(dijkstraMatrix* dijkstraMatrix, short x, short y);


void mixeCoord (coord* reference, coord* result );


void findMin(dijkstraMatrix* dijkstra, coord* sommet, LIST list );

void updateDistance(dijkstraMatrix* dijkstra, GRAPH* graph, coord sommet1, coord sommet2);


void addSuccessorListe(LIST* list, coord* succ, coord sommet,  short sizeSucc, dijkstraMatrix* dijkstra, GRAPH* graph);

void allPathDijkstra(dijkstraMatrix* dijkstra, GRAPH* graph, coord firstSommet);

LIFO givePath(dijkstraMatrix* dijkstra, GRAPH* graph, short firstx, short firsty, short finalx, short finaly);

#endif /* DIJKSTRA_ALGO_HH__ */