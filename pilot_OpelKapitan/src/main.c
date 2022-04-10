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
    int row;
    int width, height;
    int gasLevel = 0;
    int boosts = BOOSTS_AT_START;
    int round = 0;
    int accelerationX = 1, accelerationY = 0;
    int speedX = 0, speedY = 0;
    char action[100];
    char line_buffer[MAX_LINE_LENGTH];
    DATA_MAP map;
    PILOT myPilot, autre2, autre3;
    myPilot = createPilot();

    boosts = boosts;                       /* Prevent warning "unused variable" */

    /*
    fgets(line_buffer, MAX_LINE_LENGTH, stdin);      
    sscanf(line_buffer, "%d %d %d", &width, &height, &gasLevel);
    fprintf(stderr, "=== >Map< ===\n");
    fprintf(stderr, "Size %d x %d\n", width, height);
    fprintf(stderr, "Gas at start %d \n\n", gasLevel);
    for (row = 0; row < height; ++row) {        
        fgets(line_buffer, MAX_LINE_LENGTH, stdin);
        fputs(line_buffer, stderr);
    }
    fflush(stderr);
    */

    map = readDataMap ( &myPilot );

    fprintf(stderr, "\n=== Race start ===\n");
    while (!feof(stdin)) {
        int myX, myY, secondX, secondY, thirdX, thirdY;
        round++;
        fprintf(stderr, "=== ROUND %d\n", round);
        fflush(stderr);
        /*
        fgets(line_buffer, MAX_LINE_LENGTH, stdin);  
        
        sscanf(line_buffer, "%d %d %d %d %d %d",
                &myX, &myY, &secondX, &secondY, &thirdX, &thirdY);
        fprintf(stderr, "    Positions: Me(%d,%d)  A(%d,%d), B(%d,%d)\n",
                myX, myY, secondX, secondY, thirdX, thirdY);
        fflush(stderr);
        */
       readPilotsPosition ( &myPilot, &autre2, &autre3 );


        fprintf ( stderr, "%s", "==> test line buffer\n" );
        fprintf ( stderr, "%s", line_buffer );
        fflush ( stderr );
        /* Gas consumption cannot be accurate here. */

        /* Write the acceleration request to the race manager (stdout). */
        if ( round == 1 ) {
            sprintf(action, "%d %d", 1, 0);
        } else if ( round == 2 ) {
            sprintf(action, "%d %d", 1, 0);
        } else if ( round == 4 ){
            sprintf(action, "%d %d", 2, 0);
        } else {
            sprintf(action, "%d %d", 0, 0);
        }
        fprintf(stdout, "%s", action);
        fflush(stdout);                           /* CAUTION : This is necessary  */
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