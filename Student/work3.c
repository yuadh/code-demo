#include <stdio.h>


int main(){
    int a,b,c,d,e,f;
    for(a=0;a<=1;a++)//设定条件为0是没作案，1为作案
        for(b=0;b<=1;b++)
            for(c=0;c<=1;c++)
                for(d=0;d<=1;d++)
                    for(e=0;e<=1;e++)
                        for(f=0;f<=1;f++){
                            if( 6 ==
                                ((a||b)//条件1,ab至少一个人作案为真
                                +!(a&&d)//条件2，ad不可能同时作案为真
                                +((a&&e)||(a&&f)||(e&&f))//条件3，aef至少2人作案
                                +((b&&c)||(!b&&!c))//条件4，bc或同时作案或同时没作案
                                +((c&&!d)||(!c&&d))//条件5，cd有且只有一个人作案
                                +(d||(!e)))//条件6，如果d没有参加作案则e也不可能参加作案
                            ){
                                if(a==1){
                                    printf("the:a\n");
                                }
                                if(b==1){
                                    printf("the:b\n",b);
                                }
                                if(c==1){
                                    printf("the:c\n",c);
                                }
                                if(d==1){
                                    printf("the:d\n",d);
                                }
                                if(e==1){
                                    printf("the:e\n",e);
                                }
                                if(f==1){
                                    printf("the:f\n",f);
                                }
                            }

                        }
                        
            
}