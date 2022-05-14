






#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../../include/dijkstraAlgo.h"
#include "../../include/dijkstraMatrix.h"
#include "../../include/graphMadj.h"
#include "../../include/pathList.h"
#include "../../include/list.h"





int main(int argc, char* argv[]) {

    

    FILE* map;
    FILE* output;
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
    POSITION result;
    char buff[100];
    clock_t t1,t2;

    if (argc != 2) {
        printf("problème d'argument\n");
        return EXIT_FAILURE;
    }
    fileName = (char*)malloc( (strlen(path) + strlen(argv[1]) ) * sizeof(char));
    strcpy(fileName, path);
    strcat(fileName, argv[1]);

    map = fopen(argv[1], "r");
    output = fopen("../test.txt", "w");
    if(map == NULL){
		printf("Impossible d'ouvrir le fichier en read\n");
		return EXIT_FAILURE;
	}
    fgets(buff, 100, map);
    sscanf(buff, "%d %d %d", &width, &heigth, & fuel);
    
    t1=clock();
    
    graph = createGraph( width, heigth);
    dijkstra = createDijkstraMatrix(width, heigth);

    for ( j = 0; j < heigth; j++ ) {
        fgets(buff, 100, map);
        for ( i = 0; i < width; i++ ) {
            if ( buff[i] == wall ) {
                setElementGraph ( &graph, wallGraph, i, j );
            } else if ( buff[i] == road ) {
                setElementGraph ( &graph, roadGraph, i, j );
            } else if ( buff[i] == sand ) {
                setElementGraph ( &graph, sandGraph, i, j );
            } else if ( buff[i] == finishLine ) {
                setElementGraph ( &graph, finishLineGraph, i, j);
                graph.finishLineCoord[countFinish].X = i;
                graph.finishLineCoord[countFinish].Y = j;
                countFinish++;
            } else if (buff[i] == '1' || buff[i] == '2' ||buff[i] == '3') {
                if (buff[i] == '1') {
                    first.X = i;
                    first.Y = j;
                }
                setElementGraph(&graph, 1, i, j);
            }
        }
    }
    graph.sizeFinishLine = countFinish;
    stack = givePath(&dijkstra, &graph, first);

    displayDijkstraMatrix(&dijkstra, first.X, first.Y);

    while ( !isEmptyPathList ( stack ) ) {
        stack = removeHeadElementPathList ( stack, &result );
        printf ( "[%d, %d] ", result.X, result.Y );
        fprintf(output, "%d  %d\n", result.X, result.Y);
    }
    t2 = clock();
    printf("\ntimer : %f",(float)(t2-t1)/CLOCKS_PER_SEC);
    destroyDijkstraMatrix(dijkstra);
    destroyGraph(graph);
    destroyPathList (stack);
    free(fileName);
    fclose(output);
    fclose(map); 

    return 1;
}