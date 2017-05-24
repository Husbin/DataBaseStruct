//Graph_H.h
#pragma once
//ͼ���ڽӾ���洢��ʾ
#define MaxInt 32767			//��ʾ����ֵ��������
#define MVNum 100				//��󶥵���
#define OK true
#define ERROR false
typedef bool Status;
typedef char VerTexType;		//���趥�������Ϊ�ַ���
typedef int ArcType;			//����� ��Ȩֵ����Ϊ����
typedef struct {
	VerTexType vexs[MVNum];		//�����
	ArcType arcs[MVNum][MVNum];	//�ڽӾ���
	int vexnum, arcnum;			//ͼ�ĵ�ǰ�����ͱ���
}AMGraph;


//ͼ���ڽӱ�洢��ʾ
typedef struct ArcNode {		//�߽ڵ�
	int adjvex;					//�ñ���ָ��Ķ����λ��
	struct ArcNode * nextArc;	//ָ����һ���ߵ�ָ��
	//�ͱ���ص�������Ϣ
}AecNode ,*LAecNode;
typedef struct VNode {			//������Ϣ
	VerTexType data;			//��Ŷ������ƻ�������Ϣ
	ArcNode *firstArc;			//ָ���һ�������ö���ıߵ�ָ��
}VNode ,AdjList[MVNum];			//AdjList��ʾ�ڽӱ������
typedef struct{
	AdjList vertices;
	int vexnum, arcnum;			//ͼ�ĵ�ǰ�������ͱ���
}ALGraph;

//����ķ�㷨��������,������¼�Ӷ��㼯U��V-U��Ȩֵ��С�ı�
typedef struct CLOSEDGE{
	VerTexType adjvex;			//��С����U�е��Ǹ�����
	ArcType lowcost;			//��С���ϵ�Ȩֵ
}Closedge;


//�����ڽӾ����ʾ��������������G
Status CreateUDN_Matrix(AMGraph &G);
//�����������飬��ȡȷ��һ���ߵ�����������±�
int LocateVex(AMGraph G, char v);
//��������ڽӾ���
void TraverseMatrix(AMGraph G);

//�����ڽӱ��ʾ����������ͼ
Status CreateUDN_List(ALGraph &G);
//(�ڽӱ��ʾ��)�����������飬��ȡȷ��һ���ߵ�����������±�
int LocateVex(ALGraph G, char v);
//DFS����������������ڽ�ͼ
void DFS_AL(ALGraph G, int v , bool*);
//����ķ�㷨,������G���ڽӾ������ʽ�洢���Ӷ���u��������G����С������T�����T�ĸ�����
void MiniSpanTree_Prim(AMGraph G, VerTexType u);



