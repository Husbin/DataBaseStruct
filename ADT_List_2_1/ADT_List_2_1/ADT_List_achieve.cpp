#include"ADT_List_H.h"
#include<stdlib.h>


//����һ���յ�˳������
Status InitList(SqList &L) {
	L.elem = new ElemType[MAXSIZE];//Ϊ˳���������һ����СΪMAXSIZE������ռ�
	if (!L.elem) exit(OVERFLOW);	//����ʧ��
	L.length = 0;					//��������Ϊ0
	return OK;
}

// ��˳�����ȡֵ
Status GetElem(SqList L, int i, ElemType &e) {
	if (i < 1 || i >L.length)return ERROR;	//�ж�iֵ�Ƿ����������������ERROR
	e = L.elem[i - 1];						//elem[i-1]��Ԫ�����i������Ԫ��
	return OK;
}

//˳���Ĳ���
Status LocateElem(SqList L, ElemType e) {
	//��˳����в���ֵΪe������Ԫ�أ����������
	for (int i = 0; i < L.length; i++) {
		if (L.elem[i] == e)return i + 1;		
	}
	return 0;
}

//��˳���L�еĵ�i��λ��֮ǰ�����µ�Ԫ��e��i�ĺϷ���Χ��1 <= i <= L.length + 1
Status ListInsert(SqList &L, int i, ElemType e) {
	if ((i < 1) || (i > L.length + 1))return ERROR;		//iֵ���Ϸ�
	if (L.length == MAXSIZE) return ERROR;				//��ǰ�洢�ռ�����
	for (int j = L.length - 1; j >= i - 1; j--) {
		L.elem[j + 1] = L.elem[j];						//����λ��֮���Ԫ�غ���
	}
	L.elem[i - 1] = e;									//����Ԫ��e���ڵ�i��λ��
	L.length++;											//��+1
	return OK;
}

//˳����ɾ��
Status ListDelete(SqList &L, int i) {
	//��˳���L��ɾ����i��Ԫ�أ�i�ĺϷ���ΧΪ1 <= i <= L.length
	if (i < 1 || i > L.length)return ERROR;
	if (i == MAXSIZE) return ERROR;
	for (int j = i; j <= L.length - 1; j++) {
		L.elem[j - 1] = L.elem[j];
	}
	L.length--;
	return OK;
}
