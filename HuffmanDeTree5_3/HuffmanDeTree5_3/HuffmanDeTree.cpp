//HuffmanDeTree_main

#include<iostream>
#include<fstream>
#include"HuffmanDeTree_H.h"
using namespace std;
void main()
{
	HuffmanTree HT = NULL;//��ʼ����Ϊ����
	int falg;//��¼Ҫ������ַ�����
	char a[MAX_MA];//��������Ķ������ַ�
	char b[MAX_ZF];//�洢������ַ�
	char zf[MAX_ZF];//����Ҫ������ַ�
	HuffmanCode HC = NULL;//��ʼ�������Ϊ�ձ�
	ofstream output_Code;
	menu();
	while (true)
	{
		int num;
		cout << "��ѡ����: ";
		cin >> num;
		switch (num)
		{
		case 1:
			int cou[100];
			for (int i = 0; i < 100; i++) {
				cou[i] = 0;
			}
			falg = Count(HT , cou , zf);
			break;
		case 2:
			CreatHuffmanCode(HT, HC, falg);//���ô��������������ĺ���
			cout << endl;
			cout << "���ɹ����������ɹ���,�����Ǹñ����������" << endl;
			cout << endl;
			cout << "���i" << "\t" << "�ַ�" << "\t" << "Ȩֵ" << "\t" << "����" << endl;
			for (int i = 1; i <= falg; i++)
			{
				cout << i << "\t" << zf[i] << "\t" << HT[i].weight << "\t" << HC[i] << endl;
			}
			output_Code.open("F:\\Code.txt");
			if (!output_Code) {
				cout << "can'toenfile!" << endl;
				return ;
			}
			for (int i = 1; i <= falg; i++)
			{
				output_Code << "(" << zf[i] << HC[i] << ")";
			}
			output_Code.close();
			cout << "�շ������Ѿ�������ϣ������Ѿ�����Code.txt�ļ���!" << endl;
			cout << endl;
			break;
		case 3:
			cout << "��������Ҫ�����һ�������Ʊ��룺";
			/*�������Զ�̬��ֱ������һ�������Ʊ��룬��Ϊ��������ʱ���ϵͳ���Զ���һ��������*/
			cin >> a;
			TranCode(HT, a, zf, b, falg);//��������ĺ�����
			/*��������ֱ�Ӱ�����b�������Ϊ�����������b������ʱ������������������*/
			cout << endl;
			cout << "����ɹ���������Ϊ��" << b << endl;
			cout << endl;
			break;
		case 4:
			cout << endl;
			cout << "�˳��ɹ���" << endl;
			exit(0);
		default:
			break;
		}
	}

}