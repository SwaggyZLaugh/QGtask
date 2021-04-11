#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//初始化两个栈 
	numstack numbers;
	symstack symbols;
	numbers.top=-1;
	symbols.top=-1;
	//s1存放用户输入的中缀表达式,s2存放转化后的后缀表达式 
	char s1[50],s2[50];
	int sum,i=0,j=0,tag=0,result;
	printf("(未设置输入检测，所以请输入正确的四则运算表达式)\n");
	printf("输入四则运算表达式:");
	scanf("%s",s1);
	while(i<=strlen(s1))//遍历s1 
	{
		if(s1[i]=='-'&&i==0)//判断第一个数是否是符数 
		{
			s2[j++]='0';//若是负数则在表达式前加一个0 
			s2[j++]=' ';
			symbols.sym[++symbols.top]=s1[i];
		}
		else if(s1[i]>=48&&s1[i]<=57)//若是数字直接输出至s2 
		{
			s2[j++]=s1[i];
			tag=1;
		}
		else
		{
			if(tag==1) s2[j++]=' ';//用空格来隔开不同数字 
			if(s1[i]=='(')//'('直接放入符号栈 
			{
				symbols.sym[++symbols.top]=s1[i];
			}
			else if(s1[i]==')')//')'右括号则将'()'内的符号输出至s2 
			{
				while(symbols.sym[symbols.top]!='(')
				{
					s2[j++]=symbols.sym[symbols.top--];
				}
				symbols.top--;
			}
			else//运算符号则根据运算优先级,栈顶元素是否为'('以及栈是否为空来进行操作 
			{
				while(symbols.sym[symbols.top]!='('&&!symboljudge(s1[i],symbols.sym[symbols.top])&&symbols.top!=-1)
				{
					s2[j++]=symbols.sym[symbols.top--];
				}
				symbols.sym[++symbols.top]=s1[i];
			}
			tag=0;
		}
		i++;
	}
	while(symbols.top>-1)//将符号栈中全部元素输出至s2 
	{
		s2[j++]=symbols.sym[symbols.top--];
	}
	printf("后缀表达式为:%s\n",s2);
	i=0;
	while(i<=strlen(s2))//遍历s2
	{
		if(s2[i]>=48&&s2[i]<=57)//若是数字，则将字符组成的数字转化为整数 
		{
			result=0;
			while(s2[i]!=' ')
			{
				result=result*10+(s2[i++]-48);
			}
			numbers.num[++numbers.top]=result;
			i++;
		}
		else if(s2[i]==' ') i++;//若是空格则直接跳过 
		else
		{
			switch(s2[i])//若是运算符则将数字栈中栈顶两元素进行操作 
			{
				case '+':
					{
						numbers.num[numbers.top-1]=numbers.num[numbers.top-1]+numbers.num[numbers.top--];
						break;
					}
				case '-':
					{
						result=numbers.num[numbers.top-1]-numbers.num[numbers.top--];
						numbers.num[numbers.top]=result;
						break;
					}
				case '*':
					{
						result=numbers.num[numbers.top-1]*numbers.num[numbers.top--];
						numbers.num[numbers.top]=result;
						break;
					}
				case '/':
					{
						result=numbers.num[numbers.top-1]/numbers.num[numbers.top--];
						numbers.num[numbers.top]=result;
						break;
					}
			}
			i++;
		}
	}
	printf("运算结果为:%d",numbers.num[numbers.top]);
	return 0;
}
