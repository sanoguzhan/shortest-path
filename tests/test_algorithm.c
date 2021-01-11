#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<errno.h>
#include "algorithm.h"
#include "utils.h"



void test_thread_link(struct logger* log){
    Node* initial = malloc(sizeof(Node));
    Node* second = malloc(sizeof(Node));
    Node* test = malloc(sizeof(Node));
    test->f = 100;
    add_link(initial, second);
    add_link(initial, test);
    Node* tNode = initial;
    
    while(tNode->next){
        tNode = tNode->next;
    }

    assert((int)tNode->f == 100);
    assert(test == tNode);
    
    log->print("Success", __func__);
}




int main(void){
    struct logger* log = log_init();

    test_thread_link(log);
    
}


