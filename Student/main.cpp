#define _stprintf
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
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
stuList pro;//ȫ�ֱ���
// Operation	
/*getstu(L,i,*e):��ȡ�����indexλ�õ�Ԫ��,���ظ�e
  inserStu(*L,i,e):������Ԫ��e�������index��λ����
  deleteStu(*L,i,*e):ɾ����indexλ�õ�Ԫ��
  changeStu(*L,i,e):�޸ĵ�indexλ�õ�Ԫ��Ϊe
*/
// ��ȡ����Ԫ��
STATUA getStu(stuList pro,int index,student *stuSomeOne){
    if(pro.length==0||index<1||index>pro.length){
        return ERROR;
    }
    *stuSomeOne = pro.stuDatas[index-1];
	return SUCCESS;
}
// ��������Ԫ��
STATUA insertStu(stuList *pro,int index,student stuSomeOne){
	if(index<1||index>pro->length+1){
		return ERROR;
	}
	if(index==pro->length+1){//��ĩβ����
		pro->stuDatas[pro->length]=stuSomeOne;
		pro->length++;
	}else{//���м���� 
		for(int i=pro->length;i>=index;i--){
			pro->stuDatas[i]=pro->stuDatas[i-1];	
		}	
		pro->stuDatas[index-1]=stuSomeOne;
		pro->length++;
	}
	return SUCCESS;
}
// ɾ������Ԫ��
STATUA deleteStu(stuList *pro,int index,student *stuSomeOne){
	int i;
	if(pro->length==0||index<1||index>pro->length){
		return ERROR;
	}
	//��indexλ��֮���Ԫ��ǰ��
	for(i=index;i<=pro->length;i++){
		pro->stuDatas[i-1]=pro->stuDatas[i];
	}
	pro->length--;
	return SUCCESS;
}
// �޸�����Ԫ��
STATUA changeStu(stuList *pro,int index,student stuSomeOne){
	if(pro->length==0||index<1||index>pro->length){
		return ERROR;
	}
	pro->stuDatas[index-1]=stuSomeOne;
}
// ���������� - ͼ�λ���˳�����ɾ�Ĳ�
void InitListReadFile(stuList *pro,char *fileName);
void WriteListFile(stuList *pro,char *fileName);
void listListen(stuList *pro);
void showAllStu(stuList *pro);
void proAddStu(stuList *pro);
void prodelStu(stuList *pro);
void proEdiStu(stuList *pro);
//���ڽ���ʹ�õ���ͼƬ����
IMAGE enterPic;
IMAGE indexPic;
IMAGE logoPic;
// RGB color;
void mainPage();
void ButtonInit();
MOUSEMSG sta;//���������Ϣȫ�ֱ���
void enterPage(){//��ʼ���棬�����������������
	InitListReadFile(&pro,"test.txt");//��ʼ����ȡ��pro
	loadimage(&enterPic,"resources\\enter.png",800,600);
	putimage(0,0,&enterPic);
	FlushMouseMsgBuffer();// ��������Ϣ��������������Ч�����Ϣ���뵽��ʽ�ж���
	while(true){
		if(MouseHit()){//���������Ϣ
			sta = GetMouseMsg();//��ȡ�����Ϣ
			if (sta.uMsg==WM_LBUTTONDOWN){//�ж������Ϣ;����������
				Sleep(100);
				//�������������
				mainPage();
			}	
		}
	}
	_getch();				// �����������
	closegraph();			// �رջ�ͼ����	
}
void initMainP(){
	setbkmode(TRANSPARENT);
	loadimage(&indexPic,"resources\\mainbackg.png",800,600);
	putimage(0,0,&indexPic);
	LOGFONT f;
	gettextstyle(&f);						// ��ȡ��ǰ��������
	f.lfHeight = 58;						// ��������߶�Ϊ 48
	_tcscpy(f.lfFaceName, _T("����"));		// ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f);						// ����������ʽ
	setcolor(RGB(157,41,59));
	outtextxy(160, 40, _T("ѧ���ɼ�����ϵͳ"));
	ButtonInit();
}
void ButtonInit(){
	//����ѡ��ı���
	// fillrectangle(130, 645, 260, 670);
	setfillcolor(RGB(58,59,79));
	setcolor(RGB(66,75,80));
	solidroundrect(106,515,236,560,20,20);
	solidroundrect(256,515,386,560,20,20);
	solidroundrect(406,515,536,560,20,20);
	solidroundrect(556,515,686,560,20,20);
	//��������
	LOGFONT f;
	gettextstyle(&f);						// ��ȡ��ǰ��������
	f.lfHeight = 25;						// ��������߶�Ϊ 48
	_tcscpy(f.lfFaceName, _T("����"));		// ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f);						// ����������ʽ
	setcolor(RGB(243,248,241));
	outtextxy(121, 526, _T("�������"));
	outtextxy(271, 526, _T("���ɾ��"));
	outtextxy(421, 526, _T("�����ѯ"));
	outtextxy(571, 526, _T("����޸�"));
}
void initMainDtaP(stuList now,int sta){
	//��������
	LOGFONT f;
	gettextstyle(&f);						// ��ȡ��ǰ��������
	f.lfHeight = 58;						// ��������߶�Ϊ 48
	_tcscpy(f.lfFaceName, _T("����"));		// ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f);						// ����������ʽ
	//���ñ����ʾ
	setfillcolor(RGB(224,240,230));
	solidrectangle(
		100,
		100,
		700,
		500
	);
	f.lfHeight = 40;						// ��������߶�Ϊ 48
	_tcscpy(f.lfFaceName, _T("΢���ź�"));		// ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f);						// ����������ʽ
	setcolor(RGB(58,59,79));
	outtextxy(180, 120, _T("ѧ��"));
	outtextxy(380, 120, _T("����"));
	outtextxy(580, 120, _T("�ɼ�"));
	ButtonInit();

	setcolor(RGB(58,59,79));
	gettextstyle(&f);						// ��ȡ��ǰ��������
	f.lfHeight = 30;						// ��������߶�Ϊ 48
	_tcscpy(f.lfFaceName, _T("΢���ź�"));		// ��������Ϊ�����塱(�߰汾 VC �Ƽ�ʹ�� _tcscpy_s ����)
	f.lfQuality = ANTIALIASED_QUALITY;		// �������Ч��Ϊ�����  
	settextstyle(&f);						// ����������ʽ
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
	initMainP();//��ʼ��ҳ��
	// initMainDtaP(pro,0);//��������ҳ��	
	while(1){//��������
		//��Ҫ������������
		if(changeFlag){
			initMainDtaP(pro,0);//��������ҳ��	
			changeFlag--;
		}
		FlushMouseMsgBuffer();//�������ݴ�
		sta = GetMouseMsg();
		HWND wnd = GetHWnd();
		if(sta.x>106&&sta.x<236&&sta.y>515&&sta.y<560){//����ѧ����Ϣ
			setlinecolor(RED);
			if(sta.uMsg==WM_LBUTTONDOWN){
				student temp;
				char index[10],stuID[10],stuName[40],stuScore[10];
				InputBox(index, 10, "����Ҫ�����λ�����");
				// int i = _wtoi(index);
				int i = atoi(index);
				InputBox(stuID, 10, "����ѧ��ID");
				InputBox(temp.stuName, 40, "����ѧ������");
				InputBox(stuScore, 10, "����ѧ���ɼ�");
				int tempID=atoi(stuID),tempScore=atof(stuScore);
				temp.stuID=tempID;temp.stuScore=tempScore;
				// STATUA insertStu(stuList *pro,int index,student stuSomeOne)
				insertStu(&pro,i,temp);
				WriteListFile(&pro,"test.txt");changeFlag++;
				MessageBox(wnd, "д��ɹ�", "��ʾ", MB_OK | MB_ICONWARNING);
			}
		}
		if(sta.x>256&&sta.x<386&&sta.y>515&&sta.y<560){
			setlinecolor(RED);
			if(sta.uMsg==WM_LBUTTONDOWN){
				student temp;
				char index[10];
				InputBox(index, 10, "����Ҫɾ����λ�����");
				int i = atoi(index);
				deleteStu(&pro,i,&temp);
				MessageBox(wnd, "�ɹ�ɾ��", "��ʾ", MB_OK | MB_ICONWARNING);
				//STATUA deleteStu(stuList *pro,int index,student *stuSomeOne)
				//MessageBox(wnd, "button2", "��ʾ", MB_OK | MB_ICONWARNING);
				WriteListFile(&pro,"test.txt");changeFlag++;
			}
		}
		if(sta.x>406&&sta.x<536&&sta.y>515&&sta.y<560){//��ѯѧ����Ϣ
			setlinecolor(RED);
			if(sta.uMsg==WM_LBUTTONDOWN){
				char index[10];
				InputBox(index, 10, "����Ҫ��ѯ�����");
				// int i = _wtoi(index);
				int i = atoi(index);
				student temp;
				getStu(pro,i,&temp);
				char tempShow[40]="";char stuID[10]=""; char stuScore[10];
				sprintf(stuID,"%d",temp.stuID);
				sprintf(stuScore,"%.2f",temp.stuScore);
				strcat(tempShow,"��ѯ����Ϣ:ѧ��:");
				strcat(tempShow,stuID);
				strcat(tempShow," ����:");
				strcat(tempShow,temp.stuName);
				strcat(tempShow," �ɼ�:");
				strcat(tempShow,stuScore);
				MessageBox(wnd, tempShow, "��ʾ", MB_OK | MB_ICONWARNING);
			}
		}
		if(sta.x>556&&sta.x<686&&sta.y>515&&sta.y<560){
			setlinecolor(RED);
			if(sta.uMsg==WM_LBUTTONDOWN){
				// MessageBox(wnd, "button4", "��ʾ", MB_OK | MB_ICONWARNING);
				student temp;
				char index[10],stuID[10],stuName[40],stuScore[10];
				InputBox(index, 10, "����Ҫ�޸ĵ�λ�����");
				// int i = _wtoi(index);
				int i = atoi(index);
				InputBox(stuID, 10, "����ѧ��ID");
				InputBox(temp.stuName, 40, "����ѧ������");
				InputBox(stuScore, 10, "����ѧ���ɼ�");
				int tempID=atoi(stuID),tempScore=atof(stuScore);
				temp.stuID=tempID;temp.stuScore=tempScore;
				// STATUA insertStu(stuList *pro,int index,student stuSomeOne)
				// STATUA changeStu(stuList *pro,int index,student stuSomeOne)
				changeStu(&pro,i,temp);
				MessageBox(wnd, "�޸ĳɹ�", "��ʾ", MB_OK | MB_ICONWARNING);
				WriteListFile(&pro,"test.txt");changeFlag++;
			}
		}
	}
}
int main(){
	initgraph(800, 600);//��ʼ������
	enterPage();
}
// Ӧ�ò���
/*
	dos��-Ӧ�ò������
*/
void InitListReadFile(stuList *pro,char *fileName){//���ļ�����
	FILE *fp;
	fp=fopen(fileName,"r");
	// printf("����ɹ�\n�������:");
	student stu;int index=0;
	while(fscanf(fp,"%d\t%s\t%f\n",&stu.stuID,stu.stuName,&stu.stuScore) != EOF){
		if(insertStu(pro,++index,stu)){
			printf("����ɹ�\n�������:");
			printf("%d %s  %.2f\n",stu.stuID,stu.stuName,stu.stuScore);
		}else{
			printf("����ʧ��\n");
			printf("%d %s  %.2f\n",stu.stuID,stu.stuName,stu.stuScore);
		}
	}
	fclose(fp);
}
void WriteListFile(stuList *pro,char *fileName){//д�ļ�����
	FILE *fp;
	fp=fopen(fileName,"w");
	if(fp==NULL){
		printf("�ļ���ʧ��");
		return ;
	}
	for(int i=0;i<pro->length;i++){
		fprintf(fp,"%d\t%s\t%f\n",pro->stuDatas[i].stuID,pro->stuDatas[i].stuName,pro->stuDatas[i].stuScore);
	}
	fclose(fp);
}
void listListen(stuList *pro){//�����¼�
	while(1){
		printf("--------------------\n");
		printf("-----1.���ѧ��------\n");
		printf("-----2.ɾ��ѧ��------\n");
		printf("-----3.�޸�ѧ��------\n");
		printf("-----4.��ѯѧ��------\n");
		printf("-----0.�˳�����------\n");
		printf("--------------------\n");
		int btn; scanf("%d",&btn);
		switch(btn){
			case 1://����Ԫ��
				proAddStu(pro);
				break;
			case 2://ɾ��Ԫ��
				prodelStu(pro);
				break;
			case 3://�޸�Ԫ��
				proEdiStu(pro);
				break;
			case 4://��ѯԪ��
				showAllStu(pro);
				break;
			case 0://�˳��رճ���
				exit(0);
				break;
		}
		WriteListFile(pro,"test.txt");
		// printf("\n%s\n",pro.stuDatas[0].stuName);	
	}
}
void showAllStu(stuList *pro){
	printf("ѧ�� ���� �ɼ�\n");
	for(int i=0;i<pro->length;i++){
		printf("%d  ",pro->stuDatas[i].stuID);
    	printf("%s  ",pro->stuDatas[i].stuName);
    	printf("%.2f\n",pro->stuDatas[i].stuScore);
	}
}
void proAddStu(stuList *pro){//����ѧ��
	printf("����:λ��:%%d ѧ��:%%d ����:%%s �ɼ�:%%f\n");
	int stuID,index;char stuName[100];float stuScore;
	printf("λ��:");scanf("%d",&index);
	printf("ѧ��:");scanf("%d",&stuID);
	printf("����:");scanf("%s",stuName);
	printf("�ɼ�:");scanf("%f",&stuScore);
	// scanf("%d %d %s %f",&index,&stuID,stuName,&stuScore);
	student stu;
	stu.stuID=stuID;strcpy(stu.stuName,stuName);stu.stuScore=stuScore;
	if(insertStu(pro,index,stu)){
		printf("����ɹ�\n�������:");
		printf("%d %s  %.2f\n",stu.stuID,stu.stuName,stu.stuScore);
	}else{
		printf("����ʧ��\n");
		printf("%d %s  %.2f\n",stu.stuID,stu.stuName,stu.stuScore);
	}
}
void prodelStu(stuList *pro){//ɾ��ѧ��
	printf("����:λ��:%%d");
	int index; 
	scanf("%d",&index);
	student stu;
	if(deleteStu(pro,index,&stu)){
		printf("ɾ���ɹ�\n");
		printf("%d %s  %.2f\n",stu.stuID,stu.stuName,stu.stuScore);
	}else{
		printf("ɾ��ʧ��\n");
		printf("%d %s  %.2f\n",stu.stuID,stu.stuName,stu.stuScore);
	}
}
void proEdiStu(stuList *pro){
	printf("����:���޸�λ��:%%d");
	int stuID,index;char stuName[100];float stuScore;
	scanf("%d",&index);
	student stu;
	printf("����:λ��:%%d ѧ��:%%d ����:%%s �ɼ�:%%f\n");
	printf("ѧ��:");scanf("%d",&stuID);
	printf("����:");scanf("%s",stuName);
	printf("�ɼ�:");scanf("%f",&stuScore);
	stu.stuID=stuID;strcpy(stu.stuName,stuName);stu.stuScore=stuScore;
	if(changeStu(pro,index,stu)){
		printf("����ɹ�\n�������:");
		printf("%d %s  %.2f\n",stu.stuID,stu.stuName,stu.stuScore);
	}else{
		printf("����ʧ��\n");
		printf("%d %s  %.2f\n",stu.stuID,stu.stuName,stu.stuScore);
	}
}
void proGetStu(stuList *pro){

}