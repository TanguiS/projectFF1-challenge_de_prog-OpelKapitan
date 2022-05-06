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
 * @file main_matrix.c
 * @brief This is used to test matrix algo.
 */

/**
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.0
 * @date 6 mai 2022
 */

#include "../../include/matrix.h"

void displayMatrix ( MATRIX* matrix )
{
    int i, j;
    for ( i = 0; i < getHeightMatrix ( matrix ); i++ ) {
        for ( j = 0; j < getWidthMatrix ( matrix ); j++ ) {
            printf ( "[ %d ]", getElementMatrix(matrix, j, i) );
        }
        printf ( "\n " );
    }
}

void fillMatrix ( MATRIX* matrix )
{
    int value = 0;
    int i, j;
    for ( i = 0; i < getHeightMatrix ( matrix ); i++ ) {
        for ( j = 0; j < getWidthMatrix ( matrix ); j++ ) {
            setElementMatrix ( matrix, j, i, value );
        }
        value++;
    }
}

int main ( void )
{
    MATRIX matrix;

    matrix = createMatrix ( 10, 50 );
    fillMatrix ( &matrix );
    displayMatrix ( &matrix );

    return EXIT_SUCCESS;
}