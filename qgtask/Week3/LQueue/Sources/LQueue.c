#include "LQueue.h"
#include <stdio.h>
#include <stdlib.h>

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
	Q->length=0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
	Node *p;
	while(Q->front!=NULL)//释放内存 
	{
		p=Q->front;
		Q->front=Q->front->next;
		free(p);
	}
	free(Q);
	Q=NULL;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q->length==0) return TRUE;
	return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue *Q, void *e1)
{
	if(IsEmptyLQueue(Q)) return FALSE;
	e=Q->front->data;
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q)
{
	return Q->length;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue *Q, void *data)
{
	//入队 
	if(type=='i') memcpy(Q->rear->data,data,sizeof(int));
	else memcpy(Q->rear->data,data,20*sizeof(char));
	Q->length++;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
	Node *p;
	if(IsEmptyLQueue(Q)) return FALSE;
	//出队 
	p=Q->front;
	Q->front=Q->front->next;
	Q->length--;
	free(p);
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
	Node *p;
	while(Q->front!=NULL)
	{
		p=Q->front;
		Q->front=Q->front->next;
		free(p);
	}
	Q->front=NULL;
	Q->rear=NULL;
	Q->length=0;
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
	Node *p=Q->front;
	if(IsEmptyLQueue(Q)) return FALSE;
	while(p!=NULL)
	{
		foo(p->data);
		p=p->next;
	}
	return TRUE;
}


/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
void LPrint(void *q)
{
	int *i;
	char *s;
	if(type=='i')
	{
		i=q;
		printf("%d\n",*i);
	}
	else
	{
		s=q;
		printf("%s\n",s);
	}
}


int judgeint(char *s)
{
	int j=0,result=0,tag=1;
	while(s[j])
	{
		if(j==0&&s[j]=='-') tag=0;
		if(s[j]>=48&&s[j]<=57) result=result*10+s[j]-48;
		else return 0;
		j++;
	}
	if(tag=0) result=0-result;
	return result;
}
