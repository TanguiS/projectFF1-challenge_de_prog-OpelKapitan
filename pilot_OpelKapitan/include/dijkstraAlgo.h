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
 * @param DIJKSTRA The dijkstra matrix. Already created. 
 * @param firstNode Coordinates of the firstNode position.  
 */
void initDijkstra(DIJKSTRA* DIJKSTRA, POSITION firstNode, POSITION parentNode);


/**
 * @brief Find the position with the fewer length for a successors of positions. 
 * 
 * @param dijkstra The dijkstra matrix. Place where are stocked position's length. 
 * @param minimalNode The position where whill be stocked the minimal coordonate. 
 * @param successors successors where the successors of already visited coordinates are stored
 */
void findNodeWithMinimalLength(DIJKSTRA* dijkstra, POSITION* minimalNode, LIST successors );



void updateLengthNodes(DIJKSTRA* dijkstra, GRAPH* graph, POSITION parentNode, POSITION successorNode);


void addSuccessorToList(LIST* successors, POSITION* successorNode, POSITION minimalNode,  short sizeSuccesor, DIJKSTRA* dijkstra, GRAPH* graph);


void redirectorToProcessSuccessor(GRAPH*graph, DIJKSTRA* dijkstra ,LIST* successors, POSITION parentNode);

void executeDijkstra(DIJKSTRA* dijkstra, GRAPH* graph, POSITION firstNode, POSITION parentNode);


PATH_LIST pathToFollow(DIJKSTRA* dijkstra, GRAPH* graph, POSITION firstNode, POSITION parentNode );

#endif /* DIJKSTRA_ALGO_HH__ */