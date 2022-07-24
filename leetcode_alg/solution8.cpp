#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <utility>

using namespace  std;
class Solution{
public:
    int myAtoi(string s){
        const string &basicString = this->trim(std::move(s));

        int result=0;
        bool isMinus;

    }

    string trim(string s){
        if(s.empty()){
            return s;
        }
        s.erase(0, s.find_first_of(' '));
        s.erase(s.find_last_not_of(' ')+1);
        return s;
    }
};
int main(){
    cout<<"hello world"<<endl;

    return 0;
}