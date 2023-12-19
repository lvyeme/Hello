#include <iostream>
#define T true
bool check() {
    bool If = T;
    return If;
}

int main() {
    bool If = check();
    std::cout << (If ? "Y" : "N") << std::endl;
    return 0;
}
