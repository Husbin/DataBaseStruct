//Tickets_achieve.cpp
#include"Tickets_H.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//��ʼ������
Status InitQueue(Queue &queue) {
	queue.base = new long int[MaxSize];
	if (queue.base == NULL) {
		printf("Memory allocation failed ! And the Queue intialize failed !\n");	//�����ڴ�ʧ�ܣ����г�ʼ��ʧ�ܣ�
		return ERROR;
	}
	queue.front = queue.rear = 0;
	return OK;
}

//��ʼ����ϣ��
Status InitHashTab(HashTable* &hashTable) {
	hashTable = new HashTable[MaxSize];
	if (hashTable == NULL) {
		printf("Memory allocation failed ! And the HashTable intialize failed !\n");//�����ڴ�ʧ�ܣ���ϣ���ʼ��ʧ�ܣ�
		return ERROR;
	}
	return OK;
}




//����ɢ��ֵ
long int HashVal(Queue &queue ,HashTable* &hashTab , char *name) {
	if (hashTab == NULL) {
		printf("Parameter hashTable NULL , calculate hash value failed !\n");
		return ERROR;
	}
	if (name == NULL) {
		printf("Parameter name NULL , calculate hash value failed failed !\n");
		return ERROR;
	}
	int key = name[0] - 'a';
	//�õ�ַ��Ԫδ��ռ��
	if (hashTab[key].status == false) {
		strcpy(hashTab[key].name, name);
		hashTab[key].status = true;
		//printf("%d\t", key);
		//printf("%d\t", currentNum);
		return key;
	}
	//�õ�ַ��Ԫ�ѱ�ռ��
	else {
		int d = 1;
		while (hashTab[(key + d) % (MaxSize - 1)].status) {
			//key = (key + d) % (MaxSize - 1);
			//printf("%d\t", d);
			d++;
		}
		int newKey = (key + d) % (MaxSize - 1);
		strcpy(hashTab[newKey].name, name);
		hashTab[newKey].status = true;
		//printf("%d\t%s\t", newKey , hashTab[newKey].name);
		return newKey;
	}
}

//�������
Status EnQueue(Queue &queue, HashTable* &hashTab,long int hashVal, bool hasFriend, long int maxIndex) {
	if (queue.hashVal == NULL) {
		printf("Parameter queue NULL , enter Line failed !\n");
		return ERROR;
	}
	if (hashTab == NULL) {
		printf("Parameter hashTable NULL , enter Line failed !\n");
		return ERROR;
	}
	if (maxIndex < 0 || maxIndex > MaxSize) {
		printf("Error:Friends maxIndex Overflow! EnQueue Error!\n");
		return ERROR;
	}
	//�ж϶��Ƿ���
	if ((queue.rear + 1) % MaxSize == queue.front) {
		printf("Queue Fulling!\n");
		return ERROR;
	}
	//��������û�����ѣ���������ʱ�����ѣ����ǲ��Ҷ������ձ�־λflagΪ0
	if (!hasFriend || flag == 0) {
		queue.base[queue.rear] = hashVal;
		hashTab[hashVal].index = queue.rear;		//��¼��ϣԪ���ڶ����е�λ��
		queue.rear = (queue.rear + 1) % MaxSize;	//��βָ���һ
	}
	else {
		queue.rear = (queue.rear + 1) % MaxSize;	//��βָ���һ
		queue.base[queue.rear] = hashVal;
		for (int i = queue.rear - 1 ; i > maxIndex; i--) {
			queue.base[i] = queue.base[i - 1];
			//hashTab[hashVal].index = queue.rear;
			//printf("%d\t%d\t\n", queue.base[i], queue.base[i - 1]);
			//printf("%s\t%s\t\n", hashTab[i].name, hashTab[i - 1].name);
		}
		queue.base[maxIndex + 1] = queue.base[queue.rear];
		hashTab[hashVal].index = queue.rear;
		//queue.rear = (queue.rear + 1) % MaxSize;	//��βָ���һ
		flag = 0;									//�����̬��־λ
	}
	currentNum++;
	return OK;
}


//���г���
Status DeQueue(Queue &queue, HashTable* &hashTab ,long int &hashVal , char *name) {
	if (queue.hashVal == NULL) {
		printf("Parameter queue NULL , out Line failed !\n");
		return ERROR;
	}
	if (queue.front == queue.rear) {
		printf("Queue Empty!\n");
		return ERROR;
	}
	hashVal = queue.base[queue.front];	//����Ԫ��ֵ
	strcpy(name, hashTab[hashVal].name);//��������

	//��չ�ϣֵ
	strcpy(hashTab[hashVal].name , "");
	hashTab[hashVal].status = false;
	hashTab[hashVal].flag = false;
	hashTab[hashVal].index = -1;
	queue.front = (queue.front + 1) % MaxSize;//��ͷָ���һ
	currentNum--;
	return OK;
}

//���еı���
Status TraverseQueue(Queue queue , HashTable* hashTab) {
	if (queue.base == NULL) {
		printf("Parameter queue NULL , Traverse Line failed !\n");
		return ERROR;
	}
	printf("The ranks are arranged as follows ��\n");
	printf("HashVal\tname\t\t\n");
	if (queue.front == queue.rear) {
		printf("Queue Empty��\n");
		return ERROR;
	}
	int count = queue.front;
	while (count != queue.rear) {
		printf("%d\t%s\t\t", queue.base[count], hashTab[queue.base[count]].name);
		//printf("%s\t", hashTab[count].name);
		count = (count + 1) % MaxSize;
	}
	printf("\n");
}


//��ʼ�����飬��ǰ������26��(Ĭ�ϻ���Ϊ����)���ֱ�Ϊaaa��zzz
//��ʼ������
Status InitLine(Queue &queue, HashTable* &hashTable) {
	if (queue.hashVal == NULL) {
		printf("Parameter queue NULL , intialize Line failed !\n");
		return ERROR;
	}
	if (hashTable == NULL) {
		printf("Parameter hashTable NULL , intialize Line failed !\n");
		return ERROR;
	}
	//��ʼ�����飬��ǰ������26��(Ĭ�ϻ���Ϊ����)���ֱ�Ϊaaa��zzz
	int hashVal;
	hashVal = HashVal(queue ,hashTable, "aaaa");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal ,hashTable[currentNum].flag ,0);
	hashVal = HashVal(queue, hashTable, "bbbb");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "cccc");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "dddd");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "eeee");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "ffff");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "gggg");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "hhhh");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "iiii");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "jjjj");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "kkkk");
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "llll");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "mmmm");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "nnnn");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "oooo");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "pppp");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "qqqq");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "rrrr");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "ssss");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "tttt");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "uuuu");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "vvvv");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "wwww");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "xxxx");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "yyyy");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal( queue, hashTable, "zzzz");
	hashTable[currentNum].flag = false;
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);

	hashVal = HashVal(queue, hashTable, "aabb");
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "bbcc");
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
	hashVal = HashVal(queue, hashTable, "gghh");
	EnQueue(queue, hashTable, hashVal, hashTable[currentNum].flag, 0);
}

//ɢ�б�Ĳ���
long int SearchHash(Queue queue , HashTable* hashTab, char* name) {
	if (hashTab == NULL) {
		printf("Parameter hashTab NULL , Search Friend failed !\n");
		return ERROR;
	}
	if (name == NULL) {
		printf("Parameter name NULL , Search Friend failed !\n");
		return ERROR;
	}
	int key = name[0] - 'a';
	if (strcmp(name , hashTab[key].name) == 0) {
		flag++;
		return key;
	}
	else {
		for (int i = 1; i < (MaxSize - 1); i++) {
			int newKey = (key + i) % (MaxSize - 1);
			if (hashTab[newKey].name == NULL) {
				printf("The Hash Element Null , search fail!\n");
				return ERROR;
			}
			else if(strcmp(hashTab[newKey].name, name) == 0){
				flag++;
				return newKey;
			}
		}
	}
	if (flag == 0) {
		printf("%s is no in the line.\n" , name);
		return OK;
	}
}

//���򣬻�ȡ���������һ�����ѵ�λ��
long int Sort(long int* friendIndex, int friendNum) {
	if (friendIndex == NULL || friendNum == 0) {
		printf("Size of friendArray Error , sort and get MaxIndex Error!\n");
		return ERROR;
	}
	int temp = 0;
	for (int i = 0; i < friendNum; i++) {
		for (int j = i + 1; j < friendNum; j++) {
			if (friendIndex[i] > friendIndex[j]) {
				temp = friendIndex[i];
				friendIndex[i] = friendIndex[j];
				friendIndex[j] = temp;
			}
		}
	}
	return friendIndex[friendNum - 1];
}