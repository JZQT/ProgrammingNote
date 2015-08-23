/* 二叉查找树 - 数据结构
 * Binary Search Tree - Data Structure
 * 
 * 该二叉查找树的实现不存储重复元素。
 */

#ifndef _BINARY_SEARCH_TREE_CPP_
#define _BINARY_SEARCH_TREE_CPP_

#include <stdio.h>

typedef int ValueType;

class BSTree;
class BSTreeNode;

class BSTree {
    public:
        BSTree(void);
        BSTree(const ValueType key);
        ~BSTree(void);
        BSTreeNode *Find(const ValueType key);
        BSTreeNode *FindMin(void);
        BSTreeNode *FindMax(void);
        void Insert(const ValueType key);
        void Delete(const ValueType key);
    private:
        BSTreeNode *root;
};

class BSTreeNode {
    friend class BSTree;
    public:
        BSTreeNode(const ValueType key);
        ~BSTreeNode(void);

        ValueType value;
        BSTreeNode *left;
        BSTreeNode *right;
    private:
        BSTreeNode *Delete(const ValueType key);
};

#endif
