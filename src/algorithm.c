#include "algorithm.h"


int** create_path(int coordinate[N_DIM][N_DIM], int step, int point_start[2],
    int point_end[2]){
    struct Node* initial = malloc(sizeof(Node));
    memcpy(initial->points, point_start, sizeof(int)*2);

    for(int i = 0; i < 2; i++){
        printf("%d",initial->points[i]);
    }

}