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


/**
 * @brief Set result's values to reference.
 * 
 * @param reference The reference position.
 * @param result The result position.
 */
void mergePosition (POSITION* reference, POSITION* result );


/**
 * @brief Initialize the dijkstra matrix. It add the max value for every lenght(to simulate the infinity)
 * 
 * @param dijkstraMatrix The dijkstra matrix. Already created. 
 * @param first Coordinates of the first position.  
 */
void initDijkstraLength(dijkstraMatrix* dijkstraMatrix, POSITION first);


/**
 * @brief Find the position with the fewer length for a list of positions. 
 * 
 * @param dijkstra The dijkstra matrix. Place where are stocked position's length. 
 * @param sommet The position where whill be stocked the minimal coordonate. 
 * @param list list where the successors of already visited coordinates are stored
 */
void findMin(dijkstraMatrix* dijkstra, POSITION* sommet, LIST list );



void updateDistance(dijkstraMatrix* dijkstra, GRAPH* graph, POSITION sommet1, POSITION sommet2);


void addSuccessorListe(LIST* list, POSITION* succ, POSITION sommet,  short sizeSucc, dijkstraMatrix* dijkstra, GRAPH* graph);

void allPathDijkstra(dijkstraMatrix* dijkstra, GRAPH* graph, POSITION firstSommet);

void listGraphSucc(GRAPH*graph, dijkstraMatrix* dijkstra ,LIST* list, POSITION parent);

PATH_LIST givePath(dijkstraMatrix* dijkstra, GRAPH* graph, POSITION first);

#endif /* DIJKSTRA_ALGO_HH__ */