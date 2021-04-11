#ifndef CALCULATOR_H_INCLUDED
#define CALCULATOR_H_INCLUDED

#define size 50

typedef struct numberstack//计算后缀表达式所用的存放数字的栈 
{
	int num[size];
	int top;
}numstack;

 typedef struct symbolstack//将中缀表达式转化为后缀表达式存放符号的栈 
{
	char sym[size];
	int top;
}symstack;

int symboljudge(char x,char y);//判断运算符号优先级

#endif
