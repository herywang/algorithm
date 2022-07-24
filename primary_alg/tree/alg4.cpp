//
// Created by wangheng on 2021/6/26.
// 对称二叉树

#include <iostream>
#include <vector>
#include "treenode.h"

using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        return isSymmetricHelper(root->left, root->right);
    }

    bool isSymmetricHelper(TreeNode* left, TreeNode* right){
        if(left == nullptr && right == nullptr){
            return true;
        }
        if(left == nullptr || right == nullptr || left ->val != right->val){
            return false;
        }
        return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);
    }


};

int main() {

    return 0;
}
