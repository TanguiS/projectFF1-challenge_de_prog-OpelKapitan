






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

dijkstraMatrix createDijkstraMatrix(short width, short heigth) {
    int i;


    dijkstraMatrix dijkstra;
    dijkstra.matrix = (elementdij**)malloc(heigth*sizeof(elementdij*));
    for (i=0; i<heigth; i++) {
        dijkstra.matrix[i] = (elementdij*)malloc(width*sizeof(elementdij));
    }
    return dijkstra;
}

void destroyDijkstraMatrix(dijkstraMatrix dijkstra) {
    int i;

    for (i=0; i<getHeigthMatrixDijkstra(&dijkstra); i++) {
        free(dijkstra.matrix[i]);
    }
    free(dijkstra.matrix);
}
