//
// Created by wangheng on 2022/8/17.
// 二叉树的序列化和反序列化

#include <iostream>
#include <list>
#include "treenode.h"

using namespace std;

class Codec {
private:
    void dfs(TreeNode *node, string &str) {
        if (node == nullptr) {
            str += "X,";
        } else {
            str = str + to_string(node->val) + ",";
            dfs(node->left, str);
            dfs(node->right, str);
        }
    }

    TreeNode* buildTree(list<string> &val){
        if(val.front() == "X"){
            val.erase(val.begin());
            return nullptr;
        }
        TreeNode* node = new TreeNode(stoi(val.front()));
        val.erase(val.begin());
        node->left = buildTree(val);
        node->right = buildTree(val);
        return node;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string ret = "";
        dfs(root, ret);
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        list<string> dataArray;
        string str;
        for(auto &c: data){
            if(c==','){
                dataArray.push_back(str);
                str.clear();
            }else{
                str.push_back(c);
            }
        }
        if(str.size()>0){
            dataArray.push_back(str);
        }
        TreeNode *root = buildTree(dataArray);
        return root;
    }
};

void testSolution() {
    auto s = new Codec;
    TreeNode *root = new TreeNode(1, new TreeNode(2), 
            new TreeNode(3, new TreeNode(4), nullptr));
    const string &res = s->serialize(root);
    cout<<res<<endl;
    TreeNode *newRoot = s->deserialize(res);
    deleteNode(root);
    deleteNode(newRoot);
    delete s;
}

int main() {
    testSolution();
    return 0;
}
