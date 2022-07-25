//
// Created by wangheng on 2022/7/25.
//

#include <iostream>
#include <vector>
#include <cmath>
#include "treenode.h"

using namespace std;

class Solution {
private:
    int vecToInt(vector<int> &v) {
        int res = 0;
        int j = 0;
        for(int i = v.size()-1;i>=0;i--){
            res += v[i] * pow(10, j);
            j++;
        }
        return res;
    }
public:
    int sumNumbers(TreeNode *root) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, path, res);
        int ans = 0;
        for(vector<int> v:res){
            ans += vecToInt(v);
        }
        return ans;
    }


    void dfs(TreeNode *node, vector<int> &path, vector<vector<int>> &res) {
        if (node == nullptr) {
            return;
        }
        path.push_back(node->val);
        if (node->left == nullptr && node->right == nullptr) {
            res.emplace_back(path);
        }
        dfs(node->left, path, res);
        dfs(node->right, path, res);
        path.pop_back();
    }
};

void testSolution() {
    auto s = new Solution;
    TreeNode *root = new TreeNode(4, new TreeNode(9,
                                                  new TreeNode(5), new TreeNode(1)),
                                  new TreeNode(0));
    cout<<s->sumNumbers(root)<<endl;
    deleteNode(root);
    delete s;
}

int main() {
    testSolution();
    return 0;
}
