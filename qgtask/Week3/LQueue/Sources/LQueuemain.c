#include "LQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 


//�������� 
void covers() 
{
	printf("**********************************\n");
	printf("***       1.��ʼ������         ***\n");
	printf("***       2.���ٶ���           ***\n");
	printf("***       3.�鿴��ͷԪ��       ***\n");
	printf("***       4.ȷ�����г���       ***\n");
	printf("***       5.��Ӳ���           ***\n");
	printf("***       6.���Ӳ���           ***\n");
	printf("***       7.��ն���           ***\n");
	printf("***       8.��������           ***\n");
	printf("***       9.��������           ***\n");
	printf("**********************************\n");
	printf("������Ҫִ�еĲ���:");
}

void covers();

void *e;
int main()
{
	LQueue *Q=NULL;
	int length,op,i;
	char option[50],s[20];
	void *data;
	Node *q;
	printf("��������д洢��������(integer or string):");
	scanf("%s",datatype);
	while(strcmp(datatype,"integer")!=0&&strcmp(datatype,"string")!=0)
	{
		system("cls");
		printf("��������д洢��������(integer or string):(ָ�����������)");
		scanf("%s",datatype);
	}
	if(strcmp(datatype,"integer")==0) type='i';
	else type='s';
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
	system("cls");
	switch(op)
	{
		case 1://��ʼ������
			{
				if(Q!=NULL)
				{
					printf("�����Ѵ���\n");
					break;
				}
				Q=(LQueue*)malloc(sizeof(LQueue));
				Q->front=NULL;
				Q->rear=NULL;
				InitLQueue(Q);
				printf("���г�ʼ���ɹ�\n");
				break;
			}
		case 2://���ٶ���
			{
				if(Q==NULL)
				{
					printf("���в�����\n");
					break;
				}
				DestoryLQueue(Q);
				Q=NULL;
				printf("�������ٳɹ�\n");
				break;
			}
		case 3://�鿴��ͷԪ��
			{
				if(Q==NULL)
				{
					printf("���в�����\n");
					break;
				}
				if(GetHeadLQueue(Q, e)==FALSE) printf("�ն���!!!\n");
				else LPrint(e);
				break;
			}
		case 4://ȷ�����г���
			{
				if(Q==NULL)
				{
					printf("���в�����\n");
					break;
				}
				length=LengthLQueue(Q);
				printf("���г���Ϊ:%d\n",length);
				break; 
			}
		case 5://��Ӳ���
			{
				if(Q==NULL)
				{
					printf("���в�����\n");
					break;
				}
				q=(Node *)malloc(sizeof(Node));//�����½��q�����ڶ�β 
				q->next=NULL;
				if(Q->front==NULL) Q->front=Q->rear=q;
				else
				{
					Q->rear->next=q;
					Q->rear=Q->rear->next;
				}
				if(type=='i')
				{
					q->data=(void *)malloc(sizeof(int));
					printf("���������Ԫ��(integer):");
					while(1)
					{
						scanf("%s",s);
						i=judgeint(s);//��������Ƿ�Ϊ���� 
						if(i) break;
						else
						{
							system("cls");
							printf("���������Ԫ��(integer):(�������������)");
						}
					}
					data=&i;
				}
				else
				{
					q->data=(void *)malloc(20*sizeof(char));
					printf("���������Ԫ��(string):");
					scanf("%s",s);
					data=s;
				}
				if(EnLQueue(Q, data)==FALSE) printf("��������!!!\n");
				else printf("��ӳɹ�\n");
				break;
			}
		case 6://���Ӳ���
			{
				if(Q==NULL)
				{
					printf("���в�����\n");
					break;
				}
				if(DeLQueue(Q)==FALSE) printf("����Ϊ��!!!\n");
				else printf("���ӳɹ�\n");
				break;
			}
		case 7://��ն���
			{
				if(Q==NULL)
				{
					printf("���в�����\n");
					break;
				}
				ClearLQueue(Q);
				printf("���������\n");
				break;
			
			}
		case 8://��������
			{
				if(Q==NULL)
				{
					printf("���в�����\n");
					break;
				}
				if(TraverseLQueue(Q, LPrint)==FALSE) printf("����Ϊ��!!!\n");
				else printf("�������\n");
				break;
			}
		case 9:return 0;//��������
	}
	printf("��������ֵ���ز�������:");
	scanf("%s",option);
	if(option) goto label;
	return 0;
}
