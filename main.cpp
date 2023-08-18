#include <iostream>


int main() {
    int m = 0;
    int m1 = 1;
    int &n = m;
    int &z = m;
    n = m1;
    std::cout << n;


}
