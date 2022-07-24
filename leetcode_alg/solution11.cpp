//
// Created by wangheng on 2021/6/17.
// 盛水问题: 双指针算法
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int l = 0;
        int r = height.size()-1;
        int maxArea=0;
        while(l<r){
            int area = min(height[l], height[r]) * (r-l);
            if(maxArea< area){
                maxArea = area;
            }
            if(height[l] < height[r]){
                l++;
            }else{
                r--;
            }
        }
        return maxArea;
    }
};

int main() {

    return 0;
}

