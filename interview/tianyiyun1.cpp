#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(pair<int, int> _p1, pair<int, int> _p2) {
    if (_p1.first == _p2.first) {
        return _p1.second < _p2.second;
    }
    return _p1.first < _p2.first;
}

pair<int, int> split(string _tmp) {
    pair<int, int> ans;
    for (int i = 0; i < _tmp.length(); i++) {
        if (_tmp[i] == ',') {
            ans.first = atoi(_tmp.substr(0, i).c_str());
            ans.second = atoi(_tmp.substr(i + 1, _tmp.size()).c_str());
            return ans;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> samples;
    for (int i = 0; i < n; i++) {
        string _tmp;
        cin >> _tmp;
        pair<int, int> _p = split(_tmp);
        samples.push_back(_p);
    }
    sort(samples.begin(), samples.end(), comp);
    int ans = 0;
    if (n == 1) {
        cout << samples[0].second - samples[0].first << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (i == 0) {
            ans += (min(samples[i + 1].first, samples[i].second) - samples[i].first);
        } else if (i > 0 && i + 1 < n) {
            // i > 0
            ans += (min(samples[i + 1].first, samples[i].second) - max(samples[i].first, samples[i - 1].second));
        } else {
            // i+1 == n, 最后一个线段
            ans += (samples[i].second - max(samples[i].first, samples[i - 1].second));
        }
    }
    cout << ans << endl;
    return 0;
}