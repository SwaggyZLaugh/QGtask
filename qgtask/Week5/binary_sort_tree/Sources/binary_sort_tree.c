#include "binary_sort_tree.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
BST_Status BST_init(BinarySortTreePtr T)
{
	if(T->root!=NULL) return failed;
	return succeed;
}

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
BST_Status BST_insert(BinarySortTreePtr T, ElemType value)
{
	int tag=0;
	NodePtr N=(NodePtr)malloc(sizeof(Node)),P1,P2;//开辟结点N 
	N->left=NULL;
	N->right=NULL;
	N->value=value;
	P1=T->root;
	while(P1)//找到插入位置 
	{
		P2=P1;
		if(N->value<P1->value)
		{
			P1=P1->left;
			tag=1;
		}
		else if(N->value>P1->value)
		{
			P1=P1->right;
			tag=2;
		}
		else return failed;//若value已存在则插入失败 
	}
	if(tag==0) T->root=N;        //tag为0时插入根节点 
	else if(tag==1) P2->left=N;  //tag为1时插入左孩 
	else P2->right=N;            //tag为2时插入右孩
	if(N->value==value) return succeed;
	return failed;
}

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
BST_Status BST_delete(BinarySortTreePtr T, ElemType value)
{
	NodePtr P1=T->root,P2,P3,P4;
	int tag=0,tag1=0;
	while(P1)//找到删除的结点 
	{
		if(value<P1->value)
		{
			P2=P1;
			P1=P1->left;
			tag=1;
		}
		else if(value>P1->value)
		{
			P2=P1;
			P1=P1->right;
			tag=2;
		}
		else
		{
			
			//如果无左右孩则直接删除
			if(P1->left==NULL&&P1->right==NULL) 
			{
				if(tag==0) T->root=NULL;
				if(tag==1) P2->left=NULL;
				if(tag==2) P2->right=NULL;
			}
			//有左右孩之一，则替换
			else if(P1->left==NULL&&P1->right!=NULL) 
			{
				if(tag==0) T->root=P1->right;
				if(tag==1) P2->left=P1->right;
				if(tag==2) P2->right=P1->right;
			}
			else if(P1->left!=NULL&&P1->right==NULL)
			{
				if(tag==0) T->root=P1->left;
				if(tag==1) P2->left=P1->left;
				if(tag==2) P2->right=P1->left;
			}
			//左右孩都有则用左子族最右结点替换，再删除左子族最右结点
			else
			{
				P3=P1->left;
				while(P3->right)
				{
					P4=P3;
					tag1=1;
				}
				if(tag==0)
				{
					T->root->value=P3->value;
					if(tag1==0) P1->left=NULL;
					else P4->right=NULL;
					free(P3);
				}
				if(tag==1)
				{
					P2->left->value=P3->value;
					if(tag1==0) P1->left=NULL;
					else P4->right=NULL;
					free(P3);
				}
				if(tag==2)
				{
					P2->right->value=P3->value;
					if(tag1==0) P1->left=NULL;
					else P4->right=NULL;
					free(P3);
				}
			}
			return succeed;
		}
		
	}
	return failed;//未找到则失败 
}

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
BST_Status BST_search(BinarySortTreePtr T, ElemType value)
{
	NodePtr P=T->root;
	while(P)
	{
		if(value<P->value) P=P->left;
		else if(value>P->value) P=P->right;
		else return succeed;
	}
	return failed;
}

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_preorderI(BinarySortTreePtr T, void (*visit)(NodePtr P))
{
	NodePtr stack[20],P=T->root;
	int top=-1;
	if(!P) return failed;
	//入栈 
	stack[++top]=P;
	while(top!=-1)
	{
		//出栈 
		P=stack[top--];
		visit(P);
		//入栈 
		if(P->right) stack[++top]=P->right;
		//入栈 
		if(P->left) stack[++top]=P->left;
	}
	return succeed;
}


/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_preorderR(BinarySortTreePtr T, void (*visit)(NodePtr P))
{
	NodePtr P=T->root;
	if(P==NULL) return failed;
	BST_preorderR_1(P,visit);
	return succeed;
}

void BST_preorderR_1(NodePtr P,void (*visit)(NodePtr P))
{
	if(P==NULL) return;
	visit(P);
	BST_preorderR_1(P->left,visit);
	BST_preorderR_1(P->right,visit);
}

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_inorderI(BinarySortTreePtr T, void (*visit)(NodePtr))
{
	NodePtr stack[20],P=T->root;
	int top=-1;
	if(!P) return failed;
	while(top!=-1||P)
	{
		while(P)
		{
			//入栈 
			stack[++top]=P;
			P=P->left;
		}
		if(top!=-1)
		{
			//出栈 
			P=stack[top--];
			visit(P);
			P=P->right;
		}
	}
	return succeed;
}

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_inorderR(BinarySortTreePtr T, void (*visit)(NodePtr P))
{
	NodePtr P=T->root;
	if(P==NULL) return failed;
	BST_inorderR_1(P,visit);
	return succeed;
}

void BST_inorderR_1(NodePtr P,void (*visit)(NodePtr P))
{
	if(P==NULL) return;
	BST_inorderR_1(P->left,visit);
	visit(P);
	BST_inorderR_1(P->right,visit);
}

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_postorderI(BinarySortTreePtr T, void (*visit)(NodePtr))
{
	NodePtr stack[20],P=T->root;
	int top=-1;
	int a[50],i=0;
	if(!P) return failed;
	//入栈 
	stack[++top]=P;
	while(top!=-1)
	{
		//出栈 
		P=stack[top--];
		a[i++]=P->value;
		//入栈 
		if(P->left) stack[++top]=P->left;
		//入栈 
		if(P->right) stack[++top]=P->right;
	}
	for(i=i-1;i>=0;i--) printf("%d\n",a[i]);
	return succeed;
}

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_postorderR(BinarySortTreePtr T, void (*visit)(NodePtr P))
{
	NodePtr P=T->root;
	if(P==NULL) return failed;
	else BST_postorderR_1(P,visit);
	return succeed;
}

void BST_postorderR_1(NodePtr P,void (*visit)(NodePtr P))
{
	if(P==NULL) return;
	BST_postorderR_1(P->left,visit);
	BST_postorderR_1(P->right,visit);
	visit(P);
}

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_levelOrder(BinarySortTreePtr T, void (*visit)(NodePtr P))
{
	NodePtr queue[20],P=T->root;
	int front=0,rear=0,length=0;
	if(!P) return failed;
	//入队 
	queue[rear]=P;
	rear=(rear+1)%20;
	length++;
	// 
	while(length!=0)
	{
		//出队 
		P=queue[front];
		queue[front]=(NodePtr)malloc(sizeof(Node));
		front=(front+1)%20;
		length--;
		//
		visit(P);
		if(P->left)
		{
			//入队 
			queue[rear]=P->left;
			rear=(rear+1)%20;
			length++;
		}
		if(P->right)
		{
			//入队 
			queue[rear]=P->right;
			rear=(rear+1)%20;
			length++;
		}
	}
	return succeed; 
}

void visit(NodePtr P)
{
	printf("%d\n",P->value);
}

/**
 *  @name        :  void judgeint(char *s)
 *    @description : 检测输入是否为整数 
 *    @param         s 指针s
 *  @notice      : None
 */
int judgeint(char *s,int *n)
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
	*n=result;
	return 1;
}
