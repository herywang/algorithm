//
// Created by wangheng on 2021/6/25.
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

#endif //MAC_ALGORITHM_TREENODE_H
