#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "Link.h"


//�����ʵ�岻ʹ��ָ�룬��������ṹ������ֵʱ��Ҫʹ�õ�ָ��
//ͷָ���ʾ���������
int main(){
    //ͷָ�룺ָ��ͷ�ڵ��ָ��
    //ͷ�ڵ㣺���洢���ݵģ�ָ��������Ԫ�ص�ͷ���
    //��Ԫ�أ�����ĵ�һ��Ԫ��?
    ListArg=InitListEnd(ListArg); //ͷָ�룬����ͷ���ĵ�ַ
    // printf(ListArg->nodeData);
    // ListNode a = {4,NULL};
    // ListAddNode(ListArg,4,a);
    // ListOne=getItemUN(ListArg,5);
    // LinkList x = getItem(ListArg,4);
    // printf("ȡֵ:%d\n",ListOne.nodeData);
    ListRmNode(ListArg,4);
    ShowList(ListArg);
    return 0;
}

