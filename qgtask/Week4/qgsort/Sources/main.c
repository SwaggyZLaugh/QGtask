#include "qgsort.h"
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

//操作界面 
void covers() 
{
	printf("***************************************************\n");
	printf("***    1.检测插入排序算法运行时间               ***\n");
	printf("***    2.检测归并排序算法运行时间               ***\n");
	printf("***    3.检测快速排序算法（递归版）运行时间     ***\n");
	printf("***    4.检测计数排序算法运行时间               ***\n");
	printf("***    5.检测基数计数排序算法运行时间           ***\n");
	printf("***    6.检测颜色排序算法运行时间               ***\n");
	printf("***    7.结束操作                               ***\n");
	printf("***************************************************\n");
	printf("输入你要执行的操作:");
}
int a_1[N3+1];
int main()
{
	FILE *fp;
	char option[10];
	int op,i,N,max;
	int a[N3+1];
	srand((unsigned)time(NULL));
	label:
	system("cls");
	covers();
	scanf("%s",option);
	//检测输入指令 
	while(strcmp(option,"1")!=0&&strcmp(option,"2")!=0&&strcmp(option,"3")!=0&&strcmp(option,"4")!=0&&strcmp(option,"5")!=0&&strcmp(option,"6")!=0&&strcmp(option,"7")!=0)
	{
		system("cls");
		covers();
		printf("(错误指令请重新输入)");
		scanf("%s",option);
	}
	op=*option-48;
	system("cls");
	switch(op)
	{
		case 1://插入排序 
			{
				printf("选择所要检测数组大小:1:10000  2:50000  3:200000\n");
				scanf("%s",option);
				while(strcmp(option,"1")!=0&&strcmp(option,"2")!=0&&strcmp(option,"3")!=0)
				{
					system("cls");
					printf("选择所要检测数组大小:1:10000  2:50000  3:200000(错误指令请重新输入)\n");
					scanf("%s",option);
				}
				op=*option-48;
				//根据选择生成数组 
				switch (op)
				{
					case 1:
						{
							N=N1;
							for(i=1;i<=N1;i++) a[i]=rand()%MAX;
							break;
						}
					case 2:
						{
							N=N2;
							for(i=1;i<=N2;i++) a[i]=rand()%MAX;
							break;
						}
					case 3:
						{
							N=N3;
							for(i=1;i<=N3;i++) a[i]=rand()%MAX;
							break;
						}
				}
				clock_t start = clock();
				{
					insertSort(a,N);
				}
				clock_t end = clock();
				printf("Running time is: %d  ms\n", end - start);
				printf("排序好的前十个数为：\n");
				for(i=1;i<=10;i++) printf("%d ",a[i]);
				break;
			}
		case 2://归并排序
			{
				printf("选择所要检测数组大小:1:10000  2:50000  3:200000\n");
				scanf("%s",option);
				while(strcmp(option,"1")!=0&&strcmp(option,"2")!=0&&strcmp(option,"3")!=0)
				{
					system("cls");
					printf("选择所要检测数组大小:1:10000  2:50000  3:200000(错误指令请重新输入)\n");
					scanf("%s",option);
				}
				op=*option-48;
				//根据选择生成数组 
				switch (op)
				{
					case 1:
						{
							N=N1;
							for(i=1;i<=N1;i++) a[i]=rand()%MAX+1;
							break;
						}
					case 2:
						{
							N=N2;
							for(i=1;i<=N2;i++) a[i]=rand()%MAX+1;
							break;
						}
					case 3:
						{
							N=N3;
							for(i=1;i<=N3;i++) a[i]=rand()%MAX+1;
							break;
						}
				}
				clock_t start = clock();
				{
					MergeSort(a,1,N,a);
				}
				clock_t end = clock();
				printf("Running time is: %d  ms\n", end - start);
				printf("排序好的前十个数为：\n");
				for(i=1;i<=10;i++) printf("%d ",a[i]);
				break;
			}
		case 3://快速排序（递归版） 
			{
				printf("选择所要检测数组大小:1:10000  2:50000  3:200000\n");
				scanf("%s",option);
				while(strcmp(option,"1")!=0&&strcmp(option,"2")!=0&&strcmp(option,"3")!=0)
				{
					system("cls");
					printf("选择所要检测数组大小:1:10000  2:50000  3:200000(错误指令请重新输入)\n");
					scanf("%s",option);
				}
				op=*option-48;
				//根据选择生成数组 
				switch (op)
				{
					case 1:
						{
							N=N1;
							for(i=1;i<=N1;i++) a[i]=rand()%MAX;
							break;
						}
					case 2:
						{
							N=N2;
							for(i=1;i<=N2;i++) a[i]=rand()%MAX;
							break;
						}
					case 3:
						{
							N=N3;
							for(i=1;i<=N3;i++) a[i]=rand()%MAX;
							break;
						}
				}
				clock_t start = clock();
				{
					QuickSort_Recursion(a,1,N);
				}
				clock_t end = clock();
				printf("Running time is: %d  ms\n", end - start);
				printf("排序好的前十个数为：\n");
				for(i=1;i<=10;i++) printf("%d ",a[i]);
				break;
			}
		case 4://计数排序
			{
				printf("选择所要检测数组大小:1:10000  2:50000  3:200000\n");
				scanf("%s",option);
				while(strcmp(option,"1")!=0&&strcmp(option,"2")!=0&&strcmp(option,"3")!=0)
				{
					system("cls");
					printf("选择所要检测数组大小:1:10000  2:50000  3:200000(错误指令请重新输入)\n");
					scanf("%s",option);
				}
				op=*option-48;
				//根据选择生成数组 
				switch (op)
				{
					case 1:
						{
							N=N1;
							for(i=1;i<=N1;i++) a[i]=rand()%MAX;
							break;
						}
					case 2:
						{
							N=N2;
							for(i=1;i<=N2;i++) a[i]=rand()%MAX;
							break;
						}
					case 3:
						{
							N=N3;
							for(i=1;i<=N3;i++) a[i]=rand()%MAX;
							break;
						}
				}
				max=a[1];
				for(i=2;a[i];i++) max=max>a[i]?max:a[i];
				clock_t start = clock();
				{
					CountSort(a,N,max);
				}
				clock_t end = clock();
				printf("Running time is: %d  ms\n", end - start);
				printf("排序好的前十个数为：\n");
				for(i=1;i<=10;i++) printf("%d ",a[i]);
				break;
			}
		case 5://基数计数排序
			{
				printf("选择所要检测数组大小:1:10000  2:50000  3:200000\n");
				scanf("%s",option);
				while(strcmp(option,"1")!=0&&strcmp(option,"2")!=0&&strcmp(option,"3")!=0)
				{
					system("cls");
					printf("选择所要检测数组大小:1:10000  2:50000  3:200000(错误指令请重新输入)\n");
					scanf("%s",option);
				}
				op=*option-48;
				//根据选择生成数组 
				switch (op)
				{
					case 1:
						{
							N=N1;
							for(i=1;i<=N1;i++) a[i]=rand()%MAX;
							break;
						}
					case 2:
						{
							N=N2;
							for(i=1;i<=N2;i++) a[i]=rand()%MAX;
							break;
						}
					case 3:
						{
							N=N3;
							for(i=1;i<=N3;i++) a[i]=rand()%MAX;
							break;
						}
				}
				clock_t start = clock();
				{
					RadixCountSort(a,N);
				}
				clock_t end = clock();
				printf("Running time is: %d  ms\n", end - start);
				printf("排序好的前十个数为：\n");
				for(i=1;i<=10;i++) printf("%d ",a[i]);
				break;
			}
		case 6://颜色排序
			{
				printf("选择所要检测数组大小:1:10000  2:50000  3:200000\n");
				scanf("%s",option);
				while(strcmp(option,"1")!=0&&strcmp(option,"2")!=0&&strcmp(option,"3")!=0)
				{
					system("cls");
					printf("选择所要检测数组大小:1:10000  2:50000  3:200000(错误指令请重新输入)\n");
					scanf("%s",option);
				}
				op=*option-48;
				//根据选择生成数组 
				switch (op)
				{
					case 1:
						{
							N=N1;
							for(i=1;i<=N1;i++) a[i]=rand()%3;
							break;
						}
					case 2:
						{
							N=N2;
							for(i=1;i<=N2;i++) a[i]=rand()%3;
							break;
						}
					case 3:
						{
							N=N3;
							for(i=1;i<=N3;i++) a[i]=rand()%3;
							break;
						}
				}
				clock_t start = clock();
				{
					ColorSort(a,N);
				}
				clock_t end = clock();
				printf("Running time is: %d  ms\n", end - start);
				printf("排序好的前十个数为：\n");
				for(i=1;i<=10;i++) printf("%d ",a[i]);
				break;
			}
		case 7:return 0;//结束操作
	}
	if((fp=fopen("datafile.txt","wb"))==NULL)                   //打开输出文件
	{
		printf("打开文件失败\n");
		exit(0);
	}
	for(i=1;i<=N;i++)
	{
		fprintf(fp,"%d ",a[i]);
	}
	fclose(fp);
	memset(a_1,0,N3+1);
	memset(a,0,N3+1);
	printf("输入任意值返回操作界面:");
	scanf("%s",option);
	if(option) goto label;
	return 0;
}
