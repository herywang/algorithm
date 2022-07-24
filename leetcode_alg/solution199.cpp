//
// Created by wangheng on 2022/6/18.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *tmpNode = q.front();
                q.pop();
                if (tmpNode->left != nullptr) {
                    q.push(tmpNode->left);
                }
                if (tmpNode->right != nullptr) {
                    q.push(tmpNode->right);
                }
                if (i == size - 1) {
                    res.push_back(tmpNode->val);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution *s = new Solution;
    TreeNode *root = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(5)),
                                  new TreeNode(3, nullptr, new TreeNode(4)));
    vector<int> res = s->rightSideView(root);
    for (int a: res) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}
