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
 * @file dijkstraAlgo.c
 * @brief This file contains the functions to implement the Dijstra's algo.
 */

/**
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.0
 * @date 29 avril 2022
 */

#include "../include/dijkstraAlgo.h"





void initDijkstra(dijkstraMatrix* dijkstraMatrix, int width, int heigth, short x, short y) {
    int i;
    int j;

    for (i=0; i<heigth; i++){
        for (j=0; j<width; j++) {
            dijkstraMatrix->matrix[i][j].pathLength = SHRT_MAX;
        }
    }
    dijkstraMatrix->matrix[x][y].pathLength = 0;
}

