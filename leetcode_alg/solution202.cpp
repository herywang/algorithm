//
// Created by wangheng on 2022/7/20.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;
        while(true) {
            slow = getNext(slow);
            fast = getNext(fast);
            fast = getNext(fast);
            if (slow == fast && slow != 1) {
                return false;
            } else if (slow == 1 || fast == 1) {
                return true;
            }
        }
    }

    int getNext(int n){
        int ans = 0;
        int t;
        while(n>0){
            t = n % 10;
            ans += t*t;
            n /= 10;
        }
        return ans;
    }
};

void testSolution(){
    auto s = new Solution;
    cout<<s->isHappy(19)<<endl;
}

int main() {
testSolution();
    return 0;
}
