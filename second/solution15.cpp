#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i = 0;
        vector<vector<int>> res;
        while(i < nums.size() - 2){
            int j = i + 1;
            while(j < nums.size() - 1){
                int k = j + 1;
                while(k < nums.size()){
                    if(nums[i] + nums[j] + nums[k] == 0){
                        vector<int> row = {nums[i], nums[j], nums[k]};
                        res.push_back(row);
                    }else if(nums[i] + nums[j] + nums[k] <0){
                        j++;
                    }else{
                        k--;
                    }
                    
                    k++;
                }
                j++;
            }
            i++;
        }
        return {};
        
    }
};

int main(){

    return 0;
}