//链表使用二分查找法

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define KeyType int
#define false 0
#define true 1
#define Status  int

typedef struct {
	KeyType key;
} ElemType;				
typedef struct {
    ElemType     *R; //表基址
    int  length;     //表长
}SSTable;


void crateSSTable(SSTable** st,int length){
  (*st) = (SSTable*)malloc(sizeof(SSTable));
  (*st)->length = length;
  (*st)->R = (ElemType*)malloc(sizeof(ElemType));
  printf("输入%d个数字\n",length);
  for(int i = 1;i<=length;i++){
    scanf("%d",&((*st)->R[i].key));
  }
}
int Search_Bin(SSTable ST,KeyType key){
  int low = 1,high = ST.length,mid;
  while(low<=high){
    mid = (low+high)/2;
    if(ST.R[mid].key==key){
      return mid;//返回key值所在索引
    }else if(ST.R[mid].key<key){
      low = mid+1;
    }else if(ST.R[mid].key>key){
      high = mid-1;
    }
  }
  return 0;//未找到key索引
}


int main(){
  SSTable *st;
  crateSSTable(&st,5);
  int location = Search_Bin(*st,4);
  if (location==0) {
    printf("查找表中无该元素");
  }else{
    printf("数据在查找表中的位置为：%d",location);
  }
}