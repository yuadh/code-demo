#include "Link.h"
// link.h ��װ����ʽ�洢����Ļ������ݽṹ
// �����Ƕ���Ŀ�ľ������

/** 
01.�����������������б�ϲ�Ϊһ�������������б�
Ҫ����������ʹ��ԭ����������Ĵ洢�ռ䣬������ռ�������Ĵ洢�ռ䡣���в��������ظ�������
**/
void MergeList(LinkList listA,LinkList listB){
    LinkList tA = listA->nodeNext,tB = listB->nodeNext;//ָ����Ԫ�ڵ㣬�����ڵ�
    LinkList t,tend; //��ʱ��������ڵ�ָ��
    listA->nodeNext = NULL ; //ָ�������
    tend = listA; //β�ڵ�
    while(tA&&tB){//
        if(tA->nodeData<tB->nodeData){
            //ͷ�巨�����������
            tend->nodeNext = tA;
            tend = tA;
            tA = tA->nodeNext;
        }else if(tA->nodeData>tB->nodeData){
            tend->nodeNext = tB;
            tend = tB;
            tB = tB->nodeNext;
        }else{
            // ɾ���ظ�����
            tend->nodeNext = tA;
            tend = tA;
            tA = tA->nodeNext;
            t = tB->nodeNext;
            free(tB);
            tB = t;
        }
    }
    tend->nodeNext = tA?tA:tB;
    free(listB);
}
// ��֪�������� A �� B �ֱ��ʾ�������ϣ���Ԫ�ص������С�
// �����һ���㷨��������� A �� B �Ľ����������������� A ������
void listAUlistB(LinkList la,LinkList lb){
    LinkList tA = la->nodeNext,tB = lb->nodeNext;
    LinkList tend,t;
    tend = la; // tendΪָ���������βԪ��
    while(tA&&tB){
        if(tA->nodeData==tB->nodeData){//�����������������ͷŶ���ڵ�
            tend->nodeNext = tA;
            tend = tA;
            tA = tA->nodeNext;
            t = tB;
            tB = tB->nodeNext;
            free(t);
        }else if(tA->nodeData<tB->nodeData){
            //��Ϊ�ǵ�������������Ҫɾ����С��Ԫ�����ԱȺ����Ԫ���Ƿ��н���
            t = tA;
            tA = tA->nodeNext;
            free(t);
        }else{
            t = tB;
            tB = tB->nodeNext;
            free(t);
        }
    }
    while(tA){//�ͷ�ʣ��ڵ�
        t = tA;
        tA = tA->nodeNext;
        free(t);
    }
    while(tB){
        t = tB;
        tB = tB->nodeNext;
        free(t);
    }
    tend->nodeNext = NULL;
    free(lb);
}
//����㷨��һ����ͷ�ڵ�ĵ����� A �ֽ�Ϊ����������ͬ�ṹ������ B �� C��
//���� B ��Ľڵ�Ϊ A ����ֵС��0�Ľڵ㣬
//�� C ��Ľڵ�Ϊ A ����ֵ����0�Ľڵ� (����A�е�Ԫ��Ϊ����������Ҫ��B��C������A��Ľڵ�)
void  ListAtoBandC(LinkList la,LinkList lb,LinkList lc){
    LinkList tA= la->nodeNext,tB = lb,tC = lc; //ָ����������β�ڵ�
    while(tA){//ѭ������
        if(tA->nodeData == 0){
            return ;//�����0����
        }else if(tA->nodeData<0){//���� B ��
            tB->nodeNext = tA;
            tB = tB->nodeNext;
            tA = tA->nodeNext;
        }else if(tA->nodeData>0){
            tC->nodeNext = tA;
            tC = tC->nodeNext;
            tA = tA->nodeNext;
        }
    }
    tB->nodeNext = NULL;
    tC->nodeNext = NULL;
    free(la);
}
// ���һ���㷨�������������нڵ�������� `ԭ��` ��ת��
// ��Ҫ�������ԭ��Ĵ洢�ռ䣬���仰˵��Ҫ���㷨�Ŀռ临�Ӷ�Ϊ o(1)
void ListReverse(LinkList la){
    LinkList tA = la->nodeNext,trear,tpre;//����ǰ������̽ڵ�
    tpre = NULL ; //��ʼ�� ǰ���սڵ㣬���Ϊͷָ��
    la->nodeNext = NULL;
    while(tA){
        trear = tA->nodeNext;//�洢�����ڵ�
        tA->nodeNext = tpre;
        tpre = tA;
        tA = trear;
    }
    la->nodeNext = tpre;
}
// ��֪ p ָ��˫��ѭ�������е�һ���ڵ㣬��ڵ�ṹΪ `data`��`prior`��`next` ������
// ����㷨 `change(p)` , ���� p ��ָ��Ľڵ㼰��ǰ���ڵ��˳��
void change(LinkList lp){
    
}


int main(){
    //ͷָ�룺ָ��ͷ�ڵ��ָ��
    //ͷ�ڵ㣺���洢���ݵģ�ָ��������Ԫ�ص�ͷ���
    //��Ԫ�أ�����ĵ�һ��Ԫ��
    // ListArg=InitListEnd(ListArg);
    LinkList la,lb,lc;
    la = InitListEnd(la);
    // lb = InitListEnd(lb);
    // lc = InitListEnd(lc);
    // ListAtoBandC(la,lb,lc);
    ListReverse(la);
    ShowList(la);
    return 0;
}