#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct QueueNode{
    int NodeData;
    struct QueueNode *next;
}QueueNode,*QueueND;//队列节点

typedef struct QueueList{
    QueueND front,rear;
}QueueList,*QueueLink;

// 此队列引入了头指针 即front指向的元素为头元素 不存储值
QueueLink InitQueueLink(QueueLink QL){
    QL = (QueueLink)malloc(sizeof(QueueList));
    int x;
    QueueND QN; 
    QL->front = QL->rear =(QueueND)malloc(sizeof(QueueNode));  
    QL->front->next = NULL; 
    scanf("%d",&x);
    while(x!=-1){
        // 队尾节点后移
        QN = (QueueND)malloc(sizeof(QueueNode));
        QN->next = NULL;
        QN->NodeData =x;
        // 引入头指针概念
        QL->rear->next = QN;//首尾元素指针域指向新添指针
        QL->rear = QN;// 首元素指针域仍旧指向原先添加节点,尾元素的指向尾元素
        scanf("%d",&x);
    }
    return QL;
}
// 入队
void EnQueueLink(QueueLink QL,int dat){
    QueueND QN=(QueueND)malloc(sizeof(QueueNode));
    QN->next = NULL; 
    QN->NodeData = dat;
    QL->rear->next = QN; 
    QL->rear = QN;
    // return QL;
}

// 出队
void DeQueueLink(QueueLink QL){
    if(QL->front == QL->rear){
        printf("空队列");
        return ;
    }
    QueueND QD= QL->front->next;
    QL->front->next = QD->next;
    if(QD == QL->rear){//如果只有一个节点在删除后设置队列为空
       QL->rear = QL->front;
    }
    free(QD);
}


// 打印队列
void ShowQueueLink(QueueLink QL){
    QueueND n ; 
    n = QL->front->next;//指向队列首元素
    if(QL->front == QL->rear){
        printf("空队列");
        return ;
    }
    while(n!=NULL){
        printf("队列值:%d\n",n->NodeData);
        n = n->next;
    }
    return ;
}

int main(){
    QueueLink ql;
    ql = InitQueueLink(ql);
    DeQueueLink(ql);
    ShowQueueLink(ql);
}