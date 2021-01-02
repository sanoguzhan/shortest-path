#include "utils.h"


void log_print(const char*, const char* );

struct logger* log_init(){
    struct logger *log_t= malloc(sizeof(logger));
    log_t->print = log_print;
    return log_t;
}