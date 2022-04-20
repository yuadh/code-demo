// 串的链式存储结构
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MaxSize 24
typedef struct StrNode{//可以是主串的概念 也可以是子串
    char ch[MaxSize];
    struct StrNode* next;
}StrNode,*StrND;

typedef struct StrList{
    StrND head;
    int StrLen;
}StrList,*StrLink;

StrLink InitStrLink(StrLink SL){//引入了 头指针的概念 
    SL = (StrLink)malloc(sizeof(StrList));
    SL->head->next = NULL;
    SL->StrLen = 0;
    char str;
    gets(str);
    int i=0,j=0;
    StrND sf = (StrND)malloc(sizeof(StrNode));
    SL->head->next = sf; 
    sf->next = NULL;
    
    return SL;
}

void ShowStrLink(StrLink SL){
    if(SL->StrLen == 0){//串为空的情况
        return ;
    }
    int i=0;
    StrND sn = SL->head->next; //指向实际工作节点
    while(1){
        if(i=MaxSize){//不理解的字符串扩充操作
            i = i%MaxSize;
            sn = sn->next;
        }
        if(sn->next == NULL){
            for(;i<MaxSize;i++){
                if(sn->ch[i]=='#')
                    break;
                printf("%c ",sn->ch[i]);
            }
            break;
        }
        printf("%c ",sn->ch[i]);
        i++;
    }
    printf("\n");
}
