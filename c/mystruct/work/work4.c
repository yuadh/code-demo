#include <stdio.h>

int jNumber(int y,int s);
int main(){
    int n,y,s;
    printf("scanf y:");
    scanf("%d",&y);
    printf("scanf s:");
    scanf("%d",&s);
    n = jNumber(y,s);
    printf("the count:%d",n);
}
int jNumber(int y,int s){
    int n;
    if(s==0){
        n=y+1;
    }else{
        n=2*jNumber(y,s-1);
    }
    return n;
}