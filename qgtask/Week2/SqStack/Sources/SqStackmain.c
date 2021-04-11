#include "SqStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//�������� 
void covers() 
{
	printf("***********************************\n");
	printf("***       1.��ʼ��ջ            ***\n");
	printf("***       2.�ж�ջ�Ƿ�Ϊ��      ***\n");
	printf("***       3.�õ�ջ��Ԫ��        ***\n");
	printf("***       4.���ջ              ***\n");
	printf("***       5.����ջ              ***\n");
	printf("***       6.���ջ����          ***\n");
	printf("***       7.��ջ                ***\n");
	printf("***       8.��ջ                ***\n");
	printf("***       9.��������            ***\n");
	printf("***********************************\n");
	printf("������Ҫִ�еĲ���:");
}

void covers();

int main()
{
	SqStack stack,*s=&stack;
	s->elem=NULL;
	s->size=0;
	s->top=-1;
	int length,sizes,op;
	ElemType e,data;
	char option[50];
	label:
	system("cls");
	covers();
	scanf("%s",option);
	//�������ָ�� 
	while(strcmp(option,"1")!=0&&strcmp(option,"2")!=0&&strcmp(option,"3")!=0&&strcmp(option,"4")!=0&&strcmp(option,"5")!=0&&strcmp(option,"6")!=0&&strcmp(option,"7")!=0&&strcmp(option,"8")!=0&&strcmp(option,"9")!=0)
	{
		system("cls");
		covers();
		printf("(����ָ������������)");
		scanf("%s",option);
	}
	op=*option-48;
	switch(op)
	{
		case 1://��ʼ��ջ
			{
				if(s->elem!=NULL)
				{
					printf("ջ�Ѵ���\n");
					break;
				}
				printf("������ջ������������");
				scanf("%d",&sizes);
				if(initStack(s,sizes)==SUCCESS) printf("�ɹ���ʼ��ջ\n");
				break;
			}
		case 2://�ж�ջ�Ƿ�Ϊ��
			{
				if(s->elem==NULL)
				{
					printf("ջ������\n");
					break;
				}
				if(isEmptyStack(s)==SUCCESS) printf("ջΪ��\n");
				else printf("ջ��Ϊ��\n");
				break; 
			}
		case 3://�õ�ջ��Ԫ��
			{
				if(s->elem==NULL)
				{
					printf("ջ������\n");
					break;
				}
				if(getTopStack(s,&e)==SUCCESS) printf("ջ��Ԫ��Ϊ%d\n",e);
				break;
			}
		case 4://���ջ 
			{
				if(s->elem==NULL)
				{
					printf("ջ������\n");
					break;
				}
				if(clearStack(s)==SUCCESS) printf("ջ�����\n");
				break;
			}
		case 5://����ջ
			{
				if(s->elem==NULL)
				{
					printf("ջ������\n");
					break;
				}
				if(destroyStack(s)==SUCCESS) printf("ջ������\n");
				else printf("����ʧ��\n");
				break;
			}
		case 6://���ջ����
			{
				if(s->elem==NULL)
				{
					printf("ջ������\n");
					break;
				}
				if(stackLength(s,&length)==SUCCESS) printf("ջ�ĳ���Ϊ%d\n",length);
				break;
			}
		case 7://��ջ 
			{
				if(s->elem==NULL)
				{
					printf("ջ������\n");
					break;
				}
				printf("������ջԪ��:");
				scanf("%d",&data);
				if(pushStack(s,data)==SUCCESS) printf("��ջ�ɹ�\n");
				else printf("ջ��������ջʧ��\n");
				break;
			}
		case 8://��ջ
			{
				if(s->elem==NULL)
				{
					printf("ջ������\n");
					break;
				}
				if(popStack(s,&data)==SUCCESS) printf("��ջԪ��Ϊ%d\n",data);
				break;
			}
		case 9:return 0;
	}
	printf("��������ֵ���ز�������:");
	scanf("%s",option);
	if(option) goto label;
	return 0;
}
