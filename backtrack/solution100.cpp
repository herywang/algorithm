//
// Created by wangheng on 2021/6/29.
// 判断两棵树是否相同

#include <iostream>
#include <vector>
#include "treenode.h"

using namespace std;

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p== nullptr && q == nullptr)
            return true;
        if(p == nullptr || q== nullptr)
            return false;
        if(p->val == q->val){
            return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
        }else{
            return false;
        }
    }
};

int main() {
    TreeNode* p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
    TreeNode* q = new TreeNode(1, new TreeNode(2), new TreeNode(4));
    Solution *solution = new Solution;
    cout<<solution->isSameTree(p, q)<<endl;
    return 0;
}
