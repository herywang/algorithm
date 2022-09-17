//
// Created by wangheng on 2022/9/15.
//

#include <iostream>
#include <vector>
#include "treenode.h"
#include <queue>
#include "vec_util.h"

using namespace std;

class Solution {
public:
    vector<int> solve(TreeNode *root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }
        TreeNode *p = root;
        queue<TreeNode *> q;
        q.push(p);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *pNode = q.front();
                ans.push_back(pNode->val);
                q.pop();
                if (pNode->left != nullptr) {
                    q.push(pNode->left);
                }
                if (pNode->right != nullptr) {
                    q.push(pNode->right);
                }
            }
        }
        return ans;
    }

    void dfs(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        cout << root->val << endl;
        dfs(root->left);
        dfs(root->right);
    }
};
void testSolution() {
    auto root = new TreeNode(1, new TreeNode(2, new TreeNode(4), nullptr), new TreeNode(3));
    auto solution = new Solution;
    //    vector<int> ans = solution->solve(root);

    //    print_vec(ans);
    solution->dfs(root);
    delete solution;
    deleteNode(root);
}

int main(int argc, char *argv[]) {
    testSolution();
    return 0;
}