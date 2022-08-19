//
// Created by wangheng on 2022/8/18.
// 锯齿遍历二叉树

#include <iostream>
#include <vector>
#include "treenode.h"
#include "vec_util.h"
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr){
            return ans;
        }
        bool isLeftToRight = true;
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);
        while (!nodeQueue.empty()){
            int size = nodeQueue.size();
            deque<int> path;
            for(int i = 0;i<size;i++){
                auto pNode = nodeQueue.front();
                nodeQueue.pop();
                if(isLeftToRight){
                    path.push_back(pNode->val);
                }else{
                    path.push_front(pNode->val);
                }
                if(pNode->left != nullptr){
                    nodeQueue.push(pNode->left);
                }
                if(pNode->right != nullptr){
                    nodeQueue.push(pNode->right);
                }
            }
            isLeftToRight = !isLeftToRight;
            ans.emplace_back(vector<int>(path.begin(), path.end()));
        }
        return ans;
    }
};

void testSolution(){
    auto s = new Solution;
    TreeNode* root = new TreeNode(3, new TreeNode(9), 
            new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    const vector<vector<int>> &res = s->zigzagLevelOrder(root);
    for(auto &v:res){
        print_vec(v);
    }
    deleteNode(root);
    delete s;
}

int main() {
    testSolution();
    return 0;
}
