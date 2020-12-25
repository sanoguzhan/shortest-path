#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N_DIM 20

typedef void (*func)(unsigned grid[N_DIM][N_DIM]);
typedef struct Frame
{
   unsigned GRID[N_DIM][N_DIM];
   unsigned index[N_DIM][N_DIM];
   func show;

} Frame;

Frame init_Frame(){
   Frame frame;
   register unsigned loc = 0;
   for(size_t i=0; i< N_DIM; i++){
      for(size_t j=0;j< N_DIM; j++){
         frame.index[i][j]=loc;
         loc++;
      }
   }
   return frame;
}

static unsigned GRID[N_DIM][N_DIM];

void print_grid(int grid[N_DIM][N_DIM]){
  unsigned item=0;
  printf("%*s", 30, " ");
  printf("GRID 20x20", 20);
  printf("\n");

  for(size_t i=0; i<N_DIM; i++){
     printf("-");
      for(size_t j=0; j<N_DIM; j++){
         
         printf("----");
      }
      puts("");
      printf("| ");
      for(size_t j=0; j<N_DIM; j++){
         item = grid[i][j];
         printf("%u",item);
         if(item < 9) printf(" | ");
         else if (item < 99) printf("| ");
         else printf("|");
      }
     puts(""); 
   } 
}

int main(int argc, char* argv[argc +1]){
   Frame frame = init_Frame();
   frame.show = print_grid;
   frame.show(frame.GRID);
   frame.show(frame.index);
    return 0;
}