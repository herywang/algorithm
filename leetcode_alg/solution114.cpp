//
// Created by wangheng on 2022/8/9.
//

#include <iostream>
#include <vector>
#include "treenode.h"
using namespace std;

class Solution {
public:
    void flatten(TreeNode *root) {
        if(root == nullptr){
            return;
        }
        vector<TreeNode*> stack;
        preOrder(root, stack);
        for(int i = 0;i<stack.size();i++){
            if(i==stack.size()-1){
                stack[i]->left = nullptr;
                stack[i]->right = nullptr;
            }else{
                stack[i]->left = nullptr;
                stack[i]->right = stack[i+1];
            }
        }
    }

    void preOrder(TreeNode* node, vector<TreeNode*> &stack){
        if(node == nullptr){
            return;
        }
        stack.emplace_back(node);
        preOrder(node->left, stack);
        preOrder(node->right, stack);
    }
};

int main() {

    return 0;
}
