#include <stdio.h>
#include <stdlib.h>
#inlcude <malloc.h>8
typedef struct ListNode//定义链表节点
{
    int nodeData;//数据�?
    struct ListNode *nodeNext;//地址�?
}ListNode,*LinkList;//指向节点的指�?
LinkList ListArg;//链表头节�?
ListNode ListOne;//实体节点
LinkList InitList(LinkList L);
LinkList InitList(LinkList L){
    //初始化链表：返回一个指向头节点的链表指针，因为是空节点所以头节点的指针域指向NULL
    ListNode *LN ;int x;
    L = (LinkList)malloc(sizeof(ListNode));
    L->nodeNext = NULL;
    scanf("%d",&x);
    while(x!=-1){
        LN = (ListNode*)malloc(sizeof(ListNode));
        LN->nodeData=x;
        L->nodeNext=LN;
        scanf("%d",&x);
    }
    return L;
}
//链表的实体不使用指针，但在链表结构方法传值时需要使用到指针
//头指针表示链表的名称
int main(){
    //头指针：指向头节点的指针
    //头节点：不存储数据的，指向链表首元素的头结点
    //首元素：链表的第一个元�?
    ListArg=InitList(ListArg); //头指针，传入头结点的地址
    // printf(ListArg->nodeData);
    printf("success-%d-one",ListArg->nodeNext->nodeNext->nodeData);

}