#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_sort_tree.h"

//�������� 
void covers()
{
	printf("����������\n");
	printf("1. ��������\n");
	printf("2. ��������\n");
	printf("3. ɾ������\n");
	printf("4. �ݹ�ǰ������\n");
	printf("5. �ݹ���������\n");
	printf("6. �ݹ��������\n");
	printf("7. ����ǰ������\n");
	printf("8. ������������\n");
	printf("9. ������������\n");
	printf("10. ��������\n");
	printf("11. �˳�����\n");
	printf("��ֱ���������ֽ�����Ӧ������\n");
}

void covers();


int main()
{
	int op=0,i,t;
	char option[50],s[20];
	ElemType value;
	BinarySortTree T;
	T.root=NULL;
	label:
	system("cls");
	covers();
	scanf("%s",option);
	t=judgeint(option,&op);
	//�������ָ�� 
	while(!t||op<=0||op>11)
	{
		system("cls");
		covers();
		printf("(����ָ������������)");
		scanf("%s",option);
		t=judgeint(option,&op);
	}
	system("cls");
	switch(op)
	{
		case 1://��������
			{
				printf("��������Ҫ���������:");
				scanf("%s",s);
				t=judgeint(s,&value);
				while(!t)
				{
					system("cls");
					printf("��������Ҫ���������:(�������������)");
					scanf("%s",s);
					t=judgeint(s,&value);
				}
				if(BST_insert(&T, value)==succeed) printf("����%d�ɹ�\n",value);
				else printf("����%dʧ��\n",value);
				break;
			}
		case 2://��������
			{
				printf("��������Ҫ���ҵ�����:");
				scanf("%s",s);
				t=judgeint(s,&value);
				while(!t)
				{
					system("cls");
					printf("��������Ҫ���ҵ�����:(�������������)");
					scanf("%s",s);
					t=judgeint(s,&value);
				}
				if(BST_search(&T, value)==succeed) printf("����%d�ɹ�\n",value);
				else printf("����%dʧ��\n",value);
				break;
			}
		case 3://ɾ������
			{
				
				printf("��������Ҫɾ��������:");
				scanf("%s",s);
				t=judgeint(s,&value);
				while(!t)
				{
					system("cls");
					printf("��������Ҫ������:(�������������)");
					scanf("%s",s);
					t=judgeint(s,&value);
				}
				if(BST_delete(&T, value)==succeed) printf("ɾ��%d�ɹ�\n",value);
				else printf("ɾ��%dʧ��\n",value);
				break;
			}
		case 4://4.�ݹ�ǰ������
			{
				if(BST_preorderR(&T,visit)==succeed) printf("�ݹ�ǰ������ɹ�\n");
				else printf("�ݹ�ǰ�����ʧ��\n");
				break;
			}
		case 5://5.�ݹ���������
			{
				if(BST_inorderR(&T,visit)==succeed) printf("��������ɹ�\n");
				else printf("�������ʧ��\n");
				break;
			}
		case 6://6.�ݹ��������
			{
				if(BST_postorderR(&T,visit)==succeed) printf("��������ɹ�\n");
				else printf("�������ʧ��\n");
				break;
			}
		case 7://7.����ǰ������
			{
				if(BST_preorderI(&T,visit)==succeed) printf("����ǰ������ɹ�\n");
				else printf("����ǰ�����ʧ��\n");
				break;
			}
		case 8://8.������������
			{
				if(BST_inorderI(&T,visit)==succeed) printf("������������ɹ�\n");
				else printf("�����������ʧ��\n");
				break;
			}
		case 9://9.������������
			{
				if(BST_postorderI(&T,visit)==succeed) printf("������������ɹ�\n");
				else printf("�����������ʧ��\n");
				break;
			}
		case 10:
			{
				if(BST_levelOrder(&T,visit)==succeed) printf("��������ɹ�\n");
				else printf("�������ʧ��\n");
				break;
			}
		case 11: return 0;
	}
	printf("��������ֵ���ز�������:");
	scanf("%s",option);
	if(option) goto label;
	return 0;
}
