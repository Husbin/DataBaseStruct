#pragma once
//HuffmanDeTree_H.h
#include<iostream>
#include<fstream>
#define MAX_MA 1000
#define MAX_ZF 100
using namespace std;
typedef struct
{
	int weight;  //����Ȩֵ
	int parent, lchild, rchild;//˫�ף����ӣ��Һ��ӵ��±�
}HTNode, *HuffmanTree;  //��̬����������������������Ľ��

						//�����������Ĵ����ʾ
typedef char **HuffmanCode;//��̬��������洢����������

void Select(HuffmanTree HT, int n, int &s1, int &s2);

void CreatHuffmanCode(HuffmanTree HT, HuffmanCode &HC, int n);

void CreateHuffmanTree(HuffmanTree &HT, int n, int*cou);

void TranCode(HuffmanTree HT, char a[], char zf[], char b[], int n);

void menu();

int Count(HuffmanTree &HT, int cou[], char* zf);
