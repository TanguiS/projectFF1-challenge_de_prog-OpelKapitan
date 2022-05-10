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
 * @file file.h
 * @brief This file contains all the prototype of the file algo.
 */

/**
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.1
 * @date 22 janvier 2022
 */

#ifndef __FILE_H__
#define __FILE_H__

#include <stdlib.h>
#include <stdio.h>
#include "util.h"

/**
 * @brief listeElement type declaration 
 */
typedef coord listeElement;

/**
 * @brief A structure to represent a cell object 
 */
typedef struct _liste_cell {
    listeElement contents;           /**< the element that the cell contains */
    struct _liste_cell* followingCell;    /**< the following cell */
} _liste_cell; 
/**
 * @brief Cell object declaration 
 */
typedef struct _liste_cell *LISTE_CELL;

/**
 * @brief A structure to represent a lifo object 
 */
typedef struct _liste {
    LISTE_CELL head;                      /**< the head of the liste */
    LISTE_CELL tail;                      /**< the tail of the liste */
    /*int size;*/                             /**< the size of the liste */
} _lifo; 
/**
 * @brief Lifo object declaration 
 */
typedef struct _liste LISTE;


/**
 * @brief Create a Lifo object
 * 
 * @return LISTE 
 */
LISTE createListe ();

/**
 * @brief If the lifo is empty
 * 
 * @param lifo 
 * @return boolean 
 */
boolean isEmptyListe ( LISTE liste );

/**
 * @brief Add a lifo element int the lifo
 * 
 * @param file 
 * @param x : the element to add
 * @return LISTE 
 */
LISTE addElementListe ( LISTE liste, listeElement x );



LISTE removeElementListeCoord ( LISTE liste, listeElement* result , coord* removeCoord);


/**
 * @brief Remove a lifo element from the lifo
 * 
 * @param file 
 * @param result : the removed element
 * @return LISTE 
 */
LISTE removeElementListe ( LISTE liste, listeElement* result );

/**
 * @brief Destroy a Lifo Object
 * 
 * @param file 
 */
void destroyListe ( LISTE liste );




boolean getElementListe ( LISTE liste, listeElement* result, int position);

boolean getNextElementListe ( LISTE liste, listeElement* result, listeElement* refElement);

#endif /* __FILE_H__ */