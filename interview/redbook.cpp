#include <iostream>
#include <vector>

using namespace std;

long solution(vector<long> &data, const long &N, const long &K) {
    long ans = 0;
    sort(data.begin(), data.end());

    for (int i = 0; i < N; i++) {
        long _a = data[i];
        for (int j = i - 1; j >= 0; j--) {
            long _b = data[j];
            if (_a * _b >= K) {
                ans++;
            } else {
                break;
            }
        }
    }
    return ans * 2;
}

int main() {
    long n, K;
    cin >> n >> K;
    if (n < 2) {
        cout << 0 << endl;
        return 0;
    }

    vector<long> data(n, 0);
    for (long i = 0; i < n; i++) {
        cin >> data[i];
    }
    cout << solution(data, n, K) << endl;
}