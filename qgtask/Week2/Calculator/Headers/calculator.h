#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#define size 50

typedef struct numberstack//�����׺���ʽ���õĴ�����ֵ�ջ 
{
	int num[size];
	int top;
}numstack;

 typedef struct symbolstack//����׺���ʽת��Ϊ��׺���ʽ��ŷ��ŵ�ջ 
{
	char sym[size];
	int top;
}symstack;

int symboljudge(char x,char y);//�ж�����������ȼ�

#endif
