#include "LQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h> 


//操作界面 
void covers() 
{
	printf("**********************************\n");
	printf("***       1.初始化队列         ***\n");
	printf("***       2.销毁队列           ***\n");
	printf("***       3.查看队头元素       ***\n");
	printf("***       4.确定队列长度       ***\n");
	printf("***       5.入队操作           ***\n");
	printf("***       6.出队操作           ***\n");
	printf("***       7.清空队列           ***\n");
	printf("***       8.遍历队列           ***\n");
	printf("***       9.结束操作           ***\n");
	printf("**********************************\n");
	printf("输入你要执行的操作:");
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
	printf("请输入队列存储数据类型(integer or string):");
	scanf("%s",datatype);
	while(strcmp(datatype,"integer")!=0&&strcmp(datatype,"string")!=0)
	{
		system("cls");
		printf("请输入队列存储数据类型(integer or string):(指令错误请重输)");
		scanf("%s",datatype);
	}
	if(strcmp(datatype,"integer")==0) type='i';
	else type='s';
	label:
	system("cls");
	covers();
	scanf("%s",option);
	//检测输入指令 
	while(strcmp(option,"1")!=0&&strcmp(option,"2")!=0&&strcmp(option,"3")!=0&&strcmp(option,"4")!=0&&strcmp(option,"5")!=0&&strcmp(option,"6")!=0&&strcmp(option,"7")!=0&&strcmp(option,"8")!=0&&strcmp(option,"9")!=0)
	{
		system("cls");
		covers();
		printf("(错误指令请重新输入)");
		scanf("%s",option);
	}
	op=*option-48;
	system("cls");
	switch(op)
	{
		case 1://初始化队列
			{
				if(Q!=NULL)
				{
					printf("队列已存在\n");
					break;
				}
				Q=(LQueue*)malloc(sizeof(LQueue));
				Q->front=NULL;
				Q->rear=NULL;
				InitLQueue(Q);
				printf("队列初始化成功\n");
				break;
			}
		case 2://销毁队列
			{
				if(Q==NULL)
				{
					printf("队列不存在\n");
					break;
				}
				DestoryLQueue(Q);
				Q=NULL;
				printf("队列销毁成功\n");
				break;
			}
		case 3://查看队头元素
			{
				if(Q==NULL)
				{
					printf("队列不存在\n");
					break;
				}
				if(GetHeadLQueue(Q, e)==FALSE) printf("空队列!!!\n");
				else LPrint(e);
				break;
			}
		case 4://确定队列长度
			{
				if(Q==NULL)
				{
					printf("队列不存在\n");
					break;
				}
				length=LengthLQueue(Q);
				printf("队列长度为:%d\n",length);
				break; 
			}
		case 5://入队操作
			{
				if(Q==NULL)
				{
					printf("队列不存在\n");
					break;
				}
				q=(Node *)malloc(sizeof(Node));//创建新结点q并放在队尾 
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
					printf("请输入入队元素(integer):");
					while(1)
					{
						scanf("%s",s);
						i=judgeint(s);//检测输入是否为整数 
						if(i) break;
						else
						{
							system("cls");
							printf("请输入入队元素(integer):(输入错误请重输)");
						}
					}
					data=&i;
				}
				else
				{
					q->data=(void *)malloc(20*sizeof(char));
					printf("请输入入队元素(string):");
					scanf("%s",s);
					data=s;
				}
				if(EnLQueue(Q, data)==FALSE) printf("队列已满!!!\n");
				else printf("入队成功\n");
				break;
			}
		case 6://出队操作
			{
				if(Q==NULL)
				{
					printf("队列不存在\n");
					break;
				}
				if(DeLQueue(Q)==FALSE) printf("队列为空!!!\n");
				else printf("出队成功\n");
				break;
			}
		case 7://清空队列
			{
				if(Q==NULL)
				{
					printf("队列不存在\n");
					break;
				}
				ClearLQueue(Q);
				printf("队列已清空\n");
				break;
			
			}
		case 8://遍历队列
			{
				if(Q==NULL)
				{
					printf("队列不存在\n");
					break;
				}
				if(TraverseLQueue(Q, LPrint)==FALSE) printf("队列为空!!!\n");
				else printf("遍历完毕\n");
				break;
			}
		case 9:return 0;//结束操作
	}
	printf("输入任意值返回操作界面:");
	scanf("%s",option);
	if(option) goto label;
	return 0;
}
