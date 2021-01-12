#include<stdio.h>
#include "algorithm.h"
#include "math.h"


void add_link(Node* list, Node* node){
    Node* nTemp = malloc(sizeof(Node));
    nTemp = list;
    while(nTemp->next){
        nTemp = list->next;
    }
    nTemp->next = node;
}

int** create_path(int coordinate[N_DIM][N_DIM], 
                  int point_start[2],
                  int point_end[2]){
 
    struct Node* boundaries = (Node*)malloc(2*sizeof(Node));
    struct Node* nTemp= NULL;
    memcpy(boundaries[0].points, point_start, sizeof(int)*2);
    memcpy(boundaries[1].points, point_end, sizeof(int)*2);

    for(int i = 0; i < 2; i++){
        printf("%d\n",boundaries[i].points[i]);
    }

    const int MAXITER = pow((N_DIM / 2), 10);
    static int index = 0;
    static int counter = 0;
    int move[4][2] = {{-1, 0},  // up
                      {0, -1},  // left
                      {1, 0},   // down
                      {0, 1}};  // right

    Thread* checks = calloc(1000,sizeof(Thread));
    Thread* sNode = NULL;
    Thread* iter = NULL;
    Thread* finished = NULL;    

    checks->node = &boundaries[0];
    nTemp = boundaries;
    sNode = checks;    
    
    while(sNode != NULL){
        counter++;
        iter = sNode;
        int i =0;
        while(iter != NULL){
            if(iter->node->f < nTemp->f){
                nTemp = iter->node;
                index = i;
            }
            i++;
            iter = iter->next;          
        }

        if(MAXITER < counter){
            exit(1);
        }
        sNode = sNode->next;

        move_node(checks, finished, counter);
        if(compare_nodes(nTemp, &boundaries[1])){
            exit(0); // Done
        }

        for(int j=0; j<4;j++){
            printf("%d %d\n", move[j][0], move[j][1]);
        }

    }
    
}

static short compare_nodes(const Node*, const Node*);
static void move_node(Thread*, Thread*, const int counter);