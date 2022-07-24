//
// Created by wangheng on 2021/6/25.
// 验证二叉搜索树

#include <iostream>
#include <vector>
#include "treenode.h"
#include "stack"
#include "vec_util.h"

using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        vector<int> ans = inOrder(root);
        for(int i = 1;i<ans.size();i++){
            if(ans[i]<ans[i-1])
                return false;
        }
        return true;
    }
    vector<int> inOrder(TreeNode* root){
        vector<int> ans;
        // 中序遍历，非递归
        stack<TreeNode*> stack1;
        TreeNode* p = root;
        while(p != nullptr || !stack1.empty()){
            if (p!= nullptr){
                stack1.push(p);
                p = p->left;
            }else {
                p = stack1.top();
                stack1.pop();
                ans.push_back(p->val);
                p = p->right;
            }
        }
        return ans;
    }
};

int main() {
    TreeNode *tree = new TreeNode(5, new TreeNode(4), new TreeNode(6, new TreeNode(3), new TreeNode(7)));
    Solution* solution = new Solution;
    bool b = solution->isValidBST(tree);
    cout<<b<<endl;
//    vector<int> result = solution->inOrder(tree);
//    print_vec(result);
    return 0;
}
