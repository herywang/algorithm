/**
 * @file duxiaoman1.cpp
 * @author wangheng
 * @version 0.1
 * @date 2022-08-31
 *
 * @copyright Copyright (c) 2022 wangheng
 *
 */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> rules;
    for (int i = 0; i < m; i++) {
        vector<int> rule(3);
        cin >> rule[0] >> rule[1] >> rule[2];
        rules.push_back(rule);
    }
    sort(rules.begin(), rules.end(), [](vector<int> r1, vector<int> r2) {
        return r1[0] - r2[0];
    });
}