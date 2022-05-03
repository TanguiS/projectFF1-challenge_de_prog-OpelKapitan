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

#define X 10
#define Y 12


const short graph[X][Y] = { { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }, 
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

int main ( void )
{
    printf ( "depart value  : %d\n", graph[coordStart[0]][coordStart[1]] );
    printf ( "end value     : %d\n", graph[coordEnd[0]][coordEnd[1]] );
    return EXIT_SUCCESS;
}