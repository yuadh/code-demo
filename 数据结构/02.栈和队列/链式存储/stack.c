#include <stdio.h>
#include <malloc.h>

typedef struct ListStack{
    int NodeData;
    struct ListStack *NextNode;//ָ����ָ���������һ���ڵ�
}ListStack,*LinkStack;

LinkStack InitStack(LinkStack LS){//��ʼ��ջ����
    LinkStack LN; int x;
    LS = (LinkStack) malloc(sizeof(ListStack));
    LS = NULL; //��ʼ��
    scanf("%d",&x);
    while(x!=-1){
        LN = (LinkStack) malloc(sizeof(ListStack));
        LN->NodeData = x;
        LN->NextNode = LS;
        LS = LN;
        scanf("%d",&x);
    }
    return LS; 
}
void StackPush(LinkStack LS,int dat){
    LinkStack LN;
    LN->NodeData = dat;
    LN->NextNode = LS;
    LS = LN;
    return;
}
void StackPop(LinkStack LS,int *dat){
    LinkStack LN;
    if(LS == NULL){
        return;//��ջ
    }
    *dat = LN->NodeData;
    LN = LS;
    LS = LS->NextNode;
    free(LN);
    return ;
}
void ShowList(LinkStack LS){ //����ջ
    LinkStack L =  LS;
    if(L==NULL){
        printf("��ջ");
    }
    while(L){
        printf("ջ��ֵ:%d\n",L->NodeData);
        L = L->NextNode;
    }
    return ;
}

int main(){
    LinkStack ls;
    ls=InitStack(ls);
    ShowList(ls);
}   