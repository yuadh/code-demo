#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct QueueNode{
    int NodeData;
    struct QueueNode *next;
}QueueNode,*QueueND;//���нڵ�

typedef struct QueueList{
    QueueND front,rear;
}QueueList,*QueueLink;

// �˶���������ͷָ�� ��frontָ���Ԫ��ΪͷԪ�� ���洢ֵ
QueueLink InitQueueLink(QueueLink QL){
    QL = (QueueLink)malloc(sizeof(QueueNode));
    int x;
    QueueND QN; 
    QL->front = QL->rear =(QueueND)malloc(sizeof(QueueNode));  
    QL->front->next = NULL; 
    scanf("%d",&x);
    while(x!=-1){
        // ��β�ڵ����
        QN = (QueueND)malloc(sizeof(QueueNode));
        QN->next = NULL;
        QN->NodeData =x;
        // ����ͷָ�����
        QL->rear->next = QN;//��βԪ��ָ����ָ������ָ��
        QL->rear = QN;// ��Ԫ��ָ�����Ծ�ָ��ԭ����ӽڵ�,βԪ�ص�ָ��βԪ��
        scanf("%d",&x);
    }
    return QL;
}
// ���
void EnQueueLink(QueueLink QL){

}

// ����

// ��ӡ����
void ShowQueueLink(QueueLink QL){
    printf("���");
    QueueND n ; 
    n = QL->front->next;//ָ�������Ԫ��
    if(QL->front == QL->rear){
        printf("�ն���");
        return ;
    }
    printf("���");
    while(n!=NULL){
        printf("����ֵ:%d\n",n->NodeData);
        n = n->next;
    }
    printf("%d",QL->rear->next);
    return ;
}

int main(){
    QueueLink ql;
    ql = InitQueueLink(ql);
    ShowQueueLink(ql);
}