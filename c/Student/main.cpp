#include <stdio.h>
#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
// status
#define SUCCESS 1
#define ERROR 0
typedef int STATUA;
#define MAXSIZE 100
// Data
typedef struct{
    int stuID;
    char *stuName;
    float stuScore;
}student;
typedef struct{
    student  stuDatas[MAXSIZE];
    int length=0;
}stuList;
// Operation	
/*getstu(L,i,*e):获取链表第index位置的元素,返回给e
  inserStu(*L,i,e):插入新元素e在链表第index的位置上
  deleteStu(*L,i,*e):删除第index位置的元素
  changeStu(*L,i,e):修改第index位置的元素为e
*/
// 获取链表元素
STATUA getStu(stuList pro,int index,student *stuSomeOne){
    if(pro.length==0||index<1||index>pro.length){
        return ERROR;
    }
    *stuSomeOne = pro.stuDatas[index-1];
	return SUCCESS;
}
// 插入链表元素
STATUA insertStu(stuList *pro,student stu){
	if(pro->length==MAXSIZE){
		return ERROR;
	}
	//默认只在线性表最后插入
	pro->stuDatas[pro->length]=stu;
	pro->length++;
	return SUCCESS;
}
// 删除链表元素
STATUA deleteStu(stuList *pro,int index){
	if(pro->length==0){
		return ERROR;//链表为空
	}

}
// 修改链表元素

// 应用操作
void showAllStu(stuList *pro){
	int temp = pro->length,i;
	for(i=temp-1;i>=0;i--){
		printf("%d  ",pro->stuDatas[i].stuID);
    	printf("%s  ",pro->stuDatas[i].stuName);
    	printf("%.2f\n",pro->stuDatas[i].stuScore);
	}
}

int main(){
	initgraph(640, 480);	// 创建绘图窗口，大小为 640x480 像素
	circle(200, 200, 100);	// 画圆，圆心(200, 200)，半径 100
	_getch();				// 按任意键继续
	closegraph();			// 关闭绘图窗口
	return 0;
    // stuList pro;
    // student stu1={1,"yuadh",66},stu2={2,"iii",77},stu3={3,"zzz",47};
	// insertStu(&pro,stu1);
	// insertStu(&pro,stu2);
	// insertStu(&pro,stu3);
    // showAllStu(&pro);
    // scanf("%d");
}