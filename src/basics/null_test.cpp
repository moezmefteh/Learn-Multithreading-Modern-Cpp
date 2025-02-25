#include <iostream>

void func(int x) {
    std::cout << "Called func(int)" << std::endl;
}

void func(int* ptr) {
    std::cout << "Called func(int*)" << std::endl;
}

int main() {
    //func(NULL);
    func(nullptr);
    return 0;
}