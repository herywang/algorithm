//
// Created by wangheng on 2022/7/27.
// 恢复二叉搜索树

#include <iostream>
#include <vector>
#include "treenode.h"
#include "vec_util.h"
using namespace std;

class Solution {
public:
    void recoverTree(TreeNode* root) {
        vector<int> order;
        inOrder(root, order);
        vector<int> twoIndex;
        // 找顺序不一致的两个下标
        for(int i = 0;i<order.size()-1;i++){
            if(order[i] > order[i+1]){
                twoIndex.push_back(i);
            }
            if(twoIndex.size() == 2){
                break;
            }
        }
        if(twoIndex.size() < 2){
            twoIndex.push_back(twoIndex[0]+1);
        }else if(twoIndex.size()==2){
            twoIndex[1] = twoIndex[1]+1;
        }
        int a =order[twoIndex[0]];
        int b = order[twoIndex[1]];
        recover(root, a, b);
    }

    void recover(TreeNode *root, int &a, int &b){
        if(root == nullptr){
            return;
        }
        if(root->val ==a){
            root->val = b;
        }else if(root->val == b){
            root->val = a;
        }
        recover(root->left, a, b);
        recover(root->right, a, b);
    }


    // 中序遍历获得序列
    void inOrder(TreeNode *node, vector<int> &order){
        if(node == nullptr){
            return;
        }
        inOrder(node->left, order);
        order.emplace_back(node->val);
        inOrder(node->right, order);
    }
};

void testSolution(){
    auto s = new Solution;

    TreeNode *root = new TreeNode(1,
            new TreeNode(3, nullptr, new TreeNode(2)), nullptr);
    TreeNode *root1 = new TreeNode(3,
            new TreeNode(1),
            new TreeNode(4, new TreeNode(2), nullptr));
    s->recoverTree(root1);
    s->recoverTree(root);
    vector<int> res;

    s->inOrder(root, res);
    print_vec(res);
    res.erase(res.begin(), res.end());
    s->inOrder(root1, res);
    print_vec(res);

    deleteNode(root);
    deleteNode(root1);
    delete s;
}

int main() {
    testSolution();
    return 0;
}
