/**
 * @file solution699.cpp
 * @author your name (you@domain.com)
 * @brief 掉落的方块
 * @version 0.1
 * @date 2022-09-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>

using namespace std;

//定义方块的结构体
struct Block {
    int i;      //第i个方块
    int left;   //左边坐标
    int length; //宽度
    int hight;  //当前方块所能保证的最大堆叠高度
};

vector<int> fallingSquares(vector<vector<int>> &positions) {
    vector<int> res;
    if (positions.size() == 0) {
        return res;
    }
    vector<Block *> ans;

    for (int i = 0; i < positions.size(); i++) {
        vector<int> &pair = positions[i];
        Block *b = new Block;
        b->i = i;
        b->left = pair[0];
        b->length = pair[1];
        if (ans.size() == 0) {
            b->hight = b->length;
            ans.push_back(b);
            res.push_back(b->hight);
            continue;
        }
        // ans 中按照高度进行从大到小排列
        bool flag = false;
        for (int j = 0; j < ans.size(); j++) {
            if ((b->left >= ans[j]->left && b->left < ans[j]->left + ans[j]->length)
                || (b->left + b->length > ans[j]->left && b->left + b->length <= ans[j]->left + ans[j]->length)
                || (b->left <= ans[j]->left && b->left + b->length >= ans[j]->left + ans[j]->length)) {
                // 落在了最高的格子上了
                b->hight = b->length + ans[j]->hight;
                ans.push_back(b);
                flag = true;
                break;
            }
        }
        if (!flag) {
            b->hight = b->length;
            ans.push_back(b);
        }
        // 按照高度进行排序
        sort(ans.begin(), ans.end(), [](Block *b1, Block *b2) {
            return b2->hight < b1->hight;
        });
        res.push_back(ans[0]->hight);
    }
    // 销毁对象
    for (Block *_b : ans) {
        delete _b;
    }
    return res;
}

int main() {
    vector<vector<int>> position = {{1, 2}, {2, 3}, {6, 1}};
    vector<vector<int>> position1 = {{100, 100}, {200, 100}};
    vector<vector<int>> position2 = {{9, 1}, {6, 5}, {6, 7}};
    vector<int> ans = fallingSquares(position2);
    for (int &v : ans) {
        cout << v << " ";
    }
    cout << endl;
    return 0;
}