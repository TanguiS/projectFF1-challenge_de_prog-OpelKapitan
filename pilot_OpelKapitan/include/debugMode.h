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
 * @file debugMode.h
 * @brief This file is a debug header.
 */

/**
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.0
 * @date 06 avril 2022
 */

#ifndef __DEBUG_MODE_HH__
#define __DEBUG_MODE_HH__

#ifndef DEBUG

#define DEBUG_INT(string, value) { fprintf ( stderr, "%s %d\n", string, value ); }
#define DEBUG_CHAR(string, value) { fprintf ( stderr, "%s %c\n", string, value ); }
#define DEBUG_ONLY_CHAR(value) { fprintf ( stderr, "%c", value ); } 

#else

#define DEBUG_INT(string, value)
#define DEBUG_CHAR(string, value)
#define DEBUG_ONLY_CHAR(value)

#endif /* DEBUG */

#endif /* __DEBUG_MODE_HH__ */