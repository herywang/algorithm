//
// Created by wangheng on 2022/8/9.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> stack;
        for(string &s: tokens){
            if(s.length() == 1 && s[0] == '+'){
                int a = stack.back();
                stack.pop_back();
                int b = stack.back();
                stack.pop_back();
                stack.emplace_back(a+b);
            }else if(s.length() == 1 && s[0] == '-'){

            }else if(s.length() == 1 && s[0] == '*'){

            }else if(s.length() == 1 && s[0] == '/'){

            }else{
                int a = atoi(s.c_str());
                stack.emplace_back(a);
            }
        }

    }
};

int main() {

    return 0;
}
