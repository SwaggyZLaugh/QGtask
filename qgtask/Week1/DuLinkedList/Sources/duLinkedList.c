#include "duLinkedList.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
	DuLinkedList L1;                         //创建头节点L1
	L1=(DuLinkedList)malloc(sizeof(DuLNode));//申请存储空间
	if(L1==NULL)                             //判断是否申请成功 
	{
		return ERROR;
	}
	L1->next=NULL;
	L1->prior=NULL;
	*L=L1;                                    //将L1的地址给到head头节点
	return SUCCESS;
}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
	DuLinkedList p;
	while(*L!=NULL)                 //遍历链表，释放每个节点
	{
		p=*L;
		*L=(*L)->next;
		free(p);
	}
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
	if(p==NULL||q==NULL)
	{
		return ERROR;
	}
	if(p->next==NULL)                  //如果只有头节点，将q连接至头节点后 
	{
		p->next=q;
		q->prior=p;
	}
	else                               //连接q至头节点后 
	{
		p->next->prior=q;
		q->next=p->next;
		p->next=q;
		q->prior=p;
	}
	
	if(p->next=q) printf("successfully insert.\n");
	return SUCCESS;
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {
	DuLNode *t=p;
	if(t==NULL||q==NULL)
	{
		return ERROR;
	}
	while(t->next!=NULL) t=t->next;                 //将p移动到链表末尾并将q与p连接
	t->next=q;
	q->prior=t;
	if(t->next=q) printf("successfully insert.\n");
	return SUCCESS;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
	DuLNode *q;
	if(p==NULL)
	{
		printf("empty Linked list.\n");
		return ERROR;
	}
	while(p->data!=*e)                                      //删除第一个data为*e的结点
	{
		q=p;
		p=p->next;
		if(p==NULL)
		{
			printf("data is not in the Linked list.\n");    //若p走到NULL仍未退出while则不存在data为*e的结点
			return ERROR;
		}
	}
	p->next->prior=q;
	q->next=p->next;
	free(p);
	printf("successfully delete.\n");
	return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	DuLinkedList p;
	p=L->next;
	if(p==NULL)
	{
		printf("empty Linked list.\n");
		return;
	}
	while(p!=NULL)
	{
		visit(p->data);
		p=p->next;
	}
	printf("\n");
}
