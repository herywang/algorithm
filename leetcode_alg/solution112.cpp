//
// Created by wangheng on 2022/7/16.
//

#include <iostream>
#include <vector>
#include "treenode.h"

using namespace std;

class Solution {
public:
    bool hasPathSum(TreeNode *node, int target) {
        if (node == nullptr) {
            return false;
        }
        if (node->left == nullptr && node->right == nullptr) {
            return target == node->val;
        }
        return hasPathSum(node->left, target - node->val)
               or hasPathSum(node->right, target - node->val);
    }
};

int main() {

    return 0;
}
