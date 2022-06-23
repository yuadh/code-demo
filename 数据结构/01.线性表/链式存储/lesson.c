#include "Link.h"


/** 
01.将两个递增的有序列表合并为一个递增的有序列表。
要求结果链表仍使用原来两个链表的存储空间，不另外占用其它的存储空间。表中不允许有重复的数据
**/
void MergeList(LinkList listA,LinkList listB){
    LinkList tA = listA->nodeNext,tB = listB->nodeNext;//????????????????
    LinkList t,tend; //?????????????????
    listA->nodeNext = NULL ; //????????
    tend = listA; //????
    while(tA&&tB){//
        if(tA->nodeData<tB->nodeData){
            //??????????????
            tend->nodeNext = tA;
            tend = tA;
            tA = tA->nodeNext;
        }else if(tA->nodeData>tB->nodeData){
            tend->nodeNext = tB;
            tend = tB;
            tB = tB->nodeNext;
        }else{
            // 如果出现有相同值得情况下，释放其中一个
            // ??????????
            tend->nodeNext = tA;
            tend = tA;
            tA = tA->nodeNext;
            t = tB->nodeNext;//释放
            free(tB);
            tB = t;
        }
    }
    tend->nodeNext = tA?tA:tB;//总有一个节点没有情况加入到链表中
    free(listB);
}
// 已知两个链表 A 和 B 分别表示两个集合，其元素递增排列。
// 请设计一个算法，用于求出 A 与 B 的交集，并将结果存放在 A 链表中
void listAUlistB(LinkList la,LinkList lb){
    LinkList tA = la->nodeNext,tB = lb->nodeNext;
    LinkList tend,t;
    tend = la; // tend????????????????
    while(tA&&tB){
        if(tA->nodeData==tB->nodeData){//????????????????????????
            tend->nodeNext = tA;
            tend = tA;
            tA = tA->nodeNext;
            t = tB;
            tB = tB->nodeNext;
            free(t);
        }else if(tA->nodeData<tB->nodeData){
            //??????????????????????????????????????????????????
            t = tA;
            tA = tA->nodeNext;
            free(t);
        }else{
            t = tB;
            tB = tB->nodeNext;
            free(t);
        }
    }
    while(tA){//????????
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
// 设计算法将一个带头节点的单链表 A 分解为两个具有相同结构的链表 B 和 C，
// 其中 B 表的节点为 A 表中值小于0的节点，
// 而 C 表的节点为 A 表中值大于0的节点 (链表A中的元素为非零整数，要求B、C表利用A表的节点)
void  ListAtoBandC(LinkList la,LinkList lb,LinkList lc){
    LinkList tA= la->nodeNext,tB = lb,tC = lc; //????????????????
    while(tA){//???????
        if(tA->nodeData == 0){
            return ;//?????0????
        }else if(tA->nodeData<0){//???? B ??
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
    LinkList tA = la->nodeNext,trear,tpre;//??????????????
    tpre = NULL ; //????? ???????????????
    la->nodeNext = NULL;
    while(tA){
        trear = tA->nodeNext;//?????????
        tA->nodeNext = tpre;
        tpre = tA;
        tA = trear;
    }
    la->nodeNext = tpre;
}
// 已知 p 指向双向循环链表中的一个节点，其节点结构为 `data`、`prior`、`next` 三个域，
// 设计算法 `change(p)` , 交换 p 所指向的节点及其前驱节点的顺序
void change(LinkListDDW Lnode){ //因为是循环链表所有对链表和链尾节点不考虑？
    LinkListDDW Pnode,PPnode,Nnode;
    Pnode = Lnode->nodePrev;
    PPnode = Pnode->nodePrev;
    Nnode = Lnode->nodeNext;
    PPnode->nodeNext = Lnode;
    Lnode->nodePrev = PPnode;
    Lnode->nodeNext = Pnode;
    Pnode->nodePrev = Lnode;
    Pnode->nodeNext = Nnode;
    Nnode->nodePrev = Pnode; 
}


int main(){
    // LinkListDDW la,lb;
    // la=InitListEndDDW(la);
    // ShowListDDW(la);
    // lb = la->nodeNext->nodeNext->nodeNext->nodeNext;//模拟取第4个节点
    // change(lb);//调换与其前驱节点的位置
    // printf("调换后\n");
    // ShowListDDW(la);
    // LinkList la,lb,lc;
    // la = InitListEnd(la);
    // ListReverse(la);
    // ShowList(la);
    // ListAtoBandC(la,lb,lc);
    // ShowList(lc);
    //???????????????
    //???????????????????????????????
    //???????????????????
    // ListArg=InitListEnd(ListArg);
    LinkList la;
    la = InitListEnd(la);
    int a=-1;
    if(ListDelete_L(la,1,&a)){
        printf("删除成功:其值为%d\n",a);
    }
    printf("链表打印:\n");
    ShowList(la);
    return 0;
}