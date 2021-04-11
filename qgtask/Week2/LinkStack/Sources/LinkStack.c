#include "LinkStack.h"
#include <stdio.h>
#include <stdlib.h>

Status initLStack(LinkStack *s)//��ʼ��ջ
{
	s->count=0;
	s->top=NULL;
	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)//�ж�ջ�Ƿ�Ϊ��
{
	if(s->top==NULL) return SUCCESS;
	return ERROR;
}

Status getTopLStack(LinkStack *s,ElemType *e)//�õ�ջ��Ԫ��
{
	if(isEmptyLStack(s)==SUCCESS)
	{
		printf("ջΪ��\n");
		return ERROR;
	}
	*e=s->top->data;
	return SUCCESS;
}
Status clearLStack(LinkStack *s)//���ջ
{
	LinkStackPtr t;
	if(isEmptyLStack(s)==SUCCESS)
	{
		printf("ջΪ��\n");
		return ERROR;
	}
	while(s->top!=NULL)
	{
		t=s->top;
		s->top=s->top->next;
		free(t);
		(s->count)--;
	} 
	return SUCCESS;
}

Status destroyLStack(LinkStack *s)//����ջ
{
	
	LinkStackPtr t;
	while(s->top!=NULL)
	{
		t=s->top;
		s->top=s->top->next;
		free(t);
		(s->count)--;
	}
	s=NULL;
	if(s==NULL) return SUCCESS;
	else return ERROR;
}

Status LStackLength(LinkStack *s,int *length)//���ջ����
{
	*length=s->count;
	return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data)//��ջ
{
	LinkStackPtr p;
	p=(LinkStackPtr)malloc(sizeof(StackNode));
	p->data=data;
	p->next=s->top;
	s->top=p;
	(s->count)++;
	return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data)//��ջ
{
	LinkStackPtr t;
	if(isEmptyLStack(s)==SUCCESS)
	{
		printf("ջΪ��\n");
		return ERROR;
	}
	t=s->top;
	s->top=s->top->next;
	*data=t->data;
	free(t);
	(s->count)--;
	return SUCCESS;
}
