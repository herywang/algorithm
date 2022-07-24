//
// Created by wangheng on 2021/6/22.
//

#ifndef MAC_ALGORITHM_VEC_UTIL_H
#define MAC_ALGORITHM_VEC_UTIL_H
#pragma once

#include "iostream"
#include "vector"

using namespace std;

template<typename T>
void print_vec(const vector<T> &vec) {
    cout << "[";
    for (T t: vec) {
        cout << t << " ";
    }
    cout << "]" << endl;
}


#endif //MAC_ALGORITHM_VEC_UTIL_H
