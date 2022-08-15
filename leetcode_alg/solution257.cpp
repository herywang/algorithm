//
// Created by wangheng on 2022/8/15.
//

#include <iostream>
#include <vector>
#include "treenode.h"
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode *root) {
        vector<string> res;
        vector<int> path;
        dfs(res, path, root);
        return res;
    }

    void dfs(vector<string> &res, vector<int> &path, TreeNode *node) {
        path.emplace_back(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            res.emplace_back(vec2string(path));
            return;
        }
        if (node->left != nullptr) {
            dfs(res, path, node->left);
            path.pop_back();
        }
        if (node->right != nullptr) {
            dfs(res, path, node->right);
            path.pop_back();
        }
    }

    string vec2string(vector<int> &path) {
        if (path.size() == 0) {
            return "";
        }
        stringstream ss;
        if (path.size() == 1) {
            ss << path[0];
            return ss.str();
        } else {
            for (int i = 0; i < path.size() - 1; i++) {
                ss << path[i] << "->";
            }
            ss << path[path.size() - 1];
            return ss.str();
        }
    }
};

void testSolution() {
    auto s = new Solution;
    TreeNode *root = new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(5)), new TreeNode(3));
    const vector<string> &paths = s->binaryTreePaths(root);
    for (string s: paths) {
        cout << s << endl;
    }
    deleteNode(root);
    delete s;
}

int main() {
    testSolution();
    return 0;
}
