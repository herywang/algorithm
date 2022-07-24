//
// Created by wangheng on 2021/6/20.
// 回溯法求解电话号码字母组合
#include "iostream"
#include "map"
#include "vector"
using namespace std;

class Solution {
private:
    map<char, string> phoneMap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
    };
    vector<string> combinations;
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return combinations;
        }
        string combination;
        backtrack(digits, 0, combination);
        return combinations;
    }

    /**
     * 递归方式回溯
     * @param digits 电话号码列表
     * @param index 开始处理第n个电话号码
     * @param combination 组合
     */
    void backtrack(const string& digits,int index, string& combination){
        if(index == digits.length()){
            this->combinations.push_back(combination);
        }else{
            char digit = digits[index];
            string& letters = phoneMap.at(digit);
            for(const char& letter: letters){
                combination.push_back(letter);
                backtrack(digits, index+1, combination);
                combination.pop_back();
            }
        }
    }
};

int main(){

    return 0;
}

