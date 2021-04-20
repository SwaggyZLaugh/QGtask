#include "qgsort.h"
#include <stdio.h>
#include <stdlib.h>
extern int a_1[N3+1];
/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : ���������㷨
 *  @param       : ����ָ�� a, ���鳤�� n
 */
void insertSort(int *a,int n)
{
	int i,j;
	for(i=2;i<=n;i++)
	{
		if(a[i]<a[i-1])
		{
			a[0]=a[i];                              //��a[0]��¼a[i] 
			for(j=i-1;a[j]>a[0];j--) a[j+1]=a[j];   //����a[0]���Ԫ��ȫ������ 
			a[j+1]=a[0];                            //��a[0]���뵽a[j+1] 
		}
	}
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : �鲢���򣨺ϲ����飩
 *  @param       : ����ָ��a���������begin�������е�mid�������յ�end����������ָ��temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
	int i,j,k;
	//��temp[begin,...,mid]��temp[mid+1,...,end]����ÿ��Ԫ�ش�С�ϲ�������a
	for(i=mid+1,j=begin;begin<=mid&&i<=end;j++) 
	{
		if(temp[begin]<temp[i]) a[j]=temp[begin++];
		else a[j]=temp[i++];
	}
	//��ʣ��Ԫ�طŵ�����aĩβ 
	if(begin<=mid)
	{
		for(k=0;k<=mid-begin;k++) a[j+k]=temp[begin+k];
	}
	if(i<=end)
	{
		for(k=0;k<=end-i;k++) a[j+k]=temp[i+k];
	}
}


/**
 *  @name        : void MergeSort(int *a,int begin,int end,int *temp);
 *  @description : �鲢����
 *  @param       : ����ָ��a���������begin�������յ�end����������ָ��temp
 */
void MergeSort(int *a,int begin,int end,int *temp)
{
	int mid;
	if(begin==end) a[begin]=temp[begin];
	else
	{
		//ƽ������tempΪtemp[begin,...,mid]��temp[mid+1,...,end] 
		mid=(begin+end)/2;
		//�ݹ����MergeSort��temp[begin,...,mid]��temp[mid+1,...,end]�鲢Ϊa_1[begin,...,mid]��a_1[mid+1,...,end]
		MergeSort(a_1,begin,mid,temp);
		MergeSort(a_1,mid+1,end,temp);
		//������a_1[begin,...,mid]��a_1[mid+1,...,end]�鲢��a 
		MergeArray(a,begin,mid,end,a_1);
	}
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : �������򣨵ݹ�棩
 *  @param       : ����ָ��a���������begin�������յ�end
 */
void QuickSort_Recursion(int *a, int begin, int end)
{
	int p;
	if(begin<end)
	{
		//�������a��ÿ�����������������ֵp
		p=Partition(a,begin,end);
		//��p֮ǰ���������p֮���������ݹ����� 
		QuickSort_Recursion(a,begin,p-1);
		QuickSort_Recursion(a,p+1,end);
	}
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : �������򣨷ǵݹ�棩
 *  @param       : ����ָ��a�����鳤��size
 */
void QuickSort(int *a,int size);


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : �������������ţ�
 *  @param       : ����ָ��a���������begin�������յ�end
 */
int Partition(int *a, int begin, int end)
{
	int p,mid,t;
	mid=begin+(end-begin)/2;
	//ʹa[mid]<a[begin]<a[end]�������м�ֵa[begin]����p 
	if(a[begin]>a[end])
	{
		t=a[end];
		a[end]=a[begin];
		a[begin]=t;
	}
	if(a[mid]>a[end])
	{
		t=a[end];
		a[end]=a[mid];
		a[mid]=t;
	}
	if(a[mid]>a[begin])
	{
		t=a[begin];
		a[begin]=a[mid];
		a[mid]=t;
	}
	p=a[begin];
	a[0]=p;            //��a[0]��¼p
	while(begin<end)
	{
		//����pС������������ǰ�� 
		while(begin<end&&a[end]>=p) end--;
		a[begin]=a[end];
		//����p���������������� 
		while(begin<end&&a[begin]<=p) begin++;
		a[end]=a[begin];
	}
	a[begin]=a[0];
	return begin;
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : ��������
 *  @param       : ����ָ��a�����鳤��size���������ֵmax
 */
void CountSort(int *a, int size , int max)
{
	int *count=(int *)malloc((max+1)*sizeof(int));
	int i,j=1;
	for(i=0;i<=max;i++) count[i]=0;
	//��count[i]��¼i�ĸ��� 
	for(i=1;i<=size;i++) count[a[i]]++;
	//��count[i]��¼�����i��ĩλ��
	for(i=1;i<=max;i++) count[i]+=count[i-1];
	for(i=0;i<=max;i++)
	{
		//j��count[i]��Ԫ�ض�Ϊi 
		while(j<=count[i])
		{
			a[j++]=i;
		}
	}
	
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : ������������
 *  @param       : ����ָ��a�����鳤��size
 */
void RadixCountSort(int *a,int size)
{
	int *temp=(int *)malloc((size+1)*sizeof(int));
	int *count=(int *)malloc(10*sizeof(int));
	int max=a[1],max_l=1;
	int i,t,k=1,l;
	for(i=2;i<=size;i++) max=max>a[i]?max:a[i];
	max/=10;
	while(max!=0)
	{
		max/=10;
		max_l++;
	}
	for(l=1;l<=max_l;l++,k*=10)
	{
		for(i=0;i<10;i++) count[i]=0;
		//ͳ�Ƶ�ǰλ��Ϊ0~9�����ĸ��� 
		for(i=1;i<=size;i++) count[(a[i]/k)%10]++;
		//�ۼӵ�count 
		for(i=1;i<10;i++) count[i]+=count[i-1];
		for(i=size;i>=1;i--)
		{
			t=(a[i]/k)%10;
			temp[count[t]]=a[i];
			count[t]--;
		}
		for(i=1;i<=size;i++) a[i]=temp[i];
	}
	free(temp);
	free(count);
}


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : ��ɫ����
 *  @param       : ����ָ��a��ֻ��0��1��2Ԫ�أ������鳤��size
 */
void ColorSort(int *a,int size)
{
	int begin=1,end=size,i=1,t;
	while(i<=end)
	{
		switch(a[i])
		{
			case 0:
				{
					t=a[i];
					a[i]=a[begin];
					a[begin]=t;
					begin++;
					break;
				}
			case 1:
				{
					i++;
					break;
				}
			case 2:
				{
					t=a[i];
					a[i]=a[end];
					a[end]=t;
					end--;
					break;
				}
		}
	}
}
