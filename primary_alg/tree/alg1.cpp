//
// Created by wangheng on 2021/6/25.
//

#include <iostream>
#include <vector>
#include "treenode.h"

using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int left = maxDepth(root->left);
        int right = maxDepth(root->right);
        return max(left, right)+1;
    }
};

int main() {
    TreeNode *pNode = new TreeNode(1, new TreeNode(2, new TreeNode(3, nullptr, new TreeNode(4)), new TreeNode(3)),
                                   new TreeNode(5));
    Solution* solution = new Solution;
    cout<<solution->maxDepth(pNode)<<endl;
    return 0;
}
