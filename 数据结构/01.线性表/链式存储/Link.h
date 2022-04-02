#ifndef  _Link_H_
#define _Link_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct ListNode//��������ڵ�
{
    int nodeData;//����??
    struct ListNode *nodeNext;//��ַ??
}ListNode,*LinkList;//ָ��ڵ��ָ??
typedef struct ListNodeDDW{
    struct ListNodeDDW *nodePrev;
    int nodeData;
    struct ListNodeDDW *nodeNext; 
}ListNodeDDW,*LinkListDDW;
LinkList ListArg;//����ͷ��??
ListNode ListOne;//ʵ��ڵ�
// ��������
LinkList InitListHead(LinkList L);


//opear
LinkList InitListHead(LinkList L){
    //��ʼ����������һ��ָ��ͷ�ڵ������ָ�룬��Ϊ�ǿսڵ�����ͷ�ڵ��ָ����ָ��NULL
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
    EN = L;//β�ڵ�
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
LinkListDDW InitListEndDDW(LinkListDDW  L){//˫��ѭ������β�巨
    ListNodeDDW *LN,*EN;int x;
    L = (LinkListDDW)malloc(sizeof(ListNodeDDW));
    L->nodeNext = NULL; L->nodePrev = NULL;
    EN = L;//����ָ��
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
void ShowListDDW(LinkListDDW L){//ͨ�������ڵ����
    if(L->nodeNext==L){
        printf("����Ϊ��");
        return;
    }
    LinkListDDW f = L->nodeNext;//ָ����Ԫ�ڵ�
    while(f&&f!=L){
        printf("����ֵ:%d\n",f->nodeData);
        f = f->nodeNext;
    }
    return ;
}
void ShowList(LinkList L){//ѭ���������ֵ
    if(L->nodeNext==NULL){
        printf("����Ϊ��");
        return;
    }
    LinkList f = L->nodeNext;//ָ����Ԫ�ڵ�
    while(f){
        printf("����ֵ:%d\n",f->nodeData);
        f = f->nodeNext;
    }
    return ;
}

ListNode getItemUN(LinkList L,int Nx){//����������ȡ�ڵ�
    ListNode  *p = L->nodeNext; //ָ����Ԫ�ڵ�
    int f = 1;
    if(Nx == 0){ // �ձ���ͷ�ڵ� 
        return *L;
    } 
    while(p&&f<Nx){ //����Ԫ�ڵ㿪ʼѭ������ָ����һλ
        p=p->nodeNext;
        f++;
    }
    return *p;
}
ListNode getItemUV(LinkList L,int val){//���ݽڵ�ֵ��ȡ�ڵ�
    ListNode *p = L->nodeNext;//ָ����Ԫ�ڵ�
    while(p&&p->nodeData!=val){
        p = p->nodeNext;
    }
    return *p;//�������Ϊ�շ���ֵNULL
}
void ListAddNode(LinkList L,int n,ListNode LN){
    LinkList p = L; int f=0;
    while(p&&f<(n-1)){//��ͷ��Ϊ�ս�����������Ҫ�����ǰһλ
        p=p->nodeNext;
        f++;
    }
    if(!p){//�������λ�õ�ǰһ���ڵ�Ϊ�������
        printf("error");
        return ;
    }
    LN.nodeNext = p->nodeNext;
    p->nodeNext = &LN;
    return ;
}
ListNode ListRmNode(LinkList L,int n){
    LinkList p = L; int f=0;
    while(p&&f<(n-1)){//ѭ����Ҫɾ����ǰһ��Ԫ��
        p=p->nodeNext;
        f++;
    }
    if(!p->nodeNext){//���Ҫɾ����Ԫ��Ϊ�� �򷵻�
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