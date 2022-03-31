#include "Link.h"
// link.h ��?����?�?�����?������??
// �����?���?�?������

/** 
01.�����������������?��?�??�������������?���
?����������?��?�����������??�??������?�������??�??���?��������?�������
**/
void MergeList(LinkList listA,LinkList listB){
    LinkList tA = listA->nodeNext,tB = listB->nodeNext;//?����?�??�����?�
    LinkList t,tend; //��?���������?�?��
    listA->nodeNext = NULL ; //?�������
    tend = listA; //?�?�
    while(tA&&tB){//
        if(tA->nodeData<tB->nodeData){
            //?�?�����������
            tend->nodeNext = tA;
            tend = tA;
            tA = tA->nodeNext;
        }else if(tA->nodeData>tB->nodeData){
            tend->nodeNext = tB;
            tend = tB;
            tB = tB->nodeNext;
        }else{
            // ?���?�����
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
// ��?�������� A �� B �?��?�������?���?�?������?�
// �����?���?��������� A �� B �?����������������� A ������
void listAUlistB(LinkList la,LinkList lb){
    LinkList tA = la->nodeNext,tB = lb->nodeNext;
    LinkList tend,t;
    tend = la; // tend??����������??��
    while(tA&&tB){
        if(tA->nodeData==tB->nodeData){//�����������������??���?�
            tend->nodeNext = tA;
            tend = tA;
            tA = tA->nodeNext;
            t = tB;
            tB = tB->nodeNext;
            free(t);
        }else if(tA->nodeData<tB->nodeData){
            //��?�?�������������??����?��?�����??����?���?��?���
            t = tA;
            tA = tA->nodeNext;
            free(t);
        }else{
            t = tB;
            tB = tB->nodeNext;
            free(t);
        }
    }
    while(tA){//�?�?��?�
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
//����?��?����?�?�?����� A �?�?����������?�?������ B �� C��
//���� B ���??�? A ����??��0�???
//�� C ���??�? A ����?����0�??� (����A�?�?��?����������?��B��C������A���??�)
void  ListAtoBandC(LinkList la,LinkList lb,LinkList lc){
    LinkList tA= la->nodeNext,tB = lb,tC = lc; //?�����������?�?�
    while(tA){//?������
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
// ���?���?�������������??���������� `?��` ��?��
// ��?�������?���??�??���??��?���?�???�?�? o(1)
void ListReverse(LinkList la){
    LinkList tA = la->nodeNext,trear,tpre;//����?������??�
    tpre = NULL ; //��?�� ?���???���???��
    la->nodeNext = NULL;
    while(tA){
        trear = tA->nodeNext;//�?�����?�
        tA->nodeNext = tpre;
        tpre = tA;
        tA = trear;
    }
    la->nodeNext = tpre;
}
// ��? p ?��?��?�������?�?���??��?�?? `data`��`prior`��`next` ������
// ����? `change(p)` , ���� p ��?��???��?���?��?��
void change(LinkList lp){
    
}


int main(){
    //??�??��?�?��?��
    //?�??���?���??�?��������?�?�?���
    //��?�?������?�?��?��
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