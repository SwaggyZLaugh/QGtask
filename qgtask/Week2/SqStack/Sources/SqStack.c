#include "SqStack.h"
#include <stdio.h>
#include <stdlib.h>

Status initStack(SqStack *s,int sizes)//³õÊ¼»¯Õ»
{
	s->elem=(ElemType *)malloc(sizes*sizeof(ElemType));//¿ª±ÙÐÂ¿Õ¼ä 
	if(s->elem==NULL) return ERROR;
	s->size=sizes;
	return SUCCESS;
}

Status isEmptyStack(SqStack *s)//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
{
	if(s->top==-1) return SUCCESS;
	return ERROR;
}

Status getTopStack(SqStack *s,ElemType *e)//µÃµ½Õ»¶¥ÔªËØ
{
	if(isEmptyStack(s)==SUCCESS)//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ 
	{
		printf("Õ»Îª¿Õ\n");
		return ERROR;
	}
	*e=s->elem[s->top]; 
	return SUCCESS;
}

Status clearStack(SqStack *s)//Çå¿ÕÕ»
{
	if(isEmptyStack(s)==SUCCESS)//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ 
	{
		printf("Õ»Îª¿Õ\n");
		return ERROR;
	}
	s->top=-1;
	return SUCCESS;
}

Status destroyStack(SqStack *s)//Ïú»ÙÕ»
{
	free(s->elem);//ÊÍ·ÅÊý×é´æ´¢¿Õ¼ä 
	s->elem=NULL;
	if(s->elem==NULL) return SUCCESS;
	else return ERROR;
}

Status stackLength(SqStack *s,int *length)//¼ì²âÕ»³¤¶È
{
	*length=1+s->top;
	return SUCCESS;
}

Status pushStack(SqStack *s,ElemType data)//ÈëÕ»
{
	if(s->top+1==s->size) return ERROR;
	s->elem[++(s->top)]=data;
	return SUCCESS;
}

Status popStack(SqStack *s,ElemType *data)//³öÕ»
{
	if(isEmptyStack(s)==SUCCESS)//ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ 
	{
		printf("Õ»Îª¿Õ\n");
		return ERROR;
	}
	*data=s->elem[(s->top)--];
	return SUCCESS;
}
