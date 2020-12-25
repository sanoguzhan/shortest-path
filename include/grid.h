#ifndef __GRID_
#define __GRID_


#define N_DIM 20


typedef void (*func)(unsigned grid[N_DIM][N_DIM]);
typedef struct Frame
{
   unsigned GRID[N_DIM][N_DIM];
   unsigned index[N_DIM][N_DIM];
   func show;

} Frame;


Frame init_Frame();
void print_grid(unsigned[N_DIM][N_DIM]);
#endif
