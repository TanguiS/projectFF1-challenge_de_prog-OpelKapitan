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
#include "../../include/pathList.h"
#include "../../include/list.h"

#define X_GIANT 10
#define Y_GIANT 12
#define X_SMALL 3
#define Y_SMALL 4
#define X_MID 7
#define Y_MID 8

const short smallGraph[X_SMALL][Y_SMALL] = 
            { { 0, 0, 0, 0 },
              { 1, 1, 1, 1 },
              { 1, 1, 1, 0 },
            };

const short midGraph[X_MID][Y_MID] = 
            {
                { 0, 0, 0, 0, 0, 0, 0, 0 },
                { 0, 1, 1, 1, 0, 1, 0, 0 },
                { 0, 1, 1, 1, 1, 1, 1, 1 },
                { 0, 1, 1, 0, 0, 1, 1, 1 },
                { 0, 0, 0, 0, 1, 1, 0, 1 },
                { 0, 1, 1, 1, 1, 1, 1, 1 },
                { 0, 0, 0, 0, 0, 1, 1, 1 }
            };

const short graphNSand[X_GIANT][Y_GIANT] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
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

const short graphWSand[X_GIANT][Y_GIANT] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
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

const short coordStart[] = { 2, 7 };
const short coordEnd[] = { 6, 7 };
const short coordStartSmall[] = {0, 2};
const short coordEndSmall[] = {3, 1};
const short coordStartMid[] = {1, 2};
const short coordEndMid[] = {1, 5};

int main ( void )
{
    POSITION path[1000];
    int count = 0;
/*     int i, j;
    GRAPH graph = createGraph ( Y_MID, X_MID );
    dijkstraMatrix dij = createDijkstraMatrix ( Y_MID, X_MID );
    PATH_LIST stack;
    lifoElement result;
    printf ( "depart value  : %d\n", midGraph[coordStartMid[1]][coordStartMid[0]] );
    printf ( "end value     : %d\n", midGraph[coordEndMid[1]][coordEndMid[0]] );
    for ( i = 0; i < getHeightGraph ( &graph ); i++ ) {
        for ( j = 0; j < getWidthGraph ( &graph ); j++ ) {
            graph.graph.matrix[j][i] = (element)midGraph[i][j];
        }
    }
    graph.closestFinishLine[0] = coordEndSmall[0];
    graph.closestFinishLine[1] = coordEndSmall[1];
    displayGraph ( &graph );
    displayDijkstraMatrix ( &dij, -1, -1 );
    stack = givePath ( &dij, &graph, coordStartMid[0], coordStartMid[1], coordEndMid[0], coordEndMid[1] );
    displayDijkstraMatrix ( &dij, -1, -1 );
    printf ( "\n\n" );
    while ( !isEmpty ( stack ) ) {
        stack = removeElementLifo ( stack, &result );
        printf ( "[%d, %d] ", result[0], result[1] );
    }
    printf ( "\n" );
    destroyDijkstraMatrix ( dij );
    destroyGraph ( graph ); */

    /**
     * @brief Gran graph sans sable : 
     */

/*     int i, j;
    GRAPH graph = createGraph ( Y, X );
    dijkstraMatrix dij = createDijkstraMatrix ( Y, X );
    PATH_LIST stack;
    lifoElement result;
    printf ( "depart value  : %d\n", midGraph[coordStart[1]][coordStart[0]] );
    printf ( "end value     : %d\n", midGraph[coordEnd[1]][coordEnd[0]] );
    for ( i = 0; i < getHeightGraph ( &graph ); i++ ) {
        for ( j = 0; j < getWidthGraph ( &graph ); j++ ) {
            graph.graph.matrix[j][i] = (element)graphNSand[i][j];
        }
    }
    graph.closestFinishLine[0] = coordEndSmall[0];
    graph.closestFinishLine[1] = coordEndSmall[1];
    displayGraph ( &graph );
    displayDijkstraMatrix ( &dij, -1, -1 );
    stack = givePath ( &dij, &graph, coordStart[0], coordStart[1], coordEnd[0], coordEnd[1] );
    displayDijkstraMatrix ( &dij, -1, -1 );
    printf ( "\n\n" );
    while ( !isEmpty ( stack ) ) {
        stack = removeElementLifo ( stack, &result );
        printf ( "[%d, %d] ", result[0], result[1] );
    }
    printf ( "\n" );
    destroyDijkstraMatrix ( dij );
    destroyGraph ( graph ); */

        /**
     * @brief Gran graph sans sable : 
     */

    int i, j;
    GRAPH graph = createGraph ( Y_GIANT, X_GIANT );
    dijkstraMatrix dij = createDijkstraMatrix ( Y_GIANT, X_GIANT     );
    PATH_LIST stack;
    /*lifoElement result;*/
    LIST list;
    POSITION sommetTest;
    list = createList();
    
    /*
    printf ( "depart value  : %d\n", midGraph[coordStart[1]][coordStart[0]] );
    printf ( "end value     : %d\n", midGraph[coordEnd[1]][coordEnd[0]] );

    for ( i = 0; i < getHeightGraph ( &graph ); i++ ) {
        for ( j = 0; j < getWidthGraph ( &graph ); j++ ) {
            graph.graph.matrix[j][i] = (element)graphNSand[i][j];
        }
    }
    graph.closestFinishLine[0] = coordEndSmall[0];
    graph.closestFinishLine[1] = coordEndSmall[1];
    displayGraph ( &graph );
    displayDijkstraMatrix ( &dij, -1, -1 );
    stack = givePath ( &dij, &graph, coordStart[0], coordStart[1], coordEnd[0], coordEnd[1] );

    displayDijkstraMatrix ( &dij, -1, -1 );
    printf ( "\n\n" );
    
    while ( !isEmpty ( stack ) ) {
        stack = removeElementLifo ( stack, &result );
        printf ( "[%d, %d] ", result[0], result[1] );
        path[count][0] = result[0];
        path[count][1] = result[1];
        count++;
    }
    printf ( "\n" );
    displayDijkstraMatrixPath ( &dij, count, path );*/
    
    printf("\n\ntests de la liste\n");
    sommetTest.X = 2;
    sommetTest.Y = 3;
    list = addElementList(list, sommetTest);
    sommetTest.X = 4;
    sommetTest.Y = 6;
    list = addElementList(list, sommetTest);
    sommetTest.X = 8;
    sommetTest.Y = 9;
    list = addElementList(list, sommetTest);

    displaylist(list);
    


    destroyDijkstraMatrix ( dij );
    destroyGraph ( graph );

    return EXIT_SUCCESS;
}