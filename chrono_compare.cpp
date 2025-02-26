#include <iostream>
#include <chrono>
//g++ -std=c++14 chrono_compare.cpp -o chrono_compare

int main() {
    using namespace std::chrono_literals;

    auto duration1_qualified = 2s;
    auto duration2_qualified = 1500ms;
    auto duration3_qualified = 2000000us;

    // Comparison of durations
    if (duration1_qualified == duration3_qualified) {
        std::cout << "duration1 and duration3 are equal (2 seconds)." << std::endl;
    }

    if (duration1_qualified > duration2_qualified) {
        std::cout << "duration1 (2 seconds) is longer than duration2 (1.5 seconds)." << std::endl;
    }

    // Duration cast examples
    auto milliseconds1 = std::chrono::duration_cast<std::chrono::milliseconds>(duration1_qualified);
    std::cout << "duration1 in milliseconds: " << milliseconds1.count() << "ms" << std::endl;

    auto seconds2 = std::chrono::duration_cast<std::chrono::seconds>(duration2_qualified);
    std::cout << "duration2 in seconds: " << seconds2.count() << "s" << std::endl;

    return 0;
}