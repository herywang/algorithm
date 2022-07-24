//
// Created by wangheng on 2022/6/22.
//

#include <iostream>
#include <vector>
#include "treenode.h"
#include <queue>

using namespace std;


class Solution {
public:
    int findBottomLeftValue(TreeNode *root) {
        if (root == nullptr) {
            return -1;
        }
        queue<TreeNode *> q;
        q.push(root);
        int leftV = 0;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *tmp = q.front();
                if (i == 0) {
                    leftV = tmp->val;
                }
                if (tmp->left != nullptr) {
                    q.push(tmp->left);
                }
                if (tmp->right != nullptr) {
                    q.push(tmp->right);
                }
                q.pop();
            }
        }
        return leftV;
    }
};

int main() {
    Solution *s = new Solution;
    TreeNode *root = new TreeNode(1, nullptr,
                                  new TreeNode(2, new TreeNode(3), new TreeNode(4, new TreeNode(5), nullptr)));
    int v = s->findBottomLeftValue(root);
    cout << v << endl;
    return 0;
}
