#include <stdio.h>
#include <malloc.h>

typedef struct ListStack{
    int NodeData;
    struct ListStack *NextNode;//指针域指向链表的下一个节点
}ListStack,*LinkStack;

LinkStack InitStack(LinkStack LS){//初始化栈队列
    LinkStack LN; int x;
    LS = (LinkStack) malloc(sizeof(ListStack));
    LS = NULL; //初始化
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
        return;//空栈
    }
    *dat = LN->NodeData;
    LN = LS;
    LS = LS->NextNode;
    free(LN);
    return ;
}
void ShowList(LinkStack LS){ //遍历栈
    LinkStack L =  LS;
    if(L==NULL){
        printf("空栈");
    }
    while(L){
        printf("栈顶值:%d\n",L->NodeData);
        L = L->NextNode;
    }
    return ;
}

int main(){
    LinkStack ls;
    ls=InitStack(ls);
    ShowList(ls);
}   