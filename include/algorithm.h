
/** @file algorithm.hpp
 *  @brief Solvers
 *
 *  
 *  @author Oguzhan San
 *  @bug No known bugs.
 * 
 */ 

#ifndef __ALGORITHM_
#define __ALGORITHM_

#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<tgmath.h>
#include "grid.h"


// Cost for each step move
#define STEP_SIZE 1
static int dSize;

/**
 * @brief Node Struct
 *
 *  Holds data for each node in the Grid
 * 
 */
typedef struct Node{
    double f;
    double g;
    double h;

    int points[2];

    bool state;
    bool hold;
    struct Node* parent;
    
} Node;

        
/**
 * @brief Adds Parent to Child Node
 *
 * Assign  
 * @return path Path to yaml file.
 */

void add_parent(Node*, Node*);

/**
 * @brief Solver for Maze
 *
 * Creates Nodes on Heap
 * Validates Boundary Conditions
 * 
 * @return 2-D array of solved maze
 */
int** solve(unsigned[][N_DIM], int[2], int[2]);


/**
 * @brief Move Node to Node List
 *
 * Moves attributes of second element to first element
 * @param current_node pointer Node instance
 * @param vList pointer Node instances list
 * @param size int 
 * 
 * @return int index of moved item
 */
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


/**
 * @brief Relates given Nodes
 *
 * @param childs pointer Node instance
 * @param cNode pointer Node instances list
 * @param coor coordinates 1d array
 * 
 */
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

/**
 * @brief Checks if the points the parent
 *
 * @param child pointer Node instance
 * @param vlist pointer Node instances list
 * @param size size of array
 * 
 * @return bool status of comparasion
 */
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


/**
 * @brief Compares Nodes Points with given Points
 *
 * @param node pointer Node instance
 * @param points 1-d array
 * 
 * @return bool status of comparasion
 */
inline bool compare(Node* node, int points[2]){
    if(node->points[0] == points[0]
       && node->points[1] == points[1]){
           return true;
       }
    return false;
}

/**
 * @brief Removes Nodes
 *
 * Removes node at index from list 
 * @param vlist pointer to Node list
 * @param index int
 */
inline void remove_node(Node* vlist, int index){
    vlist[index].f=0;
    vlist[index].g=0;
    vlist[index].h=0;
    vlist[index].hold = false;
    vlist[index].points[0] = 0;
    vlist[index].points[1]= 0; 
}


/**
 * @brief Inserts Node to List
 *
 * Insert second argument to first Argument
 * 
 * @param vlist pointer to Node list
 * @param node  Node instance
 * @param size int
 * 
 * @returns bool status of operation 
 */
inline bool insert_vlist(Node* vlist, Node node,int size){
    for(int i=0; i<size; i++){
        if(!vlist[i].hold){
                vlist[i].f=node.f;
                vlist[i].g=node.g;
                vlist[i].h=node.h;
                vlist[i].hold = true;
                vlist[i].points[0] = node.points[0];
                vlist[i].points[1]= node.points[1];
                return true;
        }        
    }
    return false;
}
#endif