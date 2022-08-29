#include <iostream>
#include <vector>

using namespace std;

int main() {
    int userLen, weidu, resultId;
    cin >> userLen >> weidu >> resultId;
    resultId = resultId - 1;
    int resultNum = 0;
    int importCount[userLen];
    for (int i = 0; i < userLen; i++) {
        int _ = 0;
        for (int j = 0; j < weidu; j++) {
            int _w;
            cin >> _w;
            _ += _w;
        }
        if (i == resultId) {
            resultNum = _;
        }
        importCount[i] = _;
    }
    int result = 0;
    for (int i = 0; i < userLen; i++) {
        if (importCount[i] > resultNum || (i < resultId && importCount[i] == resultNum)) {
            result++;
        }
    }
    cout << result + 1 << endl;
}