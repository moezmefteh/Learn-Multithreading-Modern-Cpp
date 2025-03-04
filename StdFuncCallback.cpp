#include <iostream>
#include <functional>

// A function that takes a callback
void performOperation(std::function<void(int)> callback) {
    for (int i = 0; i < 5; ++i) {
        callback(i);
    }
}

// A callback function
void printNumber(int number) {
    std::cout << "Number: " << number << std::endl;
}

int main() {
    // Using std::bind to create a callback
    auto callback = std::bind(printNumber, std::placeholders::_1);
    performOperation(callback);
    return 0;
}