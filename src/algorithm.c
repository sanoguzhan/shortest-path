#include "algorithm.h"
#include "math.h"

int** create_path(int coordinate[N_DIM][N_DIM], int point_start[2],
    int point_end[2]){
    struct Node* initial = malloc(sizeof(Node));
    struct Node* end = malloc(sizeof(Node));

    memcpy(initial->points, point_start, sizeof(int)*2);
    memcpy(end->points, point_end, sizeof(int)*2);


    for(int i = 0; i < 2; i++){
        printf("%d",initial->points[i]);
    }

    const int MAXITER = pow((N_DIM / 2), 10);
    
    int move[4][2] = {{-1, 0},  //up
                      {0, -1},  //left
                      {1, 0},   //down
                      {0, 1}};   //right



}