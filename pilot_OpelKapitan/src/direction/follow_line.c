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
 * @file follow_line.c
 * @brief This file contains the functions used to move a point in a 2 diemsions.
 * @author Gestionnaire de Course
 * @version 0.0.0
 * @date 01 janvier 2022
 */

#include "../../include/direction/follow_line.h"

void initLine(int x1, int y1, int x2, int y2, InfoLine * infoLine)
{
  int adxi, adyi, dxi, dyi;
  infoLine->start.X = x1;
  infoLine->start.Y = y1;
  infoLine->currentPosition.X = x1 + 0.5;
  infoLine->currentPosition.Y = y1 + 0.5;
  infoLine->end.X = x2;
  infoLine->end.Y = y2;

  adxi = dxi = x2 - x1;
  adyi = dyi = y2 - y1;
  if (adxi < 0)  {
    adxi = -dxi;
  }
  if (adyi < 0) {
    adyi = -dyi;
  }
  infoLine->pos = 0;
  infoLine->len = adxi;
  if (adyi > adxi) {
    infoLine->len = adyi;
  }
  infoLine->delta.X = ((float)dxi) / infoLine->len;
  infoLine->delta.Y = ((float)dyi) / infoLine->len;
}

int nextPoint(InfoLine * infoLine, POSITION * point, int direction)
{
  if (direction > 0) {
    if (infoLine->pos == infoLine->len) {
      point->X = infoLine->end.X;
      point->Y = infoLine->end.Y;
      return -1; /* End of the line */
    }
    infoLine->currentPosition.X += infoLine->delta.X;
    infoLine->currentPosition.Y += infoLine->delta.Y;
    point->X = ((int)infoLine->currentPosition.X);
    point->Y = ((int)infoLine->currentPosition.Y);
    infoLine->pos++;
    return 1;   /* a new point is found */
  }
  if (direction < 0) {
    if (infoLine->pos == 0) {
      point->X = infoLine->start.X;
      point->Y = infoLine->start.Y;
      return -1; /* End of the line */
    }
    infoLine->currentPosition.X -= infoLine->delta.X;
    infoLine->currentPosition.Y -= infoLine->delta.Y;
    point->X = ((int)infoLine->currentPosition.X);
    point->Y = ((int)infoLine->currentPosition.Y);
    infoLine->pos--;

    return 1; /* a new point is found */
  }
  return 1; /* direction == 0 => no motion */
}

