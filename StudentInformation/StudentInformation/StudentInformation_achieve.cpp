#include"StudentInformation_H.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


Status InitSqList(SqList &SL) {
	int len;						//����ѧ������
	printf("������ѧ��������");
	scanf("%d", &len);
	SL.elem = new Student[MAXSIZE];
	if (SL.elem == NULL) {
		printf("�ڴ����ʧ�ܣ�\n");
		exit(OVERFLOW);
	}
	SL.length = len;
	return OK;
}

Status InputInformation(SqList &SL) {
	int i;
	for ( i = 0; i < SL.length; i++) {
		char ch_no[8];
		char ch_name[20];
		int price = 0;
		printf("�������%d��ѧ������Ϣ��\n", i + 1);
		printf("ѧ�ţ�");
		scanf("%s", ch_no);
		strcpy(SL.elem[i].no,ch_no);
		printf("������");
		scanf("%s", ch_name);
		strcpy_s(SL.elem[i].name,ch_name);
		printf("�ɼ���");
		scanf("%d", &price);
		SL.elem[i].price = price;
	}
	printf("¼����Ϣ��ɣ�\n");
	return OK;
}

Status TraverseInformation(SqList SL) {
	if (SL.elem == NULL) {
		printf("˳�������Ϊ�գ����ʧ�ܣ�\n");
		return ERROR;

	}
	for (int i = 0; i < SL.length; i++) {
		printf("�����%d��ѧ����Ϣ��\n", i + 1);
		printf("ѧ�ţ�%s  ������%s  �ɼ���%d\n", SL.elem[i].no, SL.elem[i].name, SL.elem[i].price);
	}
	printf("��Ϣ�����ϣ�\n");
	return OK;
}

Status SearchByName(SqList SL, char* name) {
	int count = SL.length;	//ͳ��ѧ����
	if (SL.elem == NULL) {
		printf("˳�������Ϊ�գ�����ʧ�ܣ�\n");
		return ERROR;
	}
	for (int i = 0; i < SL.length; i++) {
		if (strcmp(SL.elem[i].name , name) == 0) {
			printf("%s����Ϣ���ң�ѧ�ţ�%s  �ɼ���%d\n", SL.elem[i].name, SL.elem[i].no, SL.elem[i].price);
			count--;
		}
	}
	if (count == SL.length) {
		printf("˳������޴�����Ϣ��\n");
		return OK;
	}
}

Status SerchByPos(SqList SL, int pos) {
	if (pos > SL.length || pos < 1) {
		printf("�����ָ��λ�÷Ƿ���\n");
		return ERROR;
	}
	else {
		printf("�����%d��ѧ����Ϣ��\n", pos);
		printf("ѧ�ţ�%s  ������%s  �ɼ���%d\n", SL.elem[pos - 1].no, SL.elem[pos - 1].name, SL.elem[pos - 1].price);
		return OK;
	}
}
//SΪҪ��������ݣ���pos֮ǰ����SԪ�ء�
Status InsertInformation(SqList &SL, int pos) {		
	if (pos < 1 || pos > SL.length + 1) {
		printf("�����ָ��λ�÷Ƿ���\n");
		return ERROR;
	}
	Student S;
	printf("�������%d��ѧ������Ϣ��\n", pos);
	printf("ѧ�ţ�");
	scanf("%s", S.no);
	printf("������");
	scanf("%s", S.name);
	printf("�ɼ���");
	scanf("%d", &S.price);
	for (int j = SL.length - 1; j >= pos - 1; j--) {
		strcpy(SL.elem[j + 1].name, SL.elem[j].name);
		strcpy(SL.elem[j + 1].no, SL.elem[j].no);
		SL.elem[j + 1].price = SL.elem[j].price;
	}
	strcpy(SL.elem[pos - 1].name, S.name);
	strcpy(SL.elem[pos - 1].no, S.no);
	SL.elem[pos - 1].price = S.price;
	SL.length++;
	printf("����ɹ���\n");
	return OK;
}

Status DeleteInformation(SqList &SL, int pos) {
	if (pos > SL.length - 1 || pos < 1) {
		printf("�����ָ��λ�÷Ƿ���\n");
		return ERROR;
	}
	for (int i = pos - 1; i < SL.length; i++) {
		strcpy(SL.elem[i].name, SL.elem[i + 1].name);
		strcpy(SL.elem[i].no, SL.elem[i + 1].no);
		SL.elem[i].price = SL.elem[i + 1].price;
	}
	SL.length--;
	printf("ɾ���ɹ���\n");
	return OK;
}

int SqListLength(SqList SL) {
	return SL.length;
}



Status InitLinkList(LinkList &L) {
	L = new LNode;
	if (!L) {
		printf("�ڴ����ʧ�ܣ�\n");
		exit(OVERFLOW);
	}
	L->next = NULL;
	return OK;
}

LinkList CreateList(LinkList &L) {
	int len;					//��¼ѧ����Ŀ
	char ch_no[8];
	char ch_name[20];
	printf("������ѧ��������");
	scanf("%d", &len);
	LinkList pHead = (LinkList)malloc(sizeof(LNode));
	LinkList pTial = pHead;		//����һ�������ƶ��ڵ�ָ��ͷ�ڵ�
	for (int i = 0; i < len; i++) {
		LinkList pNew = (LinkList)malloc(sizeof(LNode));
		printf("�������%d��ѧ������Ϣ��\n", i + 1);
		printf("ѧ�ţ�");
		scanf("%s", ch_no);
		strcpy(pNew->data.no, ch_no);
		printf("������");
		scanf("%s", ch_name);
		strcpy(pNew->data.name, ch_name);
		printf("�ɼ���");
		scanf("%d", &pNew->data.price);
		pNew->next = NULL;
		pTial->next = pNew;		//���½ڵ����β�ڵ�pTial֮��
		pTial = pNew;			//pTialָ���µ�β�ڵ�pNew
	}
	return pHead;
}

Status TraverseLinkList(LinkList pHead) {
	int count = 1;			//ͳ��ѧ������
	LinkList p = (LinkList)malloc(sizeof(LNode));
	p = pHead->next;
	if (p == NULL) {
		printf("ѧ����ϢΪ�գ�\n");
		return ERROR;
	}
	while (p != NULL) {
		printf("�����%d��ѧ����Ϣ��\n" , count);
		printf("ѧ�ţ�%s  ������%s  �ɼ���%d\n", p->data.no, p->data.name, p->data.price);
		p = p->next;
		count++;
	}
	printf("��Ϣ�����ϣ�\n");
	return OK;
}

Status LserchByName(LinkList pHead, char* name) {
	LinkList p = pHead->next;
	int count = LinkListLength(pHead);	//��ȡ��ǰ�����ȣ��Ƚϲ�ѯǰ������ֵ���䣬������޴����ݣ�������д��ڴ�ѧ����Ϣ(�˴���������ϢҲ�����)
	if (p == NULL) {
		printf("ѧ����ϢΪ�գ�\n");
		return ERROR;
	}
	while (p != NULL) {
		if (strcmp(p->data.name, name) == 0) {
			printf("%s����Ϣ���ң�ѧ�ţ�%s  �ɼ���%d\n", name, p->data.no, p->data.price);
			count--;
		}
		p = p->next;
	}
	if (count == LinkListLength(pHead)) {
		printf("�޴�ѧ����Ϣ��¼��\n");
		return ERROR;
	}
	else {
		printf("��Ϣ��ѯ��ϣ�\n");
		return OK;
	}
}

Status LserchByPos(LinkList pHead, int pos) {
	LinkList p = pHead->next;
	int count = LinkListLength(pHead);	//��ȡ��ǰ�����ȣ��Ƚϲ�ѯǰ������ֵ���䣬������޴����ݣ�������д��ڴ�ѧ����Ϣ(�˴���������ϢҲ�����)
	int index = 0;
	if (p == NULL) {
		printf("ѧ����ϢΪ�գ�\n");
		return ERROR;
	}
	while (p != NULL) {
		if (index == pos - 1) {
			printf("%s����Ϣ���ң�ѧ�ţ�%s  �ɼ���%d\n", p->data.name, p->data.no, p->data.price);
			count--;
		}
		index++;
		p = p->next;
	}
	if (count == LinkListLength(pHead)) {
		printf("�޴�ѧ����Ϣ��¼��\n");
		return ERROR;
	}
	else {
		printf("��Ϣ��ѯ��ϣ�\n");
		return OK;
	}

}

Status Insert(LinkList pHead, int pos) {
	if (pos > LinkListLength(pHead) || pos < 1) {
		printf("����λ�ò�����\n");
		return ERROR;
	}
	int index = 0;
	char ch_no[8];
	char ch_name[20];
	int price;
	LinkList p = pHead->next;
	while (p && index < pos - 1) {
		p = p->next;
		index++;
	}
	LinkList pNew = (LinkList)malloc(sizeof(LNode));
	printf("�������%d��ѧ������Ϣ��\n", pos);
	printf("ѧ�ţ�");
	scanf("%s", ch_no);
	strcpy(pNew->data.no, ch_no);
	printf("������");
	scanf("%s", ch_name);
	strcpy(pNew->data.name, ch_name);
	printf("�ɼ���");
	scanf("%d", &price);
	pNew->data.price = price;
	printf("��Ϣ����ɹ���\n");
	pNew->next = p->next;
	p->next = pNew;
	return OK;
}

Status Delete(LinkList pHead, int pos) {
	if (pos > LinkListLength(pHead) || pos < 1) {
		printf("����λ�ò�����\n");
		return ERROR;
	}
	char name[20];
	LinkList p = pHead->next;
	int index = 0;
	while (p && index < pos - 1) {
		p = p->next;
		index++;
	}
	LinkList temp = (LinkList)malloc(sizeof(LNode));
	strcpy(name, p->data.name);
	temp = p->next;
	p->next = temp->next;
	free(temp);
	printf("%s������ɾ���ɹ���\n" , name);
	return OK;
}

int LinkListLength(LinkList pHead) {
	int count = 0;
	LinkList p = pHead->next;
	while (p != NULL) {
		count++;
		p = p->next;
	}
	return count;
}