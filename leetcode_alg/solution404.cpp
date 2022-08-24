//
// Created by wangheng on 2022/8/23.
//

#include <iostream>
#include "treenode.h"

using namespace std;

class Solution {
private:
    void preOrder(TreeNode* node, bool isLeft, int &sum){
        if(node == nullptr){
            return;
        }
        if(isLeft && node->left == nullptr && node->right== nullptr) {
            sum += node->val;
        }
        preOrder(node->left, true, sum);
        preOrder(node->right, false, sum);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        preOrder(root, false, sum);
        return sum;
    }
};

void testSolution(){
    auto s= new Solution;
    TreeNode* root=  new TreeNode(3, new TreeNode(9),
                                  new TreeNode(20, new TreeNode(15), new TreeNode(7)));
    cout<<s->sumOfLeftLeaves(root)<<endl;
    deleteNode(root);
    delete s;
}

int main(int argc, char *argv[]) {
    testSolution();
    return 0;
}