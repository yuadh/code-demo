#include <stdio.h>

int main(){
    int x=90,y=100;
    while(y>0)
    if(x>100){x=x-10;y--;}
    else x++;
    printf("%d-%d",x,y);
}