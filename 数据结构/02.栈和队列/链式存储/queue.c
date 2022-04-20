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
    QL = (QueueLink)malloc(sizeof(QueueList));
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
void EnQueueLink(QueueLink QL,int dat){
    QueueND QN=(QueueND)malloc(sizeof(QueueNode));
    QN->next = NULL; 
    QN->NodeData = dat;
    QL->rear->next = QN; 
    QL->rear = QN;
    // return QL;
}

// ����
void DeQueueLink(QueueLink QL){
    if(QL->front == QL->rear){
        printf("�ն���");
        return ;
    }
    QueueND QD= QL->front->next;
    QL->front->next = QD->next;
    if(QD == QL->rear){//���ֻ��һ���ڵ���ɾ�������ö���Ϊ��
       QL->rear = QL->front;
    }
    free(QD);
}


// ��ӡ����
void ShowQueueLink(QueueLink QL){
    QueueND n ; 
    n = QL->front->next;//ָ�������Ԫ��
    if(QL->front == QL->rear){
        printf("�ն���");
        return ;
    }
    while(n!=NULL){
        printf("����ֵ:%d\n",n->NodeData);
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