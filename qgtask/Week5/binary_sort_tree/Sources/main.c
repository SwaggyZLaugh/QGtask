#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_sort_tree.h"

//操作界面 
void covers()
{
	printf("二叉排序树\n");
	printf("1. 插入数字\n");
	printf("2. 查找数字\n");
	printf("3. 删除数字\n");
	printf("4. 递归前序排序\n");
	printf("5. 递归中序排序\n");
	printf("6. 递归后序排序\n");
	printf("7. 迭代前序排序\n");
	printf("8. 迭代中序排序\n");
	printf("9. 迭代后序排序\n");
	printf("10. 层序排序\n");
	printf("11. 退出程序\n");
	printf("请直接输入数字进行相应操作：\n");
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
	//检测输入指令 
	while(!t||op<=0||op>11)
	{
		system("cls");
		covers();
		printf("(错误指令请重新输入)");
		scanf("%s",option);
		t=judgeint(option,&op);
	}
	system("cls");
	switch(op)
	{
		case 1://插入数字
			{
				printf("请输入需要插入的数字:");
				scanf("%s",s);
				t=judgeint(s,&value);
				while(!t)
				{
					system("cls");
					printf("请输入需要插入的数字:(输入错误请重输)");
					scanf("%s",s);
					t=judgeint(s,&value);
				}
				if(BST_insert(&T, value)==succeed) printf("插入%d成功\n",value);
				else printf("插入%d失败\n",value);
				break;
			}
		case 2://查找数字
			{
				printf("请输入需要查找的数字:");
				scanf("%s",s);
				t=judgeint(s,&value);
				while(!t)
				{
					system("cls");
					printf("请输入需要查找的数字:(输入错误请重输)");
					scanf("%s",s);
					t=judgeint(s,&value);
				}
				if(BST_search(&T, value)==succeed) printf("查找%d成功\n",value);
				else printf("查找%d失败\n",value);
				break;
			}
		case 3://删除数字
			{
				
				printf("请输入需要删除的数字:");
				scanf("%s",s);
				t=judgeint(s,&value);
				while(!t)
				{
					system("cls");
					printf("请输入需要的数字:(输入错误请重输)");
					scanf("%s",s);
					t=judgeint(s,&value);
				}
				if(BST_delete(&T, value)==succeed) printf("删除%d成功\n",value);
				else printf("删除%d失败\n",value);
				break;
			}
		case 4://4.递归前序排序
			{
				if(BST_preorderR(&T,visit)==succeed) printf("递归前序遍历成功\n");
				else printf("递归前序遍历失败\n");
				break;
			}
		case 5://5.递归中序排序
			{
				if(BST_inorderR(&T,visit)==succeed) printf("中序遍历成功\n");
				else printf("中序遍历失败\n");
				break;
			}
		case 6://6.递归后序排序
			{
				if(BST_postorderR(&T,visit)==succeed) printf("后序遍历成功\n");
				else printf("后序遍历失败\n");
				break;
			}
		case 7://7.迭代前序排序
			{
				if(BST_preorderI(&T,visit)==succeed) printf("迭代前序遍历成功\n");
				else printf("迭代前序遍历失败\n");
				break;
			}
		case 8://8.迭代中序排序
			{
				if(BST_inorderI(&T,visit)==succeed) printf("迭代中序遍历成功\n");
				else printf("迭代中序遍历失败\n");
				break;
			}
		case 9://9.迭代后序排序
			{
				if(BST_postorderI(&T,visit)==succeed) printf("迭代后序遍历成功\n");
				else printf("迭代后序遍历失败\n");
				break;
			}
		case 10:
			{
				if(BST_levelOrder(&T,visit)==succeed) printf("层序遍历成功\n");
				else printf("层序遍历失败\n");
				break;
			}
		case 11: return 0;
	}
	printf("输入任意值返回操作界面:");
	scanf("%s",option);
	if(option) goto label;
	return 0;
}
