//
// Created by wangheng on 2022/8/15.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int addDigits(int num) {
        while(num >= 10){
            int sum = 0;
            while(num > 0){
                sum += num%10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }
};

int main() {
    Solution *pSolution = new Solution;
    cout<<pSolution->addDigits(99)<<endl;
    delete pSolution;
    return 0;
}
