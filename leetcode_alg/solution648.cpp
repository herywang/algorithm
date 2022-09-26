/**
 * @file solution648.cpp
 * @author your name (you@domain.com)
 * @brief 单词替换
 * @version 0.1
 * @date 2022-09-26
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

string replaceWords(vector<string> &dictionary, string sentence) {
    if (dictionary.size() == 0) {
        return sentence;
    }
    // 切割字符串
    stringstream ss(sentence);
    string tmpStr;
    vector<string> words;
    while (getline(ss, tmpStr, ' ')) {
        words.push_back(tmpStr);
    }
    for (int i = 0; i < words.size(); i++) {
        bool flag = false;
        string _d = "";
        for (string &dict : dictionary) {
            if (words[i].substr(0, dict.length()) == dict) {
                flag = true;
                _d = dict;
                break;
            }
        }
        if (flag) {
            words[i] = _d;
        }
    }
    // 对结果进行再次拼接
    string ans;
    for (int i = 0; i < words.size(); i++) {
        if (i == words.size() - 1) {
            ans = ans + words[i];
            continue;
        }
        ans = ans + words[i] + ' ';
    }
    return ans;
}

int main() {
    vector<string> dictionary = {"catt", "cat", "bat", "rat"};

    sort(dictionary.begin(), dictionary.end());
    for (string &s : dictionary) {
        cout << s << endl;
    }
    string ans = replaceWords(dictionary, "the cattle was rattled by the battery");
    cout << ans << endl;
    return 0;
}