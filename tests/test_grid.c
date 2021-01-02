#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"grid.h"
#include "utils.h"


void test_grid_size(Frame frame){
	struct logger* log = log_init();
	assert(400 == (sizeof frame.GRID/ sizeof(unsigned)));
	log->print("Succes",__func__);
}

void print_line();
int main(void){

	Frame frame = init_frame();
	test_grid_size(frame);

	return 0;

}
