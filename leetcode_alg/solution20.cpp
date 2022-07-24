//
// Created by wangheng on 2021/6/20.
// 有效括号问题
#include "iostream"
#include "stack"

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.length() == 0)
            return true;
        if(s.length() % 2 != 0)
            return false;
        stack<char> st;
        for(char c: s){
            switch (c) {
                case '(':{
                    st.push(c);
                    break;
                }
                case ')':{
                    if(st.size() == 0){
                        return false;
                    }else{
                        char &i = st.top();
                        if(i != '('){
                            return false;
                        }
                        st.pop();
                    }
                    break;
                }
                case '[':{
                    st.push(c);
                    break;
                }
                case ']':{
                    if(st.size() == 0){
                        return false;
                    }else{
                        char &i = st.top();
                        if(i != '['){
                            return false;
                        }
                        st.pop();
                    }
                    break;
                }
                case '{':{
                    st.push(c);
                    break;
                }
                case '}':{
                    if(st.size() == 0){
                        return false;
                    }else{
                        char &i = st.top();
                        if(i != '{'){
                            return false;
                        }
                        st.pop();
                    }
                    break;
                }
                default:{
                    continue;
                }
            }
        }
        if(st.size() == 0){
            return true;
        }
        return false;
    }
};

int main(){
    Solution *s = new Solution;
    cout<<s->isValid("()[]{}]")<<endl;
    return 0;
}

