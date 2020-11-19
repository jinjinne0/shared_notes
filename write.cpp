#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "easy_func.hpp"

void usage(char *program){
    printf("[使用方法]: %s '自己紹介'　",program);
    exit(0);
}