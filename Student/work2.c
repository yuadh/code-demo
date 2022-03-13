#include<stdio.h>
 
int c = 50;
int i = 1;
int j = 0;
int a[50] = { 0 };
int b[50] = { 0 };
 
int main()
{
    while (i<=51)
    {
        if (i == 51)
        {
            i = 1;
        }
        else if (c == 0)
        {
            break;
        }
        else
        {
            if (b[i] != 0)//已经跳了 跳过该位
            {
                i++;
                continue;
            }
            else
            {
                j++;
                if (j != 9)
                {
                    i++;
                    continue;
                }
                else
                {
                    b[i] = 1;//跳一个
                    a[i] = j;
                    j = 0;
                    printf("the Node:%d tump%d\n ", i,a[i]);
                    i++;
                    c--;
                }
            }
        }
    }
}