#include <iostream>
using namespace std;

int main() {
    string str;
    cin >> str;
    int counter[26] = {0};
    for (int i = 0; i < str.length(); i++) {
        counter[str[i] - 'a'] += 1;
    }
    string res = "";
    for (int i = 0; i < 26; i++) {
        if (counter[i] >= 2) {
            char c = ('a' + i);
            res.push_back(c);
        }
    }
    cout << res << endl;
    return 0;
}