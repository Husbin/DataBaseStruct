#pragma once
typedef char ElemType;

#define MAXSIZE 100

//------------------�������Ķ�������洢��ʾ------------------
typedef struct BiTNode {
	ElemType data;						//���������
	struct BiTNode *lchild, *rchild;	//���Һ���ָ��
}BiTNode , *BiTree;

//���������˳������������
char CreateBiTree(BiTree &T);
//�������������
void InOrderTraverse(BiTree T);