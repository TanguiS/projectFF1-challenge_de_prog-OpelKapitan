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
#include "pilotDirection.h"
#include "util.h"

typedef char element;

typedef struct dijkstra {
    short vertices;
    coord* shortestPath;

};

typedef struct _matrix {
    short width;
    short height;
    element** matrix;
} _matrix;
typedef struct _matrix MATRIX; 


#endif /* DIJKSTRA_ALGO_HH__ */