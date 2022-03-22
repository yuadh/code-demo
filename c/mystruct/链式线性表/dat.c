#include <stdio.h>
#include <stdlib.h>

#define success 1
#define error 0
typedef int status;

typedef struct{
    int id;
    float score;
}student; 
typedef struct LinkNode{
    int dat;
    struct LNode *next;
}LinkNode,*LinkList;
// 概念
// 首元节点
// 头节点
// 头指针
//opeartion

// 初始化链表 传入头指针并初始化
status InitList(LinkList L){
    LinkNode node;
    *L=node;//头指针指向头结点
    node.next = NULL;
    return success;
}
//创建链表 头插法
status CreateListHead(LinkList L){
    int dat; LinkNode *n;
    scanf("%d",&dat);
    while(dat>=0){//输入负数停止插入
        n = (LinkNode*)malloc(sizeof(LinkNode));
        n->dat = dat;
        n->next = L->next;
        L->next = n;
        scanf("%d",&dat);
    }
    return success;
}
//创建链表 尾插法
status CreateListEnd(LinkList L){
    int dat; LinkNode *n;
    scanf("%d",&dat);
    
}
// 插入链表 
status insertList(LinkList L,int i,student dat){

}

int main(){
    LinkList L;
    InitList(L);
    printf("hell");
}