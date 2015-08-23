/* 二叉查找树 - 数据结构
 * Binary Search Tree - Data Structure
 *
 * 该二叉查找树的实现不存储重复元素。
 */

#include "bst.hpp"

/* 二叉查找树初始化
 * 初始化为空树
 */
BSTree::BSTree(void)
{
    this->root = NULL;
    return;
}

/* 二叉查找树初始化
 * 根据给定值初始化根节点
 */
BSTree::BSTree(const ValueType key)
{
    this->root = new BSTreeNode(key);
    return;
}

/* 二叉查找树销毁
 * 递归销毁子树及其存储值并释放其内存
 */
BSTree::~BSTree(void)
{
    if (root != NULL) delete this->root;
    return;
}

/* 二叉查找树查找
 * 在该二叉查找树中查找是否存在指定值的元素
 * 存在则返回对应二叉查找树节点指针，否则返回NULL
 */
BSTreeNode *BSTree::Find(const ValueType key)
{
    BSTreeNode *node = this->root;

    while (node != NULL && node->value != key) {
        node = key < node->value ? node->left : node->right;
    }
    return node;
}

/* 二叉查找树查找最小元素值
 * 在该二叉查找树中查找出存储最小元素的节点并返回其指针
 */
BSTreeNode *BSTree::FindMin(void)
{
    BSTreeNode *node = this->root;

    while (node != NULL && node->left != NULL) {
        node = node->left;
    }
    return node;
}

/* 二叉查找树查找最大元素值
 * 在该二叉查找树中查找出最大元素值并返回
 */
BSTreeNode *BSTree::FindMax(void)
{
    BSTreeNode *node = this->root;

    while (node != NULL && node->right != NULL) {
        node = node->right;
    }
    return node;
}

/* 二叉查找树插入
 * 在该二叉查找树中插入一个元素
 * 如果该元素已经存在则不做操作
 */
void BSTree::Insert(const ValueType key)
{
    if (this->root == NULL) {
        this->root = new BSTreeNode(key);
        return;
    }

    BSTreeNode *node = this->root;

    while (node->value != key) {
        if (key < node->value) {
            node = node->left == NULL ? new BSTreeNode(key) : node->left;
        } else {
            node = node->right == NULL ? new BSTreeNode(key) : node->right;
        }
    }
    return;
}

/* 二叉查找树删除
 * 在该二叉查找树中删除元素
 * 如果不存在对应元素则不删除任何元素直接返回
 */
void BSTree::Delete(const ValueType key)
{
    if (this->root != NULL) this->root = this->root->Delete(key);
    return;
}

/* 二叉查找树节点初始化
 * 存储值设置为给定值
 */
BSTreeNode::BSTreeNode(const ValueType key)
{
    this->value = key;
    this->left = NULL;
    this->right = NULL;
    return;
}

/* 二叉查找树节点销毁
 * 将会递归销毁子树并释放内存
 */
BSTreeNode::~BSTreeNode(void)
{
    if (this->left != NULL) delete this->left;
    if (this->right != NULL) delete this->right;
    return;
}

/* 二叉查找树节点删除
 * 在以该二叉查找树节点为根节点的树中删除元素
 * 返回删除元素后的新二叉查找树根节点指针
 * 没有待删除元素则不做操作直接返回自身
 */
BSTreeNode *BSTreeNode::Delete(const ValueType key)
{
    // 待删除节点不是自己
    if (key < this->value) {
        if (this->left != NULL) {
            this->left = this->left->Delete(key);
        }
        return this;
    }
    if (key > this->value) {
        if (this->right != NULL) {
            this->right = this->right->Delete(key);
        }
        return this;
    }

    // 待删除节点是自己

    // 待删除节点左右子树都不为空
    if (this->left != NULL && this->right != NULL) {
        // 查找右子树最小元素节点
        BSTreeNode *min_node = this->right;
        while (min_node->left != NULL) {
            min_node = min_node->left;
        }
        // 更新与删除
        this->value = min_node->value;
        this->right = this->right->Delete(min_node->value);
        return this;
    }

    // 待删除节点为叶子节点
    if (this->left == NULL && this->right == NULL) {
        delete this;
        return NULL;
    }

    // 待删除节点仅有一颗子树
    BSTreeNode *tmp = this->left == NULL ? this->right : this->left;
    delete this;
    return tmp;
}
