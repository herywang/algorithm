//
// Created by wangheng on 2022/7/27.
// 删除第k层的节点

#include <iostream>
#include <vector>
#include "treenode.h"
#include <queue>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @param a int整型vector
     * @return TreeNode类vector
     */
    vector<TreeNode *> deleteLevel(TreeNode *root, vector<int> &a) {
        // write code here
        vector<TreeNode *> ans;
        queue<TreeNode *> q;
        q.push(root);
        int level = 1;
        while (!q.empty()) {
            int size = q.size();
            auto iter = std::find(a.begin(), a.end(), level);
            for (int i = 0; i < size; i++) {
                auto pNode = q.front();

                if (iter != a.end()) {
                    // 当前层需要被删除, 则需要将下一层的节点添加到ans结果集合中
                    if (pNode->left != nullptr) {
                        q.push(pNode->left);
                        ans.push_back(pNode->left);
                    }
                    if (pNode->right != nullptr) {
                        q.push(pNode->right);
                        ans.push_back(pNode->right);
                    }
                    q.pop();
                    delete pNode;
                } else {
                    // 当前层不需要被删除
                    if (level == 1) {
                        ans.push_back(pNode);
                    }
                    if (q.front()->left != nullptr) {
                        q.push(pNode->left);
                    }
                    if (q.front()->right != nullptr) {
                        q.push(pNode->right);
                    }
                    q.pop();
                }
            }
            // 层数+1；
            level++;
        }
        return ans;
    }
};

void testSolution(){
    auto s = new Solution;
    TreeNode *root = new TreeNode(1,
            new TreeNode(2,
                    new TreeNode(4,
                            new TreeNode(7, nullptr, new TreeNode(9)),
                            new TreeNode(8, new TreeNode(10), nullptr)),
                    new TreeNode(5, nullptr, new TreeNode(11))),
            new TreeNode(3,
                    new TreeNode(6), nullptr));

    vector<int> a = {3};
    const vector<TreeNode *> &level = s->deleteLevel(root, a);

//    for(TreeNode* node:level){
//        deleteNode(node);
//    }
    delete s;
}

int main() {
    testSolution();
    return 0;
}
