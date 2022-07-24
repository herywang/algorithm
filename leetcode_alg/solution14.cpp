//
// Created by wangheng on 2021/6/18.
// 最长公共前缀问题
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0){
            return "";
        }else if(strs.size()==1){
            return strs[0];
        }else{
            string ans = strs[0];
            int l = 0;
            while(true){
                for(int i = 1;i<strs.size();i++){
                    if(l >= strs[i].length()){
                        return ans.substr(0, l);
                    }
                    if(strs[i][l] != ans[l]){
                        return ans.substr(0,l);
                    }
                }
                l+=1;
            }
        }
    }
};

int main(){
    vector<string> strs = {"ab", "abbb"};
    auto solution = new Solution;
    auto ans = solution->longestCommonPrefix(strs);
    cout<<ans<<endl;
    return 0;
}
