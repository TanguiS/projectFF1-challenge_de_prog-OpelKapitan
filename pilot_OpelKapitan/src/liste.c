/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This liste is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */

/**
 * @liste liste.c
 * @brief This liste contains all the functions of the liste algo.
 */

/**
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.2
 * @date 22 janvier 2022
 */

#include "liste.h"

/**
 * @brief Create a Cell object
 * 
 * @param x : the new element 
 * @return LISTE_CELL 
 */
static LISTE_CELL createCell ( listeElement x );
/**
 * @brief Destroy a Cell object
 * 
 * @param cell : the cell to destroy
 * @return boolean 
 */
static boolean destroyCell ( LISTE_CELL cell );

static LISTE_CELL createCell ( listeElement x)
{
    LISTE_CELL newCell;

    newCell =  ( LISTE_CELL ) malloc ( sizeof ( _liste_cell ) );
    newCell->contents[0] = x[0];
    newCell->contents[1] = x[1];
    newCell->followingCell = NULL;
    return newCell;
}

static boolean destroyCell ( LISTE_CELL cell )
{
    if ( cell != NULL ) {
        free ( cell );
        cell = NULL;
        return true;
    }
    return false;
}

boolean comparElement(listeElement* element1, listeElement* element2) {
    if (element1[0] == element2[0] && element1[1] == element2[1]) {
        return true;
    }
    return false;
}

LISTE createListe () 
{
    LISTE newListe;
    newListe.head = NULL;
    newListe.tail = NULL;
    return newListe;
}

boolean isEmptyListe ( LISTE liste )
{
    if ( liste.head == NULL ) {
        return true;
    }
    return false;
}

LISTE addElementListe ( LISTE liste, listeElement x )
{
    LISTE_CELL newCell;

    newCell = createCell ( x );
    if ( isEmptyListe( liste ) ) {
        liste.head = newCell;
        liste.tail = newCell;
        return liste;
    }

    newCell->followingCell = liste.tail;
    liste.tail = newCell;
    return liste;
}

LISTE removeElementListeCoord ( LISTE liste, listeElement* result , coord* removeCoord)
{
    LISTE_CELL previousHead;
    LISTE_CELL current;
    
    if ( isEmptyListe( liste ) ) {
        return liste;
    }
    current = liste.head;
    while (!comparElement(removeCoord, &(current->contents)) && current != NULL) {
        previousHead = current;
        current = current->followingCell;
    }
    if (current == NULL) {
        return liste;
    }
    result[0][0] = current->contents[0]; 
    result[0][1] = current->contents[1];
    if (current == liste.head) {
        liste.head = current->followingCell;
    } else if ( current == liste.tail) {
        liste.tail = previousHead;
    } else {
        previousHead->followingCell = current->followingCell;
    }
    destroyCell ( current );
    return liste;
}



LISTE removeElementListe ( LISTE liste, listeElement* result )
{
    LISTE_CELL previousHead;
    
    if ( isEmptyListe( liste ) ) {
        return liste;
    }
    result[0][0] = liste.head->contents[0]; 
    result[0][1] = liste.head->contents[1];
    previousHead = liste.head;
    liste.head = liste.head->followingCell;
    destroyCell ( previousHead );
    return liste;
}


void destroyListe ( LISTE liste )
{
    coord trash;
    while ( !isEmptyListe( liste ) ) {
        liste = removeElementListe ( liste, &trash );
    }
}



boolean getElementListe ( LISTE liste, listeElement* result, int position) {
    LISTE_CELL current;
    int i = 1;

    if (isEmptyListe(liste)) {
        return false;
    }
    current = liste.head;
    while (i<position && current!= NULL) {
        current = current->followingCell;
        i++;
    } if (current == NULL) {
        return false;
    }
    result[0][0] = current->contents[0]; 
    result[0][1] = current->contents[1];
    return true;
}

boolean getNextElementListe ( LISTE liste, listeElement* result, listeElement* refElement) {
    LISTE_CELL current;

    if (isEmptyListe(liste)) {
        return false;
    }

    current = liste.head;
    while (!comparElement(refElement, &(current->contents)) && current!= NULL) {
        current = current->followingCell;
    } if (current == NULL) {
        return false;
    }
    result[0][0] = current->contents[0]; 
    result[0][1] = current->contents[1];
    return true;
}
