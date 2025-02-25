#include <iostream>
#include <algorithm>
#include <vector>
#include <chrono>

int main() {
    // Lambda expressions and return type deduction
    auto lam1 = [] (int arg) { return 2 * arg; };
    std::cout << "Calling lam1 with argument 3\n";
    std::cout << "Returns " << lam1(3) << '\n';

    // Lambda capturing local variable by reference
    int n = 2;
    auto lam2 = [&n] (int arg) { return (++n * arg); };
    lam2(3);
    std::cout << "n = " << n << '\n';

    // Algorithm call with predicate using lambda expression with capture
    std::vector<int> vec1{4, 2, 3, 5, 1};
    std::cout << "Elements of vector: ";
    for (auto elem : vec1)
        std::cout << elem << ", ";
    std::cout << '\n';

    int radix = 3;
    auto n_multiples = std::count_if(vec1.begin(), vec1.end(), [radix] (int n) {
        return (n % radix == 0);
    });
    std::cout << "The vector has " << n_multiples << " element(s) which are exact multiples of " << radix << '\n';

    // Algorithm call with predicate using lambda expression
    std::vector<int> vec2{4, 2, 3, 5, 1};
    std::cout << "Elements of vector: ";
    for (auto i : vec2)
        std::cout << i << ", ";
    std::cout << '\n';

    auto n_even = std::count_if(vec2.begin(), vec2.end(), [] (int n) {
        return (n % 2 == 0);
    });
    std::cout << "The vector has " << n_even << " element(s) with even values\n";

    return 0;
}