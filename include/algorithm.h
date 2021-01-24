#ifndef __ALGORITHM_
#define __ALGORITHM_

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<tgmath.h>
#include "grid.h"

#define STEP_SIZE 1
static int dSize;

typedef struct Node{
    double f;
    double g;
    double h;

    int points[2];

    bool state;
    bool hold;
    struct Node* parent;
    
} Node;



void add_parent(Node*, Node*);
int** create_path(int*[N_DIM], int[2], int[2]);

inline int mv_current_node(Node* vList, Node* current_node, const int size){
      int i;
      for(i=0; i < size; i++){
            if(vList[i].f < current_node->f){
                if(!vList[i].state){
                    vList[i].state = true;
                    vList[i].hold=true;
                    *current_node = vList[i];
                    
                }
            }
        }
        return i;
}

inline void relate(Node* childs, Node* cNode, int coor[]){
                int index= 0;
                while(childs[index].hold){
                    index++;
                }
                childs[index].f=cNode->f;
                childs[index].g=cNode->g;
                childs[index].h=cNode->h;
                childs[index].hold = true;
                childs[index].parent = &childs[index+1];
            
                memcpy(childs[index].points, cNode->points, sizeof(int)*2);

                childs[index+1].hold = true;
                memcpy(childs[index+1].points, coor, sizeof(int)*2);
                
}           
inline static short compare_nodes(const Node* left, const Node* right){
    if(left->points[0] == right->points[0] &&
        left->points[1] == right->points[1])
        return 1;
    return 0;
}


inline bool is_child(Node* childs, Node* vlist, int size){
 for(int i=0; i < size; i++){
     for(int j=0; j<size; j++){
       if(vlist[i].points[0] == childs[j].points[0]
          && vlist[i].points[1] == childs[j].points[1]
          && vlist[i].g < childs[j].g){
              return true;
          }  
     }
 }   
 return false;
}


inline bool insert_vlist(Node* vlist, Node node,int size){
    for(int i=0; i<size; i++){
        if(!vlist[i].hold){
                vlist[i].f=node.f;
                vlist[i].g=node.g;
                vlist[i].h=node.h;
                vlist[i].hold = true;
                memcpy(vlist[i].points, node.points, sizeof(int)*2);
                return true;
        }        
    }
    return false;
}
#endif