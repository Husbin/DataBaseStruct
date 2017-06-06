//Tickets_main.cpp
#include"Tickets_H.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main() {	
	Queue queue;
	HashTable *hashTable;
	int currNum;		//��ǰ��������
	long int hashVal;	//�洢�����˵Ĺ�ϣֵ
	char name[20];		//���������
	char hasFriend;
	int friendNum;		//��������
	long int friendIndex[FriendNum];//ͨ����ȡ���ѵĹ�ϣֵ���õ������ڶ����е�λ��
	long int maxIndex;	//��ȡ��������ѵ��±�
	char operation;
	//��ʼ������
	InitQueue(queue);
	//��ʼ����ϣ��
	InitHashTab(hashTable);
	//��ʼ�����飬��ǰ������26��(Ĭ�ϻ���Ϊ����)���ֱ�Ϊaaaa��zzzz
	InitLine(queue, hashTable);

	printf("1��Show The Line.\n");
	printf("2��Someone Dequeue.\n");
	printf("3��Someone Enqueue.\n");
	printf("4��Clean The Dos.\n");
	printf("5��Exit The Program.\n");
	printf("Please input the operation:");
	scanf("%*[\t\n\r]");
	while (scanf("%c", &operation)) {
		//��operation�����ж�
		if (!(operation >= '1' && operation <= '5')) {
			printf("Parameter operation Error.\n");
			printf("Please input the next operation:");
			scanf("%*[\t\n\r]");
			continue;
		}
		switch (operation) {
		case '1':
			TraverseQueue(queue, hashTable);
			break;
		case '2':
			//��Ʊ��ϣ����ӣ���ϣ���ÿ�
			DeQueue(queue, hashTable, hashVal , name);
			printf("%d %s has already bought the tickets!\n", hashVal, name);
			break;
		case '3':
			//���
			printf("Enter your name(format:char name[20]):");
			scanf("%*[\t\n\r]");
			scanf("%s", name);
			//�ж�����������Ƿ����
			//SearchHash(queue, hashTable, name);
			//if (queue.base[SearchHash(queue, hashTable, name)]) {
			//if(flag != 0){
			//	printf("%s is in the line.\n", name);
			//	printf("Please input the next operation:");
			//	flag = 0;
			//	scanf("%*[\t\n\r]");
			//	continue;
			//}
			printf("Has Friend in line? (Enter:Y/N):  ");
			scanf("%*[\t\n\r]");
			scanf("%c", &hasFriend);
			switch (hasFriend) {
			case 'y':
			case 'Y':
				//����ɢ��ֵ
				hashVal = HashVal(queue, hashTable, name);
				//printf("%d", hashVal);
				hashTable[hashVal].flag = true;
				printf("How many friends in line(no more than 9):  ");
				scanf("%*[\t\n\r]");
				scanf("%d", &friendNum);
				char ch_FriendNum ;
				ch_FriendNum = '0' + friendNum;
				if (!(ch_FriendNum >= '0' && ch_FriendNum <= '9')) {
					printf("Input Friends Number Error!\n");
					printf("Please input the next operation:");
					scanf("%*[\t\n\r]");
					continue;
				}
				if (friendNum)
					for (int i = 0; i < friendNum; i++) {
						printf("Friend %d Name:", i + 1);
						scanf("%s", name);
						//��ȡ�±�����
						friendIndex[i] = queue.base[SearchHash(queue, hashTable, name)];
						//printf("%d\n", friendIndex[i]);
					}
				//����ȡ���һ��
				maxIndex = Sort(friendIndex, friendNum);
				//printf("%d", maxIndex);
				//����ӵ��˲���indexΪmaxIndex����
				EnQueue(queue, hashTable, hashVal, hashTable[hashVal].flag, maxIndex);
				TraverseQueue(queue, hashTable);
				break;
			case 'n':
			case 'N':
				//����ɢ��ֵ
				hashVal = HashVal(queue, hashTable, name);
				hashTable[hashVal].flag = false;
				EnQueue(queue, hashTable, hashVal, hashTable[hashVal].flag, 0);
				TraverseQueue(queue, hashTable);
				break;
			default:
				printf("Please Enter Y(y) or N(n).\n");
				break;
			}
			break;
		case '4':
			system("cls");
			printf("1��Show The Line.\n");
			printf("2��Someone Dequeue.\n");
			printf("3��Someone Enqueue.\n");
			printf("4��Clean The Dos.\n");
			printf("5��Exit The Program.\n");
			break;
		case '5':
			exit(OVERFLOW);
		default:
			printf("Parameter operation Error.\n");
			break;
		}
		printf("Please input the next operation:");
		scanf("%*[\t\n\r]");
	}
}
