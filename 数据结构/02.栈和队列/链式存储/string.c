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
    char str[1024];
    gets(str);
    // 以上为输入字符串的初始化
    int i=0,j=0;
    StrND sf = (StrND)malloc(sizeof(StrNode));
    SL->head->next = sf; 
    sf->next = NULL;
    while(str[j]){
        if(i == MaxSize){//创建一个新数组节点存储多出的字符串
            i = i%MaxSize;
            StrND sn = (StrND)malloc(sizeof(StrNode));
            sf->next = sn;
            sn->next = NULL;
            sf = sn;
        }
        sf->ch[i] = str[j];
        i++;
        j++;
    }
    if(i!=MaxSize){
        sf->ch[i++] = '#';
    }
    SL->StrLen = j;
    return SL;
}

void ShowStrLink(StrLink SL){
    if(SL->StrLen == 0){//串为空的情况
        return ;
    }
    int i=0;
    StrND sn = SL->head->next; //指向实际工作节点
    while(1){
        if(i==MaxSize){//不理解的字符串扩充操作
            i = i%MaxSize;
            sn = sn->next;
        }
        if(sn->next==NULL){
            printf("oooo");
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

StrLink copyStr(StrLink SL1,StrLink SL2){//字符串的赋值
    if(SL1->StrLen==0){
        printf("字符串为空");
        return NULL;
    }
    SL2 = (StrLink)malloc(sizeof(StrList));
    SL2->head = SL1->head;
    SL2->StrLen = SL1->StrLen;
    return SL2;
}

int main(){
    StrLink sl,sc;
    //malloc重新申请了内存空间所以会改变指向需要接收
    sl = InitStrLink(sl);
    sc = copyStr(sl,sc);
    // printf("%d",sc->StrLen);
    ShowStrLink(sl);
}