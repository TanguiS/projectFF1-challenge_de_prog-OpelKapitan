#include "dijkstraMatrix.h"


short getWidthMatrixDijkstra(dijkstraMatrix* dijkstra) {
    return dijkstra->width;
}

short getHeigthMatrixDijkstra(dijkstraMatrix* dijkstra) {
    return dijkstra->height;
}


elementdij getElementDijkstra(dijkstraMatrix* dijkstra, short x, short y) {
    return dijkstra->matrix[x][y];
}

void setElementDijkstra(dijkstraMatrix* dijkstra, short x, short y, elementdij values) {
    setPathLength ( dijkstra, x, y, values.pathLength );
    setPredecessor ( dijkstra, x, y, values.predecessor );
}


short getPathLength(dijkstraMatrix* dijkstra, short x, short y) {
    return dijkstra->matrix[x][y].pathLength;
}

void setPathLength(dijkstraMatrix* dijkstra, short x, short y, short newPathLength) {
    dijkstra->matrix[x][y].pathLength = newPathLength;
}

void getPredecessor(dijkstraMatrix* dijkstra, short x, short y, POSITION* result) {
    result->Y = dijkstra->matrix[x][y].predecessor.Y;
    result->X = dijkstra->matrix[x][y].predecessor.X;
}

void setPredecessor(dijkstraMatrix* dijkstra, short x, short y, POSITION newPredecessor) {
    dijkstra->matrix[x][y].predecessor.X = newPredecessor.X;
    dijkstra->matrix[x][y].predecessor.Y = newPredecessor.Y;
}

dijkstraMatrix createDijkstraMatrix(short width, short heigth) {
    int i;


    dijkstraMatrix dijkstra;
    dijkstra.height = heigth;
    dijkstra.width = width;
    dijkstra.matrix = (elementdij**)malloc(width*sizeof(elementdij*));
    for (i=0; i<width; i++) {
        dijkstra.matrix[i] = (elementdij*)malloc(heigth*sizeof(elementdij));
    }
    return dijkstra;
}

#ifndef DEBUG
void displayDijkstraMatrix(dijkstraMatrix* dijkstra, short x, short y)
{
    int i, j;
    elementdij tmp;
    DEBUG_CHAR ( "Affichage de la matrice de dijkstra : ", ' ' );
    DEBUG_INT ( "width graph : ", getWidthMatrixDijkstra ( dijkstra ) );
    DEBUG_INT ( "height graph : ", getHeigthMatrixDijkstra ( dijkstra ) );
    for ( i = 0; i < getHeigthMatrixDijkstra ( dijkstra ); i++ ) {
        for ( j = 0; j < getWidthMatrixDijkstra ( dijkstra ); j++ ) {
            tmp = getElementDijkstra ( dijkstra, j, i );
            if ( tmp.pathLength == SHRT_MAX ) {
                fprintf ( stderr, "[%d, %d],% *d %d | ", tmp.predecessor.X, tmp.predecessor.Y,3, -9, tmp.flag );
            } else if ( j == x && i == y ) {
                fprintf ( stderr, "\033[33m[%d, %d],% *d %d | \033[00m", tmp.predecessor.X, tmp.predecessor.Y,3, tmp.pathLength, tmp.flag );
            } else {
                fprintf ( stderr, "\033[31m[%d, %d],% *d %d | \033[00m", tmp.predecessor.X, tmp.predecessor.Y,3, tmp.pathLength, tmp.flag );
            }
        }
        DEBUG_ONLY_CHAR ( '\n' );
    }
}
#endif

#ifndef DEBUG
void displayDijkstraMatrixPath(dijkstraMatrix* dijkstra, int count, POSITION* path)
{
    int i, j, h;
    elementdij tmp;
    boolean flag;
    DEBUG_CHAR ( "Affichage de la matrice de dijkstra : ", ' ' );
    DEBUG_INT ( "width graph : ", getWidthMatrixDijkstra ( dijkstra ) );
    DEBUG_INT ( "height graph : ", getHeigthMatrixDijkstra ( dijkstra ) );
    for ( i = 0; i < getHeigthMatrixDijkstra ( dijkstra ); i++ ) {
        for ( j = 0; j < getWidthMatrixDijkstra ( dijkstra ); j++ ) {
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
        DEBUG_ONLY_CHAR ( '\n' );
    }
}
#endif

void destroyDijkstraMatrix(dijkstraMatrix dijkstra) {
    int i;

    for (i=0; i<getWidthMatrixDijkstra(&dijkstra); i++) {
        free(dijkstra.matrix[i]);
    }
    free(dijkstra.matrix);
}