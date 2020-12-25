#include<stdio.h>
#include<assert.h>
#include"grid.h"

int main(void){

	Frame frame = init_frame();
	assert(403 == (sizeof frame.GRID/ sizeof(unsigned)));
	// printf("%zu\n", );
	return 0;
}
