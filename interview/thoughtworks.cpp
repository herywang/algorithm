#include <stdio.h>
void fun(char **p) {
    int i;
    for (i = 0; i < 4; i++) printf("%s", p[i]);
}
int main() {
    int n = 10;
    int const *p = &n;
    p++;
    printf("%d", *p);
    return 0;
}

// int main() {
//     cout << f(3) << endl;
// }