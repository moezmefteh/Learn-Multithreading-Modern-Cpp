#include <iostream>

// A function that takes a callback
void performOperation(void (*callback)(int)) {
    for (int i = 0; i < 5; ++i) {
        callback(i);
    }
}

// A callback function
void printNumber(int number) {
    std::cout << "Number: " << number << std::endl;
}

int main() {
    performOperation(printNumber);
    return 0;
}