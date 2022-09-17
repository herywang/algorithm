#include <iostream>
#include <vector>

using namespace std;

int solve(string &str, int n) {
    if (n < 4) {
        return 0;
    }
    int ans = 0;
    while (true) {
        vector<int> _index;
        for (int i = 0; i < str.size(); i++) {
            if (_index.size() == 4) {
                break;
            }
            if (str[i] == ' ') {
                continue;
            }
            if (str[i] == 'p' && _index.size() == 0) {
                _index.emplace_back(i);
            } else if (str[i] == 'o' && _index.size() == 1) {
                _index.emplace_back(i);
            } else if (str[i] == 'n' && _index.size() == 2) {
                _index.emplace_back(i);
            } else if (str[i] == 'y' && _index.size() == 3) {
                _index.emplace_back(i);
            }
        }
        if (_index.size() != 4) {
            break;
        } else {
            // for (int &j : _index) {
            //     str[j] = ' ';
            // }
            for (int j = 3; j >= 0; j--) {
                str.erase(str.begin() + _index[j]);
            }
            ans += 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    string str;
    cin >> str;
    cout << solve(str, n) << endl;
    return 0;
}