//
// Created by wangheng on 2022/6/19.
//

#ifndef MAC_ALGORITHM_TREENODE_H
#define MAC_ALGORITHM_TREENODE_H
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void deleteNode(TreeNode *node){
    if(node == nullptr){
        return;
    }
    deleteNode(node->left);
    deleteNode(node->right);
    delete node;
}
#endif //MAC_ALGORITHM_TREENODE_H
