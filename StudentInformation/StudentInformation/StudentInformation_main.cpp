#include"StudentInformation_H.h"
#include<stdio.h>
int main() {
	SqList SL;
	char name[10];			//��������ѧ����Ϣ
	int pos;				//��index���ҡ����롢ɾ��ѧ����Ϣ
	InitSqList(SL);
	InputInformation(SL);
	TraverseInformation(SL);
	printf("˳����������ң���������ҵ�ѧ��������");
	scanf("%s", name);
	SearchByName(SL, name);
	printf("���ָ��λ�õ�ѧ����Ϣ��������ѧ����λ�ã�");
	scanf("%d", &pos);
	SerchByPos(SL, pos);
	printf("����ѧ����Ϣ�����������λ�ã�");
	scanf("%d", &pos);
	InsertInformation(SL,pos);
	TraverseInformation(SL);
	printf("ɾ��ѧ����Ϣ��������ɾ��λ�ã�");
	scanf("%d", &pos);
	DeleteInformation(SL, pos);
	TraverseInformation(SL);
	pos = SqListLength(SL);
	printf("˳����е����ݸ�����%d\n" , pos);
	return OK;
}