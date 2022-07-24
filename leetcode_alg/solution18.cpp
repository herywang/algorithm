//
// Created by wangheng on 2021/6/20.
// 四数之和 (参考三数之和,双指针解决)
#include "iostream"
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size()<4){
            return ans;
        }
        sort(nums.begin(), nums.end());
        for(int i = 0;i<nums.size()-3;i++){
            for(int j = i+1;j<nums.size()-2;j++){
                int left = j+1;
                int right = nums.size()-1;
                while(left<right){
                    int result = nums[i] + nums[j] + nums[left] + nums[right];
                    if(result > target){
                        right--;
                    }else if(result < target){
                        left++;
                    }else{
                        ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;
                        while (left<right && nums[left] == nums[left-1])
                            left++;
                        while(left<right && nums[right] == nums[right+1])
                            right--;
                    }
                }
                while(j+1 < nums.size()-2 && nums[j+1] == nums[j])
                    j++;
            }
            while(i+1<nums.size()-3 && nums[i+1] == nums[i])
                i++;
        }
        return ans;
    }
};

int main(){
    auto s = new Solution;
    vector<int> nums = {1,0,-1,0,-2,2,2,4,5,-1,-1,-2};
    const vector<vector<int>> &sum = s->fourSum(nums, 0);
    for(vector<int> v:sum){
        cout<<"[";
        for(int n: v){
            cout<<n<<",";
        }
        cout<<"]"<<endl;
    }
    return 0;
}

