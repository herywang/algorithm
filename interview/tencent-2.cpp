//
// Created by wangheng on 2022/7/27.
//小红拿到了一个数组 a，每次操作小红可以选择数组中的任意一个数减去 x，小红一共能进行 k 次。
//小红想在 k 次操作之后，数组的最大值尽可能小。请你返回这个最大值。

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    int getMaxIndex(vector<int> &nums){
        int maxIndex = 0;
        int maxValue = INT_MIN;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i] > maxValue){
                maxValue = nums[i];
                maxIndex = i;
            }
        }
        return maxIndex;
    }
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param a int整型vector
     * @param k int整型
     * @param x int整型
     * @return int整型
     */
    int minMax(vector<int>& a, int k, int x) {
        // write code here
        for(int i = 0;i<k;i++){
            // 执行k次
            int maxIndex = getMaxIndex(a);
            a[maxIndex] -= x;
        }
        int maxIndex = getMaxIndex(a);
        return a[maxIndex];
    }
};

int main() {

    return 0;
}
