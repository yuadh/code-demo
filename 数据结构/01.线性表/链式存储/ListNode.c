#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
typedef struct ListNode//��������ڵ�
{
    int nodeData;//����??
    struct ListNode *nodeNext;//��ַ??
}ListNode,*LinkList;//ָ��ڵ��ָ??
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

//�����ʵ�岻ʹ��ָ�룬��������ṹ������ֵʱ��Ҫʹ�õ�ָ��
//ͷָ���ʾ���������
int main(){
    //ͷָ�룺ָ��ͷ�ڵ��ָ��
    //ͷ�ڵ㣺���洢���ݵģ�ָ��������Ԫ�ص�ͷ���
    //��Ԫ�أ�����ĵ�һ��Ԫ��?
    ListArg=InitListEnd(ListArg); //ͷָ�룬����ͷ���ĵ�ַ
    // printf(ListArg->nodeData);
    // ListNode a = {4,NULL};
    // ListAddNode(ListArg,4,a);
    // ListOne=getItemUN(ListArg,5);
    // LinkList x = getItem(ListArg,4);
    // printf("ȡֵ:%d\n",ListOne.nodeData);
    ListRmNode(ListArg,4);
    ShowList(ListArg);
    return 0;
}