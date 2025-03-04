#include <iostream>
#include <functional>

class MyClass {
public:
    void printNumber(int number) {
        std::cout << "Number: " << number << std::endl;
    }
};

void performOperation(std::function<void(int)> callback) {
    for (int i = 0; i < 5; ++i) {
        callback(i);
    }
}

int main() {
    MyClass myObject;
    // Using std::bind to create a member function callback
    auto callback = std::bind(&MyClass::printNumber, &myObject, std::placeholders::_1);
    performOperation(callback);
    return 0;
}