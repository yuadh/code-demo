#include "Link.h"


/** 
01.�����������������б�ϲ�Ϊһ�������������б�
Ҫ����������ʹ��ԭ����������Ĵ洢�ռ䣬������ռ�������Ĵ洢�ռ䡣���в��������ظ�������
**/
void MergeList(LinkList listA,LinkList listB){
    LinkList tA = listA->nodeNext,tB = listB->nodeNext;//????????????????
    LinkList t,tend; //?????????????????
    listA->nodeNext = NULL ; //????????
    tend = listA; //????
    while(tA&&tB){//
        if(tA->nodeData<tB->nodeData){
            //??????????????
            tend->nodeNext = tA;
            tend = tA;
            tA = tA->nodeNext;
        }else if(tA->nodeData>tB->nodeData){
            tend->nodeNext = tB;
            tend = tB;
            tB = tB->nodeNext;
        }else{
            // �����������ֵͬ������£��ͷ�����һ��
            // ??????????
            tend->nodeNext = tA;
            tend = tA;
            tA = tA->nodeNext;
            t = tB->nodeNext;//�ͷ�
            free(tB);
            tB = t;
        }
    }
    tend->nodeNext = tA?tA:tB;//����һ���ڵ�û��������뵽������
    free(listB);
}
// ��֪�������� A �� B �ֱ��ʾ�������ϣ���Ԫ�ص������С�
// �����һ���㷨��������� A �� B �Ľ����������������� A ������
void listAUlistB(LinkList la,LinkList lb){
    LinkList tA = la->nodeNext,tB = lb->nodeNext;
    LinkList tend,t;
    tend = la; // tend????????????????
    while(tA&&tB){
        if(tA->nodeData==tB->nodeData){//????????????????????????
            tend->nodeNext = tA;
            tend = tA;
            tA = tA->nodeNext;
            t = tB;
            tB = tB->nodeNext;
            free(t);
        }else if(tA->nodeData<tB->nodeData){
            //??????????????????????????????????????????????????
            t = tA;
            tA = tA->nodeNext;
            free(t);
        }else{
            t = tB;
            tB = tB->nodeNext;
            free(t);
        }
    }
    while(tA){//????????
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
// ����㷨��һ����ͷ�ڵ�ĵ����� A �ֽ�Ϊ����������ͬ�ṹ������ B �� C��
// ���� B ��Ľڵ�Ϊ A ����ֵС��0�Ľڵ㣬
// �� C ��Ľڵ�Ϊ A ����ֵ����0�Ľڵ� (����A�е�Ԫ��Ϊ����������Ҫ��B��C������A��Ľڵ�)
void  ListAtoBandC(LinkList la,LinkList lb,LinkList lc){
    LinkList tA= la->nodeNext,tB = lb,tC = lc; //????????????????
    while(tA){//???????
        if(tA->nodeData == 0){
            return ;//?????0????
        }else if(tA->nodeData<0){//???? B ??
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
    LinkList tA = la->nodeNext,trear,tpre;//??????????????
    tpre = NULL ; //????? ???????????????
    la->nodeNext = NULL;
    while(tA){
        trear = tA->nodeNext;//?????????
        tA->nodeNext = tpre;
        tpre = tA;
        tA = trear;
    }
    la->nodeNext = tpre;
}
// ��֪ p ָ��˫��ѭ�������е�һ���ڵ㣬��ڵ�ṹΪ `data`��`prior`��`next` ������
// ����㷨 `change(p)` , ���� p ��ָ��Ľڵ㼰��ǰ���ڵ��˳��
void change(LinkListDDW Lnode){ //��Ϊ��ѭ���������ж��������β�ڵ㲻���ǣ�
    LinkListDDW Pnode,PPnode,Nnode;
    Pnode = Lnode->nodePrev;
    PPnode = Pnode->nodePrev;
    Nnode = Lnode->nodeNext;
    PPnode->nodeNext = Lnode;
    Lnode->nodePrev = PPnode;
    Lnode->nodeNext = Pnode;
    Pnode->nodePrev = Lnode;
    Pnode->nodeNext = Nnode;
    Nnode->nodePrev = Pnode; 
}


int main(){
    // LinkListDDW la,lb;
    // la=InitListEndDDW(la);
    // ShowListDDW(la);
    // lb = la->nodeNext->nodeNext->nodeNext->nodeNext;//ģ��ȡ��4���ڵ�
    // change(lb);//��������ǰ���ڵ��λ��
    // printf("������\n");
    // ShowListDDW(la);
    // LinkList la,lb,lc;
    // la = InitListEnd(la);
    // ListReverse(la);
    // ShowList(la);
    // ListAtoBandC(la,lb,lc);
    // ShowList(lc);
    //???????????????
    //???????????????????????????????
    //???????????????????
    // ListArg=InitListEnd(ListArg);
    LinkList la;
    la = InitListEnd(la);
    int a=-1;
    if(ListDelete_L(la,1,&a)){
        printf("ɾ���ɹ�:��ֵΪ%d\n",a);
    }
    printf("�����ӡ:\n");
    ShowList(la);
    return 0;
}