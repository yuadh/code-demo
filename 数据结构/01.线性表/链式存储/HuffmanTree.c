
// 哈夫曼树

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//哈夫曼树结点结构
typedef struct {
    int weight;//结点权重
    int parent, left, right;//父结点、左孩子、右孩子在数组中的位置下标
}HTNode, *HuffmanTree;

//end是存放生成节点的位置,s1和s2是两个权值最小的元素在数组中的位置
void Select(HuffmanTree HT,int end,int* s1,int* s2){
  int min1,min2;//左右权值比较
  int i=1;
  while(HT[i].parent!=0&&i<=end){
    i++;
  }
  min1 = HT[i].weight;
  *s1 = i;
  i++;
  while(HT[i].parent!=0&&i<=end){
    i++;
  }
  if(HT[i].weight<min1){
    min2=min1;
    *s2 = *s1;
    min1 = HT[i].weight;
    *s1 = i;
  }else{
    min2 = HT[i].weight;
    *s2 = i;
  }
  for(int j=i+1;j<=end;j++){//和后续未构建成树的节点比较
    if(HT[j].parent!=0){
      continue;
    }
    if(HT[j].weight<min1){
      min2 = min1;
      min1 = HT[j].weight;
      *s2 = *s1;
      *s1 = j;
    }else if(HT[j].weight>min1&&HT[j].weight<min2){
      min2 = HT[j].weight;
      *s2 = j;
    }
  }


  return;
}


// HT是指向HTNode的二级指针 w为权值数组 n为原始节点个数
void CrateHuffmanTree(HuffmanTree* HT,int n){
  if(n<=1)return ;//单节点不构成
  int m = 2*n - 1; //生成二叉树的总节点个数
  *HT = (HuffmanTree) malloc((m+1)*sizeof(HTNode));//数组索引从1开始
  HuffmanTree p = *HT;
  for(int i=1;i<=m;i++){//初始化原始节点和生成二叉树节点
    (p+i)->weight = 0;
    (p+i)->right = 0;
    (p+i)->left = 0;
    (p+i)->parent = 0;
  }
  for(int i=1;i<=n;++i){//输入原始节点权值
    int  temp;scanf("%d",&temp);
    (p+i)->weight = temp;
  }
  //题解
  for(int i=n+1;i<=m;i++){
    int s1,s2;
    Select(*HT,i-1,&s1,&s2);//查找权重值最小的两个结点索引
    (*HT)[s1].parent = (*HT)[s2].parent = i;//给s1,s2设置父节点索引
    (*HT)[i].left = s1;
    (*HT)[i].right = s2;
    (*HT)[i].weight = (*HT)[s1].weight+(*HT)[s2].weight;
  }
}

void main(){
  HuffmanTree HT;
  CrateHuffmanTree(&HT,4);
}