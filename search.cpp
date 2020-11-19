#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include "easy_func.hpp"

void usage2(char *program){
    printf("[使用方法]: %s uid\n",program);
    exit(0);
}

int main(int argc,char *argv[]){
    if(argc<2)
        usage2(argv[0]);

    int uid=0;
    int s=1;
    for(int i=strlen(argv[1])-1;i>=0;i--){
        uid+=(argv[1][i]-'0')*s;
        s*=10;
    }

    int usr;
    int fd=open("notes",O_RDONLY);

    char data[205];
    char skip[205];
    char c;
    int exist=0;
    while(read(fd,&usr,4)==4){
        if(usr!=uid){
            read(fd,skip,202);
            continue;
        }
        exist=1;
        read(fd,&c,1);
        read(fd,data,200);
        data[200]='\0';
        break;
    }
    if(!exist){
        printf("そのユーザーの情報は無い\n");
    }
    else{
        printf("%d: %s\n",uid,data);
    }
    close(fd);

    return 0;
}