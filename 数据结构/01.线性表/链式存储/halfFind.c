//����ʹ�ö��ֲ��ҷ�

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
    ElemType     *R; //���ַ
    int  length;     //��
}SSTable;


void crateSSTable(SSTable** st,int length){
  (*st) = (SSTable*)malloc(sizeof(SSTable));
  (*st)->length = length;
  (*st)->R = (ElemType*)malloc(sizeof(ElemType));
  printf("����%d������\n",length);
  for(int i = 1;i<=length;i++){
    scanf("%d",&((*st)->R[i].key));
  }
}
int Search_Bin(SSTable ST,KeyType key){
  int low = 1,high = ST.length,mid;
  while(low<=high){
    mid = (low+high)/2;
    if(ST.R[mid].key==key){
      return mid;//����keyֵ��������
    }else if(ST.R[mid].key<key){
      low = mid+1;
    }else if(ST.R[mid].key>key){
      high = mid-1;
    }
  }
  return 0;//δ�ҵ�key����
}


int main(){
  SSTable *st;
  crateSSTable(&st,5);
  int location = Search_Bin(*st,4);
  if (location==0) {
    printf("���ұ����޸�Ԫ��");
  }else{
    printf("�����ڲ��ұ��е�λ��Ϊ��%d",location);
  }
}