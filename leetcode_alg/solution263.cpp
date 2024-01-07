//
// Created by wangheng on 1/7/24.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) {
            return false;
        }
        vector<int> factor{2, 3, 5};
        for (int f: factor) {
            while (n % f == 0) {
                n = n / f;
            }
        }
        return n == 1;
    }
};

int main(int argc, char *argv[]) {
    auto s = new Solution;
    cout << "结果是:" << s->isUgly(25) << endl;
    delete s;
    return 0;
}