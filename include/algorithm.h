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

    int points[2];
    struct Node* next;

} Node;


typedef struct Thread{
    Node* node;
    struct Thread* next;
} Thread;

void add_link(Node*, Node*);
int** create_path(int[N_DIM][N_DIM], int[2], int[2]);


inline static void move_node(Thread* from, Thread* to, const int bound){
    if(bound < 2 && bound >0){
        while(from->next != NULL){
            from = from->next;
        }         
    }else{
       while(from->next->next != NULL){
            from = from->next;
        }
    }
    if(to != NULL){
        while (to->next != NULL){
            to = to->next;
        }
    }
   if (to == NULL && from->next != NULL){
        to = from->next;
   }
   else if(to == NULL && from->next == NULL){
       to = from;
   }
   else{
       to->next = from->next;
   }
}

inline static short compare_nodes(const Node* left, const Node* right){
    if(left->points[0] == right->points[0] &&
        left->points[1] == right->points[1])
        return 1;
    return 0;
}
#endif