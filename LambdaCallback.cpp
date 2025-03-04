#include <iostream>
#include <functional>

// A function that takes a callback
void performOperation(std::function<void(int)> callback) {
    for (int i = 0; i < 5; ++i) {
        callback(i);
    }
}

int main() {
    // Using a lambda function as a callback
    performOperation( [](int number ) {
        std::cout << "Number: " << number << std::endl;
    });
    return 0;
}