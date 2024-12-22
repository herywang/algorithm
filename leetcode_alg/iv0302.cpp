//
// Created by wangheng on 1/8/24.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
    }

    void push(int x) {
        if(this->_s.empty()){
            this->_s.push({x, x});
            this->min = x;
        }else{
            this->min = std::min(this->min, x);
            this->_s.push({x, this->min});
        }
    }

    void pop() {
        this->_s.pop();
    }

    int top() {
        return this->_s.top().first;
    }

    int getMin() {
        return this->_s.top().second;
    }
private:
    stack<pair<int, int>> _s;
    int min;
};

int main(int argc, char *argv[]) {

    return 0;
}