#include "calculator.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//��ʼ������ջ 
	numstack numbers;
	symstack symbols;
	numbers.top=-1;
	symbols.top=-1;
	//s1����û��������׺���ʽ,s2���ת����ĺ�׺���ʽ 
	char s1[50],s2[50];
	int sum,i=0,j=0,tag=0,result;
	printf("(δ���������⣬������������ȷ������������ʽ)\n");
	printf("��������������ʽ:");
	scanf("%s",s1);
	while(i<=strlen(s1))//����s1 
	{
		if(s1[i]=='-'&&i==0)//�жϵ�һ�����Ƿ��Ƿ��� 
		{
			s2[j++]='0';//���Ǹ������ڱ��ʽǰ��һ��0 
			s2[j++]=' ';
			symbols.sym[++symbols.top]=s1[i];
		}
		else if(s1[i]>=48&&s1[i]<=57)//��������ֱ�������s2 
		{
			s2[j++]=s1[i];
			tag=1;
		}
		else
		{
			if(tag==1) s2[j++]=' ';//�ÿո���������ͬ���� 
			if(s1[i]=='(')//'('ֱ�ӷ������ջ 
			{
				symbols.sym[++symbols.top]=s1[i];
			}
			else if(s1[i]==')')//')'��������'()'�ڵķ��������s2 
			{
				while(symbols.sym[symbols.top]!='(')
				{
					s2[j++]=symbols.sym[symbols.top--];
				}
				symbols.top--;
			}
			else//�������������������ȼ�,ջ��Ԫ���Ƿ�Ϊ'('�Լ�ջ�Ƿ�Ϊ�������в��� 
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
	while(symbols.top>-1)//������ջ��ȫ��Ԫ�������s2 
	{
		s2[j++]=symbols.sym[symbols.top--];
	}
	printf("��׺���ʽΪ:%s\n",s2);
	i=0;
	while(i<=strlen(s2))//����s2
	{
		if(s2[i]>=48&&s2[i]<=57)//�������֣����ַ���ɵ�����ת��Ϊ���� 
		{
			result=0;
			while(s2[i]!=' ')
			{
				result=result*10+(s2[i++]-48);
			}
			numbers.num[++numbers.top]=result;
			i++;
		}
		else if(s2[i]==' ') i++;//���ǿո���ֱ������ 
		else
		{
			switch(s2[i])//���������������ջ��ջ����Ԫ�ؽ��в��� 
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
	printf("������Ϊ:%d",numbers.num[numbers.top]);
	return 0;
}
