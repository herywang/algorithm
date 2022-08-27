#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        vector<string> paper;
        vector<string> wall;
        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            string temp;
            cin >> temp;
            paper.push_back(temp);
        }

        if (N == M) {
            for (int i = 0; i < N; i++) {
                cout << paper[i] << endl;
            }
            // 输出换行
            cout << endl;
        } else {
            int border_num = 1;
            while (N * border_num < M) {
                border_num += 2;
            }
            int border_length = border_num * N;
            vector<string> used_paper;
            for (int i = 0; i < border_length; i++) {
                int low = i % N;
                string temp = "";
                for (int j = 0; j < border_num; j++) {
                    temp += paper[low];
                }
                used_paper.push_back(temp);
            }
            int rest = M / 2;
            int l = border_length / 2 - rest;
            int r = border_length / 2 + rest;
            for (int i = l; i <= r; i++) {
                string temp = used_paper[i].substr(l, r - l + 1);
                wall.push_back(temp);
            }
            for (int i = 0; i < M; i++) {
                cout << wall[i] << endl;
            }
            cout << endl;
        }
    }
}