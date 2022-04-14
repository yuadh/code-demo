#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct ListStack{
    char NodeData;
    struct ListStack *NextNode;//ָ����ָ���������һ���ڵ�
}ListStack,*LinkStack;
void ShowList(LinkStack LS);
LinkStack InitStack(LinkStack LS){//��ʼ��ջ����
    LinkStack LN; char x;
    LS = (LinkStack) malloc(sizeof(ListStack));
    LS = NULL; //��ʼ��
    scanf("%c",&x);
    fflush(stdin);//��ֹ�س�����
    while(x!='e'){
        LN = (LinkStack) malloc(sizeof(ListStack));
        LN->NodeData = x;
        LN->NextNode = LS;
        LS = LN;
        scanf("%c",&x);
        fflush(stdin);
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
        printf("��ջ");
        return NULL;//��ջ
    }
    *dat = LS->NodeData;
    LN = LS;
    LS = LS->NextNode;
    free(LN);
    return LS;
}
void ShowList(LinkStack LS){ //����ջ
    LinkStack L =  LS;
    if(L==NULL){
        printf("��ջ");
    }
    while(L){
        printf("ջ��ֵ:%c\n",L->NodeData);
        L = L->NextNode;
    }
    printf("----\n");
    return ;
}

int getStrLength(char *str);
//
int checkStr(){
    LinkStack LS;
    LS=InitStack(LS);
    // ��������ַ����Ƿ�Ϸ�
    char KhStr[40];int len;
    gets(KhStr);
    len = getStrLength(KhStr);
    printf("��ⳤ��%d",len);
    // �㷨˼�룺
    // ����������žͼ���ջ�� ����Ӧ��������ƥ�䵯ջ 
    // �������Ż����Ų�ƥ���������ж�Ϊ�ַ����Ƿ�
    for(int i=0;i<len;i++){
        switch(KhStr[i]){
            case '(':
            case '[':
                LS = StackPush(LS,KhStr[i]);//��ջ
                break;
            case ')':
                if(LS->NodeData=='('){//ջ��ƥ�䣬��ջ
                    char t;
                    LS = StackPop(LS,&t);
                    break;
                }else{
                    return 0;//����false
                }
            case ']':
                if(LS->NodeData=='['){//ջ��ƥ�䣬��ջ
                    char t;
                    LS = StackPop(LS,&t);
                    break;
                }else{
                    return 0;//����false
                }
        }
        ShowList(LS);
    }
    if(LS!=NULL){return 0;}//���ļ��� �ж�ջ�Ƿ�Ϊ��
    return 1;//ͨ�����鷵�� true
}
int getStrLength(char str[]){
    int l=0;
    while(str[l]!='\0'){
        l++;
    }
    return l;
}

int main(){
    int sta=checkStr();
    if(sta==0){
        printf("���Ϸ�");
    }else{
        printf("�Ϸ�");
    }
}   