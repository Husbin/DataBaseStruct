#pragma once
//���Ĵ洢�ṹ


//------------���Ķ���˳��洢�ṹ--------------------
//��̬���壬�ڱ���ʱȷ���˴��ռ�Ĵ�С
//˳��洢���ַ������Ǵ��±�Ϊ1�����������ʼ�洢�ģ��±�Ϊ0�ķ������ò���
#define MAXLEN 255				//������󳤶�
typedef struct {
	char ch[MAXLEN + 1];		//�洢����һά����
	int length;					//���ĵ�ǰ����
}SSTRING;

//------------���Ķ�ʽ˳��洢�ṹ--------------------
//�ѣ�Heap�����ɴ洢����Ϊÿ���²����Ĵ���̬����һ��ʵ�ʴ�������Ĵ洢�ռ�
typedef struct {
	char *ch;					//�����ǿմ����򰴴�������洢��������chΪNULL
	int length;					//���ĵ�ǰ����
}HSTRING;

//------------���Ķ���ʽ�洢�ṹ----------------------
#define CHUNKSIZE 80			//�����û�����Ŀ��С
typedef struct Chunk {
	char ch[CHUNKSIZE];
	struct Chunk* next;
}CHUNK;
typedef struct {
	Chunk *head, *tail;			//����ͷ��βָ��
	int length;					//���ĵ�ǰ����
}LSTRING;

int Index_BF(SSTRING S, SSTRING T, int &pos);