#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k <= 0) {
            return s;
        }
        unordered_map<char, int> map;
        for (auto c : s) {
            map[c]++;
        }
        auto cmp = [](pair<char, int> a, pair<char, int> b) {
            return a.second < b.second;
        };
        // 按出现次数从大到小排序
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq1(cmp); // 定义一个优先级队列
        // 用于暂存用过的数据
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq2(cmp); // 第二个暂存的优先级队列

        for (auto _p : map) {
            pq1.emplace(_p.first, _p.second);
        }
        string ans;
        while (!pq1.empty()) {
            auto _p = pq1.top();
            ans.push_back(_p.first);
            pq1.pop();
            _p.second -= 1;
            pq2.emplace(_p);

            if (pq2.size() == k) {
                pair<char, int> _pq2 = pq2.top();
                if (_pq2.second > 0) {
                    pq1.emplace(_pq2);
                }
                pq2.pop();
            }
        }
        return ans.size() == s.size() ? ans : "";
    }

    string rearrangeString2(string s, int k) {
        if (!k) {
            return s;
        }
        // 记录每个字母的出现次数
        unordered_map<char, int> map;
        for (char c : s) {
            map[c]++;
        }
        // 按出现次数从大到小排序
        priority_queue<pair<int, char>> pq;
        for (auto [c, i] : map) {
            pq.emplace(i, c);
        }
        // 用于暂存用过的字母
        queue<pair<int, char>> q;
        string res;
        while (!pq.empty()) {
            // 每次放一个数量最多的字母，然后放入暂存队列
            auto &[i, c] = pq.top();
            res += c;
            q.emplace(i - 1, c);
            pq.pop();
            // 队列长度为k，说明重复元素距离达到了k，可以出队一个元素
            if (q.size() == k) {
                if (q.front().first > 0) {
                    pq.emplace(q.front().first, q.front().second);
                }
                q.pop();
            }
        }
        // 最后根据条件生成的字符串比原字符串短，说明无法放入所有字母
        return res.size() < s.size() ? "" : res;
    }
};

int main() {
    auto s = new Solution;
    cout << s->rearrangeString("aabbccd", 3) << endl;
    delete s;
    return 0;
}