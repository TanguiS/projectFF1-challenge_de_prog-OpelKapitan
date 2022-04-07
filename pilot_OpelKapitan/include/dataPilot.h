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
 * @file dataPilot.h
 * @brief This file contains the data for the pilot.
 */

/**
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.0
 * @date 06 avril 2022
 */

#ifndef __DATA_PILOT_HH__
#define __DATA_PILOT_HH__

#define SIZE_ACTION 3

typedef struct _dataPilot {
    short xPosition;
    short yPosition;
    short GasLvl; /** ne va pas rester ici @TODO */
    char action[SIZE_ACTION];
} _dataPilot;
typedef struct _dataPilot PILOT;




#endif /* __DATA_PILOT_HH__ */