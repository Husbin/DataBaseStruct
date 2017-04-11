#include"EvaluateExpression_H.h"
#include<stdio.h>  
#include"stdlib.h"   
#include"string.h"   
#include"math.h"  

unsigned char Prior[8][8] =
{ // ��������ȼ���   
  // '+' '-' '*' '/' '(' ')' '#' '^'   
	/*'+'*/'>','>','<','<','<','>','>','<',
	/*'-'*/'>','>','<','<','<','>','>','<',
	/*'*'*/'>','>','>','>','<','>','>','<',
	/*'/'*/'>','>','>','>','<','>','>','<',
	/*'('*/'<','<','<','<','<','=',' ','<',
	/*')'*/'>','>','>','>',' ','>','>','>',
	/*'#'*/'<','<','<','<','<',' ','=','<',
	/*'^'*/'>','>','>','>','<','>','>','>'
};


SC *Push(SC *s, char c)          //SC���͵�ָ��Push������p  
{
	SC *p = (SC*)malloc(sizeof(SC));
	p->c = c;
	p->next = s;
	return p;
}

SF *Push(SF *s, float f)        //SF���͵�ָ��Push������p  
{
	SF *p = (SF*)malloc(sizeof(SF));
	p->f = f;
	p->next = s;
	return p;
}

SC *Pop(SC *s)    //SC���͵�ָ��Pop  
{
	SC *q = s;
	s = s->next;
	free(q);
	return s;
}

SF *Pop(SF *s)      //SF���͵�ָ��Pop  
{
	SF *q = s;
	s = s->next;
	free(q);
	return s;
}

float Operate(float a, unsigned char theta, float b)      //���㺯��Operate  
{
	switch (theta)
	{
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a*b;
	case '/': return a / b;
	case '^': return pow(a, b);
	default: return 0;
	}
}

char OPSET[OPSETSIZE] = { '+','-','*','/','(',')','#','^' };

Status In(char Test, char *TestOp)
{
	int Find = false;
	for (int i = 0; i< OPSETSIZE; i++)
	{
		if (Test == TestOp[i])
			Find = true;
	}
	return Find;
}

Status ReturnOpOrd(char op, char *TestOp)
{
	for (int i = 0; i< OPSETSIZE; i++)
	{
		if (op == TestOp[i])
			return i;
	}
}

char precede(char Aop, char Bop)
{
	return Prior[ReturnOpOrd(Aop, OPSET)][ReturnOpOrd(Bop, OPSET)];
}

float EvaluateExpression(char* MyExpression)
{
	// ��������ʽ��ֵ����������㷨  
	// ��OPTR��OPND�ֱ�Ϊ�����ջ��������ջ��OPΪ���������   
	SC *OPTR = NULL;       // �����ջ���ַ�Ԫ��   
	SF *OPND = NULL;       // ������ջ��ʵ��Ԫ��   
	char TempData[20];
	float Data, a, b;
	char theta, *c, Dr[] = { '#','\0' };
	OPTR = Push(OPTR, '#');
	c = strcat(MyExpression, Dr);
	strcpy(TempData, "\0");//�ַ�����������   
	while (*c != '#' || OPTR->c != '#')
	{
		if (!In(*c, OPSET))
		{
			Dr[0] = *c;
			strcat(TempData, Dr);           //�ַ������Ӻ���   
			c++;
			if (In(*c, OPSET))
			{
				Data = atof(TempData);       //�ַ���ת������(double)   
				OPND = Push(OPND, Data);
				strcpy(TempData, "\0");
			}
		}
		else    // ������������ջ   
		{
			switch (precede(OPTR->c, *c))
			{
			case '<': // ջ��Ԫ�����ȼ���   
				OPTR = Push(OPTR, *c);
				c++;
				break;
			case '=': // �����Ų�������һ�ַ�   
				OPTR = Pop(OPTR);
				c++;
				break;
			case '>': // ��ջ������������ջ   
				theta = OPTR->c; OPTR = Pop(OPTR);
				b = OPND->f; OPND = Pop(OPND);
				a = OPND->f; OPND = Pop(OPND);
				OPND = Push(OPND, Operate(a, theta, b));
				break;
			} //switch  
		}
	} //while   
	return OPND->f;
} //EvaluateExpression   