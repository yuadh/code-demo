#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50
#define bool int
#define true 1
#define false 0

typedef struct StackLink{
    int NodeData[MaxSize];
    int topNum;
}StackLink;

//˳��洢ջ�ĳ�ʼ��
void InitStack(StackLink *SL){
    SL->topNum = -1;
    return ;//��ʼ��һ��û��ջ�׵�ջ����
}
// ��ջ
bool StackPush(StackLink *SL,int dat){
    if(SL->topNum==MaxSize-1){//ջ��
        return false;
    }
    SL->NodeData[++SL->topNum]=dat;
    return true;
}
// ��ջ
bool StackPop(StackLink *SL,int *x){
    if(SL->topNum==-1){//ջ��
        return false;
    }
    *x = SL->NodeData[SL->topNum--];
    return true;
}

void showStack(StackLink sl){
    if(sl.topNum==-1){//ջ�����
        printf("ջ��");
        return;
    }
    for(int i=sl.topNum;i>=0;i--){
        printf("%c\n",sl.NodeData[i]);
    }
}

void work03(){
    StackLink sl;
    InitStack(&sl);
    int n;
    scanf("%d",&n);
    while(n!=-1){
        StackPush(&sl,n);
        scanf("%d",&n);
    }
    // StackPop(&sl,&n);
    showStack(sl);
}
bool work05(char *str){
    StackLink sl;
    InitStack(&sl);
    int i=0,n;
    // ����������������ݽ�����ջ�ͳ�ջ
    while(str[i]){
        if(str[i]=='I'){
            StackPush(&sl,str[i]);
        }else if(str[i]=='O'){
            StackPop(&sl,&n);
        }else{
            printf("���鵱ǰ��������\n");
            return false;
        }
        i++;
    }
    showStack(sl);
    if(sl.topNum==-1){//ջ�����
        printf("ջ��");
        return true;
    }
    return false;
}
//�ݹ�
int Ack(int m,int n){
	if (m==0) return n+1;
	else if(m!=0&&n==0) return Ack(m-1,1);
	else return Ack(m-1,Ack(m,n-1));
}
int main(){
    // work03();
    // char s[]="IIIOOIOO";
    // if(work05(s)){
    //     printf("\n�Ϸ�����\n");
    // }else{
    //     printf("\n�Ƿ�����\n");
    // }
    int a = Ack(2,1);
    printf("%d",a);
}