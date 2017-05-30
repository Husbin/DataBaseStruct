#include"Tickets_H.h"
#include<stdio.h>
#include<string.h>
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
	//��ʼ������
	InitQueue(queue);
	//��ʼ����ϣ��
	InitHashTab(hashTable);
	//��ʼ�����飬��ǰ������26��(Ĭ�ϻ���Ϊ����)���ֱ�Ϊaaaa��zzzz
	InitLine(queue, hashTable);

	TraverseQueue(queue, hashTable);

	//��Ʊ��ϣ����ӣ���ϣ���ÿ�
	DeQueue(queue, hashTable, hashVal);
	printf("%d %s has already bought the tickets!\n" , hashVal , hashTable[hashVal].name);
	TraverseQueue(queue, hashTable);
	//���
	printf("Enter your name:");
	scanf("%*[\t\n\r]");
	scanf("%s", name);
	printf("Has Friend in line? (Enter:Y/N):  ");
	scanf("%*[\t\n\r]");
	scanf("%c", &hasFriend);
	switch (hasFriend) {
	case 'y':
	case 'Y':
		//����ɢ��ֵ
		hashVal = HashVal(queue ,hashTable, name);
		//printf("%d", hashVal);
		hashTable[hashVal].flag = true;
		printf("How many friends in line:  ");
		scanf("%*[\t\n\r]");
		scanf("%d", &friendNum);
		if(friendNum)
		for (int i = 0; i < friendNum; i++) {
			printf("Friend %d Name:", i + 1);
			scanf("%s", name);
			//��ȡ�±�����
			friendIndex[i] = queue.base[SearchHash(queue ,hashTable, name)];
			//printf("%d\n", friendIndex[i]);
		}
		//����ȡ���һ��
		maxIndex = Sort(friendIndex, friendNum);
		//printf("%d", maxIndex);
		//����ӵ��˲���indexΪmaxIndex����
		EnQueue(queue, hashTable, hashVal , hashTable[hashVal].flag , maxIndex);
		TraverseQueue(queue, hashTable);
		break;
	case 'n':
	case 'N':
		//����ɢ��ֵ
		hashVal = HashVal(queue,hashTable, name);
		hashTable[hashVal].flag = false;
		EnQueue(queue,hashTable, hashVal, hashTable[hashVal].flag ,0);
		TraverseQueue(queue, hashTable);
		break;
	default:
		printf("Please Enter Y(y) or N(n).\n");
	}
}


//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//#include <iostream>
//#define TabSize 2000003           /*ɢ�б��СTabSize �Ǵ��ڱ����ռ������*/
//#define Max 1000001              /*���пռ����ֵ*/
//using namespace std;
//
//class hashtab                     /*ɢ�б����ݽṹ*/
//{
//public:
//	char name[5];                 /*����*/
//	int group;                    /*�����ĸ�������*/
//	char info;                    /*��־λ���õ�Ԫ�Ƿ�ռ��*/
//};
//class PtrToHash :public hashtab {};
//
//class Que                         /*�������ݽṹ*/
//{
//public:
//	long int HashVal;             /*ɢ��ֵ*/
//	long int Index;               /*���еĶ������*/
//};
//class PtrToQue :public Que {};
//
//int hashedx = 0;                    /*���Ԫ���Ƿ��Ѿ���ɢ�б���*/
//long int Findf(PtrToHash *hash, char *c) /*������ɢ�б��е�λ��*/
//{
//	char *key;
//	long int CurrentPos, CollisionNum;
//
//	key = c;
//	for (CurrentPos = 0; *key; ++key)               /*ɢ�к���������ɢ��ֵ*/
//		CurrentPos = (CurrentPos << 6) + *key;
//	CurrentPos %= TabSize;                   /*ɢ��ֵ*/
//	CollisionNum = 0;
//	/*�����ǰ��Ԫ��ռ�ã���Ԫ�ڵ�Ԫ���뵱ǰ���������ֲ�ͬ��ʹ��ƽ��̽�ⷨ�����ͻ��
//	�뵱ǰ������������ͬ����ֱ�ӷ�����ɢ���е�λ��*/
//	while ((hash[CurrentPos].info) && (strcmp(hash[CurrentPos].name, c)))
//	{   /*ƽ��̽�ⷨ*/
//		CurrentPos += 2 * (++CollisionNum) - 1;
//		if (CurrentPos >= TabSize)
//			CurrentPos -= TabSize;
//	}
//	if ((hash[CurrentPos].info) && (strcmp(hash[CurrentPos].name, c) == 0)) /*Ԫ���Ѿ���ɢ�б���*/
//		hashedx = 1;
//	else /*Ԫ�ز���ɢ�б���*/
//		hashedx = 0;
//	return CurrentPos;/*������ɢ�б��е�λ��*/
//}
//
//void main()
//{
//	long int Find(PtrToHash *hash, char *c);   /*������ɢ�б��е�λ��*/
//
//	PtrToHash *hash;                          /*ɢ�б�*/
//	PtrToQue *queue;                          /*����*/
//	int *grouppos;                    /*��¼ÿ������������һλ�����������*/
//	int n;                                   /*����������Ŀ*/
//	int num;                                 /*��ǰ�����������*/
//	long int i, ii, j, key, temp;
//	long int head, last;                     /*���е�ͷ��β*/
//	char c[8], tempc[8];                     /*����*/
//	hash = (PtrToHash*)malloc(sizeof(hashtab)*TabSize);
//	queue = (PtrToQue*)malloc(sizeof(Que)*Max);
//	grouppos = (int *)malloc(sizeof(int) * 1000);
//
//	for (i = 0, j = 1; i<Max; ++i, ++j) /*��ʼ�����У�queue[i]�ĺ�̵�Ԫ��queue[i��1]*/
//		queue[i].Index = j;
//	queue[i - 1].Index = 0; /*���һ����Ԫ�ĺ�̵�Ԫ�ǵ�0�����γɻ�*/
//
//	num = 0;
//	cout << "���뵱ǰ������������������:" << endl;
//	for (cin >> n; n; cin >> n)/*���뵱ǰ������������������*/
//	{
//		if (n<1 || n>1000)      /*�����쳣����n*/
//		{
//			cout << "n is out of range!" << endl;
//		}
//		num++;
//		if (num != 1)                    /*������������������һ����*/
//			cout << "\n";
//		for (i = 0; i<TabSize;)
//			hash[i++].info = 0;         /*��ʼ��ɢ�б����λ��0*/
//		for (i = 0; i<n; ++i)              /*��ÿһ������*/
//		{
//			cout << "��ǰ���������:" << endl;
//			cin >> j;      /*��ǰ���������*/
//			if (j<1 || j>1000)  /*�����쳣����j*/
//			{
//				cout << "j is out of range!" << endl;
//			}
//			for (; j; --j)
//			{
//				cout << "��������:" << endl;
//				cin >> c;    /*��������*/
//				for (ii = 0; ii<sizeof(tempc); ii++) /*tempc��գ������쳣��������*/
//					tempc[ii] = '\0';
//				strcpy(tempc, c);
//				ii = 0;
//				while (tempc[ii] != '\0')      /* �Ƿ����ĸ�������ĸ���*/
//				{
//					if (tempc[ii]<'A' || ('Z'<tempc[ii] && tempc[ii]<'a') || tempc[ii]>'z' || ii>4)
//					{
//						cout << "Group" << i << ":Not standard name" << endl;
//					}
//					ii++;
//				}
//				key = Find(hash, c); /*�ҵ���ɢ�б��е�λ��*/
//				if (hashedx == 1) /*����*/
//				{
//					cout << "Repeated name" << " " << c << endl;
//				}
//				else
//				{
//					strcpy(hash[key].name, c);/*����ɢ�б�*/
//					hash[key].info = 1;      /*�����1���õ�Ԫ��ռ��*/
//					hash[key].group = i;     /*��¼�������ĸ���*/
//				}
//			}
//		}
//		for (i = 0; i<1000;)
//			grouppos[i++] = 0; /*��ʼ���������*/
//		head = 0;/*��ʼ������ͷ��β���*/
//		last = 0;
//		for (cout << "��������:I���/O����" << endl, cin >> c;; cout << "��������:I���/O����" << endl, cin >> c) /*��������*/
//		{
//
//			if (*c == 'I' || *c == 'i')/*�������*/
//			{
//				cout << "��������" << endl;
//				cin >> c;    /*��������*/
//				key = Find(hash, c);/*������ɢ�б��е�λ��*/
//
//				if (hashedx == 0) /*ɢ�б���û�����*/
//				{
//					cout << "no" << c << endl;
//				}
//
//				temp = queue[0].Index;   /*���е�0��λ�ü�¼��β�ĺ�̵�Ԫ*/
//				queue[0].Index = queue[temp].Index; /*�ڶ���������һ���µ�Ԫ����β��Ǻ���һ��λ�� */
//				queue[temp].HashVal = key; /*���*/
//				if (!head) /*����Ƕ�����ĵ�һ��Ԫ�� */
//					last = head = temp; /*��ͷ����β���ָ���һ��Ԫ��*/
//				if (!grouppos[hash[key].group]) /*���������û����*/
//				{
//					queue[temp].Index = 0; /*��βָ���ͷ���γɻ�*/
//					queue[last].Index = temp;/*ǰһ�ζ�β�ĺ��Ԫ���ǵ�ǰԪ��*/
//					last = temp;           /*��β���ָ��ǰԪ��*/
//					grouppos[hash[key].group] = temp;/*��������¼��������������ӵ����һλ*/
//				}
//				else/*����������Ѿ�����������*/
//				{
//					queue[temp].Index = queue[grouppos[hash[key].group]].Index;
//					/*��ӵ����ѵĺ���*/
//					queue[grouppos[hash[key].group]].Index = temp;
//					/*��ӵ����Ѻ���һλ��ǰ��*/
//					grouppos[hash[key].group] = temp;
//					/*�滻�������������Ԫ��Ϊ��ǰԪ��*/
//					if (hash[queue[last].HashVal].group == hash[key].group)
//						/*�����ǰԪ�غ�ǰһԪ�������ѣ���β��־ָ��ǰԪ��*/
//						last = temp;
//				}
//			}
//			else if (*c == 'O' || *c == 'o') /*��������*/
//			{
//				if (last == 0)     /*���ܶԿն���ִ�г�������*/
//				{
//					cout << "Empty queue!\nCan't execute DEQUEUE!" << endl;
//				}
//				else
//				{
//					cout << hash[queue[head].HashVal].name << endl;/*�����ͷԪ�ص��ļ�*/
//					temp = head;
//					head = queue[temp].Index;   /*���е�һλ���ӣ���ͷ��Ǻ���һλ*/
//					queue[temp].Index = queue[0].Index;  /*���е�0��Ԫ�غ���һλ*/
//					queue[0].Index = temp;               /*�ͷſռ�*/
//					if (grouppos[hash[queue[temp].HashVal].group] == temp)
//						/*��ǰɾ����Ԫ���Ǹ��������ڶ���������һλ*/
//						grouppos[hash[queue[temp].HashVal].group] = 0;
//					if (last == temp)            /*���Ӻ󣬶���Ϊ��*/
//						last = 0;
//				}
//			}
//			else                        /*���� "STOP"*/
//				break;                  /*���Խ���*/
//		}
//	}
//}