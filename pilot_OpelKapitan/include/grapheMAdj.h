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
 * @brief This is the header.
 */

/**
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.0
 * @date 16 mars 2022
 */

#ifndef __GRAPHE_M_ADJ_H__
#define __GRAPHE_M_ADJ_H__

#include <stdio.h>
#include <stdlib.h>
#include "util.h"

typedef char element; /* valué */

typedef enum {
    blanc, 
    gris, 
    noir
} color;

typedef struct _mAdj {
    short nbVertex;
    short nbEdge;
    element** matrix;
}_mAdj;
typedef struct _mAdj M_ADJ;

/**
 * @brief Create a M_ADJ objects with the number of vertex and edges
 * 
 * @param nbVertex 
 * @param nbEdge 
 * @return M_ADJ 
 */
M_ADJ createMAdj ( short nbVertex, short nbEdge );

/**
 * @brief Initialise a M_ADJ objects
 * 
 * @param matrix 
 * @param nbVertex 
 * @param nbEdge 
 * @return M_ADJ 
 */
M_ADJ initMAdj ( M_ADJ matrix, short nbVertex, short nbEdge );

/**
 * @brief Display the matrix of a M_ADJ object
 * 
 * @param matrix 
 * @return boolean 
 */
boolean displayMAdj ( M_ADJ matrix );

/**
 * @brief Free a M_ADJ object
 * 
 * @param matrix 
 * @return boolean 
 */
boolean destroyMAdj ( M_ADJ matrix );

#endif /* __GRAPHE_M_ADJ_H__ */