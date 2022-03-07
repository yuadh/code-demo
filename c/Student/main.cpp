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
// void initWin(){
// 	initgraph(600, 600,EW_DBLCLKS);	// ������ͼ���ڣ���СΪ 640x480 ����
// 	IMAGE background;
// 	loadimage(&background,"resources\\background.png",600,600,1);
// 	putimage(0,0,&background);
// 	// circle(200, 200, 100);	// ��Բ��Բ��(200, 200)���뾶 100
// 	_getch();				// �����������
// 	closegraph();			// �رջ�ͼ����	
// }
//���ڽ���ʹ�õ���ͼƬ����
IMAGE enterPic;
IMAGE indexPic;
void enterPage(){//��ʼ���棬�����������������
	loadimage(&enterPic,"resources\\enter.png",800,600);
	putimage(0,0,&enterPic);
	MOUSEMSG msg;//������������������Ϣ
	void FlushMouseMsgBuffer();// ��������Ϣ��������������Ч�����Ϣ���뵽��ʽ�ж���
	while(true){
		while(MouseHit()){//�������������Ϣ
			msg = GetMouseMsg();//��ȡ�����Ϣ
			if (msg.uMsg==WM_LBUTTONDOWN){//�ж������Ϣ;����������
				Sleep(100);
				//�������������
				loadimage(&indexPic,"resources\\bg.jpg",800,600);
				putimage(0,0,&indexPic);
			}	
		}
	}
	_getch();				// �����������
	closegraph();			// �رջ�ͼ����	
}
void InitListReadFile(stuList *pro,char *fileName);
void WriteListFile(stuList *pro,char *fileName);
void listListen(stuList *pro);
void showAllStu(stuList *pro);
void proAddStu(stuList *pro);
void prodelStu(stuList *pro);
void proEdiStu(stuList *pro);
int main(){
	InitListReadFile(&pro,"test.txt");
	initgraph(800, 600);//��ʼ������
	//��ʼ�����ļ����ж�����
	enterPage();
	// return 0;
	// listListen(&pro);
    // scanf("%d");
}
// Ӧ�ò���
/*
	Ӧ�ò������
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