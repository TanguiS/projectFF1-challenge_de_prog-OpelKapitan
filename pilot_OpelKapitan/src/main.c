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

#include "readMap.h"
#include "pilotManagement.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LENGTH 1024
#define BOOSTS_AT_START 5

int main ()
{
    int round = 0;
    DATA_MAP map;
    PILOT myPilot, autre2, autre3;

    myPilot = createPilot();

    map = readDataMap ( &myPilot );

    fprintf(stderr, "\n=== Race start ===\n");
    while (!feof(stdin)) {
        round++;
        fprintf(stderr, "=== ROUND %d\n", round);
        fflush(stderr);

       updatePilots ( &myPilot, &autre2, &autre3 );

        if (0 && round > 4) { /* (DISABLED) Force a segfault for testing purpose */
            int * p = NULL;
            fprintf(stderr, "Good Bye!\n");
            fflush(stderr);
            *p = 0;
        }
    }
    if ( !destroyDataMap ( map ) ) {
        fprintf ( stderr, "Erreur fermeture\n" );
    }
    return EXIT_SUCCESS;
}