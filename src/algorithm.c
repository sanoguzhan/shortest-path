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
    static int iter = 0;
    static int index = 0;
    int move[4][2] = {{-1, 0},  //up
                      {0, -1},  //left
                      {1, 0},   //down
                      {0, 1}};   //right

    Node* nodes_check = calloc(N_DIM*N_DIM,sizeof(Node));

    Node* node = calloc(1,sizeof(Node));
    do
    {
       iter++;
       node = &nodes_check[index];

       

    } while (node != NULL);

}

unsigned get_current_node(unsigned, Node*, Node*);