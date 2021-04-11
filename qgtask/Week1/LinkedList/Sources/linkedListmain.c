#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

void visit(ElemType e);
void covers();

//输出函数 
void visit(ElemType e)
{
	printf("%d ",e);
}

//操作界面 
void covers() 
{
	printf("*******************************************************\n");
	printf("***    1.initialize an empty linked list            ***\n");
	printf("***    2.destroy a linked list                      ***\n");
	printf("***    3.insert a node                              ***\n");
	printf("***    4.delete a node                              ***\n");
	printf("***    5.traverse the linked list                   ***\n");
	printf("***    6.search a node                              ***\n");
	printf("***    7.reverse the linked list                    ***\n");
	printf("***    8.judge whether the linked list is looped    ***\n");
	printf("***    9.exit                                       ***\n");
	printf("*******************************************************\n");
	printf("input your command:");
}

int main()
{
	ElemType insert_e,del_e,search_e;
	int option;
	LinkedList head=NULL;
	//进入操作界面 
	label:
	covers();
	scanf("%d",&option);
	while(option<1||option>9)
	{
		system("cls");
		covers();
		printf("(wrong command)");
		scanf("%d",&option);
	}
	switch(option)     //根据用户指令执行不同操作 
	{
		case 1://initialize an empty linked list 
			{
				if(InitList(&head)==SUCCESS) printf("successfully creat an empty Linked list.\n");//判断链表是否初始化成功 
				else printf("failed to creat.\n");
				break;
			}
		case 2://destroy a linked list 
			{
				DestroyList(&head);
				printf("successfully destroy Linked list.\n");
				break;
			}
		case 3://insert a node 
			{
				LNode *q=(LNode *)malloc(sizeof(LNode));          //创建新结点 
				printf("input the data of inserted node:");
				scanf("%d",&insert_e);
				q->data=insert_e;
				q->next=NULL;
				if(InsertList(head, q)==ERROR) printf("failed to insert.\n");
				break;
			}
		case 4://delete a node 
			{
				printf("input the data of deleted node:");
				scanf("%d",&del_e);
				DeleteList(head, &del_e);
				break;
			}
		case 5://traverse the linked list 
			{
				TraverseList(head,visit);
				break;
			}
		case 6://search a node  
			{
				printf("input the data of node to search:");
				scanf("%d",&search_e);
				SearchList(head,search_e);
				break;
			}
		case 7://reverse the linked list 
			{
				if(head==NULL||head->next==NULL) printf("Linked list can not be reversed.\n");
				else if(ReverseList(&head)==SUCCESS) printf("successfully reverse.\n");
				else printf("failed to reverse.\n");
				break;
			}
		case 8://judge whether the linked list is looped
			{
				if(IsLoopList(head)==SUCCESS) printf("is looplist.\n");
				else printf("is not looplist.\n");
				break;
			}
		case 9:return 0;//exit
	}
	printf("input 0 to return covers:");
	scanf("%d",&option);
	while(option!=0)
	{
		printf("input 0 to return covers:(wrong command)");
		scanf("%d",&option);
	}
	system("cls");
	//回到操作界面 
	goto label;
	return 0;
}
