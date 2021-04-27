//
// Created by eke_l on 2021/4/21.
//

#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H

#define true 1
#define false 0
#define succeed 1
#define failed 0
#define BST_Status int

typedef int ElemType;

typedef struct Node{
    ElemType value;
    struct Node *left, *right;
}Node, *NodePtr;

typedef struct BinarySortTree{
    NodePtr root;
} BinarySortTree, *BinarySortTreePtr;

/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
BST_Status BST_init(BinarySortTreePtr T);

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
BST_Status BST_insert(BinarySortTreePtr T, ElemType value);

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
BST_Status BST_delete(BinarySortTreePtr T, ElemType value);

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
BST_Status BST_search(BinarySortTreePtr T, ElemType value);

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_preorderI(BinarySortTreePtr T, void (*visit)(NodePtr));

/**
 * BST preorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_preorderR(BinarySortTreePtr T, void (*visit)(NodePtr));
void BST_preorderR_(NodePtr P,void (*visit)(NodePtr P));

/**
 * BST inorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_inorderI(BinarySortTreePtr T, void (*visit)(NodePtr));

/**
 * BST inorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_inorderR(BinarySortTreePtr T, void (*visit)(NodePtr));
void BST_inorderR_(NodePtr P,void (*visit)(NodePtr P));

/**
 * BST preorder traversal without recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_postorderI(BinarySortTreePtr T, void (*visit)(NodePtr));

/**
 * BST postorder traversal with recursion
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_postorderR(BinarySortTreePtr T, void (*visit)(NodePtr));
void BST_postorderR_(NodePtr P,void (*visit)(NodePtr P));

/**
 * BST level order traversal
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
BST_Status BST_levelOrder(BinarySortTreePtr T, void (*visit)(NodePtr));

/**
 *  @name        :  void judgeint(char *s)
 *    @description : 检测输入是否为整数 
 *    @param         s 指针s
 *  @notice      : None
 */
int judgeint(char *s,int*n);

void visit(NodePtr P);

#endif //BINARYSORTTREE_BINARY_SORT_TREE_H
