#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include "easy_func.hpp"

void usage(char *program){
    printf("[使用方法]: %s '自己紹介'　",program);
    exit(0);
}

int main(int argc,char *argv[]){
    if(argc<2)usage(argv[0]);
    int uid=getuid();

    //自己紹介に入れる文章
    char data[200];

    int fd=open("notes",O_RDWR);

    //すでにこのユーザーがnotesに記録されているか否か
    int exist=0;
    char c,skip[205];
    int usr;
    while(read(fd,&usr,4)==4){
        if(usr!=uid){
            read(fd,&skip,202);
            continue;
        }
        exist=1;
        read(fd,&c,1);
        write(fd,data,200);
        break;
    }

    //新しくnotesにそのユーザーのスペースを確保
    if(!exist){
        write(fd,&uid,4);
        write(fd,":",1);
        write(fd,data,200);
        write(fd,"\n",1);
    }

    close(fd);
}