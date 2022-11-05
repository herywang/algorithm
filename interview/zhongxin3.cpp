#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }
    // 上下翻转
    for (int i = 0; i < n / 2; i++) {
        for (int j = 0; j < n; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[n - i - 1][j];
            matrix[n - i - 1][j] = tmp;
        }
    }
    // 左右翻转
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n / 2; j++) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][n - j - 1];
            matrix[i][n - j - 1] = tmp;
        }
    }
    for (auto row : matrix) {
        for (auto element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    return 0;
}