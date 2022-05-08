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

void showStack(StackLink sl){
    if(sl.topNum==-1){//栈空情况
        printf("栈空");
        return;
    }
    for(int i=sl.topNum;i>=0;i--){
        printf("%c\n",sl.NodeData[i]);
    }
}

void work03(){
    StackLink sl;
    InitStack(&sl);
    int n;
    scanf("%d",&n);
    while(n!=-1){
        StackPush(&sl,n);
        scanf("%d",&n);
    }
    // StackPop(&sl,&n);
    showStack(sl);
}
bool work05(char *str){
    StackLink sl;
    InitStack(&sl);
    int i=0,n;
    // 根据情况对数组数据进行入栈和出栈
    while(str[i]){
        if(str[i]=='I'){
            StackPush(&sl,str[i]);
        }else if(str[i]=='O'){
            StackPop(&sl,&n);
        }else{
            printf("数组当前数据有误\n");
            return false;
        }
        i++;
    }
    showStack(sl);
    if(sl.topNum==-1){//栈空情况
        printf("栈空");
        return true;
    }
    return false;
}
//递归
int Ack(int m,int n){
	if (m==0) return n+1;
	else if(m!=0&&n==0) return Ack(m-1,1);
	else return Ack(m-1,Ack(m,n-1));
}
int main(){
    // work03();
    // char s[]="IIIOOIOO";
    // if(work05(s)){
    //     printf("\n合法序列\n");
    // }else{
    //     printf("\n非法序列\n");
    // }
    int a = Ack(2,1);
    printf("%d",a);
}