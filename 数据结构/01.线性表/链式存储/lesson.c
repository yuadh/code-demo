#include "Link.h"
// link.h 封装了链式存储链表的基本数据结构
// 以下是对题目的具体题解

/** 
01.将两个递增的有序列表合并为一个递增的有序列表。
要求结果链表仍使用原来两个链表的存储空间，不另外占用其它的存储空间。表中不允许有重复的数据
**/
void MergeList(LinkList listA,LinkList listB){
    LinkList tA = listA->nodeNext,tB = listB->nodeNext;//指向首元节点，工作节点
    LinkList t,tend; //临时辅助链表节点指针
    listA->nodeNext = NULL ; //指向空链表
    tend = listA; //尾节点
    while(tA&&tB){//
        if(tA->nodeData<tB->nodeData){
            //头插法插入插入链表
            tend->nodeNext = tA;
            tend = tA;
            tA = tA->nodeNext;
        }else if(tA->nodeData>tB->nodeData){
            tend->nodeNext = tB;
            tend = tB;
            tB = tB->nodeNext;
        }else{
            // 删除重复数据
            tend->nodeNext = tA;
            tend = tA;
            tA = tA->nodeNext;
            t = tB->nodeNext;
            free(tB);
            tB = t;
        }
    }
    tend->nodeNext = tA?tA:tB;
    free(listB);
}
// 已知两个链表 A 和 B 分别表示两个集合，其元素递增排列。
// 请设计一个算法，用于求出 A 与 B 的交集，并将结果存放在 A 链表中
void listAUlistB(LinkList la,LinkList lb){
    LinkList tA = la->nodeNext,tB = lb->nodeNext;
    LinkList tend,t;
    tend = la; // tend为指向新链表的尾元素
    while(tA&&tB){
        if(tA->nodeData==tB->nodeData){//交集，加入新链表释放多余节点
            tend->nodeNext = tA;
            tend = tA;
            tA = tA->nodeNext;
            t = tB;
            tB = tB->nodeNext;
            free(t);
        }else if(tA->nodeData<tB->nodeData){
            //因为是递增的链表所以要删除较小的元素来对比后面的元素是否有交集
            t = tA;
            tA = tA->nodeNext;
            free(t);
        }else{
            t = tB;
            tB = tB->nodeNext;
            free(t);
        }
    }
    while(tA){//释放剩余节点
        t = tA;
        tA = tA->nodeNext;
        free(t);
    }
    while(tB){
        t = tB;
        tB = tB->nodeNext;
        free(t);
    }
    tend->nodeNext = NULL;
    free(lb);
}
//设计算法将一个带头节点的单链表 A 分解为两个具有相同结构的链表 B 和 C，
//其中 B 表的节点为 A 表中值小于0的节点，
//而 C 表的节点为 A 表中值大于0的节点 (链表A中的元素为非零整数，要求B、C表利用A表的节点)
void  ListAtoBandC(LinkList la,LinkList lb,LinkList lc){
    LinkList tA= la->nodeNext,tB = lb,tC = lc; //指向各自链表的尾节点
    while(tA){//循环链表
        if(tA->nodeData == 0){
            return ;//如果有0整数
        }else if(tA->nodeData<0){//加入 B 表
            tB->nodeNext = tA;
            tB = tB->nodeNext;
            tA = tA->nodeNext;
        }else if(tA->nodeData>0){
            tC->nodeNext = tA;
            tC = tC->nodeNext;
            tA = tA->nodeNext;
        }
    }
    tB->nodeNext = NULL;
    tC->nodeNext = NULL;
    free(la);
}
// 设计一个算法，将链表中所有节点的链表方向 `原地` 旋转，
// 既要求仅利用原表的存储空间，换句话说，要求算法的空间复杂度为 o(1)
void ListReverse(LinkList la){
    LinkList tA = la->nodeNext,trear,tpre;//工作前驱，后继节点
    tpre = NULL ; //初始化 前驱空节点，后继为头指针
    la->nodeNext = NULL;
    while(tA){
        trear = tA->nodeNext;//存储后续节点
        tA->nodeNext = tpre;
        tpre = tA;
        tA = trear;
    }
    la->nodeNext = tpre;
}
// 已知 p 指向双向循环链表中的一个节点，其节点结构为 `data`、`prior`、`next` 三个域，
// 设计算法 `change(p)` , 交换 p 所指向的节点及其前驱节点的顺序
void change(LinkList lp){
    
}


int main(){
    //头指针：指向头节点的指针
    //头节点：不存储数据的，指向链表首元素的头结点
    //首元素：链表的第一个元素
    // ListArg=InitListEnd(ListArg);
    LinkList la,lb,lc;
    la = InitListEnd(la);
    // lb = InitListEnd(lb);
    // lc = InitListEnd(lc);
    // ListAtoBandC(la,lb,lc);
    ListReverse(la);
    ShowList(la);
    return 0;
}