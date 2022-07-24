//
// Created by wangheng on 2021/6/26.
// 合并两个有序数组，假设nums1长度为m+n

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m+n-1;
        int r1 = m-1;
        int r2 = n-1;
        while(r1 >=0 && r2 >=0){
            if(nums1[r1] > nums2[r2]){
                nums1[index--] = nums1[r1--];
            }else{
                nums1[index--] = nums2[r2--];
            }
        }
        while (r1>=0){
            nums1[index--] = nums1[r1--];
        }
        while(r2>=0){
            nums1[index--] = nums2[r2--];
        }
    }
};

int main() {

    return 0;
}
