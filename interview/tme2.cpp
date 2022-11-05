#include <iostream>
#include <vector>
#include <string.h>
#define Mul(x) (x * x)

using namespace std;

int main() {
    int x = 3;
    int y = Mul(x++);
    int z = Mul(++x);
    cout << y << endl;
    cout << z << endl;
    return 0;
}