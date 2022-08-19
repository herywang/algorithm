//
// Created by wangheng on 2022/8/18.
// 从前序和中序遍历还原二叉树

#include <iostream>
#include <vector>
#include "treenode.h"
#include <unordered_map>

using namespace std;

class Solution {
private:
    unordered_map<int, int> mapping;
    TreeNode *_buildTree(vector<int> &preorder, int pLeft, int pRight, vector<int> &inorder, int iLeft, int iRight) {
        if (pLeft > pRight) {
            return nullptr;
        }
        // 先序遍历中定位根节点
        int pRoot = pLeft;
        // 中序遍历中定位根节点
        int iRoot = mapping[preorder[pRoot]];
        TreeNode *root = new TreeNode(preorder[pRoot]);
        // 计算左子树节点数目
        int leftTreeNodeCount = iRoot - iLeft;
        root->left = _buildTree(preorder, pLeft + 1, pLeft + leftTreeNodeCount, inorder, iLeft, iRoot - 1);
        root->right = _buildTree(preorder, pLeft + leftTreeNodeCount + 1, pRight, inorder, iRoot + 1, iRight);
        return root;

    }
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // 为中序遍历的值 建立<value, index>映射关系
        for (int i = 0; i < inorder.size(); i++) {
            mapping[inorder[i]] = i;
        }
        return _buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
};

int main() {

    return 0;
}
