#include <stdio.h>
/*双向栈数据结构
 *
 *
 */
#define postion int 
#define head 0
#define end 1

#define MaxSize 10
typedef struct{
    int top[2],bot[2];//栈顶和栈底指针
    int V[MaxSize];//栈数组
    int m;		//栈最大可容纳的元素个数
}DblStack;

void InitDblStack(DblStack *ds){
  ds->m = MaxSize;
  //双栈为空的初始化
  ds->top[0]=-1;ds->top[1]=ds->m;
  ds->bot[0]=0;ds->bot[1]=ds->m-1;
}
void StackPush(DblStack *ds,postion p,int dat){
  //左侧插入的栈满情况
  int i;
  if(ds->top[0]==ds->top[1]){
    printf("栈满");
    return;
  }
  if(p==head){
    i=++ds->top[p];
  }else if(p==end){
    i=--ds->top[p];
  }
  ds->V[i]=dat;
  return ;
}
void StackPop(DblStack *ds,postion p){
  int i;
  if(ds->top[p]==-1||ds->top[p]==ds->m){
    printf("栈空");
    return ;
  }
  if(p==head){
    i=--ds->top[p];
  }else if(p==end){
    i=++ds->top[p];
  }
  return ;
}
void showStack(DblStack ds,postion p){
  if(ds.top[p]==-1||ds.top[p]==ds.m){
    printf("栈空");
    return ;
  }
  if(p==head){
    while(ds.top[p]>=0)printf("%d\n",ds.V[ds.top[p]--]);
  }else if(p==end){
    while(ds.top[p]<ds.m)printf("%d\n",ds.V[ds.top[p]++]);
  }
}

int main(){
  DblStack sl;
  InitDblStack(&sl);
  int n=scanf("%d",&n);
  while(n!=-1){
    StackPush(&sl,head,n);
    scanf("%d",&n);
  }
  showStack(sl,head);
}