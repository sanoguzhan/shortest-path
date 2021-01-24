#include<stdio.h>
#include "algorithm.h"
#include "math.h"


void add_parent(Node* node, Node* parent){
    node->parent = parent;
}

int** create_path(int* maze[N_DIM], 
                  int point_start[2],
                  int point_end[2]){

    const int MAXITER = pow((N_DIM / 2), 10);
    static int index = 0;
    static int counter = 0;
    static int size_vList = 2*1000;

    struct Node* boundaries = malloc(2*sizeof(Node));
    struct Node* vList = malloc(size_vList*sizeof(Node));
    struct Node* childs = malloc(size_vList*sizeof(Node));
    struct Node* current_node = malloc(sizeof(Node));
    struct Node tNode;
    memcpy(boundaries[0].points, point_start, sizeof(int)*2);
    memcpy(boundaries[1].points, point_end, sizeof(int)*2);

    for(int i = 0; i < 2; i++){
        printf("%d\n",boundaries[i].points[i]);
    }

    int position[2];
    int moves[4][2] = {{-1, 0},  // up
                      {0, -1},  // left
                      {1, 0},   // down
                      {0, 1}};  // right

    vList[0] = boundaries[0];
    dSize = 1;

    while(counter > 0){

        *current_node = vList[0];
        index = mv_current_node(vList, current_node, dSize);

        for(int i=0; i<4; i++){
            position[0] = current_node->points[0] + moves[i][0];
            position[1] = current_node->points[1] + moves[i][1];

            if(position[0] > (N_DIM -1)
                || position[0] < 0
                || position[1] > (N_DIM -1)
                || position[1] < 0){continue;}

            if(maze[position[0]][position[1]] != 0){continue;}

         
        }

        relate(childs, current_node, position);

        for(int i=0; i<size_vList;i++){
            if(childs[i].state){
                continue;
            }
            if(childs[i].hold){
                childs[i].g = current_node->g + STEP_SIZE;
                childs[i].h = (pow((childs[i].points[0] - point_end[0]),2) +
                            pow((childs[i].points[1] - point_end[1]),2));
            childs[i].f = childs[i].g + childs[i].h;
            if(is_child(childs, vList, size_vList)){
                continue;
                }            

            insert_vlist(vList, childs[i], size_vList);
            }                                
        }

    }

}

bool insert_vlist(Node*, Node, int);
bool is_child(Node*, Node*, int);
void relate(Node* childs, Node* cNode, int coor[]);
int mv_current_node(Node*, Node*, const int);
static short compare_nodes(const Node*, const Node*);