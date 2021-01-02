#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"grid.h"
#include "utils.h"



int main(void){

	Frame frame = init_frame();
	puts("Test::Frame_size.................");
	assert(400 == (sizeof frame.GRID/ sizeof(unsigned)));
	puts(__FILENAME__);
	log_print("Succes");
	// printf("%zu\n", );
	return 0;
}
