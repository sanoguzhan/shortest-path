#ifndef __ALGORITHM_
#define __ALGORITHM_

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include "grid.h"

#define STEP_SIZE 1
static int dSize;

typedef struct Node{
    double f;
    double g;
    double h;

    int points[2];

    bool state;
    struct Node* parent;

} Node;



void add_parent(Node*, Node*);
int** create_path(int[N_DIM][N_DIM], int[2], int[2]);

inline int mv_current_node(Node* vList, Node* current_node, const int size){
      int i;
      for(i=0; i < size; i++){
            if(vList[i].f < current_node->f){
                if(!vList[i].state){
                    current_node = &vList[i];
                    vList[i].state = true;
                }
            }
        }
        return i;
}

inline static short compare_nodes(const Node* left, const Node* right){
    if(left->points[0] == right->points[0] &&
        left->points[1] == right->points[1])
        return 1;
    return 0;
}
#endif