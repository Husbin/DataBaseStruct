//Graph_main.cpp
#include"Graph_H.h"
#include<stdio.h>
#include<string.h>
int main() {

	AMGraph AMG;
	CreateUDN_Matrix(AMG);
	TraverseMatrix(AMG);
	printf("��С�������ı߼����£�\n");
	MiniSpanTree_Prim(AMG, '1');
	printf("\n");
	static bool visited[MVNum];//���ʱ�־���飬���ֵΪfalse
	memset(visited, false, sizeof(bool) * MVNum);
	ALGraph ALG;
	CreateUDN_List(ALG);
	printf("�ӵ�1���������������������ͼG���£�\n");
	DFS_AL(ALG, 0 ,visited);
	printf("\n");
	return OK;
}