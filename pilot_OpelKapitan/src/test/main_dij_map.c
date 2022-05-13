






#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/dijkstraAlgo.h"
#include "../../include/dijkstraMatrix.h"
#include "../../include/graphMadj.h"
#include "../../include/pathList.h"
#include "../../include/list.h"





void main(int argc, char* argv[]) {

    if (argc != 2) {
        return EXIT_FAILURE;
    }

    FILE* map;
    int i;
    int j;
    int countFinish =0;
    char path[] = "../../../tracks/";
    char* fileName;
    int heigth;
    int width;
    int fuel;
    GRAPH graph;
    dijkstraMatrix dijkstra;
    char mapValue;


    fileName = (char*)malloc( (strlen(path) + strlen(argv[1]) ) * sizeof(char));
    strcpy(fileName, path);
    strcat(fileName, argv[1]);

    map = fopen(fileName, "r");
    if(map == NULL){
		printf("Impossible d'ouvrir le fichier en read\n");
		return EXIT_FAILURE;
	}
    fscanf(map, "%d %d %d", &width, &heigth, &fuel);

    graph = createGraph(heigth, width);
    dijkstra = createDijkstraMatrix(heigth, width);

    for ( i = 0; i < heigth; i++ ) {
        for ( j = 0; j < width; j++ ) {
            fscanf(map, "%c", &mapValue);
            if (mapValue == '=') {
                graph.finishLineCoord[countFinish].X = j;
                graph.finishLineCoord[countFinish].Y = i;
                countFinish++;
            }
            graph.graph.matrix[j][i] = mapValue;
        }
    }




    fclose(map); 
}