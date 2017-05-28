#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MaxSzie 20


//˳�����
void SequentialSearch(int *numArray , int searchNum , int len);
//ִ���۰����֮ǰ������
void Sort(int* &numArray , int len);
//�۰����
void Search_Bin(int *numArray, int searchNum, int len);
//��������
void TraverseArray(int *numArray, int len);

int main() {
	
	printf("��������������ĸ���n��");
	int num;				//������ĸ���
	int numArray[MaxSzie];	//����洢�����
	int searchNum;			//Ҫ���ҵ���ֵ
	int len;				//����ĳ���
	scanf("%d", &num);
	srand((unsigned)time(NULL)); //Ϊ����߲��ظ��ĸ���
	for (int i = 0; i < num; i++) {	
		numArray[i] = rand()%(num+100);
	}
	printf("�������������£�\n");
	TraverseArray(numArray, num);
	len = num;				//��ȡ���鳤��
	printf("��ʼֱ�Ӳ��ң�������Ҫ���ҵ�ֵ��");
	scanf("%d", &searchNum);
	SequentialSearch(numArray, searchNum , len);
	printf("��ʼ�۰���ң�������Ҫ���ҵ�ֵ��");
	scanf("%d", &searchNum);
	Search_Bin(numArray, searchNum, len);
}

void TraverseArray(int *numArray, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d\t", numArray[i]);
	}
	printf("\n");
}

void SequentialSearch(int *numArray , int searchNum , int len) {
	int status = 0;
	for (int i = 0; i < len; i++) {
		if (numArray[i] == searchNum) {
			printf("��ѯ�ɹ���%d���������numArry�ĵ�%d��λ�ã�\n", searchNum, i + 1);
			status++;
			return;
		}
		else {
			printf("����δ��ɣ���ʱƥ�䵽������Ϊ�����е�%d��\n", numArray[i]);
		}
	}
	if (status == 0) {
		printf("��ѯʧ�ܣ�������û��%d���ֵ��\n", searchNum);
	}
}

void Sort(int* &numArray ,int len) {
	int temp = 0; 
	for (int i = 0; i < len; i++) {
		for (int j = i + 1; j < len; j++){
			if (numArray[i] > numArray[j]) {
				temp = numArray[i];
				numArray[i] = numArray[j];
				numArray[j] = temp;
			}
		}
	}
}

void Search_Bin(int *numArray, int searchNum, int len) {
	int status = 0;
	//����֮ǰ������
	Sort(numArray, len);
	printf("�������������������£�\n");
	TraverseArray(numArray, len);
	//�ò��������ֵ
	int low = 1;
	int high = len;
	int mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (searchNum == numArray[mid]) {
			printf("��ѯ�ɹ���%d���������numArry�ĵ�%d��λ�ã�\n", searchNum, mid + 1);
			status++;
			return;
		}
		//������ǰһ�ӱ���в���
		else if (searchNum < numArray[mid]) {
			high = mid - 1;
			printf("��ѯδ��ɣ�������ǰһ�ӱ���ң�");
			TraverseArray(numArray, high);
		}
		//�����ں�һ�ӱ���в���
		else { 
			low = mid + 1;
			printf("��ѯδ��ɣ���������һ�ӱ���ң�");
			TraverseArray(numArray, low);
		}
	}
	if (status == 0) {
		printf("��ѯʧ�ܣ�������û��%d���ֵ��\n", searchNum);
	}
}