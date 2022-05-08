






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
    dijkstra->matrix[x][y] = values;
}


short getPathLength(dijkstraMatrix* dijkstra, short x, short y) {
    return dijkstra->matrix[x][y].pathLength;
}

void setPathLength(dijkstraMatrix* dijkstra, short x, short y, short newPathLength) {
    dijkstra->matrix[x][y].pathLength = newPathLength;
}

short getPredecessor(dijkstraMatrix* dijkstra, short x, short y) {
    return dijkstra->matrix[x][y].predecessor;
}

void setPredecessor(dijkstraMatrix* dijkstra, short x, short y, coord newPredecessor) {
    dijkstra->matrix[x][y].predecessor[0] = newPredecessor[0];
    dijkstra->matrix[x][y].predecessor[1] = newPredecessor[1];
}

dijkstraMatrix createDijkstraMatrix(short width, short heigth) {
    int i;


    dijkstraMatrix dijkstra;
    dijkstra.matrix = (elementdij**)malloc(heigth*sizeof(elementdij*));
    for (i=0; i<heigth; i++) {
        dijkstra.matrix[i] = (elementdij*)calloc(width,sizeof(elementdij));
    }
    return dijkstra;
}

void destroyDijkstraMatrix(dijkstraMatrix* dijkstra) {
    int i;

    for (i=0; i<getHeigthMatrixDijkstra(dijkstra); i++) {
        free(dijkstra->matrix[i]);
    }
    free(dijkstra->matrix);
}
