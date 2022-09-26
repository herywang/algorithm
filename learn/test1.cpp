#include <iostream>

using namespace std;

class A {};

int main() {
    A a;
    A *b;
    cout << "sizeof(*a): " << sizeof(b) << endl;
    cout << "sizeof(A): " << sizeof(A) << endl;
    cout << "sizeof(a): " << sizeof(a) << endl;
    return 0;
}