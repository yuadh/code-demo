#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <graphics.h>		// ????????
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
stuList pro;//????
// Operation	
/*getstu(L,i,*e):?????index?????,???e
  inserStu(*L,i,e):?????e????index????
  deleteStu(*L,i,*e):???index?????
  changeStu(*L,i,e):???index??????e
*/
// ??????
STATUA getStu(stuList pro,int index,student *stuSomeOne){
    if(pro.length==0||index<1||index>pro.length){
        return ERROR;
    }
    *stuSomeOne = pro.stuDatas[index-1];
	return SUCCESS;
}
// ??????
STATUA insertStu(stuList *pro,int index,student stuSomeOne){
	if(index<1||index>pro->length+1){
		return ERROR;
	}
	if(index==pro->length+1){//?????
		pro->stuDatas[pro->length]=stuSomeOne;
		pro->length++;
	}else{//????? 
		for(int i=pro->length;i>=index;i--){
			pro->stuDatas[i]=pro->stuDatas[i-1];	
		}	
		pro->stuDatas[index-1]=stuSomeOne;
		pro->length++;
	}
	return SUCCESS;
}
// ??????
STATUA deleteStu(stuList *pro,int index,student *stuSomeOne){
	int i;
	if(pro->length==0||index<1||index>pro->length){
		return ERROR;
	}
	//?index?????????
	for(i=index;i<=pro->length;i++){
		pro->stuDatas[i-1]=pro->stuDatas[i];
	}
	pro->length--;
	return SUCCESS;
}
// ??????
STATUA changeStu(stuList *pro,int index,student stuSomeOne){
	if(pro->length==0||index<1||index>pro->length){
		return ERROR;
	}
	pro->stuDatas[index-1]=stuSomeOne;
}
// void initWin(){
// 	initgraph(600, 600,EW_DBLCLKS);	// ?????????? 640x480 ??
// 	IMAGE background;
// 	loadimage(&background,"resources\\background.png",600,600,1);
// 	putimage(0,0,&background);
// 	// circle(200, 200, 100);	// ?????(200, 200)??? 100
// 	_getch();				// ??????
// 	closegraph();			// ??????	
// }
void InitListReadFile(stuList *pro,char *fileName);
void WriteListFile(stuList *pro,char *fileName);
void listListen(stuList *pro);
void showAllStu(stuList *pro);
void proAddStu(stuList *pro);
void prodelStu(stuList *pro);
void proEdiStu(stuList *pro);
//????????????
IMAGE enterPic;
IMAGE indexPic;
IMAGE logoPic;
// RGB color;
void mainPage();
void enterPage(){//??????????????
	loadimage(&enterPic,"resources\\enter.png",800,600);
	putimage(0,0,&enterPic);
	MOUSEMSG msg;//???????????
	void FlushMouseMsgBuffer();// ??????????????????????????
	while(true){
		while(MouseHit()){//????????
			msg = GetMouseMsg();//??????
			if (msg.uMsg==WM_LBUTTONDOWN){//??????;??????
				Sleep(100);
				//???????
				mainPage();
			}	
		}
	}
	_getch();				// ??????
	closegraph();			// ??????	
}
void initMainP(){
	InitListReadFile(&pro,"test.txt");
	setbkmode(TRANSPARENT);
	loadimage(&indexPic,"resources\\mainbackg.png",800,600);
	putimage(0,0,&indexPic);
	LOGFONT f;
	gettextstyle(&f);						// ????????
	f.lfHeight = 58;						// ??????? 48
	_tcscpy(f.lfFaceName, _T("??"));		// ?????“??”(??? VC ???? _tcscpy_s ??)
	f.lfQuality = ANTIALIASED_QUALITY;		// ??????????  
	settextstyle(&f);						// ??????
	// outtextxy(0, 50, _T("?????"));
	// char proTitle[20] = { "????????" };
	// settextstyle(80, 0, "????");
	setcolor(RGB(9,164,59));
	outtextxy(160, 40, _T("学生成绩管理系统"));
	setcolor(YELLOW);
	setfillcolor(RGB(224,240,230));
	solidrectangle(
		100,
		100,
		700,
		500
	);
	f.lfHeight = 40;						// ??????? 48
	_tcscpy(f.lfFaceName, _T("????"));		// ?????“??”(??? VC ???? _tcscpy_s ??)
	f.lfQuality = ANTIALIASED_QUALITY;		// ??????????  
	settextstyle(&f);						// ??????
	setcolor(RGB(58,59,79));
	outtextxy(180, 120, _T("??"));
	outtextxy(380, 120, _T("??"));
	outtextxy(580, 120, _T("??"));
}
void mainPage(){
	initMainP();//?????
	//????
	LOGFONT f;
	gettextstyle(&f);						// ????????
	f.lfHeight = 30;						// ??????? 48
	_tcscpy(f.lfFaceName, _T("????"));		// ?????“??”(??? VC ???? _tcscpy_s ??)
	f.lfQuality = ANTIALIASED_QUALITY;		// ??????????  
	settextstyle(&f);						// ??????
	// outtextxy(0, 50, _T("?????"));
	// char proTitle[20] = { "????????" };
	// settextstyle(80, 0, "????");
	setcolor(RGB(58,59,79));
	// getStu(stuList pro,int index,student *stuSomeOne)
	student test; char stuID[10],stuScore[10];
	// outtextxy(160, 150,stuID);
	outtextxy(260, 150,test.stuName);
	// outtextxy(460, 150,test.stuScore);
}



int main(){
	// InitListReadFile(&pro,"test.txt");
	initgraph(800, 600);//?????
	//???????????
	enterPage();
	// return 0;
	// listListen(&pro);
    // scanf("%d");
}
// ????
/*
	??????
*/
void InitListReadFile(stuList *pro,char *fileName){//?????
	FILE *fp;
	fp=fopen(fileName,"r");
	// printf("????\n????:");
	student stu;int index=0;
	while(fscanf(fp,"%d\t%s\t%f\n",&stu.stuID,stu.stuName,&stu.stuScore) != EOF){
		if(insertStu(pro,++index,stu)){
			printf("????\n????:");
			printf("%d %s  %.2f\n",stu.stuID,stu.stuName,stu.stuScore);
		}else{
			printf("????\n");
			printf("%d %s  %.2f\n",stu.stuID,stu.stuName,stu.stuScore);
		}
	}
	fclose(fp);
}
void WriteListFile(stuList *pro,char *fileName){//?????
	FILE *fp;
	fp=fopen(fileName,"w");
	if(fp==NULL){
		printf("??????");
		return ;
	}
	for(int i=0;i<pro->length;i++){
		fprintf(fp,"%d\t%s\t%f\n",pro->stuDatas[i].stuID,pro->stuDatas[i].stuName,pro->stuDatas[i].stuScore);
	}
	fclose(fp);
}
void listListen(stuList *pro){//????
	while(1){
		printf("--------------------\n");
		printf("-----1.????------\n");
		printf("-----2.????------\n");
		printf("-----3.????------\n");
		printf("-----4.????------\n");
		printf("-----0.????------\n");
		printf("--------------------\n");
		int btn; scanf("%d",&btn);
		switch(btn){
			case 1://????
				proAddStu(pro);
				break;
			case 2://????
				prodelStu(pro);
				break;
			case 3://????
				proEdiStu(pro);
				break;
			case 4://????
				showAllStu(pro);
				break;
			case 0://??????
				exit(0);
				break;
		}
		WriteListFile(pro,"test.txt");
		// printf("\n%s\n",pro.stuDatas[0].stuName);	
	}
}
void showAllStu(stuList *pro){
	printf("?? ?? ??\n");
	for(int i=0;i<pro->length;i++){
		printf("%d  ",pro->stuDatas[i].stuID);
    	printf("%s  ",pro->stuDatas[i].stuName);
    	printf("%.2f\n",pro->stuDatas[i].stuScore);
	}
}
void proAddStu(stuList *pro){//????
	printf("??:??:%%d ??:%%d ??:%%s ??:%%f\n");
	int stuID,index;char stuName[100];float stuScore;
	printf("??:");scanf("%d",&index);
	printf("??:");scanf("%d",&stuID);
	printf("??:");scanf("%s",stuName);
	printf("??:");scanf("%f",&stuScore);
	// scanf("%d %d %s %f",&index,&stuID,stuName,&stuScore);
	student stu;
	stu.stuID=stuID;strcpy(stu.stuName,stuName);stu.stuScore=stuScore;
	if(insertStu(pro,index,stu)){
		printf("????\n????:");
		printf("%d %s  %.2f\n",stu.stuID,stu.stuName,stu.stuScore);
	}else{
		printf("????\n");
		printf("%d %s  %.2f\n",stu.stuID,stu.stuName,stu.stuScore);
	}
}
void prodelStu(stuList *pro){//????
	printf("??:??:%%d");
	int index; 
	scanf("%d",&index);
	student stu;
	if(deleteStu(pro,index,&stu)){
		printf("????\n");
		printf("%d %s  %.2f\n",stu.stuID,stu.stuName,stu.stuScore);
	}else{
		printf("????\n");
		printf("%d %s  %.2f\n",stu.stuID,stu.stuName,stu.stuScore);
	}
}
void proEdiStu(stuList *pro){
	printf("??:?????:%%d");
	int stuID,index;char stuName[100];float stuScore;
	scanf("%d",&index);
	student stu;
	printf("??:??:%%d ??:%%d ??:%%s ??:%%f\n");
	printf("??:");scanf("%d",&stuID);
	printf("??:");scanf("%s",stuName);
	printf("??:");scanf("%f",&stuScore);
	stu.stuID=stuID;strcpy(stu.stuName,stuName);stu.stuScore=stuScore;
	if(changeStu(pro,index,stu)){
		printf("????\n????:");
		printf("%d %s  %.2f\n",stu.stuID,stu.stuName,stu.stuScore);
	}else{
		printf("????\n");
		printf("%d %s  %.2f\n",stu.stuID,stu.stuName,stu.stuScore);
	}
}
void proGetStu(stuList *pro){

}