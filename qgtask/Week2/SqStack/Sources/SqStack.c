#include "SqStack.h"
#include <stdio.h>
#include <stdlib.h>

Status initStack(SqStack *s,int sizes)//��ʼ��ջ
{
	s->elem=(ElemType *)malloc(sizes*sizeof(ElemType));//�����¿ռ� 
	if(s->elem==NULL) return ERROR;
	s->size=sizes;
	return SUCCESS;
}

Status isEmptyStack(SqStack *s)//�ж�ջ�Ƿ�Ϊ��
{
	if(s->top==-1) return SUCCESS;
	return ERROR;
}

Status getTopStack(SqStack *s,ElemType *e)//�õ�ջ��Ԫ��
{
	if(isEmptyStack(s)==SUCCESS)//�ж�ջ�Ƿ�Ϊ�� 
	{
		printf("ջΪ��\n");
		return ERROR;
	}
	*e=s->elem[s->top]; 
	return SUCCESS;
}

Status clearStack(SqStack *s)//���ջ
{
	if(isEmptyStack(s)==SUCCESS)//�ж�ջ�Ƿ�Ϊ�� 
	{
		printf("ջΪ��\n");
		return ERROR;
	}
	s->top=-1;
	return SUCCESS;
}

Status destroyStack(SqStack *s)//����ջ
{
	free(s->elem);//�ͷ�����洢�ռ� 
	s->elem=NULL;
	if(s->elem==NULL) return SUCCESS;
	else return ERROR;
}

Status stackLength(SqStack *s,int *length)//���ջ����
{
	*length=1+s->top;
	return SUCCESS;
}

Status pushStack(SqStack *s,ElemType data)//��ջ
{
	if(s->top+1==s->size) return ERROR;
	s->elem[++(s->top)]=data;
	return SUCCESS;
}

Status popStack(SqStack *s,ElemType *data)//��ջ
{
	if(isEmptyStack(s)==SUCCESS)//�ж�ջ�Ƿ�Ϊ�� 
	{
		printf("ջΪ��\n");
		return ERROR;
	}
	*data=s->elem[(s->top)--];
	return SUCCESS;
}
