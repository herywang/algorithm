//
// Created by wangheng on 2021/6/26.
// 二叉树层序遍历

#include <iostream>
#include <vector>
#include "treenode.h"
#include "queue"
#include "vec_util.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr){
            return ans;
        }
        queue<TreeNode*> queue1;
        queue1.push(root);
        while(!queue1.empty()){
            queue<TreeNode*> queue2;
            vector<int> res;
            while(!queue1.empty()){
                TreeNode *pNode = queue1.front();
                queue1.pop();
                res.push_back(pNode->val);
                if(pNode->left != nullptr){
                    queue2.push(pNode->left);
                }
                if(pNode->right != nullptr){
                    queue2.push(pNode->right);
                }
            }
            ans.push_back(res);
            queue1 = queue2;
        }
        return ans;
    }
};

int main() {
    TreeNode* root = new TreeNode(1, new TreeNode(2,new TreeNode(4), new TreeNode(5)), new TreeNode(3,new TreeNode(6), new TreeNode(7)));
    Solution *solution = new Solution;
    vector<vector<int>> res = solution->levelOrder(root);
    for(vector<int> an:res){
        print_vec(an);
    }
    return 0;
}
