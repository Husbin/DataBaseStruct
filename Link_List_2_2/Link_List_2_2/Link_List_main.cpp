#include"Link_List_H.h"
#include"stdio.h"

int main() {
	LinkList L;
	int val;
	int cout;
	InitList(L);
	printf("��巨����������\n");
	L = CreateList_Rear();//��巨
	//printf("ǰ�巨����������\n");
	//L = CreateList_Front();//ǰ�巨
	printf("�������������£�\n");
	traverse_LinkList(L);
	GetElem(L, 2, val);
	printf("ȡ��������Ϊ��%d\n", val);
	cout = LocateElem(L, 2);
	printf("������Ϊ2�Ľڵ�λ�ڵ�%d���ڵ㡣\n", cout);
	cout = LinkList_Length(L);
	printf("������ĳ���Ϊ��%d\n", cout);
	printf("ִ�в��������");
	ListInsert(L, 4, 7);
	printf("�������������£�\n");
	traverse_LinkList(L);
	printf("ִ��ɾ��������");
	ListDelete(L, 4, val);
	printf("ɾ��������Ϊ%d\n", val);
	printf("�������������£�\n");
	traverse_LinkList(L);

}