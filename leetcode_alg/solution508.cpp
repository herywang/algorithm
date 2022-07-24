//
// Created by wangheng on 2022/6/19.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include "include/treenode.h"

using namespace std;

class Solution {
public:
    int maxCnt = 0;
    vector<int> findFrequentTreeSum(TreeNode *root) {
        vector<int> ans;
        if(root == nullptr){
            return ans;
        }
        unordered_map<int,int> m;
        dfs(m, root);
        for(auto &[k, v]:m){
            if(v == maxCnt){
                ans.push_back(k);
            }
        }
        return ans;
    }

    int dfs(unordered_map<int, int> &m, TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int res = root->val + dfs(m, root->left) + dfs(m, root->right);
        m[res] += 1;
        maxCnt = max(maxCnt, m[res]);
        return res;
    }
};

int main() {

    return 0;
}
