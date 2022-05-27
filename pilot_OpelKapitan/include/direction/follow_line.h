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
 * @file follow_line.h
 * @brief This file contains the functions used to move a point in a 2 dimensions.
 * @author Gestionnaire de Course
 * @version 0.0.0
 * @date 01 janvier 2022
 */

#include "../tools/util.h"

#ifndef FOLLOW_LINE_H
#define FOLLOW_LINE_H

/**
 * Position with floating point coordinates
 */
typedef struct {
  float X;
  float Y;
} Pos2Dfloat;

/**
 * Dicrete line traversal information
 */
typedef struct {
  POSITION start;
  POSITION end;
  Pos2Dfloat currentPosition;
  Pos2Dfloat delta; /*< Shift vector */
  int len;          /*< Length along the main axis */
  int pos;          /*< Reference position on the line */
} InfoLine;

/**
 * Initialize an InfoLine data structure
 */
void initLine(int x1, int y1, int x2, int y2, InfoLine * infoLine);

/**
 * @brief nextPoint Move a point along a line in one direction
 *
 * @param infoLine Line traversal information
 * @param point current/next position
 * @param direction (+1 forward, -1 backward)
 * @return 1 if point is a new point in the line, otherwise -1 (info is
 *         already at the end point)
 */
int nextPoint(InfoLine * infoLine, POSITION * point, int direction);

#endif
