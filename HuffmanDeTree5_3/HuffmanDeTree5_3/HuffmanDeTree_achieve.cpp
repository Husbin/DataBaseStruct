//HuffmanDeTree_achieve
#include"HuffmanDeTree_H.h"
void Select(HuffmanTree HT, int n, int &s1, int &s2)
{
	/*n����HT����ĳ��� */

	//ǰ����forѭ�������н����Ȩֵ��С�ĵ㣨�ַ���
	for (int i = 1; i <= n; i++)
	{//����forѭ���ҳ�һ��˫��Ϊ0�Ľ��
		if (HT[i].parent == 0)
		{
			s1 = i;//s1��ʼ��Ϊi
			break;//�ҵ�һ���������˳�ѭ��
		}
	}
	for (int i = 1; i <= n; i++)
	{/*����forѭ���ҵ����н�㣨�ַ���Ȩֵ��С��һ��
	 ���ұ�֤�ý���˫��Ϊ0*/
		if (HT[i].weight < HT[s1].weight && HT[i].parent == 0)
			s1 = i;
	}
	//������forѭ�����н����Ȩֵ�ڶ�С�ĵ㣨�ַ���
	for (int i = 1; i <= n; i++)
	{//����forѭ���ҳ�һ��˫��Ϊ0�Ľ�㣬���Ҳ�����s1
		if (HT[i].parent == 0 && i != s1)
		{
			s2 = i;//s2��ʼ��Ϊi
			break;//�ҵ�һ���������˳�ѭ��
		}
	}

	for (int i = 1; i <= n; i++)
	{/*����forѭ���ҵ����н�㣨�ַ���Ȩֵ�ڶ�С��һ����
	 �ý�����㲻����s1��˫����0*/
		if (HT[i].weight < HT[s2].weight && HT[i].parent == 0 && i != s1)
			s2 = i;
	}

}

void CreatHuffmanCode(HuffmanTree HT, HuffmanCode &HC, int n) {
	int start;
	char *cd;
	HC = new char*[n + 1];
	cd = new char[n];
	cd[n - 1] = '\0';
	int i, c, f;
	for (i = 1; i <= n; ++i) {
		start = n - 1;
		c = i;
		f = HT[i].parent;
		while (f != 0) {
			--start;
			if (HT[f].lchild == c)
				cd[start] = '0';
			else
				cd[start] = '1';
			c = f;
			f = HT[f].parent;
		}
		HC[i] = new char[n - start];
		strcpy(HC[i], &cd[start]);
	}      delete cd;
	cout << "HuffmanCode�������" << endl;
}

//�����������
void CreateHuffmanTree(HuffmanTree &HT, int n, int*cou)
{
	/*-----------��ʼ������-------------------------*/
	if (n <= 1)
		return;
	int m = 2 * n - 1;
	HT = new HTNode[m + 1];
	for (int i = 1; i <= m; ++i)
	{//��1~m�ŵ�Ԫ�е�˫�ף����ӣ��Һ��ӵ��±궼��ʼ��Ϊ0
		HT[i].parent = 0; HT[i].lchild = 0; HT[i].rchild = 0;
	}
	for (int i = 1; i <= n; ++i)
	{
		HT[i].weight = cou[i];//����ǰn����Ԫ��Ҷ�ӽ���Ȩֵ
	}
	/*-----------��������---------------------------*/
	int s1, s2;
	for (int i = n + 1; i <= m; ++i)
	{//ͨ��n-1�ε�ѡ��ɾ�����ϲ��������������
		Select(HT, i - 1, s1, s2);
		/*cout << HT[s1].weight << " , " << HT[s2].weight << endl;*/
		/*��s1,s2��˫������0��Ϊi (�൱�ڰ����������ɾ���ˣ���������㲻�ٲ���Select()����)*/
		HT[s1].parent = i;
		HT[s2].parent = i;
		//s1,��s2�ֱ���Ϊi�����Һ���
		HT[i].lchild = s1;
		HT[i].rchild = s2;
		//���i��ȨֵΪs1,s2Ȩֵ֮��
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
}

//����������
void TranCode(HuffmanTree HT, char a[], char zf[], char b[], int n)
{
	int q = 2 * n - 1;//q��ʼ��Ϊ�������±�
	int k = 0;//��¼�洢����ַ�������±�
	int i = 0;
	for (i = 0; a[i] != '\0'; i++)
	{//forѭ�����������Ƕ�����ַ��ǽ������������Ʊ��룩
	 //�˴���������ж϶���Ķ������ַ���0����1
		if (a[i] == '0')
		{/*����0���Ѹ����(HT[q])�����ӵ��±�ֵ����q
		 140          �´�ѭ����ʱ���HT[q]��������Ϊ�µĸ����*/
			q = HT[q].lchild;
		}
		else if (a[i] == '1')
		{
			q = HT[q].rchild;
		}
		//�˴���������ж�HT[q]�Ƿ�ΪҶ�ӽ��
		if (HT[q].lchild == 0 && HT[q].rchild == 0)
		{/*��Ҷ�ӽ�㣬˵���Ѿ����һ���ַ����ַ����±�����ҵ���Ҷ�ӽ����±�*/
			b[k++] = zf[q];//���±�Ϊq���ַ������ַ�����b[]
			q = 2 * n - 1;//��ʼ��qΪ�������±�
						  //��������һ���ַ���ʱ��ӹ��������ĸ���㿪ʼ
		}
	}
	/*�������֮��������¼����ַ�����������û�н���������� ʱ��ر����ʽ����Ű�һ���������ӵ��������*/
	b[k] = '\0';
}

//�˵�����
void menu()
{
	cout << " 1.  ������������" << endl;
	cout << " 2.  ���й��������� " << endl;
	cout << " 3.  ���й��������� " << endl;
	cout << " 4.  �˳�����" << endl;
	cout << endl;
}

//�����������ĸ�ĸ��� 
int Count(HuffmanTree &HT, int cou[], char* zf) {
	char word;
	int count = 0;
	char letter[27] = { ' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o', 'p','q','r','s','t','u','v','w','x','y','z' };
	fstream SourceFile;
	SourceFile.open("F://SourceFile.txt", ios::in);
	if (!SourceFile) {
		cout << "Can't open this file" << endl;
	}
	while (!SourceFile.eof()) {
		SourceFile.get(word);
		if (word >= 'A'&&word <= 'Z') {
			word = word + 32;
		}
		int i = word - 96;
		cou[i]++;
	}
	SourceFile.close();
	cout << "letter" << '\t' << '\t' << "Ƶ��Ϊ" << endl;
	for (int j = 1; j <= 26; j++) {
		if (cou[j] != 0) {
			cout << letter[j] << '\t' << '\t' << cou[j] << endl;
			zf[count + 1] = letter[j];
			count++;
		}
	}
	cout << "�ļ���ȡ��ϡ�" << endl;
	CreateHuffmanTree(HT, count, cou);//���ô������������ĺ���
	cout << "�����������ɹ���,�����Ǹù��������Ĳ��������" << endl;
	cout << endl;
	cout << "���i" << "\t" << "�ַ�" << "\t" << "Ȩֵ" << "\t" << "˫��" << "\t" << "����" << "\t" << "�Һ���" << endl;
	for (int i = 1; i <= count * 2 - 1; i++)
	{
		cout << i << "\t" << zf[i] << "\t" << HT[i].weight << "\t" << HT[i].parent << "\t" << HT[i].lchild << "\t" << HT[i].rchild << endl;
	}
	cout << endl;
	return count;
}