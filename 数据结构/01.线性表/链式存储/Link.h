#ifndef  _Link_H_
#define _Link_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct ListNode//定义链表节点
{
    int nodeData;//数据??
    struct ListNode *nodeNext;//地址??
}ListNode,*LinkList;//指向节点的指??
typedef struct ListNodeDDW{
    struct ListNodeDDW *nodePrev;
    int nodeData;
    struct ListNodeDDW *nodeNext; 
}ListNodeDDW,*LinkListDDW;
LinkList ListArg;//链表头节??
ListNode ListOne;//实体节点
// 函数声明
LinkList InitListHead(LinkList L);


//opear
LinkList InitListHead(LinkList L){
    //初始化链表：返回一个指向头节点的链表指针，因为是空节点所以头节点的指针域指向NULL
    ListNode *LN ;int x;
    L = (LinkList)malloc(sizeof(ListNode));
    L->nodeNext = NULL;
    scanf("%d",&x);
    while(x!=-1){
        LN = (ListNode*)malloc(sizeof(ListNode));
        LN->nodeData=x;
        LN->nodeNext=L->nodeNext;
        L->nodeNext=LN;
        scanf("%d",&x);
    }
    return L;
}
LinkList InitListEnd(LinkList L){
    ListNode *LN,*EN; int x;
    L = (LinkList)malloc(sizeof(ListNode));
    L->nodeNext = NULL;
    EN = L;//尾节点
    scanf("%d",&x);
    while(x!=-1){
        LN = (ListNode*)malloc(sizeof(ListNode));
        LN->nodeData = x;
        EN->nodeNext = LN;
        EN = LN;
        scanf("%d",&x);
    }
    EN->nodeNext = NULL;
    return L;
}
LinkListDDW InitListEndDDW(LinkListDDW  L){//双向循环链表尾插法
    ListNodeDDW *LN,*EN;int x;
    L = (LinkListDDW)malloc(sizeof(ListNodeDDW));
    L->nodeNext = NULL; L->nodePrev = NULL;
    EN = L;//工作指针
    scanf("%d",&x);
    while(x!=-1){
        LN = (ListNodeDDW*)malloc(sizeof(ListNodeDDW));
        LN->nodeData = x;
        LN->nodePrev = NULL;
        LN->nodeNext = NULL;

        EN->nodeNext = LN;
        LN->nodePrev = EN;
        EN = EN->nodeNext;
        scanf("%d",&x);
    }
    EN->nodeNext = L;
    L->nodePrev = EN;

    return L;
}
void ShowListDDW(LinkListDDW L){//通过后续节点遍历
    if(L->nodeNext==L){
        printf("链表为空");
        return;
    }
    LinkListDDW f = L->nodeNext;//指向首元节点
    while(f&&f!=L){
        printf("链表值:%d\n",f->nodeData);
        f = f->nodeNext;
    }
    return ;
}
void ShowList(LinkList L){//循环输出链表值
    if(L->nodeNext==NULL){
        printf("链表为空");
        return;
    }
    LinkList f = L->nodeNext;//指向首元节点
    while(f){
        printf("链表值:%d\n",f->nodeData);
        f = f->nodeNext;
    }
    return ;
}

ListNode getItemUN(LinkList L,int Nx){//根据索引获取节点
    ListNode  *p = L->nodeNext; //指向首元节点
    int f = 1;
    if(Nx == 0){ // 空表返回头节点 
        return *L;
    } 
    while(p&&f<Nx){ //从首元节点开始循环链表指向下一位
        p=p->nodeNext;
        f++;
    }
    return *p;
}
ListNode getItemUV(LinkList L,int val){//根据节点值获取节点
    ListNode *p = L->nodeNext;//指向首元节点
    while(p&&p->nodeData!=val){
        p = p->nodeNext;
    }
    return *p;//如果链表为空返回值NULL
}
void ListAddNode(LinkList L,int n,ListNode LN){
    LinkList p = L; int f=0;
    while(p&&f<(n-1)){//表头不为空将链表推至需要插入的前一位
        p=p->nodeNext;
        f++;
    }
    if(!p){//如果插入位置的前一个节点为空则出错
        printf("error");
        return ;
    }
    LN.nodeNext = p->nodeNext;
    p->nodeNext = &LN;
    return ;
}
ListNode ListRmNode(LinkList L,int n){
    LinkList p = L; int f=0;
    while(p&&f<(n-1)){//循环到要删除的前一个元素
        p=p->nodeNext;
        f++;
    }
    if(!p->nodeNext){//如果要删除的元素为空 则返回
        printf("error");
        return *p->nodeNext;
    }
    LinkList delNode = p->nodeNext;
    p->nodeNext = delNode->nodeNext;
    free(delNode);
    return *delNode;
}
LinkList ListRmNodeUseNode(LinkList L){
    LinkList newList;
    newList = L->nodeNext;
    free(L);
    return newList;
}


#endif