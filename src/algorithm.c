#include<stdio.h>
#include "algorithm.h"
#include "math.h"


void add_parent(Node* node, Node* parent){
    node->parent = parent;
}

int** solve(unsigned maze[N_DIM][N_DIM], 
                  int point_start[2],
                  int point_end[2]){

    const int MAXITER = pow((N_DIM / 2), 3);
    static int index = 0;
    static int counter = 0;
    static int size_vList = 1000;

    struct Node* boundaries = malloc(2*sizeof(Node));
    struct Node* vList = malloc(size_vList*sizeof(Node));
    struct Node* childs = malloc(size_vList*sizeof(Node));
    struct Node* current_node = malloc(sizeof(Node));
    memcpy(boundaries[0].points, point_start, sizeof(int)*2);
    memcpy(boundaries[1].points, point_end, sizeof(int)*2);

    int position[2];
    int moves[4][2] = {{-1, 0},  // up
                      {0, -1},  // left
                      {1, 0},   // down
                      {0, 1}};  // right

    vList[0] = boundaries[0];
    dSize = 1;
    while(dSize > 0){
        counter++;
        *current_node = vList[0];
        for(int i=0; i < size_vList; i++){
            if(vList[i].hold){
                if (vList[i].f < current_node->f){
                    *current_node = vList[i];                                
                    remove_node(vList, i);
                    dSize--;
                }
            }
        }

        if(compare(current_node, point_end)){break;}
        index = mv_current_node(vList, current_node, dSize);
        if(MAXITER <= counter){break;}

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
            childs[i].hold = true;
            if(is_child(childs, vList, size_vList)){
                continue;
                }            


            insert_vlist(vList, childs[i], size_vList);
            dSize++;
            }                                
        }

    }

}

bool compare(Node*, int[2]);
void remove_node(Node*, int);
bool insert_vlist(Node*, Node, int);
bool is_child(Node*, Node*, int);
void relate(Node* childs, Node* cNode, int coor[]);
int mv_current_node(Node*, Node*, const int);
static short compare_nodes(const Node*, const Node*);