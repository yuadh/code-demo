#include<stdio.h>
 
int c = 50;//船上剩余人数
int i = 1;//给船员的编号 1-50
int j = 0;//报数
int b[50] = { 0 };//记录跳船人员
int main()
{
    while (i<=51)
    {
        if (i == 51)//循环
        {
            i = 1;
        }
        else if (c == 0)//船上没人结束程序
        {
            break;
        }
        else
        {
            if (b[i] != 0)//该编号人员已经跳船，跳过报数
            {
                i++;
                continue;
            }
            else//如果该编号人员没有跳船，报数++
            {
                j++;
                if (j != 9)
                {
                    i++;
                    continue;
                }
                else//如果报数为9，该编号人员跳船
                {
                    b[i] = 1;
                    j = 0;
                    printf("jump Number:%d \n ", i);
                    i++;
                    c--;
                }
            }
        }
    }
}