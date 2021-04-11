#include "LinkStack.h"
#include <stdio.h>
#include <stdlib.h>

Status initLStack(LinkStack *s)//³õÊ¼»¯Õ»
{
	s->count=0;
	s->top=NULL;
	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
{
	if(s->top==NULL) return SUCCESS;
	return ERROR;
}

Status getTopLStack(LinkStack *s,ElemType *e)//µÃµ½Õ»¶¥ÔªËØ
{
	if(isEmptyLStack(s)==SUCCESS)
	{
		printf("Õ»Îª¿Õ\n");
		return ERROR;
	}
	*e=s->top->data;
	return SUCCESS;
}
Status clearLStack(LinkStack *s)//Çå¿ÕÕ»
{
	LinkStackPtr t;
	if(isEmptyLStack(s)==SUCCESS)
	{
		printf("Õ»Îª¿Õ\n");
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

Status destroyLStack(LinkStack *s)//Ïú»ÙÕ»
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

Status LStackLength(LinkStack *s,int *length)//¼ì²âÕ»³¤¶È
{
	*length=s->count;
	return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data)//ÈëÕ»
{
	LinkStackPtr p;
	p=(LinkStackPtr)malloc(sizeof(StackNode));
	p->data=data;
	p->next=s->top;
	s->top=p;
	(s->count)++;
	return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data)//³öÕ»
{
	LinkStackPtr t;
	if(isEmptyLStack(s)==SUCCESS)
	{
		printf("Õ»Îª¿Õ\n");
		return ERROR;
	}
	t=s->top;
	s->top=s->top->next;
	*data=t->data;
	free(t);
	(s->count)--;
	return SUCCESS;
}
