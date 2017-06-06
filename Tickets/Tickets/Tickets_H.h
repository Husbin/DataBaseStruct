//Tickets_H.h
#pragma once
//��ÿ�����������ӵ�����£��������Ŷӣ���һ�����ϵ�����Ҫ���ӣ�����԰������ǵ�˳��
//ÿ��һ������ӣ�������������ӵ��˷��ֶ��������Լ������ѣ�����Բ��뵽������ѵĺ��棬
//�������е����Ѳ�ֹһ��ʱ������˻��������һ�����ѵĺ��档��������û�����ѣ������ڶ��������档
//ÿһ����ӵ��˶��Ƚ��������жϡ�������ǰ�������Ʊ�����γ��ӡ�

/**����˼·������������������ϣ�����ŵ�ַ��_����̽���������ͻ��
***1����ʼ�����飨�������뵱ǰ������������ȷ���ɢ�б�����ӣ�
***2����ӣ��������Ƿ������ѣ��ޣ�����ɢ�б���ӣ����У�������������ȡ��ϣֵ����ȡ�ڶ����е��������������ӣ���
***3������
*/
typedef bool Status;
#define OK true
#define ERROR false
#define OVERFLOW -1
#define MaxSize 2000	//���ö�����󳤶�Ϊ2000��
#define FriendNum 100	//������������������100��
static int currentNum = 0;//������ɢ��ֵ�����֮��currentNum+1
static int flag = 0;	//�ж϶������Ƿ��д��˵ı�־λ,���꼴��0


typedef struct HASHTABLE {
	char name[20];		//��ϣ���KeyΪname[0]
	bool flag = false;	//�������Ƿ������ѣ���Ϊtrue��û��Ϊfalse,Ĭ��ֵΪfalse
	bool status = false;//��־λ���õ�Ԫ�Ƿ�ռ��,��ʼ��Ϊfalse��ռ����Ϊtrue
	long int index;		//��¼��key�ڶ����е���������Ӻ�ֵ��
}HashTable;

//------------���е�˳��洢�ṹ--------------
typedef struct {
	long int *base;		//�洢�ռ�Ļ���ַ
	int front;			//ͷָ��
	int rear;			//βָ��
	long int hashVal;
}Queue;

//��ʼ������
Status InitQueue(Queue &queue);

//��ʼ����ϣ��
Status InitHashTab(HashTable *&hashTable);

//����ɢ��ֵ
long int HashVal(Queue &queue , HashTable* &hashTab, char *name);

//�������
Status EnQueue(Queue &queue, HashTable* &hashTab, long int hashVal , bool hasFriend , long int maxIndex);

//���г���
Status DeQueue(Queue &queue , HashTable* &hashTab ,long int &hashVal , char *name);

//���еı���
Status TraverseQueue(Queue queue , HashTable *hashTab);

//��ʼ������
Status InitLine(Queue &queue, HashTable* &hashTable);

//ɢ�б�Ĳ���,�����ڶ����е��±�
long int SearchHash(Queue queue , HashTable* hashTab, char* name);

//���򣬻�ȡ���������һ�����ѵ�λ��
long int Sort(long int* friendIndex, int friendNum);
