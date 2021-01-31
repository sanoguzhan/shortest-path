#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<errno.h>
#include"grid.h"
#include "utils.h"

extern int errcode;

void test_grid_size(Frame frame, struct logger* log){

	assert(100 == (sizeof frame.GRID/ sizeof(unsigned)));
	log->print("Succes",__func__);

}


void test_index_size(Frame frame, struct logger *log){
	assert(100 == (sizeof frame.index/ sizeof(unsigned)));
	log->print("Succes",__func__);	
}
int main(void){
	struct logger* log = log_init();
	Frame frame = init_frame();
	test_grid_size(frame, log);
	test_index_size(frame, log);
	

	return 0;

}
