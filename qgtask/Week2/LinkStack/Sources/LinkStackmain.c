#include "LinkStack.h"
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
	LinkStack stack,*s=NULL;
	int length,op;
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
		case 1:
			{
				if(s!=NULL)
				{
					printf("ջ�Ѵ���\n");
					break;
				}
				s=&stack;
				if(initLStack(s)==SUCCESS) printf("�ɹ���ʼ��ջ\n");
				break;
			}
		case 2:
			{
				if(s==NULL)
				{
					printf("ջ������\n");
					break;
				}
				if(isEmptyLStack(s)==SUCCESS) printf("ջΪ��\n");
				else printf("ջ��Ϊ��\n");
				break; 
			}
		case 3:
			{
				if(s==NULL)
				{
					printf("ջ������\n");
					break;
				}
				if(getTopLStack(s,&e)==SUCCESS) printf("ջ��Ԫ��Ϊ%d\n",e);
				break;
			}
		case 4:
			{
				if(s==NULL)
				{
					printf("ջ������\n");
					break;
				}
				if(clearLStack(s)==SUCCESS) printf("ջ�����\n");
				break;
			}
		case 5:
			{
				if(s==NULL)
				{
					printf("ջ������\n");
					break;
				}
				if(destroyLStack(s)==SUCCESS) printf("ջ������\n");
				else printf("����ʧ��\n");
				s=NULL;
				break;
			}
		case 6:
			{
				if(s==NULL)
				{
					printf("ջ������\n");
					break;
				}
				if(LStackLength(s,&length)==SUCCESS) printf("ջ�ĳ���Ϊ%d\n",length);
				break;
			}
		case 7:
			{
				if(s==NULL)
				{
					printf("ջ������\n");
					break;
				}
				printf("������ջԪ��:");
				scanf("%d",&data);
				if(pushLStack(s,data)==SUCCESS) printf("��ջ�ɹ�\n");
				break;
			}
		case 8:
			{
				if(s==NULL)
				{
					printf("ջ������\n");
					break;
				}
				if(popLStack(s,&data)==SUCCESS) printf("��ջԪ��Ϊ%d\n",data);
				break;
			}
		case 9:return 0;
	}
	printf("��������ֵ���ز�������:");
	scanf("%s",option);
	if(option) goto label;
	return 0;
}
