#include "AQueue.h" 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 *  @name        : void InitAQueue(AQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitAQueue(AQueue *Q)
{
	int i;
	Q->front=0;
	Q->rear=0;
	Q->length=0;
	for(i=0;i<MAXQUEUE;i++) //����洢�ռ� 
	{
		if(type=='i') Q->data[i]=(void *)malloc(sizeof(int));
		else Q->data[i]=(void *)malloc(20*sizeof(char));
	}
}


/**
 *  @name        : void DestoryAQueue(AQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void DestoryAQueue(AQueue *Q)
{
	free(Q);//�ͷ��ڴ� 
}


/**
 *  @name        : Status IsFullAQueue(const AQueue *Q)
 *    @description : �������Ƿ�����
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsFullAQueue(const AQueue *Q)
{
	if(Q->length==MAXQUEUE) return TRUE;
	return FALSE;
}


/**
 *  @name        : Status IsEmptyAQueue(const AQueue *Q)
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
 *  @notice      : None
 */
Status IsEmptyAQueue(const AQueue *Q)
{
	if(Q->length==0) return TRUE;
	return FALSE;
}


/**
 *  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
 *    @description : �鿴��ͷԪ��
 *    @param         Q ����ָ��Q�����Ԫ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
 */
Status GetHeadAQueue(AQueue *Q, void *e1)
{
	if(IsEmptyAQueue(Q)) return FALSE;
	e=Q->data[Q->front];
	return TRUE;
}


/**
 *  @name        : int LengthAQueue(AQueue *Q)
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : ���г���count
 *  @notice      : None
 */
int LengthAQueue(AQueue *Q)	
{
	return Q->length;
}


/**
 *  @name        : Status EnAQueue(AQueue *Q, void *data)
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ����˻�Ϊ��
 */
Status EnAQueue(AQueue *Q, void *data)
{
	if(IsFullAQueue(Q)) return FALSE;
	//��� 
	if(type=='i') memcpy(Q->data[Q->rear],data,sizeof(int));
	else memcpy(Q->data[Q->rear],data,20*sizeof(char));
	Q->rear=(Q->rear+1)%MAXQUEUE;
	Q->length++;
	return TRUE;
}


/**
 *  @name        : Status DeAQueue(AQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
Status DeAQueue(AQueue *Q)
{
	if(IsEmptyAQueue(Q)) return FALSE;
	//���� 
	if(type=='i') Q->data[Q->front]=(void *)malloc(sizeof(int));
	else Q->data[Q->front]=(void *)malloc(20*sizeof(char));
	Q->front=(Q->front+1)%MAXQUEUE;
	Q->length--;
}


/**
 *  @name        : void ClearAQueue(Queue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
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
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
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
 *    @description : ��������
 *    @param         q ָ��q
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
 *    @description : ��������Ƿ�Ϊ���� 
 *    @param         s ָ��s
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

