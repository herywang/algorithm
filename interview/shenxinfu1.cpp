//
// Created by wangheng on 2022/9/22.
//

#include <iostream>
#include <vector>
#include <deque>
#include <cmath>

using namespace std;

string solve(string &str, char *abc) {
    deque<char> res;
    if (str[0] <= '9' && str[0] >= '0') {
        int t = atoi(str.c_str());
        while (t > 0) {
            int c = t % 5;
            t = t / 5;
            res.push_front(abc[c]);
        }
        string rr;
        for (char &_c : res) {
            rr.push_back(_c);
        }
        return rr;
    } else {
        int j = 0;
        int sum = 0;
        for (int i = str.length() - 1; i >= 0; i--) {
            if (str[i] == 'o') {
                sum += 0 * pow(5, j);
            } else if (str[i] == 'y') {
                sum += 1 * pow(5, j);
            } else if (str[i] == 'e') {
                sum += 2 * pow(5, j);

            } else if (str[i] == 'a') {
                sum += 3 * pow(5, j);

            } else if (str[i] == 's') {
                sum += 4 * pow(5, j);
            }
            j++;
        }
        return to_string(sum);
    }
}

int main(int argc, char *argv[]) {
    int n;
    cin >> n;
    vector<string> strs;
    for (int i = 0; i < n; i++) {
        string _str;
        cin >> _str;
        strs.push_back(_str);
    }
    for (string s : strs) {
        cout << solve(s, "oyeas") << endl;
    }
    return 0;
}