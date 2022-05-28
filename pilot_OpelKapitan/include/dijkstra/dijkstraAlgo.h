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
 * @file dijkstraAlgo.h
 * @brief This file contains the prototypes / declarations to implement the Dijstra's algo.
 * @author PICQUE Kylian <kylian.picque@ecole.ensicaen.fr>
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 2.5.0
 * @date 29 avril 2022
 */

#ifndef __DIJKSTRA_ALGO_HH__
#define __DIJKSTRA_ALGO_HH__

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "../graph.h"
#include "../pilotManagement.h"
#include "../tools/util.h"
#include "./dijkstraMatrix.h"
#include "../tools/pathList.h"
#include "../tools/list.h"

/**
 * @brief Give the shorter path to go on the nearest finish line
 * 
 * @param dijkstra The Dijkstra matrice. Juste created.
 * @param graph The graph of the race map.
 * @param firstNode The position of the pilot. The first node visited
 * @return PATH_LIST The path list where is stocked the path. The first element is the pilot position and the finish line.
 */
PATH_LIST pathToFollow(DIJKSTRA* dijkstra, GRAPH* graph, POSITION firstNode );

#endif /* DIJKSTRA_ALGO_HH__ */