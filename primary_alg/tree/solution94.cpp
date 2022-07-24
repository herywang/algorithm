//
// Created by wangheng on 2021/7/4.
// 二叉树中序遍历

#include <iostream>
#include <vector>
#include "treenode.h"
#include "stack"
using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr){
            return ans;
        }
        stack<TreeNode*> stack1;
        TreeNode* p = root;
        while(p != nullptr || !stack1.empty()){
            if(p != nullptr){
                stack1.push(p);
                p =p->left;
            }else{
                TreeNode *node = stack1.top();
                stack1.pop();
                ans.push_back(node->val);
                p = node->right;
            }
        }
        return ans;
    }
};

int main() {

    return 0;
}
