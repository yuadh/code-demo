#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Link.h"


//链表的实体不使用指针，但在链表结构方法传值时需要使用到指针
//头指针表示链表的名称
int main(){
    //头指针：指向头节点的指针
    //头节点：不存储数据的，指向链表首元素的头结点
    //首元素：链表的第一个元素?
    ListArg=InitListEnd(ListArg); //头指针，传入头结点的地址
    // printf(ListArg->nodeData);
    // ListNode a = {4,NULL};
    // ListAddNode(ListArg,4,a);
    // ListOne=getItemUN(ListArg,5);
    // LinkList x = getItem(ListArg,4);
    // printf("取值:%d\n",ListOne.nodeData);
    ListRmNode(ListArg,4);
    ShowList(ListArg);
    return 0;
}

