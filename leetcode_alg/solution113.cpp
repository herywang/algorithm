//
// Created by wangheng on 2022/7/17.
// 路径总和 二

#include <iostream>
#include <vector>
#include "treenode.h"
#include "vec_util.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root, targetSum, ans, path);
        return ans;
    }

    void dfs(TreeNode *node, int target, vector<vector<int>> &res, vector<int> &path) {
        if(node == nullptr){
            return;
        }
        path.push_back(node->val);
        target -= node->val;
        if(node->left == nullptr && node->right== nullptr && target==0){
            res.emplace_back(path);
        }
        dfs(node->left, target, res, path);
        dfs(node->right, target, res, path);
        path.pop_back();
    }
};

void testSolution() {
    auto s = new Solution;
    TreeNode *root = new TreeNode(5,
                                  new TreeNode(4,
                                               new TreeNode(11,
                                                            new TreeNode(7), new TreeNode(2)),
                                               nullptr),
                                  new TreeNode(8,
                                               new TreeNode(13),
                                               new TreeNode(4,
                                                            new TreeNode(5), new TreeNode(1))));
    vector<vector<int>> ans = s->pathSum(root,22);
    for(vector<int> v:ans){
        print_vec(v);
    }
}
int main() {
    testSolution();
    return 0;
}
