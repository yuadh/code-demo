// 链表的冒泡排序
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
 
# define MAXSIZE 20      		//设记录不超过20个
typedef  int  KeyType ;     	//设关键字为整型量（int型）
typedef struct {              //定义每个记录（数据元素）的结构
    KeyType      key ;         //关键字 
}RedType;
typedef  struct {               //定义顺序表的结构
  RedType  r [ MAXSIZE +1 ];   	//存储顺序表的向量，r[0]作哨兵或缓冲区
  int length ;       			//顺序表的长度
}SqList;

void crateSSTable(SqList** st,int length){
  (*st) = (SqList*)malloc(sizeof(SqList));
  (*st)->length = length;
  printf("输入%d个数字\n",length);
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
