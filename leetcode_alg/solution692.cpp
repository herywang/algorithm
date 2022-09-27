/**
 * @file solution692.cpp
 * @author your name (you@domain.com)
 * @brief 前k个高频单词
 * @version 0.1
 * @date 2022-09-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

vector<string> topKFrequent(vector<string> &words, int k) {
    vector<string> ans;
    unordered_map<string, int> _map;
    for (string &s : words) {
        if (_map.count(s) == 0) {
            _map[s] = 1;
        } else {
            _map[s] += 1;
        }
    }
    auto function = [&](pair<string, int> p1, pair<string, int> p2) {
        if (p1.second == p2.second) {
            return p1.first > p2.first;
        }
        return p1.second < p2.second;
    };

    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(function)> _queue(function);
    for (auto &p : _map) {
        _queue.push(p);
    }
    for (int i = 0; i < k; i++) {
        pair<string, int> p = _queue.top();
        ans.push_back(p.first);
        _queue.pop();
    }
    return ans;
}

int main() {
    vector<string> words = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
    vector<string> words1 = {"i", "love", "leetcode", "i", "love", "coding"};
    vector<string> ans = topKFrequent(words1, 2);
    for (auto &s : ans) {
        cout << s << endl;
    }
    return 0;
}