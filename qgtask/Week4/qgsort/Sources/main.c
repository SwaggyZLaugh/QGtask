#include "qgsort.h"
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

//�������� 
void covers() 
{
	printf("***************************************************\n");
	printf("***    1.�����������㷨����ʱ��               ***\n");
	printf("***    2.���鲢�����㷨����ʱ��               ***\n");
	printf("***    3.�����������㷨���ݹ�棩����ʱ��     ***\n");
	printf("***    4.�����������㷨����ʱ��               ***\n");
	printf("***    5.���������������㷨����ʱ��           ***\n");
	printf("***    6.�����ɫ�����㷨����ʱ��               ***\n");
	printf("***    7.��������                               ***\n");
	printf("***************************************************\n");
	printf("������Ҫִ�еĲ���:");
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
	//�������ָ�� 
	while(strcmp(option,"1")!=0&&strcmp(option,"2")!=0&&strcmp(option,"3")!=0&&strcmp(option,"4")!=0&&strcmp(option,"5")!=0&&strcmp(option,"6")!=0&&strcmp(option,"7")!=0)
	{
		system("cls");
		covers();
		printf("(����ָ������������)");
		scanf("%s",option);
	}
	op=*option-48;
	system("cls");
	switch(op)
	{
		case 1://�������� 
			{
				printf("ѡ����Ҫ��������С:1:10000  2:50000  3:200000\n");
				scanf("%s",option);
				while(strcmp(option,"1")!=0&&strcmp(option,"2")!=0&&strcmp(option,"3")!=0)
				{
					system("cls");
					printf("ѡ����Ҫ��������С:1:10000  2:50000  3:200000(����ָ������������)\n");
					scanf("%s",option);
				}
				op=*option-48;
				//����ѡ���������� 
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
				printf("����õ�ǰʮ����Ϊ��\n");
				for(i=1;i<=10;i++) printf("%d ",a[i]);
				break;
			}
		case 2://�鲢����
			{
				printf("ѡ����Ҫ��������С:1:10000  2:50000  3:200000\n");
				scanf("%s",option);
				while(strcmp(option,"1")!=0&&strcmp(option,"2")!=0&&strcmp(option,"3")!=0)
				{
					system("cls");
					printf("ѡ����Ҫ��������С:1:10000  2:50000  3:200000(����ָ������������)\n");
					scanf("%s",option);
				}
				op=*option-48;
				//����ѡ���������� 
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
				printf("����õ�ǰʮ����Ϊ��\n");
				for(i=1;i<=10;i++) printf("%d ",a[i]);
				break;
			}
		case 3://�������򣨵ݹ�棩 
			{
				printf("ѡ����Ҫ��������С:1:10000  2:50000  3:200000\n");
				scanf("%s",option);
				while(strcmp(option,"1")!=0&&strcmp(option,"2")!=0&&strcmp(option,"3")!=0)
				{
					system("cls");
					printf("ѡ����Ҫ��������С:1:10000  2:50000  3:200000(����ָ������������)\n");
					scanf("%s",option);
				}
				op=*option-48;
				//����ѡ���������� 
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
				printf("����õ�ǰʮ����Ϊ��\n");
				for(i=1;i<=10;i++) printf("%d ",a[i]);
				break;
			}
		case 4://��������
			{
				printf("ѡ����Ҫ��������С:1:10000  2:50000  3:200000\n");
				scanf("%s",option);
				while(strcmp(option,"1")!=0&&strcmp(option,"2")!=0&&strcmp(option,"3")!=0)
				{
					system("cls");
					printf("ѡ����Ҫ��������С:1:10000  2:50000  3:200000(����ָ������������)\n");
					scanf("%s",option);
				}
				op=*option-48;
				//����ѡ���������� 
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
				printf("����õ�ǰʮ����Ϊ��\n");
				for(i=1;i<=10;i++) printf("%d ",a[i]);
				break;
			}
		case 5://������������
			{
				printf("ѡ����Ҫ��������С:1:10000  2:50000  3:200000\n");
				scanf("%s",option);
				while(strcmp(option,"1")!=0&&strcmp(option,"2")!=0&&strcmp(option,"3")!=0)
				{
					system("cls");
					printf("ѡ����Ҫ��������С:1:10000  2:50000  3:200000(����ָ������������)\n");
					scanf("%s",option);
				}
				op=*option-48;
				//����ѡ���������� 
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
				printf("����õ�ǰʮ����Ϊ��\n");
				for(i=1;i<=10;i++) printf("%d ",a[i]);
				break;
			}
		case 6://��ɫ����
			{
				printf("ѡ����Ҫ��������С:1:10000  2:50000  3:200000\n");
				scanf("%s",option);
				while(strcmp(option,"1")!=0&&strcmp(option,"2")!=0&&strcmp(option,"3")!=0)
				{
					system("cls");
					printf("ѡ����Ҫ��������С:1:10000  2:50000  3:200000(����ָ������������)\n");
					scanf("%s",option);
				}
				op=*option-48;
				//����ѡ���������� 
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
				printf("����õ�ǰʮ����Ϊ��\n");
				for(i=1;i<=10;i++) printf("%d ",a[i]);
				break;
			}
		case 7:return 0;//��������
	}
	if((fp=fopen("datafile.txt","wb"))==NULL)                   //������ļ�
	{
		printf("���ļ�ʧ��\n");
		exit(0);
	}
	for(i=1;i<=N;i++)
	{
		fprintf(fp,"%d ",a[i]);
	}
	fclose(fp);
	memset(a_1,0,N3+1);
	memset(a,0,N3+1);
	printf("��������ֵ���ز�������:");
	scanf("%s",option);
	if(option) goto label;
	return 0;
}
