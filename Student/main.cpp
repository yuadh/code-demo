#define _stprintf
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
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
    char stuName[100];
    float stuScore;
}student;
typedef struct{
    student  stuDatas[MAXSIZE];
    int length;
}stuList;
stuList pro;//全局变量
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
STATUA insertStu(stuList *pro,int index,student stuSomeOne){
	if(index<1||index>pro->length+1){
		return ERROR;
	}
	if(index==pro->length+1){//在末尾插入
		pro->stuDatas[pro->length]=stuSomeOne;
		pro->length++;
	}else{//在中间插入 
		for(int i=pro->length;i>=index;i--){
			pro->stuDatas[i]=pro->stuDatas[i-1];	
		}	
		pro->stuDatas[index-1]=stuSomeOne;
		pro->length++;
	}
	return SUCCESS;
}
// 删除链表元素
STATUA deleteStu(stuList *pro,int index,student *stuSomeOne){
	int i;
	if(pro->length==0||index<1||index>pro->length){
		return ERROR;
	}
	//将index位置之后的元素前移
	for(i=index;i<=pro->length;i++){
		pro->stuDatas[i-1]=pro->stuDatas[i];
	}
	pro->length--;
	return SUCCESS;
}
// 修改链表元素
STATUA changeStu(stuList *pro,int index,student stuSomeOne){
	if(pro->length==0||index<1||index>pro->length){
		return ERROR;
	}
	pro->stuDatas[index-1]=stuSomeOne;
}
// 程序层面操作 - 图形化的顺序表增删改查
void InitListReadFile(stuList *pro,char *fileName);
void WriteListFile(stuList *pro,char *fileName);
void listListen(stuList *pro);
void showAllStu(stuList *pro);
void proAddStu(stuList *pro);
void prodelStu(stuList *pro);
void proEdiStu(stuList *pro);
//窗口界面使用到的图片变量
IMAGE enterPic;
IMAGE indexPic;
IMAGE logoPic;
// RGB color;
void mainPage();
void ButtonInit();
MOUSEMSG sta;//保存鼠标消息全局变量
void enterPage(){//开始界面，按任意键进入主程序
	InitListReadFile(&pro,"test.txt");//初始化读取到pro
	loadimage(&enterPic,"resources\\enter.png",800,600);
	putimage(0,0,&enterPic);
	FlushMouseMsgBuffer();// 清空鼠标消息缓冲区，避免无效鼠标信息带入到正式判断中
	while(true){
		if(MouseHit()){//监听鼠标信息
			sta = GetMouseMsg();//获取鼠标消息
			if (sta.uMsg==WM_LBUTTONDOWN){//判断鼠标信息;鼠标左键按下
				Sleep(100);
				//进入程序主界面
				mainPage();
			}	
		}
	}
	_getch();				// 按任意键继续
	closegraph();			// 关闭绘图窗口	
}
void initMainP(){
	setbkmode(TRANSPARENT);
	loadimage(&indexPic,"resources\\mainbackg.png",800,600);
	putimage(0,0,&indexPic);
	LOGFONT f;
	gettextstyle(&f);						// 获取当前字体设置
	f.lfHeight = 58;						// 设置字体高度为 48
	_tcscpy(f.lfFaceName, _T("黑体"));		// 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);						// 设置字体样式
	setcolor(RGB(157,41,59));
	outtextxy(160, 40, _T("学生成绩管理系统"));
	ButtonInit();
}
void ButtonInit(){
	//三个选项的背景
	// fillrectangle(130, 645, 260, 670);
	setfillcolor(RGB(58,59,79));
	setcolor(RGB(66,75,80));
	solidroundrect(106,515,236,560,20,20);
	solidroundrect(256,515,386,560,20,20);
	solidroundrect(406,515,536,560,20,20);
	solidroundrect(556,515,686,560,20,20);
	//铺设数据
	LOGFONT f;
	gettextstyle(&f);						// 获取当前字体设置
	f.lfHeight = 25;						// 设置字体高度为 48
	_tcscpy(f.lfFaceName, _T("黑体"));		// 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);						// 设置字体样式
	setcolor(RGB(243,248,241));
	outtextxy(121, 526, _T("点击增加"));
	outtextxy(271, 526, _T("点击删除"));
	outtextxy(421, 526, _T("点击查询"));
	outtextxy(571, 526, _T("点击修改"));
}
void initMainDtaP(stuList now,int sta){
	//铺设数据
	LOGFONT f;
	gettextstyle(&f);						// 获取当前字体设置
	f.lfHeight = 58;						// 设置字体高度为 48
	_tcscpy(f.lfFaceName, _T("黑体"));		// 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);						// 设置字体样式
	//设置表格显示
	setfillcolor(RGB(224,240,230));
	solidrectangle(
		100,
		100,
		700,
		500
	);
	f.lfHeight = 40;						// 设置字体高度为 48
	_tcscpy(f.lfFaceName, _T("微软雅黑"));		// 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);						// 设置字体样式
	setcolor(RGB(58,59,79));
	outtextxy(180, 120, _T("学号"));
	outtextxy(380, 120, _T("姓名"));
	outtextxy(580, 120, _T("成绩"));
	ButtonInit();

	setcolor(RGB(58,59,79));
	gettextstyle(&f);						// 获取当前字体设置
	f.lfHeight = 30;						// 设置字体高度为 48
	_tcscpy(f.lfFaceName, _T("微软雅黑"));		// 设置字体为“黑体”(高版本 VC 推荐使用 _tcscpy_s 函数)
	f.lfQuality = ANTIALIASED_QUALITY;		// 设置输出效果为抗锯齿  
	settextstyle(&f);						// 设置字体样式
	// getStu(stuList pro,int index,student *stuSomeOne)
	student test; char stuID[10],stuScore[10];int i;
	for(i=0;i<now.length;i++){
		getStu(now,i+1,&test);
		sprintf(stuID,"%d",test.stuID);
		sprintf(stuScore,"%.2f",test.stuScore);
		outtextxy(160, 160+(i*42),stuID);
		outtextxy(380, 160+(i*42),test.stuName);
		outtextxy(580, 160+(i*42),stuScore);
	}
	// ButtonInit();
}

void mainPage(){
	int changeFlag = 1;
	initMainP();//初始化页面
	// initMainDtaP(pro,0);//铺设数据页面	
	while(1){//按键监听
		//需要重新铺设数据
		if(changeFlag){
			initMainDtaP(pro,0);//铺设数据页面	
			changeFlag--;
		}
		FlushMouseMsgBuffer();//清空鼠标暂存
		sta = GetMouseMsg();
		HWND wnd = GetHWnd();
		if(sta.x>106&&sta.x<236&&sta.y>515&&sta.y<560){//增加学生信息
			setlinecolor(RED);
			if(sta.uMsg==WM_LBUTTONDOWN){
				student temp;
				char index[10],stuID[10],stuName[40],stuScore[10];
				InputBox(index, 10, "输入要插入的位置序号");
				// int i = _wtoi(index);
				int i = atoi(index);
				InputBox(stuID, 10, "输入学生ID");
				InputBox(temp.stuName, 40, "输入学生姓名");
				InputBox(stuScore, 10, "输入学生成绩");
				int tempID=atoi(stuID),tempScore=atof(stuScore);
				temp.stuID=tempID;temp.stuScore=tempScore;
				// STATUA insertStu(stuList *pro,int index,student stuSomeOne)
				insertStu(&pro,i,temp);
				WriteListFile(&pro,"test.txt");changeFlag++;
				MessageBox(wnd, "写入成功", "提示", MB_OK | MB_ICONWARNING);
			}
		}
		if(sta.x>256&&sta.x<386&&sta.y>515&&sta.y<560){
			setlinecolor(RED);
			if(sta.uMsg==WM_LBUTTONDOWN){
				student temp;
				char index[10];
				InputBox(index, 10, "输入要删除的位置序号");
				int i = atoi(index);
				deleteStu(&pro,i,&temp);
				MessageBox(wnd, "成功删除", "提示", MB_OK | MB_ICONWARNING);
				//STATUA deleteStu(stuList *pro,int index,student *stuSomeOne)
				//MessageBox(wnd, "button2", "提示", MB_OK | MB_ICONWARNING);
				WriteListFile(&pro,"test.txt");changeFlag++;
			}
		}
		if(sta.x>406&&sta.x<536&&sta.y>515&&sta.y<560){//查询学生信息
			setlinecolor(RED);
			if(sta.uMsg==WM_LBUTTONDOWN){
				char index[10];
				InputBox(index, 10, "输入要查询的序号");
				// int i = _wtoi(index);
				int i = atoi(index);
				student temp;
				getStu(pro,i,&temp);
				char tempShow[40]="";char stuID[10]=""; char stuScore[10];
				sprintf(stuID,"%d",temp.stuID);
				sprintf(stuScore,"%.2f",temp.stuScore);
				strcat(tempShow,"查询到信息:学号:");
				strcat(tempShow,stuID);
				strcat(tempShow," 姓名:");
				strcat(tempShow,temp.stuName);
				strcat(tempShow," 成绩:");
				strcat(tempShow,stuScore);
				MessageBox(wnd, tempShow, "提示", MB_OK | MB_ICONWARNING);
			}
		}
		if(sta.x>556&&sta.x<686&&sta.y>515&&sta.y<560){
			setlinecolor(RED);
			if(sta.uMsg==WM_LBUTTONDOWN){
				// MessageBox(wnd, "button4", "提示", MB_OK | MB_ICONWARNING);
				student temp;
				char index[10],stuID[10],stuName[40],stuScore[10];
				InputBox(index, 10, "输入要修改的位置序号");
				// int i = _wtoi(index);
				int i = atoi(index);
				InputBox(stuID, 10, "输入学生ID");
				InputBox(temp.stuName, 40, "输入学生姓名");
				InputBox(stuScore, 10, "输入学生成绩");
				int tempID=atoi(stuID),tempScore=atof(stuScore);
				temp.stuID=tempID;temp.stuScore=tempScore;
				// STATUA insertStu(stuList *pro,int index,student stuSomeOne)
				// STATUA changeStu(stuList *pro,int index,student stuSomeOne)
				changeStu(&pro,i,temp);
				MessageBox(wnd, "修改成功", "提示", MB_OK | MB_ICONWARNING);
				WriteListFile(&pro,"test.txt");changeFlag++;
			}
		}
	}
}
int main(){
	initgraph(800, 600);//初始化窗口
	enterPage();
}
// 应用操作
/*
	dos版-应用层面操作
*/
void InitListReadFile(stuList *pro,char *fileName){//读文件操作
	FILE *fp;
	fp=fopen(fileName,"r");
	// printf("插入成功\n插入对象:");
	student stu;int index=0;
	while(fscanf(fp,"%d\t%s\t%f\n",&stu.stuID,stu.stuName,&stu.stuScore) != EOF){
		if(insertStu(pro,++index,stu)){
			printf("插入成功\n插入对象:");
			printf("%d %s  %.2f\n",stu.stuID,stu.stuName,stu.stuScore);
		}else{
			printf("插入失败\n");
			printf("%d %s  %.2f\n",stu.stuID,stu.stuName,stu.stuScore);
		}
	}
	fclose(fp);
}
void WriteListFile(stuList *pro,char *fileName){//写文件操作
	FILE *fp;
	fp=fopen(fileName,"w");
	if(fp==NULL){
		printf("文件打开失败");
		return ;
	}
	for(int i=0;i<pro->length;i++){
		fprintf(fp,"%d\t%s\t%f\n",pro->stuDatas[i].stuID,pro->stuDatas[i].stuName,pro->stuDatas[i].stuScore);
	}
	fclose(fp);
}
void listListen(stuList *pro){//监听事件
	while(1){
		printf("--------------------\n");
		printf("-----1.添加学生------\n");
		printf("-----2.删除学生------\n");
		printf("-----3.修改学生------\n");
		printf("-----4.查询学生------\n");
		printf("-----0.退出程序------\n");
		printf("--------------------\n");
		int btn; scanf("%d",&btn);
		switch(btn){
			case 1://插入元素
				proAddStu(pro);
				break;
			case 2://删除元素
				prodelStu(pro);
				break;
			case 3://修改元素
				proEdiStu(pro);
				break;
			case 4://查询元素
				showAllStu(pro);
				break;
			case 0://退出关闭程序
				exit(0);
				break;
		}
		WriteListFile(pro,"test.txt");
		// printf("\n%s\n",pro.stuDatas[0].stuName);	
	}
}
void showAllStu(stuList *pro){
	printf("学号 姓名 成绩\n");
	for(int i=0;i<pro->length;i++){
		printf("%d  ",pro->stuDatas[i].stuID);
    	printf("%s  ",pro->stuDatas[i].stuName);
    	printf("%.2f\n",pro->stuDatas[i].stuScore);
	}
}
void proAddStu(stuList *pro){//插入学生
	printf("输入:位置:%%d 学号:%%d 姓名:%%s 成绩:%%f\n");
	int stuID,index;char stuName[100];float stuScore;
	printf("位置:");scanf("%d",&index);
	printf("学号:");scanf("%d",&stuID);
	printf("姓名:");scanf("%s",stuName);
	printf("成绩:");scanf("%f",&stuScore);
	// scanf("%d %d %s %f",&index,&stuID,stuName,&stuScore);
	student stu;
	stu.stuID=stuID;strcpy(stu.stuName,stuName);stu.stuScore=stuScore;
	if(insertStu(pro,index,stu)){
		printf("插入成功\n插入对象:");
		printf("%d %s  %.2f\n",stu.stuID,stu.stuName,stu.stuScore);
	}else{
		printf("插入失败\n");
		printf("%d %s  %.2f\n",stu.stuID,stu.stuName,stu.stuScore);
	}
}
void prodelStu(stuList *pro){//删除学生
	printf("输入:位置:%%d");
	int index; 
	scanf("%d",&index);
	student stu;
	if(deleteStu(pro,index,&stu)){
		printf("删除成功\n");
		printf("%d %s  %.2f\n",stu.stuID,stu.stuName,stu.stuScore);
	}else{
		printf("删除失败\n");
		printf("%d %s  %.2f\n",stu.stuID,stu.stuName,stu.stuScore);
	}
}
void proEdiStu(stuList *pro){
	printf("输入:需修改位置:%%d");
	int stuID,index;char stuName[100];float stuScore;
	scanf("%d",&index);
	student stu;
	printf("输入:位置:%%d 学号:%%d 姓名:%%s 成绩:%%f\n");
	printf("学号:");scanf("%d",&stuID);
	printf("姓名:");scanf("%s",stuName);
	printf("成绩:");scanf("%f",&stuScore);
	stu.stuID=stuID;strcpy(stu.stuName,stuName);stu.stuScore=stuScore;
	if(changeStu(pro,index,stu)){
		printf("插入成功\n插入对象:");
		printf("%d %s  %.2f\n",stu.stuID,stu.stuName,stu.stuScore);
	}else{
		printf("插入失败\n");
		printf("%d %s  %.2f\n",stu.stuID,stu.stuName,stu.stuScore);
	}
}
void proGetStu(stuList *pro){

}