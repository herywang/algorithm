/**
 * @file solution700.cpp
 * @author your name (you@domain.com)
 * @brief 二叉搜索树
 * @version 0.1
 * @date 2022-09-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>
#include "treenode.h"

using namespace std;

class Solution {
public:
    TreeNode *searchBST(TreeNode *root, int val) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode *p = root;
        while (p != nullptr) {
            if (p->val == val) {
                return p;
            } else if (val < p->val) {
                p = p->left;
            } else {
                p = p->right;
            }
        }
        return nullptr;
    }
};

int main() {
    shared_ptr<Solution> solution(new Solution);
    TreeNode *root = new TreeNode(4, new TreeNode(2, new TreeNode(1), new TreeNode(3)), new TreeNode(7));

    deleteNode(root);
    return 0;
}
