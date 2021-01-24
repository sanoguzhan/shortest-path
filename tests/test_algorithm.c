#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<errno.h>
#include "algorithm.h"
#include "utils.h"
#include "grid.h"


void test_thread_link(struct logger* log){
    Node* initial = malloc(sizeof(Node));

    initial->f = 100;

    assert((int)initial->f == 100);
    
    log->print("Success", __func__);
}




int main(void){
    struct logger* log = log_init();
   Frame frame = init_frame();

    int begin[] = {0,0};
    int end[] = {10,10};
   frame.show = print_grid;

   frame.show(frame.GRID);
    create_path(&frame.GRID, begin, end);
    test_thread_link(log);

}


