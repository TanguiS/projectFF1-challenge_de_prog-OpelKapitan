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
 * @file main_dikstra.c
 * @brief This is used to test Disktra algo.
 */

/**
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.0
 * @date 3 mai 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include "../../include/dijkstraAlgo.h"
#include "../../include/dijkstraMatrix.h"
#include "../../include/graphMadj.h"
#include "../../include/lifo.h"

#define X 10
#define Y 12
#define X_SMALL 3
#define Y_SMALL 4

const short smallGraph[X_SMALL][Y_SMALL] = 
            { { 1, 0, 1, 0 },
              { 1, 1, 1, 1 },
              { 1, 0, 1, 0 },
            };

const short graphNSand[X][Y] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
                                 { 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
                                 { 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0 },
                                 { 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0 },
                                 { 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0 },
                                 { 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1 },
                                 { 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1 },
                                 { 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1 },
                                 { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1 },
                                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0 }
                               };

const short graphWSand[X][Y] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
                                 { 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 },
                                 { 0, 0, 0, 1, 0, 1, 1, 2, 2, 2, 0, 0 },
                                 { 0, 0, 1, 1, 0, 0, 1, 1, 1, 2, 1, 0 },
                                 { 0, 1, 1, 2, 0, 0, 0, 0, 0, 0, 1, 0 },
                                 { 0, 1, 1, 2, 0, 0, 1, 1, 1, 0, 1, 1 },
                                 { 0, 1, 1, 2, 0, 0, 1, 1, 1, 1, 1, 1 },
                                 { 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1 },
                                 { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1 },
                                 { 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0 }
                               };

const short coordStart[SIZE_COORD] = { 7, 2 };
const short coordEnd[SIZE_COORD] = { 7, 6 };
const short coordStartSmall[SIZE_COORD] = {2, 0};
const short coordEndSmall[SIZE_COORD] = {2, 2};

int main ( void )
{
    int i, j;
    GRAPH graph = createGraph ( Y_SMALL, X_SMALL );
    dijkstraMatrix dij = createDijkstraMatrix ( Y_SMALL, X_SMALL );
    LIFO stack;

    printf ( "depart value  : %d\n", smallGraph[coordStart[0]][coordStart[1]] );
    printf ( "end value     : %d\n", smallGraph[coordEnd[0]][coordEnd[1]] );

    for ( i = 0; i < getHeightGraph ( &graph ); i++ ) {
        for ( j = 0; j < getWidthGraph ( &graph ); j++ ) {
            graph.graph.matrix[j][i] = (element)smallGraph[i][j];
        }
    }
    graph.closestFinishLine[0] = coordEnd[1];
    graph.closestFinishLine[1] = coordEnd[0];
    displayGraph ( &graph );
    printf ( "end value vue du graph : %d, %d\n", graph.closestFinishLine[0], graph.closestFinishLine[1] );

    displayDijkstraMatrix ( &dij );

    stack = givePath ( &dij, &graph, coordEndSmall[0], coordEndSmall[1], coordStartSmall[0], coordStartSmall[1] );


    displayDijkstraMatrix ( &dij );




    destroyDijkstraMatrix ( dij );
    destroyGraph ( graph );
    return EXIT_SUCCESS;
}