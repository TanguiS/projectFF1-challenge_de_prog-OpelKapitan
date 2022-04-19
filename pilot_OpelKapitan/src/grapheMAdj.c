/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */

/**
 * @file graphe-m-adj.c
 * @brief This is the function.
 */

/**
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.0
 * @date 19 avril 2022
 */
 
#include <assert.h>
#include "grapheMAdj.h"

M_ADJ createMAdj ( short nb_vertex, short nb_edge )
{
    int i;
    M_ADJ matrix;
 
    matrix = initMAdj ( matrix, nb_vertex, nb_edge );

    matrix.matrix = ( element** ) malloc ( matrix.nb_vertex * sizeof ( element* ) );

    assert ( matrix.matrix );

    for ( i = 0; i < matrix.nb_vertex; i++ ) {
        matrix.matrix[i] = ( element* ) calloc ( matrix.nb_vertex, sizeof ( element ) );
        assert ( matrix.matrix[i] );
    }
    return matrix;
}

M_ADJ initMAdj ( M_ADJ matrix, short nb_vertex, short nb_edge )
{
    matrix.nb_vertex = nb_vertex;
    matrix.nb_edge = nb_edge;
    matrix.matrix = NULL;
    return matrix;
}

boolean displayMAdj ( M_ADJ matrix )
{
    int i, j;

    for ( i = 0; i < matrix.nb_vertex; i++ ) {
        for ( j = 0; j < matrix.nb_vertex; j++ ) {
            printf ( "[%d] ", matrix.matrix[i][j] );
        }
        printf ( "\n" );
    }
    return true;
}
























boolean destroyMAdj ( M_ADJ matrix )
{
    int i;

    for ( i = 0; i < matrix.nb_vertex; i++ ) {
        free ( matrix.matrix[i] );
        matrix.matrix[i] = NULL;
    }

    free ( matrix.matrix );

    return true;
}