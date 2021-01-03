#ifndef __ALGORITHM_
#define __ALGORITHM_

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "grid.h"

#define STEP 1
typedef struct Node{
    double f;
    double g;
    double h;

    struct Node* next;
    int points[2];

} Node;



int** create_path(int(*)[N_DIM] , int[2],
    int[2]);

#endif