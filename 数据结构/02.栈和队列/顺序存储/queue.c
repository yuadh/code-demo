#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxSize 50
#define bool int
#define true 1
#define false 0
// tag=0 时栈为空栈， tag=1 时栈为满栈
int tag=0;
// 数据结构采用循环队列防止假溢出问题
typedef struct QueueLink{
    int NodeData[MaxSize];
    int front,rear;
}QueueLink;
void checkStatus(QueueLink *QL);
void InitQueueLink(QueueLink *QL){
    QL->front = QL->rear =0;
}
// 入队
void EnQueueLink(QueueLink *QL,int dat){
    checkStatus(QL);
    if(tag==1){//栈满情况
        return;
    }
    QL->NodeData[QL->rear] = dat;
    QL->rear = (QL->rear+1)%MaxSize;
    tag = -1;//能正常操作 清除标志状态
    return ;
}
void DeQueueLink(QueueLink *QL,int *dat){
    checkStatus(QL);
    if(tag==0){//栈空情况
        return;
    }
    *dat = QL->NodeData[QL->front];
    QL->front = (QL->front+1)%MaxSize;
    tag = -1;//能正常操作 清除标志状态
    return ;
}
void checkStatus(QueueLink *QL){
    if((QL->rear+1)%MaxSize==QL->front){
        printf("队列满\n");
        tag=1;
        return;//栈满情况
    }
    if(QL->front==QL->rear){
        printf("队列空\n");
        tag=0;
        return; //栈空情况
    }
}
void showQueue(QueueLink ql){
    //打印栈
    printf("队列的打印:\n");
    for(int i=ql.rear-1;i>=ql.front;i--){
        printf("%d\n",ql.NodeData[i]);
    }
}
void work03(){
    QueueLink ql;
    InitQueueLink(&ql);
    int n;
    scanf("%d",&n);
    while(n!=-1){
        EnQueueLink(&ql,n);
        scanf("%d",&n);  
    }
    DeQueueLink(&ql,&n);
    showQueue(ql);
}
int work05(int *a){
    int i=0,L;
    QueueLink ql;
    InitQueueLink(&ql);
    L = sizeof(a)/sizeof(int);
    while(i<L){
        EnQueueLink(&ql,a[i++]);
    }
    for(int i=ql.front;i<ql.rear;i++){
        printf("%d\n",ql.NodeData[i]);
    }
}

int main(){
    work03();
    // int a[]={1,2,3,4,5};
    // work05(a);
}       