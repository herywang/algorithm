#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    string str;
    cin >> str;
    unordered_set<char> _set = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    for (int i = 0; i < str.length(); i++) {
        if (_set.count(str[i]) == 0) {
            // 辅音
            if (str[i] >= 'a' && str[i] <= 'z') {
                // 小写变大写
                str[i] = str[i] - 32;
            }
        } else {
            // 元音
            if (str[i] >= 'A' && str[i] <= 'Z') {
                // 大写变小写
                str[i] = str[i] + 32;
            }
        }
    }
    cout << str << endl;
    return 0;
}