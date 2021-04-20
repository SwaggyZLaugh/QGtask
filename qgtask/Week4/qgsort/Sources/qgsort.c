#include "qgsort.h"
#include <stdio.h>
#include <stdlib.h>
extern int a_1[N3+1];
/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序算法
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int *a,int n)
{
	int i,j;
	for(i=2;i<=n;i++)
	{
		if(a[i]<a[i-1])
		{
			a[0]=a[i];                              //用a[0]记录a[i] 
			for(j=i-1;a[j]>a[0];j--) a[j+1]=a[j];   //将比a[0]大的元素全部后移 
			a[j+1]=a[0];                            //将a[0]插入到a[j+1] 
		}
	}
}


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序（合并数组）
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
	int i,j,k;
	//将temp[begin,...,mid]和temp[mid+1,...,end]根据每个元素大小合并到数组a
	for(i=mid+1,j=begin;begin<=mid&&i<=end;j++) 
	{
		if(temp[begin]<temp[i]) a[j]=temp[begin++];
		else a[j]=temp[i++];
	}
	//将剩余元素放到数组a末尾 
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
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int *a,int begin,int end,int *temp)
{
	int mid;
	if(begin==end) a[begin]=temp[begin];
	else
	{
		//平分数组temp为temp[begin,...,mid]和temp[mid+1,...,end] 
		mid=(begin+end)/2;
		//递归调用MergeSort将temp[begin,...,mid]和temp[mid+1,...,end]归并为a_1[begin,...,mid]和a_1[mid+1,...,end]
		MergeSort(a_1,begin,mid,temp);
		MergeSort(a_1,mid+1,end,temp);
		//将数组a_1[begin,...,mid]和a_1[mid+1,...,end]归并到a 
		MergeArray(a,begin,mid,end,a_1);
	}
}


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int *a, int begin, int end)
{
	int p;
	if(begin<end)
	{
		//拆分数组a获得快速排序数组的枢轴的值p
		p=Partition(a,begin,end);
		//对p之前的子数组和p之后的子数组递归排序 
		QuickSort_Recursion(a,begin,p-1);
		QuickSort_Recursion(a,p+1,end);
	}
}


/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int *a,int size);


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int *a, int begin, int end)
{
	int p,mid,t;
	mid=begin+(end-begin)/2;
	//使a[mid]<a[begin]<a[end]，并将中间值a[begin]赋给p 
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
	a[0]=p;            //用a[0]记录p
	while(begin<end)
	{
		//将比p小的数放在数组前面 
		while(begin<end&&a[end]>=p) end--;
		a[begin]=a[end];
		//将比p大的数放在数组后面 
		while(begin<end&&a[begin]<=p) begin++;
		a[end]=a[begin];
	}
	a[begin]=a[0];
	return begin;
}


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int *a, int size , int max)
{
	int *count=(int *)malloc((max+1)*sizeof(int));
	int i,j=1;
	for(i=0;i<=max;i++) count[i]=0;
	//用count[i]记录i的个数 
	for(i=1;i<=size;i++) count[a[i]]++;
	//用count[i]记录排序后i的末位置
	for(i=1;i<=max;i++) count[i]+=count[i-1];
	for(i=0;i<=max;i++)
	{
		//j至count[i]的元素都为i 
		while(j<=count[i])
		{
			a[j++]=i;
		}
	}
	
}


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
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
		//统计当前位数为0~9的数的个数 
		for(i=1;i<=size;i++) count[(a[i]/k)%10]++;
		//累加到count 
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
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
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
