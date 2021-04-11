#include "SqStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//操作界面 
void covers() 
{
	printf("***********************************\n");
	printf("***       1.初始化栈            ***\n");
	printf("***       2.判断栈是否为空      ***\n");
	printf("***       3.得到栈顶元素        ***\n");
	printf("***       4.清空栈              ***\n");
	printf("***       5.销毁栈              ***\n");
	printf("***       6.检测栈长度          ***\n");
	printf("***       7.入栈                ***\n");
	printf("***       8.出栈                ***\n");
	printf("***       9.结束操作            ***\n");
	printf("***********************************\n");
	printf("输入你要执行的操作:");
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
	//检测输入指令 
	while(strcmp(option,"1")!=0&&strcmp(option,"2")!=0&&strcmp(option,"3")!=0&&strcmp(option,"4")!=0&&strcmp(option,"5")!=0&&strcmp(option,"6")!=0&&strcmp(option,"7")!=0&&strcmp(option,"8")!=0&&strcmp(option,"9")!=0)
	{
		system("cls");
		covers();
		printf("(错误指令请重新输入)");
		scanf("%s",option);
	}
	op=*option-48;
	switch(op)
	{
		case 1://初始化栈
			{
				if(s->elem!=NULL)
				{
					printf("栈已存在\n");
					break;
				}
				printf("请输入栈的最大的容量：");
				scanf("%d",&sizes);
				if(initStack(s,sizes)==SUCCESS) printf("成功初始化栈\n");
				break;
			}
		case 2://判断栈是否为空
			{
				if(s->elem==NULL)
				{
					printf("栈不存在\n");
					break;
				}
				if(isEmptyStack(s)==SUCCESS) printf("栈为空\n");
				else printf("栈不为空\n");
				break; 
			}
		case 3://得到栈顶元素
			{
				if(s->elem==NULL)
				{
					printf("栈不存在\n");
					break;
				}
				if(getTopStack(s,&e)==SUCCESS) printf("栈顶元素为%d\n",e);
				break;
			}
		case 4://清空栈 
			{
				if(s->elem==NULL)
				{
					printf("栈不存在\n");
					break;
				}
				if(clearStack(s)==SUCCESS) printf("栈已清空\n");
				break;
			}
		case 5://销毁栈
			{
				if(s->elem==NULL)
				{
					printf("栈不存在\n");
					break;
				}
				if(destroyStack(s)==SUCCESS) printf("栈已销毁\n");
				else printf("销毁失败\n");
				break;
			}
		case 6://检测栈长度
			{
				if(s->elem==NULL)
				{
					printf("栈不存在\n");
					break;
				}
				if(stackLength(s,&length)==SUCCESS) printf("栈的长度为%d\n",length);
				break;
			}
		case 7://入栈 
			{
				if(s->elem==NULL)
				{
					printf("栈不存在\n");
					break;
				}
				printf("请输入栈元素:");
				scanf("%d",&data);
				if(pushStack(s,data)==SUCCESS) printf("入栈成功\n");
				else printf("栈已满，入栈失败\n");
				break;
			}
		case 8://出栈
			{
				if(s->elem==NULL)
				{
					printf("栈不存在\n");
					break;
				}
				if(popStack(s,&data)==SUCCESS) printf("出栈元素为%d\n",data);
				break;
			}
		case 9:return 0;
	}
	printf("输入任意值返回操作界面:");
	scanf("%s",option);
	if(option) goto label;
	return 0;
}
