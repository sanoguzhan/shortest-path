#ifndef __UTILS_
#define __UTILS_


#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

#define STRIPPATH(s)\
    (sizeof(s) > 2 && (s)[sizeof(s)-2] == '/' ? (s) + sizeof(s) - 1 : \
    sizeof(s) > 3 && (s)[sizeof(s)-3] == '/' ? (s) + sizeof(s) - 2 : \
    sizeof(s) > 4 && (s)[sizeof(s)-4] == '/' ? (s) + sizeof(s) - 3 : \
    sizeof(s) > 5 && (s)[sizeof(s)-5] == '/' ? (s) + sizeof(s) - 4 : \
    sizeof(s) > 6 && (s)[sizeof(s)-6] == '/' ? (s) + sizeof(s) - 5 : \
    sizeof(s) > 7 && (s)[sizeof(s)-7] == '/' ? (s) + sizeof(s) - 6 : \
    sizeof(s) > 8 && (s)[sizeof(s)-8] == '/' ? (s) + sizeof(s) - 7 : \
    sizeof(s) > 9 && (s)[sizeof(s)-9] == '/' ? (s) + sizeof(s) - 8 : \
    sizeof(s) > 10 && (s)[sizeof(s)-10] == '/' ? (s) + sizeof(s) - 9 : \
    sizeof(s) > 11 && (s)[sizeof(s)-11] == '/' ? (s) + sizeof(s) - 10 : (s))

#define __FILENAME__ STRIPPATH(__FILE__)



inline void log_print(const char* log){
    puts(log);

}


#endif 
