#include "duLinkedList.h"
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
	printf("***    3.insert a node at first                     ***\n");
	printf("***    4.insert a node at last                      ***\n");
	printf("***    5.delete a node                              ***\n");
	printf("***    6.traverse the linked list                   ***\n");
	printf("***    7.exit                                       ***\n");
	printf("*******************************************************\n");
	printf("input your command:");
}

int main()
{
	ElemType insert_e,del_e,search_e;
	DuLNode *q;
	int option;
	DuLinkedList head=NULL;
	//进入操作界面 
	label:
	covers();
	scanf("%d",&option);
	while(option<1||option>7)
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
				if(InitList_DuL(&head)==SUCCESS) printf("successfully creat an empty Linked list.\n");////判断链表是否初始化成功 
				else printf("failed to creat.\n");
				break;
			}
		case 2://destroy a linked list 
			{
				DestroyList_DuL(&head);
				printf("successfully destroy Linked list.\n");
				break;
			}
		case 3://insert a node at first  
			{
				q=(DuLNode *)malloc(sizeof(DuLNode));          //创建新结点
				printf("input the data of inserted node:");
				scanf("%d",&insert_e);
				q->data=insert_e;
				q->next=NULL;
				q->prior=NULL;
				if(InsertBeforeList_DuL(head, q)==ERROR) printf("failed to insert.\n");
				break;
			}
		case 4://insert a node at last 
			{
				q=(DuLNode *)malloc(sizeof(DuLNode));          //创建新结点
				printf("input the data of inserted node:");
				scanf("%d",&insert_e);
				q->data=insert_e;
				q->next=NULL;
				q->prior=NULL;
				if(InsertAfterList_DuL(head, q)==ERROR) printf("failed to insert.\n");
				break;
			}
		case 5://delete a node 
			{
				printf("input the data of deleted node:");
				scanf("%d",&del_e);
				DeleteList_DuL(head, &del_e);
				break;
			}
		case 6://traverse the linked list 
			{
				TraverseList_DuL(head,visit);
				break;
			}
		case 7:return 0;//exit
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
