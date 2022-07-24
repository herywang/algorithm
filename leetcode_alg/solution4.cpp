//
// Created by wangheng on 2022/7/14.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res;
        int n1, n2;
        while (nums1.size() > 0 && nums2.size() > 0) {
            n1 = nums1.front();
            n2 = nums2.front();
            if(n1 < n2){
                res.push_back(n1);
                nums1.erase(nums1.begin());
            }else{
                res.push_back(n2);
                nums2.erase(nums2.begin());
            }
        }
        while(nums1.size()>0){
            res.push_back(nums1.front());
            nums1.erase(nums1.begin());
        }
        while(nums2.size()>0){
            res.push_back(nums2.front());
            nums2.erase(nums2.begin());
        }
        int len = res.size();
        if(len % 2 == 0){
            return ((double)res[(len - 1) / 2] + (double)res[len / 2]) / 2.;
        }else{
            return (double)res[len / 2];
        }
    }
};

int main() {
    vector<int> nums1 = {1,3};
    vector<int> nums2 = {2,4};
    auto s = new Solution;
    double mid = s->findMedianSortedArrays(nums1, nums2);
    cout<<mid<<endl;
    return 0;
}
