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
 * @date 11 mai 2022
 */

#include <stdio.h>
#include <stdlib.h>
#include "pilotDirection.h"
#include "pathList.h"

#define SIZE 14

int main ( void )
{
    PATH_LIST list = createPathList();
    path_list_element value;
    POSITION init;
    SPEED speed;
    ACCELERATION acc;
    int i;
    int trash;
    POSITION tmp;
/*     
    int x[35] = {0, 0, 0, 0, 1, 2, 3, 4, 4, 4, 4, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 15, 15, 15, 15, 14, 13, 12, 12, 12, 12, 12, 12};
    int y[35] = {4, 3, 2, 1, 0, 0, 0, 1, 2, 3, 4, 5, 5, 5, 5, 5, 5,  5,  5,  5,  5,  5,  5,  4,  3,  2,  1,  0,  0,  0,  1,  2,  3,  4,  5};
 */

    int x[SIZE] = {1, 2, 3, 4, 5, 6, 7, 7, 7, 7, 7, 7, 7, 7};
    int y[SIZE] = {0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7};


    for ( i = 0; i < SIZE; i++ ) {
        value.X = x[SIZE - 1 -i];
        value.Y = y[SIZE - 1 -i] + 5;
        list = addHeadElementPathList ( list, value );
    }
    list = resetCurrentPathList ( list );

    init.X = 0;
    init.Y = 5;
    speed.X = 0;
    speed.Y = 0;


/*     while ( !isEmptyPathList ( list ) ) {
        list = nextActionBasic ( list, init, speed, &acc );
        speed.X += acc.X;
        speed.Y += acc.Y;
        init.X += speed.X;
        init.Y += speed.Y;
        printf ( "[%d, %d]\n", init.X, init.Y );
    } */


    while ( !isEmptyPathList ( list ) ) {
        list = nextActionLigne ( list, init, speed, &acc, &trash );
        speed.X += acc.X;
        speed.Y += acc.Y;
        init.X += speed.X;
        init.Y += speed.Y;
        printf ( "acceleration : [%d, %d]\n", acc.X, acc.Y );
        printf ( "speed        : [%d, %d]\n", speed.X, speed.Y );
        printf ( "Position     : [%d, %d]\n", init.X, init.Y );
    }
    


    return EXIT_SUCCESS;
}