#include <stdio.h>

int main(){
    int a,b,c,d,s;
    for(s='a';s<='d';s++){
        a=(s!='a');
        b=(s=='c');
        c=(s=='d');
        d=(s!='d');
        if((a+b+c+d)==3){
           printf("the:%c",s); 
        }
    }
}