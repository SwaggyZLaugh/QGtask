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
	LinkedList L1;                        //����ͷ�ڵ�L1 
	L1=(LinkedList)malloc(sizeof(LNode)); //����洢�ռ� 
	if(L1==NULL)                          //�ж��Ƿ�����ɹ� 
	{
		return ERROR;
	}
	L1->next=NULL;
	*L=L1;                                 //��L1�ĵ�ַ����headͷ�ڵ�
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
	while(*L!=NULL)                 //���������ͷ�ÿ���ڵ� 
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
	while(p->next!=NULL) p=p->next;                 //��p�ƶ�������ĩβ����q��p���� 
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
	while(p->data!=*e)                                      //ɾ����һ��dataΪ*e�Ľ�� 
	{
		q=p;
		p=p->next;
		if(p==NULL)
		{
			printf("data is not in the Linked list.\n");    //��p�ߵ�NULL��δ�˳�while�򲻴���dataΪ*e�Ľ�� 
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
	while(p!=NULL&&p->data!=e)                      //Ѱ�ҵ�һ��dataΪe�Ľ�� 
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
	s=*L;                             //s��¼��ת��ĵ�һ��������һ����� 
	while(p!=NULL)                    //pָ��ת��ĵ�һ����㲢���Ϻ���ֱ��NULL 
	{
		(*L)->next=p;                 //��L->next����ָ�������Ƶ�p��ָ�ķ�ת��ĵ�һ����� 
		p=p->next;                    //p����Ƽ�¼��ǰ��ת���ͷ�ڵ����һ����� 
		if(tag==1)                    //ԭ����ĵ�һ����㷴ת��ӦΪ���һ����㣬�����nextָ��NULL 
		{
			(*L)->next->next=NULL;
			tag=0;
		}
		else (*L)->next->next=s;      // ����һ������nextָ���䷴תǰ��ǰһ����㣬������˳���� 
		s=(*L)->next;                 //��sָ��ת��ĵ�һ����� 
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
	while(f!=NULL&&f->next!=NULL)              //����ָ���ж������Ƿ�ѭ�� 
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
