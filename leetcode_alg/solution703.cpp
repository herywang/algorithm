/**
 * @file solution703.cpp
 * @author your name (you@domain.com)
 * @brief 小顶堆解决top K问题
 * @version 0.1
 * @date 2022-08-28
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class KthLargest {
private:
    vector<int> nums;
    int k;

public:
    KthLargest(int k, vector<int> &nums) {
        this->nums = nums;
        this->k = k;
        make_heap(this->nums.begin(), this->nums.end(), greater<int>());
        while (this->nums.size() > k) {
            // 说明:C++ pop_heap操作只是把小顶堆(或者大顶堆)第一个元素放到了vector的末尾,
            // 因此调用完成了pop_heap()之后, 还需要对存储数据的vector进行pop_back()操作
            // 才是真正的数据元素移除
            pop_heap(this->nums.begin(), this->nums.end(), greater<int>());
            this->nums.pop_back();
        }
    }

    int add(int val) {
        this->nums.push_back(val);
        push_heap(this->nums.begin(), this->nums.end(), greater<int>());

        if (this->nums.size() > this->k) {
            pop_heap(this->nums.begin(), this->nums.end(), greater<int>());
            this->nums.pop_back();
        }
        return this->nums.front();
    }
};

void testKthLargest() {
    vector<int> nums = {4, 8, 5, 2};
    auto s = new KthLargest(3, nums);
    cout << s->add(3) << endl;
    cout << s->add(5) << endl;
    cout << s->add(10) << endl;
    cout << s->add(9) << endl;
    cout << s->add(4) << endl;
    delete s;
}

int main() {
    testKthLargest();
    return 0;
}