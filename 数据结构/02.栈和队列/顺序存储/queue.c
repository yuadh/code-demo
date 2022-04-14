#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50
#define bool int
#define true 1
#define false 0
// 数据结构采用循环队列防止假溢出问题
typedef struct QueueLink{
    int NodeData[MaxSize];
    int front,rear;
}QueueLink;
void InitQueueLink(QueueLink *QL){
    QL->front = QL->rear =0;

}
// 入队
void EnQueueLink(QueueLink *QL,int dat){
    if((QL->rear+1)%MaxSize==QL->front){
        return ;//栈满情况
    }
    QL->NodeData[QL->rear] = dat;
    QL->rear = (QL->rear+1)%MaxSize;
    return ;
}
void DeQueueLink(QueueLink *QL,int *dat){
    if(QL->front==QL->rear){
        return; //栈空情况
    }
    *dat = QL->NodeData[QL->front];
    QL->front = (QL->front+1)%MaxSize;
    return ;
}

int main(){
    QueueLink ql;
    InitQueueLink(&ql);
    EnQueueLink(&ql,1);
    EnQueueLink(&ql,2);
    EnQueueLink(&ql,3);
    int t;
    DeQueueLink(&ql,&t);
    for(int i=ql.front;i<ql.rear;i++){
        printf("%d\n",ql.NodeData[i]);
    }
}       