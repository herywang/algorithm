//
// Created by wangheng on 2022/8/18.
//

#include <iostream>
#include <vector>
#include <queue>
#include "treenode.h"
#include "vec_util.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            vector<int> record;
            for (int i = 0; i < size; i++) {
                auto node = q.front();
                record.push_back(node->val);
                q.pop();
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            } // 遍历完成一层
            ans.push_back(record);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

void testSolution() {
    auto s = new Solution;
    TreeNode *root = new TreeNode(3, new TreeNode(9), new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    auto ans = s->levelOrderBottom(root);
    for (auto &r : ans) {
        print_vec(r);
    }
    deleteNode(root);
    delete s;
}

int main() {
    testSolution();
    return 0;
}
