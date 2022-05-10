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
 * @file main.c
 * @brief This file the main function to test a program.
 */

/**
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.0
 * @date 05 avril 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "readMap.h"
#include "pilotManagement.h"

int main ( void )
{
    int round = 0;
    short gasLvl;
    DATA_MAP map;
    PILOT myPilot, autre2, autre3;
    GRAPH graph;
    float time;
    float initTime;
    clock_t t1, t2;
    int i;

    t1 = clock();
    map = readDataMapGraph ( &gasLvl, &graph );
    myPilot = createPilot ( gasLvl );
    t2 = clock();
    initTime = (float)(t2-t1)/CLOCKS_PER_SEC;

    fprintf(stderr, "\n=== Race start ===\n");
    
    while (!feof(stdin)) {
        t1 = clock();
        round++;
        fprintf(stderr, "=== ROUND %d\n", round);
        fflush(stderr);
        updatePilots ( &myPilot, &autre2, &autre3, &map, &graph );
        #ifndef DEBUG
        displayGraph ( &graph );
        #endif
        t2 = clock();
        time = initTime + (float)(t2-t1)/CLOCKS_PER_SEC;
        fprintf ( stderr, "===> temps exec = %f\n", time );
    }
    if ( !destroyMap ( map ) ) {
        fprintf ( stderr, "Erreur fermeture\n" );
    }
    destroyGraph(graph);
    return EXIT_SUCCESS;
}