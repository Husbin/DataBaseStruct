//Graph_achieve.cpp
#include"Graph_H.h"
#include<stdio.h>
#include<stdlib.h>

//(�ڽӾ����ʾ��)�����������飬��ȡȷ��һ���ߵ�����������±�
int LocateVex_1(AMGraph G, char v) {
	int flag = 0;
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vexs[i]== v) {
			flag++;
			return i;
		}
	}
	if (flag == 0) {
		printf("���������Ҳ���%c�㡣\n", v);
		return ERROR;
	}
}
//(�ڽӱ��ʾ��)�����������飬��ȡȷ��һ���ߵ�����������±�
int LocateVex_2(ALGraph G, char v) {
	int flag = 0;
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vertices[i].data == v) {
			flag++;
			return i;
		}
	}
	if (flag == 0) {
		printf("���������Ҳ���%c�㡣\n", v);
		return ERROR;
	}
}

//�����ڽӾ����ʾ��������������G
Status CreateUDN_Matrix(AMGraph &G) {
	//
	printf("-------------�ڽӾ����ʾ����������ͼ--------------\n");
	printf("����ͼ���ܵ�����������100����");
	scanf("%d", &G.vexnum);
	printf("����ͼ���ܱ�����");
	scanf("%d", &G.arcnum);
	//��ʼ�����붥�����Ϣ
	for (int i = 0; i < G.vexnum; i++) {
		//fflush(stdin); ������
		printf("�������%d�����㣺", i + 1);
		//scanf("%*[^\n]");������
		//scanf(" %c", &G.vexs[i]);�Ƹ��
		scanf("%*[\t\n\r]");//�߱Ƹ�
		scanf("%c", &G.vexs[i]);
	}
	//��ʼ���ڽӾ��󣬱ߵ�Ȩֵ����Ϊ����ֵMaxInt
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			G.arcs[i][j] = MaxInt;
		}
	}
	//�����ڽӾ���
	//һ���������Ķ����Լ�Ȩֵ
	char v1, v2;
	int weight;
	for (int k = 0; k < G.arcnum; k++) {
		printf("����������ȷ����%d���ߵ��������㣺" ,k + 1);
		scanf("%*[\t\n\r]");
		scanf("%c%c", &v1, &v2);
		//ȷ��v1��v2��G�е�λ�ã�������������±�
		int i = LocateVex_1(G, v1);
		int j = LocateVex_1(G, v2);
		printf("�������<%c , %c>��Ȩֵ��",v1, v2);
		scanf("%*[\t\n\r]");
		scanf("%d", &weight);
		G.arcs[i][j] = weight;
		//����ͼ���ڽӾ���Գ�
		G.arcs[j][i] = G.arcs[i][j];
	}
	return OK;
}

//��������ڽӾ���
void TraverseMatrix(AMGraph G) {
	printf("�ڽӾ���������£�\n");
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			printf("%d\t\t", G.arcs[i][j]);
		}
		printf("\n\n");
	}
}
//�����ڽӱ��ʾ����������ͼ
Status CreateUDN_List(ALGraph &G) {
	printf("-------------�ڽӱ��ʾ����������ͼ--------------\n");
	//�����ܶ��������ܱ���
	printf("����ͼ���ܵ�����������100����");
	scanf("%d", &G.vexnum);
	printf("����ͼ���ܱ�����");
	scanf("%d", &G.arcnum);
	//������������ֵ�������ͷ�ڵ��
	for (int i = 0; i < G.vexnum; i++) {
		printf("�������%d�����㣺", i + 1);
		scanf("%*[\t\n\r]");
		scanf("%c", &G.vertices[i].data);	//���붥���ֵ
		G.vertices[i].firstArc = NULL;		//��ʼ����ͷ�ڵ��ָ����ΪNULL
	}
	//������ߣ������ڽӱ�
	//һ���������Ķ����Լ�Ȩֵ
	char v1, v2;
	int weight;
	for (int k = 0; k < G.arcnum; k++) {
		printf("����������ȷ����%d���ߵ��������㣺", k + 1);
		scanf("%*[\t\n\r]");
		scanf("%c%c", &v1, &v2);
		//ȷ��v1��v2��G�е�λ�ã�������G.vertics�е����
		int i = LocateVex_2(G, v1);
		int j = LocateVex_2(G, v2);
		LAecNode p1 = (LAecNode)malloc(sizeof(ArcNode));//����һ���½ڵ�*p1
		p1->adjvex = j;									//�ڽӵ����Ϊj
		//���½ڵ�*p1���붨��vi�ı߱�ͷ��
		p1->nextArc = G.vertices[i].firstArc;
		G.vertices[i].firstArc = p1;

		AecNode *p2 = new AecNode();//����һ���½ڵ�*p2
		p2->adjvex = i;									//�ڽӵ����Ϊi
		//���½ڵ�*p2���붨��vj�ı��ͷ��
		p2->nextArc = G.vertices[j].firstArc;
		G.vertices[j].firstArc = p2;	
	}
	return OK;
}
//DFS����������������ڽ�ͼ
void DFS_AL(ALGraph G, int v, bool* visited) {
	//�ӵ�v�������������������ޱ���ͼG
	//printf("�ӵ�%d���������������������ͼG���£�\n" , v);
	visited[v] = true;
	AecNode *p = new AecNode();
	p = G.vertices[v].firstArc;//pָ��v�ı�����ĵ�һ���߽ڵ�
	printf("%c\t\t", G.vertices[v].data);
	while (p != NULL) {		//�߽ڵ�ǿ�
		int w = p->adjvex;	//��ʾw��v���ڽӵ�
		if (!visited[w]) {	//���wδ���ʣ���ݹ����DFS_AL
			DFS_AL(G, w , visited);
		}
		p = p->nextArc;		//pָ����һ���ڵ�
	}
}
void MiniSpanTree_Prim(AMGraph G, VerTexType u) {
	Closedge closedge[MVNum];
	int k = LocateVex_1(G, u);				//kΪ����u���±�
	for (int j = 0; j < G.vexnum; j++) {	//��V-U��ÿһ������vj����ʼ��closedge[j]
		if (j != k) {
			closedge[j] = { u , G.arcs[k][j] };//{adjvex , lowcost}
		}
	}
	closedge[k].lowcost = 0;				//��ʼ����U = {u}
	//ѡ������n-1�����㣬����n-1���ߣ���n = G.vexnum��
	for (int i = 1; i < G.vexnum; i++) {
		//k = Min(closedge);
		int min = MaxInt;
		int j = 1;
		int k = 0;
		while (j < G.vexnum)
		{
			//�����������֮����ڱ߲���ȨֵС��min  
			if (closedge[j].lowcost != 0 && closedge[j].lowcost<min)
			{
				min = closedge[j].lowcost;
				k = j;
			}
			++j;
		}	
		//�����һ���ڵ㣺��K�����㣬closedge[k]�д��е�ǰ��С�ı�
		char u = closedge[k].adjvex;		//uΪ��С�ߵ�һ������
		char v = G.vexs[k];					//vΪ��С�ߵ���һ������
		printf(" < %c , %c > ", u, v);			//�����ǰ��С��
		closedge[k].lowcost = 0;			//��k�����㲢��U��
		for (int j = 0; j < G.vexnum; j++) {
			if (G.arcs[k][j] < closedge[j].lowcost) {//�¶��㲢��U������ѡ����С��
				closedge[j] = { G.vexs[k] , G.arcs[k][j] };
			}
		}
	}
}