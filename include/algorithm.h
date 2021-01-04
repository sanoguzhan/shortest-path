#ifndef __ALGORITHM_
#define __ALGORITHM_

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "grid.h"

#define STEP_SIZE 1
typedef struct Node{
    double f;
    double g;
    double h;

    struct Node* next;
    int points[2];

} Node;



int** create_path(int(*)[N_DIM], int[2], int[2]);

inline unsigned get_current_node(unsigned size, Node* nodes, Node* node){
    unsigned indx = 0;
    unsigned found = 0;
    for(unsigned i = 0; i <size; i++){
        if(nodes[i].f < node->f){
            node = &node[i];
            found = indx;
        }
        indx++;
    }
    return found;
}

#endif