//
// Created by wangheng on 2021/6/26.
// 有序数组转换成一个平衡二叉树

#include <iostream>
#include <vector>
#include "treenode.h"

using namespace std;

class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        if (nums.size() == 0) {
            return nullptr;
        }
        if (nums.size() == 1) {
            return new TreeNode(nums[0]);
        }
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right) >> 1;
        TreeNode* root = new TreeNode(nums[mid]);
        vector<int> left_vec;
        for(int i = 0;i<mid;i++){
            left_vec.emplace_back(nums[i]);
        }
        vector<int> right_vec;
        for(int i = mid+1;i<nums.size();i++){
            right_vec.emplace_back(nums[i]);
        }
        root->left = sortedArrayToBST(left_vec);
        root->right = sortedArrayToBST(right_vec);
        return root;
    }
};
int main() {
    vector<int> sortedVec = {1,2,3,4,5,6,7,8,9};
    Solution *solution = new Solution;
    TreeNode *root = solution->sortedArrayToBST(sortedVec);

    cout<<"hello world"<<endl;
    delete solution;
    delete root;
    return 0;
}
