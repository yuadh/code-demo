#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct ListStack{
    char NodeData;
    struct ListStack *NextNode;//指针域指向链表的下一个节点
}ListStack,*LinkStack;
void ShowList(LinkStack LS);
LinkStack InitStack(LinkStack LS){//初始化栈队列
    LinkStack LN; char x;
    LS = (LinkStack) malloc(sizeof(ListStack));
    LS = NULL; //初始化
    scanf("%c",&x);
    while(x!=-1){
        LN = (LinkStack) malloc(sizeof(ListStack));
        LN->NodeData = x;
        LN->NextNode = LS;
        LS = LN;
        scanf("%d",&x);
    }
    return LS; 
}
LinkStack StackPush(LinkStack LS,char dat){
    LinkStack LN;
    LN = (LinkStack) malloc(sizeof(ListStack));
    LN->NodeData = dat;
    LN->NextNode = LS;
    LS = LN;
    return LS;
}
LinkStack StackPop(LinkStack LS,char *dat){
    LinkStack LN;
    if(LS == NULL){
        printf("空栈");
        return NULL;//空栈
    }
    *dat = LS->NodeData;
    LN = LS;
    LS = LS->NextNode;
    free(LN);
    return LS;
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

int getStrLength(char *str);
//
int checkStr(LinkStack LS){
    // 检查括号字符串是否合法
    char KhStr[40];int len;
    gets(KhStr);
    len = getStrLength(KhStr);
    // 算法思想：
    // 如果有左括号就加入栈中 有相应的右括号匹配弹栈 
    // 在少括号或括号不匹配的情况下判断为字符串非法
    for(int i=0;i<len;i++){
        switch(KhStr[i]){
            case '(':
            case '[':
                LS = StackPush(LS,KhStr[i]);//进栈
                break;
            case ')':
                if(LS->NodeData=='('){//栈顶匹配，弹栈
                    char t;
                    LS = StackPop(LS,&t);
                    break;
                }else{
                    return 0;//返回false
                }
            case ']':
                if(LS->NodeData=='['){//栈顶匹配，弹栈
                    char t;
                    LS = StackPop(LS,&t);
                    break;
                }else{
                    return 0;//返回false
                }
        }
    }
    return LS==NULL;//通过检验返回 true
}
int getStrLength(char str[]){
    int l=0;
    while(str[l]!='\0'){
        l++;
    }
    return l;
}

int main(){
    LinkStack ls;
    ls=InitStack(ls);
    checkStr(ls);//传入一个初始化的栈
    // DntoOn(ls);
}   