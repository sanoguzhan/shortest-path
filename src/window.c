#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "window.h"
#include "grid.h"





int main(int argc, char* argv[argc +1]){
   Frame frame = init_frame();
   frame.show = print_grid;
   frame.show(frame.GRID);
   frame.show(frame.index);
    return 0;
}