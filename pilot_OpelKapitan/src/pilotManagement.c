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
 * @file pilotManagement.h
 * @brief This file contains the functions used to manage a pilot.
 */

/**
 * @author STEIMETZ Tangui <steimetz.tangui@ecole.ensicaen.fr>
 * @version 1.0.2
 * @date 07 avril 2022
 */

#include "pilotManagement.h"
#include "pilotDirection.h"

#define UNCHANGED_ACTION "keep_value"
#define STRAIGHT_ACTION "straight"
#define DEFAULT_ACTION "default"
#define NEW_ACTION "new"
#define DONT_CARE_ACTION 0
#define ACTION_IS_UNCHANGED(choice) strcmp ( choice, UNCHANGED_ACTION ) == 0 ? true : false
#define ACTION_IS_STRAIGHT(choice) strcmp ( choice, STRAIGHT_ACTION ) == 0 ? true : false
#define ACTION_IS_DEFAULT(choice) strcmp ( choice, DEFAULT_ACTION ) == 0 ? true : false
/*
A changer probablement
*/
#define Xs "x"
#define Ys "y"
#define VALUE_DEFAULT_ACTION(i) ( strcmp ( i, Xs ) == 0 ) ? 1 : 0

/**
 * @brief Set the Position Pilot object
 * 
 * @param pilot 
 * @param position 
 */
static void setPositionPilot ( PILOT* pilot, short x, short y );

/**
 * @brief Set the Speed Pilot object
 * 
 * @param pilot 
 * @param speed 
 */
static void setSpeedPilot ( PILOT* pilot, short x, short y );

/**
 * @brief Set the Action Pilot object
 * 
 * @param pilot 
 * @param action 
 */
static void setActionPilot ( PILOT* pilot, short x, short y );

/**
 * @brief Set the Gas Lvl Pilot object
 * 
 * @param pilot : the PILOT object
 * @param newGasLvl : the gas level
 */
static void setGasLvlPilot ( PILOT* pilot, double newGasLvl );

/**
 * @brief Set the Boosts Remaining Pilot object
 * 
 * @param pilot : the PILOT object
 * @param boostsRemaining : the boosts remaining 
 */
static void setBoostsRemainingPilot ( PILOT* pilot, short boostsRemaining );

/**
 * @brief Initialize the pilot object
 * 
 * @param pilot : the PILOT object
 */
static void initNewPilot ( PILOT* pilot );

/**
 * @brief Update the position of the three pilot
 * 
 * @param myPilot : our pilot
 * @param secondPilot : the second pilot
 * @param thirdPilot : the third pilot
 */
static void updatePositionPilotFromGDC ( PILOT* myPilot, PILOT* secondPilot, PILOT* thirdPilot );

/**
 * @brief Update the speed of our pilot
 * 
 * @param pilot : the PILOT object
 */
static void updateSpeedPilot ( PILOT* pilot );

static boolean actionIsBoosted ( ACCELERATION action );

static void updateActionPilot ( PILOT* pilot, ACCELERATION action, char* modeChosen );

static double fuelConsumption ( POSITION position, SPEED speed, ACCELERATION action, DATA_MAP* map );

/**
 * @brief Update the gas remaining of our pilot
 * 
 * @param pilot : the PILOT object
 */
static void updateGasPilot ( PILOT* pilot, DATA_MAP* map );

static void updateBoostsPilot ( PILOT* pilot );

/**
 * @brief Deliver the action to the GDP
 * 
 * @param action : the action to deliver
 */
static void deliverAction ( char* action ); /* action du type : x y */

static void setPositionPilot ( PILOT* pilot, short x, short y )
{
    pilot->position.X = x;
    pilot->position.Y = y; 
}

static void setSpeedPilot ( PILOT* pilot, short x, short y )
{
    pilot->speed.X = x;
    pilot->speed.Y = y;

}

static void setActionPilot ( PILOT* pilot, short x, short y )
{
    pilot->acceleration.X = x;
    pilot->acceleration.Y = y;
}

static void setGasLvlPilot ( PILOT* pilot, double newGasLvl )
{
    pilot->gasLvl = newGasLvl;
}

static void setBoostsRemainingPilot ( PILOT* pilot, short boostsRemaining )
{
    pilot->boostsRemaining = boostsRemaining;
}

static void initNewPilot ( PILOT* pilot )
{
    /* 
    on pourrait tenter une fonctions pour partir avec un boost dans la bonne direction directement 
    */
    setPositionPilot ( pilot, 0, 0 );
    setSpeedPilot ( pilot, 0, 0 );
    setActionPilot ( pilot, 0, 0 );
    setBoostsRemainingPilot ( pilot, BOOSTS_AT_START );
}

static void updateSpeedPilot ( PILOT* pilot )
{
    SPEED speed = getSpeedPilot ( pilot );
    ACCELERATION acc = getAccelerationPilot ( pilot );
    setSpeedPilot ( pilot, speed.X + acc.X, 
                           speed.Y + acc.Y );
}

static void updatePositionPilotFromGDC ( PILOT* myPilot, PILOT* secondPilot, PILOT* thirdPilot )
{
    char buf[MAX_LINE_LENGTH];
    POSITION myPosition, secoundPosition, thirdPosition;

    fgets ( buf, MAX_LINE_LENGTH, stdin );
    fprintf ( stderr, "\n\nLECTURE TEST BUFFER >>>>>>>>>>>>< : %s\n\n", buf );
    fflush ( stdin );
    sscanf ( buf, "%hd %hd %hd %hd %hd %hd",
                    &myPosition.X,      &myPosition.Y,
                    &secoundPosition.X, &secoundPosition.Y,
                    &thirdPosition.X,   &thirdPosition.Y
            );
    setPositionPilot ( myPilot, myPosition.X, myPosition.Y );
    setPositionPilot ( secondPilot, secoundPosition.X, secoundPosition.Y);
    setPositionPilot ( thirdPilot, thirdPosition.X, thirdPosition.Y );
}

void updatePositionPilot ( POSITION myPosition, POSITION secoundPosition, POSITION thirdPosition, PILOT* myPilot, PILOT* secondPilot, PILOT* thirdPilot )
{
    setPositionPilot ( myPilot, myPosition.X, myPosition.Y );
    setPositionPilot ( secondPilot, secoundPosition.X, secoundPosition.Y);
    setPositionPilot ( thirdPilot, thirdPosition.X, thirdPosition.Y );
}


static boolean actionIsBoosted ( ACCELERATION action )
{
    if ( abs ( action.X ) != 2 ) {
        return false;
    } if ( abs ( action.Y ) != 2 ) {
        return false;
    }
    return true;
}

static void updateBoostsPilot ( PILOT* pilot )
{
    if ( actionIsBoosted ( getAccelerationPilot ( pilot ) ) ) {
        setBoostsRemainingPilot ( pilot, getBoostsRemainingPilot ( pilot ) - 1 );
    }
    DEBUG_INT ( "> nombre de Boost restant : ", getBoostsRemainingPilot ( pilot ) );
}

static void updateActionPilot ( PILOT* pilot, ACCELERATION action, char* modeChosen )
{
    if ( ACTION_IS_UNCHANGED ( modeChosen ) ) {
        DEBUG_STRING ( "====> update action : ", "ne rien faire" );
    } else if ( ACTION_IS_STRAIGHT ( modeChosen ) ) {
        DEBUG_STRING ( "====> update action : ", "garder sa vitesse actuelle" );
        setActionPilot ( pilot, (short) 0, (short) 0 );
    } else if ( ACTION_IS_DEFAULT ( modeChosen ) ) {
        DEBUG_STRING ( "====> update action : ", "en mode default (1 0)" );
        setActionPilot ( pilot, VALUE_DEFAULT_ACTION(Xs), VALUE_DEFAULT_ACTION(Ys) );
    } else {
        DEBUG_STRING ( "====> update action : ", "Changement d'acc" );
        setActionPilot ( pilot, action.X, action.Y );
    }
}

static double fuelConsumption ( POSITION position, SPEED speed, ACCELERATION action, DATA_MAP* map )
{
    double norme1;
    double squareRoot;
    #ifndef DEBUG
    char buf[100];
    sprintf ( buf, "speed : (%hd %hd), acc : (%hd %hd)", speed.X, speed.Y, action.X, action.Y );
    #endif

    DEBUG_STRING ( "> fuelConsumption donnée envoyé : " , buf );

    norme1 = ( action.X * action.X ) + ( action.Y * action.Y );
    squareRoot =  sqrt ( ( 3. * ( (double) ( speed.X * speed.X ) + (double) ( speed.Y * speed.Y ) ) ) / 2. );

    if ( ceil ( squareRoot ) - squareRoot < 0.73 ) {
        squareRoot = ceil ( squareRoot );
    } else {
        squareRoot = floor ( squareRoot );
    }

    fprintf ( stderr, ">>> resultat calcul : \n     norme1 = %f,    squareRoot = %f\n", norme1, squareRoot );

    if ( getElementMap ( map, position ) == sand ) {
        return ( norme1 + squareRoot + 1. );
    }
    return ( norme1 + squareRoot );
}

static void updateGasPilot ( PILOT* pilot, DATA_MAP* map )
{
    setGasLvlPilot ( pilot, getGasLvlPilot ( pilot ) 
                            - 
                            fuelConsumption ( getPositionPilot ( pilot ),
                                              getSpeedPilot ( pilot ),
                                              getAccelerationPilot ( pilot ),
                                              map 
                                            ) 
                    );
    fprintf ( stderr, "> gas lvl : %f\n", getGasLvlPilot ( pilot ) );
}

static void deliverAction ( char action[SIZE_ACTION] )
{
    fprintf ( stdout, "%s", action );
    fflush ( stdout );                /* CAUTION : This is necessary  */
}

POSITION getPositionPilot ( PILOT* pilot )
{
    return pilot->position;
}

SPEED getSpeedPilot ( PILOT* pilot )
{
    return pilot->speed;
}

ACCELERATION getAccelerationPilot ( PILOT* pilot )
{
    return pilot->acceleration;
}


double getGasLvlPilot ( PILOT* pilot )
{
    return pilot->gasLvl;
}

short getBoostsRemainingPilot ( PILOT* pilot )
{
    return pilot->boostsRemaining;
}

PILOT createPilot ( short gasLvl )
{
    PILOT newPilot;
    setGasLvlPilot ( &newPilot, gasLvl );
    initNewPilot ( &newPilot );

    return newPilot;
}

/**
 * @TODO : trouver l'action avant de calculer la vitesse pour trouver la future position pour etre à jour 
 * sur le statut actuel de la course et non un tour en retard
 * @TODO predire l'essence utilise pour eviter de griller nimporte comment
 */

void updatePilots ( PILOT* myPilot, PILOT* secondPilot, PILOT* thirdPilot, DATA_MAP* map, GRAPH* graph, dijkstraMatrix* dijkstra )
{
    static int round = 0;
    char action[SIZE_ACTION];
    POSITION myCar, secoundCar, thirdCar;
    POSITION trash;
    ACCELERATION nextAction;

    SPEED speed;
    PATH_LIST path = createPathList();

    round++;

    /* faire un reverse graph pour remettre à un les ancienne position des pilote */

    secoundCar = getPositionPilot ( secondPilot );
    thirdCar = getPositionPilot ( thirdPilot );
    reverseGraph ( graph, secoundCar, thirdCar );
    
    /* nouvelle 1ere action, mettre a jour le graph on doit avoir les position au depart */
    updatePositionPilotFromGDC ( myPilot, secondPilot, thirdPilot );

    myCar = getPositionPilot ( myPilot );
    secoundCar = getPositionPilot ( secondPilot );
    thirdCar = getPositionPilot ( thirdPilot );

    updateGraph ( graph, myCar, secoundCar, thirdCar );
    #ifndef DEBUG
    displayGraph ( graph );
    #endif

    /* 1ere etape : choisir une action */
    path = givePath ( dijkstra, graph, myCar );


 /*    list = nextActionForNextPosition ( list, getPositionPilot ( myPilot ), getSpeedPilot ( myPilot ), &nextAction ); */
    fprintf ( stderr, "\n\n>>>APPEL choix de l'action suivante\n" );
    if ( areEqualPosition ( examineHeadPathList ( path ), myCar ) ) {
        fprintf ( stderr, "\n\n> EQUALS POSITION\n\n" );
        removeHeadElementPathList ( path, &trash );
    }
    path = choiceNextAction ( path, myCar, getSpeedPilot ( myPilot ), &nextAction, graph );
    /* path = nextActionForNextPosition ( path, myCar, getSpeedPilot ( myPilot ), &nextAction ); */
    fprintf ( stderr, "\n>>> FIN <<<\n\n" );
    destroyPathList ( path );



    /* 2e etape : mettre a jour les donnees dans cet ordre : acc -> speed -> position */
    /* updateActionPilot ( myPilot, nextAction, mode ); */
    setActionPilot ( myPilot, nextAction.X, nextAction.Y );
    updateGasPilot ( myPilot, map );
    updateBoostsPilot ( myPilot );
    updateSpeedPilot ( myPilot );

    speed = getSpeedPilot ( myPilot );
    myCar.X += speed.X;
    myCar.Y += speed.Y;
    updatePositionPilot ( myCar, secoundCar, thirdCar, myPilot, secondPilot, thirdPilot );
    updateGraph ( graph, myCar, secoundCar, thirdCar );
    myCar = getPositionPilot ( myPilot );
    fprintf ( stderr, ">UPDATE PILOT : Position : (%d, %d); Speed : (%d, %d); Acc : (%d, %d)\n", myCar.X, myCar.Y, speed.X, speed.Y, nextAction.X, nextAction.Y );
    /* 3e etape : on transmet l'action au GDP */
    sprintf ( action, "%hd %hd", nextAction.X, nextAction.Y );
    fprintf ( stderr, "\n>>>NEXT ACTION après la mise en STRING : %s\n\n", action );
    deliverAction ( action );
}