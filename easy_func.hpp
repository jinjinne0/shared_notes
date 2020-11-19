#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//エラーメッセージを表示して終了する関数
//エラーメッセージは83文字まで表示可能(ASCIIで)
void fatal(char *message){
    char e_message[100];
    strcpy(e_message,"[!!]fatal error:");
    strncat(e_message,message,83);
    perror(e_message);
    exit(-1);
}

//malloc()とエラー判定をセットにした関数
void *e_malloc(unsigned int size){
    void *ptr;
    ptr=malloc(size);
    if(ptr==NULL)
        fatal("e_malloc()でメモリの確保に失敗しました。");
    return ptr;
}
