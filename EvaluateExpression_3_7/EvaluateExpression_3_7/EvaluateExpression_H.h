#pragma once
//����ջʵ�ֱ��ʽ��ֵ
#define true 1   
#define false 0   
#define OPSETSIZE 8   
typedef int Status;
typedef struct StackChar
{
	char c;
	struct StackChar *next;
}SC;       //StackChar���͵Ľ��SC  

typedef struct StackFloat
{
	float f;
	struct StackFloat *next;
}SF;       //StackFloat���͵Ľ��SF  

float EvaluateExpression(char* MyExpression);
