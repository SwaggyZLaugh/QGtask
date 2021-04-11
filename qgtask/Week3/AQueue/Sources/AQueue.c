#include "AQueue.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q)
{
	int i;
	Q->front=0;
	Q->rear=0;
	Q->length=0;
	for(i=0;i<MAXQUEUE;i++) //申请存储空间 
	{
		if(type=='i') Q->data[i]=(void *)malloc(sizeof(int));
		else Q->data[i]=(void *)malloc(20*sizeof(char));
	}
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q)
{
	free(Q);//释放内存 
}


/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : 检查队列是否已满
 *    @param         Q 队列指针Q
 *    @return         : 满-TRUE; 未满-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q)
{
	if(Q->length==MAXQUEUE) return TRUE;
	return FALSE;
}


/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q)
{
	if(Q->length==0) return TRUE;
	return FALSE;
}


/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q 队列指针Q，存放元素e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadAQueue(AQueue *Q, void *e1)
{
	if(IsEmptyAQueue(Q)) return FALSE;
	e=Q->data[Q->front];
	return TRUE;
}


/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 队列长度count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)	
{
	return Q->length;
}


/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否满了或为空
 */
Status EnAQueue(AQueue *Q, void *data)
{
	if(IsFullAQueue(Q)) return FALSE;
	//入队 
	if(type=='i') memcpy(Q->data[Q->rear],data,sizeof(int));
	else memcpy(Q->data[Q->rear],data,20*sizeof(char));
	Q->rear=(Q->rear+1)%MAXQUEUE;
	Q->length++;
	return TRUE;
}


/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q)
{
	if(IsEmptyAQueue(Q)) return FALSE;
	//出队 
	if(type=='i') Q->data[Q->front]=(void *)malloc(sizeof(int));
	else Q->data[Q->front]=(void *)malloc(20*sizeof(char));
	Q->front=(Q->front+1)%MAXQUEUE;
	Q->length--;
}


/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearAQueue(AQueue *Q)
{
	int i;
	Q->front=0;
	Q->rear=0;
	Q->length=0;
	for(i=0;i<MAXQUEUE;i++) 
	{
		if(type=='i') Q->data[i]=(void *)malloc(sizeof(int));
		else Q->data[i]=(void *)malloc(20*sizeof(char));
	}
}


/**
 *  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{
	int i=Q->front;
	if(IsEmptyAQueue(Q)) return FALSE;
	while(i!=Q->rear)
	{
		foo(Q->data[i]);
		i=(i+1)%MAXQUEUE;
	}
	return TRUE;
}


/**
 *  @name        : void APrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 *  @notice      : None
 */
void APrint(void *q)
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


/**
 *  @name        :  void judgeint(char *s)
 *    @description : 检测输入是否为整数 
 *    @param         s 指针s
 *  @notice      : None
 */
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

