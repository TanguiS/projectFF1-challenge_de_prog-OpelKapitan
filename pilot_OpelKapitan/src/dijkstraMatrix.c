#include "dijkstraMatrix.h"


short getWidthDijkstra(DIJKSTRA* dijkstra) {
    return dijkstra->width;
}

short getHeigthDijkstra(DIJKSTRA* dijkstra) {
    return dijkstra->height;
}


elementdij getElementDijkstra(DIJKSTRA* dijkstra, short x, short y) {
    return dijkstra->matrix[x][y];
}

void setElementDijkstra(DIJKSTRA* dijkstra, short x, short y, elementdij values) {
    setPathLength ( dijkstra, x, y, values.pathLength );
    setPredecessor ( dijkstra, x, y, values.predecessor );
}


short getPathLength(DIJKSTRA* dijkstra, short x, short y) {
    return dijkstra->matrix[x][y].pathLength;
}

void setPathLength(DIJKSTRA* dijkstra, short x, short y, short newPathLength) {
    dijkstra->matrix[x][y].pathLength = newPathLength;
}

void getPredecessor(DIJKSTRA* dijkstra, short x, short y, POSITION* result) {
    result->Y = dijkstra->matrix[x][y].predecessor.Y;
    result->X = dijkstra->matrix[x][y].predecessor.X;
}

void setPredecessor(DIJKSTRA* dijkstra, short x, short y, POSITION newPredecessor) {
    dijkstra->matrix[x][y].predecessor.X = newPredecessor.X;
    dijkstra->matrix[x][y].predecessor.Y = newPredecessor.Y;
}

DIJKSTRA createDijkstraMatrix(short width, short heigth) {
    int i;

    DIJKSTRA dijkstra;
    dijkstra.height = heigth;
    dijkstra.width = width;
    dijkstra.matrix = (elementdij**)malloc(width*sizeof(elementdij*));
    for (i=0; i<width; i++) {
        dijkstra.matrix[i] = (elementdij*)malloc(heigth*sizeof(elementdij));
    }
    return dijkstra;
}

#ifndef DEBUG
void displayDijkstraMatrix(DIJKSTRA* dijkstra, short x, short y)
{
    int i, j;
    elementdij tmp;
    fprintf ( stderr, "Affichage matrice dijkstra :\nwidth & height : %hd %hd\n", getWidthDijkstra ( dijkstra ), getHeigthDijkstra ( dijkstra ) );
    for ( i = 0; i < getHeigthDijkstra ( dijkstra ); i++ ) {
        for ( j = 0; j < getWidthDijkstra ( dijkstra ); j++ ) {
            tmp = getElementDijkstra ( dijkstra, j, i );
            if ( tmp.pathLength == SHRT_MAX ) {
                fprintf ( stderr, "[%d, %d],% *d %d | ", tmp.predecessor.X, tmp.predecessor.Y,3, -9, tmp.flag );
            } else if ( j == x && i == y ) {
                fprintf ( stderr, "\033[33m[%d, %d],% *d %d | \033[00m", tmp.predecessor.X, tmp.predecessor.Y,3, tmp.pathLength, tmp.flag );
            } else {
                fprintf ( stderr, "\033[31m[%d, %d],% *d %d | \033[00m", tmp.predecessor.X, tmp.predecessor.Y,3, tmp.pathLength, tmp.flag );
            }
        }
        fprintf ( stderr, "\n" );
    }
}
#endif

#ifndef DEBUG
void displayDijkstraMatrixPath(DIJKSTRA* dijkstra, int count, POSITION* path)
{
    int i, j, h;
    elementdij tmp;
    boolean flag;
    fprintf ( stderr, "Affichage matrice dijkstra :\nwidth & height : %hd %hd\n", getWidthDijkstra ( dijkstra ), getHeigthDijkstra ( dijkstra ) );
    for ( i = 0; i < getHeigthDijkstra ( dijkstra ); i++ ) {
        for ( j = 0; j < getWidthDijkstra ( dijkstra ); j++ ) {
            tmp = getElementDijkstra ( dijkstra, j, i );
            flag = false;
            if ( tmp.pathLength == SHRT_MAX ) {
                fprintf ( stderr, "[%d, %d],% *d %d | ", tmp.predecessor.X, tmp.predecessor.Y,4, -9, tmp.flag );
            }
            for ( h = 0; h < count; h++ ) {
                if ( j == path[h].X && i == path[h].Y ) {
                    flag = true;
                    fprintf ( stderr, "\033[33m[%d, %d],% *d %d | \033[00m", tmp.predecessor.X, tmp.predecessor.Y,4, tmp.pathLength, tmp.flag );
                }
            }
            if ( !flag && tmp.pathLength != SHRT_MAX ) {
                fprintf ( stderr, "\033[31m[%d, %d],% *d %d | \033[00m", tmp.predecessor.X, tmp.predecessor.Y,4, tmp.pathLength, tmp.flag );
            }
        }
        fprintf ( stderr, "\n" );
    }
}
#endif

void destroyDijkstraMatrix(DIJKSTRA dijkstra) {
    int i;

    for (i=0; i<getWidthDijkstra(&dijkstra); i++) {
        free(dijkstra.matrix[i]);
    }
    free(dijkstra.matrix);
}