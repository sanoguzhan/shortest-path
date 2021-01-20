#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<errno.h>
#include "algorithm.h"
#include "utils.h"



void test_thread_link(struct logger* log){
    Node* initial = malloc(sizeof(Node));

    initial->f = 100;

    assert((int)initial->f == 100);
    
    log->print("Success", __func__);
}




int main(void){
    struct logger* log = log_init();

    test_thread_link(log);
    
}


