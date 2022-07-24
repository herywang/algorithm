//
// Created by wangheng on 2022/6/24.
// 找出每一层最大值

#include <iostream>
#include <vector>
#include "treenode.h"
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> largestValues(TreeNode *root) {
        vector<int> ans;
        if (root == nullptr) {
            return ans;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            int max = INT32_MIN;
            for (int i = 0; i < size; i++) {
                TreeNode *tmp = q.front();
                if (tmp->val > max) {
                    max = tmp->val;
                }
                if (tmp->left != nullptr) {
                    q.push(tmp->left);
                }
                if (tmp->right != nullptr) {
                    q.push(tmp->right);
                }
                q.pop();
                delete tmp;
            }
            ans.push_back(max);
        }
        return ans;
    }
};

int main() {
    Solution *s = new Solution;
    TreeNode *root = new TreeNode(1, new TreeNode(3, new TreeNode(5), new TreeNode(3)),
                                  new TreeNode(2, nullptr, new TreeNode(9)));
    vector<int> res = s->largestValues(root);
    for(int t:res){
        cout<<t<<" ";
    }
    cout<<endl;
    return 0;
}
