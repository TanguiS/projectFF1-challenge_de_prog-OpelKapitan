






#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/dijkstraAlgo.h"
#include "../../include/dijkstraMatrix.h"
#include "../../include/graphMadj.h"
#include "../../include/pathList.h"
#include "../../include/list.h"





int main(int argc, char* argv[]) {

    

    FILE* map;
    FILE* outpu;
    int i;
    int j;
    int countFinish =0;
    char path[] = "../../../../tracks/";
    char* fileName;
    int heigth;
    int width;
    int fuel;
    GRAPH graph;
    dijkstraMatrix dijkstra;
    char mapValue;
    POSITION first;
    graphValues valueGraph;
    PATH_LIST stack;
    int count = 0;
    POSITION finalPath[1000];
    POSITION result;

    if (argc != 2) {
        printf("problème d'argument\n");
        return EXIT_FAILURE;
    }

    fileName = (char*)malloc( (strlen(path) + strlen(argv[1]) ) * sizeof(char));
    strcpy(fileName, path);
    strcat(fileName, argv[1]);

    map = fopen(argv[1], "r");
    if(map == NULL){
		printf("Impossible d'ouvrir le fichier en read\n");
		return EXIT_FAILURE;
	}
    fscanf(map, "%d %d %d", &heigth, &width, &fuel);

    graph = createGraph(heigth, width);
    dijkstra = createDijkstraMatrix(heigth, width);

    for ( i = 0; i < heigth; i++ ) {
        for ( j = 0; j < width; j++ ) {
            fscanf(map, "%c", &mapValue);
            if (mapValue == '.' ) {
                valueGraph = wallGraph;
            } else if (mapValue == '#'){
                valueGraph = roadGraph;
            } else if (mapValue == '~') {
                valueGraph = sandGraph;
            } else if (mapValue == '1' || mapValue == '2'|| mapValue == '3') {
                setElementGraph(&graph, '#', j, i);
                if (mapValue == '1'){
                    first.X = i;
                    first.Y = j;
                }
                valueGraph = road;
            } else if (mapValue == '=') {
                graph.finishLineCoord[countFinish].X = j;
                graph.finishLineCoord[countFinish].Y = i;
                countFinish++;
                valueGraph = finishLine;
            }
            setElementGraph(&graph, valueGraph, j, i);
        }
    }
    stack = givePath(&dijkstra, &graph, first);

    outpu = fopen("../test.txt", "w");

    while ( !isEmptyPathList ( stack ) ) {
        stack = removeHeadElementPathList ( stack, &result );
        printf ( "[%d, %d] ", result.X, result.Y );
        fprintf(outpu, "%d  %d\n", result.X, result.Y);
        count++;
    }
    printf("\n");
    
    fclose(map); 

    return 1;
}