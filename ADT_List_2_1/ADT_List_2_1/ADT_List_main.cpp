#include"ADT_List_H.h"
#include"stdio.h"

int main() {
	SqList L;
	int len = MAXSIZE;
	int temp;
	InitList(L);
	for (int i = 0; i < 5; i++) {
		L.elem[i] = i + 1;
		L.length++;
	}
	printf("���������");
	for (int i = 0; i < L.length; i++) {
		printf("%d\t", L.elem[i]);
	}
	printf("\n");
	GetElem(L, 2, temp);
	printf("��2��Ԫ��Ϊ��%d\n", temp);
	temp = LocateElem(L, 2);
	printf("�������Ϊ2�ĵ�ַΪ��%d", temp);
	printf("\n");
	ListInsert(L, 2, 6);
	printf("�ڵڶ���λ�ò���Ԫ��6����������");
	for (int i = 0; i < L.length; i++) {
		printf("%d\t", L.elem[i]);
	}
	printf("\n");
	ListDelete(L, 2);
	printf("ɾ���ڶ���Ԫ�أ����±��������");
	for (int i = 0; i < L.length; i++) {
		printf("%d\t", L.elem[i]);
	}
	printf("\n");
}