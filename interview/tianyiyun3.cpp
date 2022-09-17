#include <iostream>
#include <vector>

using namespace std;

int main() {
    int power, len;
    cin >> power >> len;
    vector<int> value(len, 0);
    vector<int> weight(len, 0);
    for (int i = 0; i < len; i++) {
        cin >> value[i];
    }
    for (int i = 0; i < len; i++) {
        cin >> weight[i];
    }
    vector<int> dp(power + 1, 0);
    for (int i = 1; i < len + 1; i++) {
        for (int j = power; j >= weight[i - 1]; j--) {
            dp[j] = max(dp[j - weight[i - 1]] + value[i - 1], dp[j]);
        }
    }
    cout << dp[power] << endl;
    return 0;
}