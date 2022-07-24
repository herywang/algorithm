//
// Created by wangheng on 2022/7/19.
//

#include <iostream>
#include <vector>
#include "treenode.h"

using namespace std;

class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        vector<TreeNode *> res;
        if(n<1){
            return{};
        }
        return generateTrees(1, n);
    }

    vector<TreeNode *> generateTrees(int start, int end) {
        if (start > end) {
            return {nullptr};
        }
        vector<TreeNode*> allTrees;
        for(int i = start;i<=end;i++){
            vector<TreeNode*> leftTrees = generateTrees(start, i-1);
            vector<TreeNode*> rightTrees = generateTrees(i+1, end);
            for(auto &left: leftTrees){
                for(auto &right: rightTrees){
                    TreeNode * currentTree = new TreeNode(i);
                    currentTree->left = left;
                    currentTree->right = right;
                    allTrees.emplace_back(currentTree);
                }
            }
        }
        return allTrees;
    }
};

void testSolution(){
    auto s = new Solution;
    const vector<TreeNode *> &trees = s->generateTrees(5);
    cout<<"hello world"<<endl;
}

int main() {
    testSolution();
    return 0;
}
