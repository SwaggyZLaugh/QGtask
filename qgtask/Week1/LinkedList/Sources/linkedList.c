#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
	LinkedList L1;                        //创建头节点L1 
	L1=(LinkedList)malloc(sizeof(LNode)); //申请存储空间 
	if(L1==NULL)                          //判断是否申请成功 
	{
		return ERROR;
	}
	L1->next=NULL;
	*L=L1;                                 //将L1的地址给到head头节点
	return SUCCESS;
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
	LinkedList p;
	while(*L!=NULL)                 //遍历链表，释放每个节点 
	{
		p=*L;
		*L=(*L)->next;
		free(p);
	}
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q) {
	if(p==NULL||q==NULL)
	{
		return ERROR;
	}
	while(p->next!=NULL) p=p->next;                 //将p移动到链表末尾并将q与p连接 
	p->next=q;
	if(p->next=q) printf("successfully insert.\n");
	return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
	LNode *q;
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
	q->next=p->next;
	free(p);
	printf("successfully delete.\n");
	return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	LinkedList p;
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

/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {
	LinkedList p;
	int num=1;
	p=L->next;
	while(p!=NULL&&p->data!=e)                      //寻找第一个data为e的结点 
	{
		p=p->next;
		num++;
	}
	if(p==NULL)
	{
		printf("e is not in the Linked list\n");
		return ERROR;
	}
	else
	{
		printf("the first node with data e is the %d node\n",num);
		return SUCCESS;
	}
}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
	LinkedList p;
	LinkedList s;
	int tag=1;
	p=(*L)->next;
	s=*L;                             //s记录反转后的第一个结点的下一个结点 
	while(p!=NULL)                    //p指向反转后的第一个结点并不断后移直至NULL 
	{
		(*L)->next=p;                 //将L->next不断指向往后移的p所指的反转后的第一个结点 
		p=p->next;                    //p向后移记录当前反转后的头节点的下一个结点 
		if(tag==1)                    //原链表的第一个结点反转后应为最后一个结点，则其的next指向NULL 
		{
			(*L)->next->next=NULL;
			tag=0;
		}
		else (*L)->next->next=s;      // 将第一个结点的next指向其反转前的前一个结点，是链表顺序导致 
		s=(*L)->next;                 //将s指向反转后的第一个结点 
	}
	return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
	LinkedList f,s;
	f=L;
	s=L;
	while(f!=NULL&&f->next!=NULL)              //快慢指针判断链表是否循环 
	{
		f=f->next->next;
		s=s->next;
		if(s==f)
		{
			return SUCCESS;
		}
	}
	return ERROR;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {

}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {

}
