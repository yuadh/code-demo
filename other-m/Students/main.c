#include <stdio.h>
// status
#define SUCCESS 1
#define ERROR 0
typedef int STATUA;
// Data
typedef struct{
    int stuID;
    char *stuName;
    float stuScore;
}student;
#define MAXSIZE 100
typedef struct{
    student  stuDatas[MAXSIZE];
    int length;
}stuList;
// Operation
// 获取链表元素
STATUA getElem(stuList pro,int stuID,student *stuSomeOne){
    if(pro.length==0||stuID<1||stuID>pro.length){
        return SUCCESS;
    }
    *stuSomeOne = pro.stuDatas[stuID];
}

int main(){
    stuList pro;
    pro.stuDatas[0].stuID=1;
    pro.stuDatas[0].stuName="yuadh";
    pro.stuDatas[0].stuScore=100;
    printf("%d\n",pro.stuDatas[0].stuID);
    printf("%s\n",pro.stuDatas[0].stuName);
    printf("%.2f\n",pro.stuDatas[0].stuScore);
    scanf("%d");
}