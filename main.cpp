#include <iostream>
using namespace std;
struct Msg{
    char a[10];
    char b[4];
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    Msg m;
    strcpy(m.a, "12333");
    strcpy(m.b, "10.6.1.34");
    cout<<m.a<<"\n"<<m.b<<endl;
    return 0;
}
