#include "grid.h"
#include <stdio.h>


Frame init_frame(){
   Frame frame;
   register unsigned loc = 0;
   for(size_t i=0; i< N_DIM; i++){
      for(size_t j=0;j< N_DIM; j++){
         frame.index[i][j]=loc;
         frame.GRID[i][j]=0;
         loc++;
      }
   }
   return frame;
}


void print_grid(unsigned grid[N_DIM][N_DIM]){
  unsigned item=0;
  printf("%*s", 15, " ");
  printf("%s","GRID 10x10");
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