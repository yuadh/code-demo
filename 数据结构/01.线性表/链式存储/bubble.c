// �����ð������
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
 
# define MAXSIZE 20      		//���¼������20��
typedef  int  KeyType ;     	//��ؼ���Ϊ��������int�ͣ�
typedef struct {              //����ÿ����¼������Ԫ�أ��Ľṹ
    KeyType      key ;         //�ؼ��� 
}RedType;
typedef  struct {               //����˳���Ľṹ
  RedType  r [ MAXSIZE +1 ];   	//�洢˳����������r[0]���ڱ��򻺳���
  int length ;       			//˳���ĳ���
}SqList;

void crateSSTable(SqList** st,int length){
  (*st) = (SqList*)malloc(sizeof(SqList));
  (*st)->length = length;
  printf("����%d������\n",length);
  for(int i = 1;i<=length;i++){
    scanf("%d",&((*st)->r[i].key));
  }
}
void bubble_sort(SqList* L){
  for(int i = 1;i < L->length;i++){
    for(int j = 1; j < (L->length-i+1);j++){
      if(L->r[j].key>L->r[j+1].key){
        int temp = L->r[j].key;
        L->r[j].key = L->r[j+1].key;
        L->r[j+1].key = temp;
      }
    }
  }
  return;
}
int main(){
  SqList *st;
  crateSSTable(&st,10);
  bubble_sort(st);
  for(int i=1;i<11;i++){
    printf("%d ",st->r[i].key);
  }
}
