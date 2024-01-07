//
// Created by wangheng on 1/7/24.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {

        // 判断是否相交
        if(bx1 >= ax2 || ax1 >= bx2 || by1 >= ay2 || ay1 >= by2){
            // 不相交, 返回两者面积总和
            return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1);
        }

        // 相交情况
        int cx1, cy1, cx2, cy2;
        cx1 = max(ax1, bx1);
        cy1 = max(ay1, by1);

        cx2 = min(ax2, bx2);
        cy2 = min(ay2, by2);

        int area = (cx2 - cx1) * (cy2 - cy1);
        return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1) - area;
    }
};

int main(int argc, char *argv[]) {

    int ax1, ay1, ax2, ay2, bx1, by1, bx2, by2;
    cin >> ax1 >> ay1 >> ax2 >> ay2 >> bx1 >> by1 >> bx2 >> by2;

    auto solution = new Solution;

    cout<<"结果:"<<solution->computeArea(ax1,ay1, ax2, ay2, bx1, by1, bx2, by2);

    delete solution;
    return 0;
}