#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50
#define bool int
#define true 1
#define false 0

typedef struct StackLink{
    int NodeData[MaxSize];
    int topNum;
}StackLink;

//顺序存储栈的初始化
void InitStack(StackLink *SL){
    SL->topNum = -1;
    return ;//初始化一个没有栈底的栈队列
}
// 进栈
bool StackPush(StackLink *SL,int dat){
    if(SL->topNum==MaxSize-1){//栈满
        return false;
    }
    SL->NodeData[++SL->topNum]=dat;
    return true;
}
// 出栈
bool StackPop(StackLink *SL,int *x){
    if(SL->topNum==-1){//栈空
        return false;
    }
    *x = SL->NodeData[SL->topNum--];
    return true;
}

int main(){
    StackLink  sl;int x;
    InitStack(&sl);
    StackPush(&sl,1);
    StackPush(&sl,2);
    StackPush(&sl,3);
    StackPush(&sl,4);
    StackPop(&sl,&x);
    printf("%d",x);
}