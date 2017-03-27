#pragma once
typedef int ElemType;
typedef bool Status;
#define OK true;
#define ERROR false;
typedef struct duLNode {
	ElemType data;			//������
	struct duLNode *prior;	//ֱ��ǰ��
	struct duLNode *pnext;	//ֱ�Ӻ���
}DULNODE , *PDULNODE;

PDULNODE create_dubleLink_List();
void traverse_duleLink_List(PDULNODE pHead);
Status insertElem(PDULNODE pHead, int index, ElemType elem);
Status deleteElem(PDULNODE &pHead, int index);