#define MAXSIZE 100	//˳�����ܴﵽ����󳤶�
#define  OVERFLOW -1
#define OK true;
#define ERROR false;
typedef bool Status;
typedef int ElemType;


typedef struct {
	ElemType *elem;	//�洢�ռ�Ļ���ַ
	int length;		//��ǰ����
}SqList , *PSqList;			//˳���Ľṹ����ΪSqList

Status InitList(SqList &L);//��ʼ��˳���
Status GetElem(SqList L, int i, ElemType &e);//��˳�����ȡֵ
Status LocateElem(SqList L, ElemType e);	//˳���Ĳ���
Status ListInsert(SqList &L, int i, ElemType e);//��˳���L�еĵ�i��λ��֮ǰ�����µ�Ԫ��e��i�ĺϷ���Χ��1 <= i <= L.length + 1
Status ListDelete(SqList &L, int i);//˳����ɾ��



