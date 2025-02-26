#include <iostream>
#include <vector>
#include <string>

// Example 1: Passing an lvalue to a function which takes an rvalue reference
void func1(std::vector<std::string>&& arg)
{
    std::cout << "Example 1: Argument vector has " << arg.size() << " elements" << std::endl;
}

// Example 2: Passing a large object by value
void func2(std::vector<std::string> arg)
{
    std::cout << "Example 2: Argument vector has " << arg.size() << " elements" << std::endl;
}

// Example 3: Function argument which is an rvalue reference
void func3(int&& x)
{
    std::cout << "Example 3: Rvalue reference" << std::endl;
}

int main()
{
    // Example 1
    std::vector<std::string> vec1(1000000);
    std::cout << "Example 1: Before calling func1, vector has " << vec1.size() << " elements\n";
    func1(std::move(vec1));
    std::cout << "Example 1: After calling func1, vector has " << vec1.size() << " elements\n";

    // Example 2
    std::vector<std::string> vec2(1000000);
    std::cout << "Example 2: Before calling func2, vector has " << vec2.size() << " elements\n";
    func2(vec2);
    std::cout << "Example 2: After calling func2, vector has " << vec2.size() << " elements\n";

    // Example 3
    func3(2);
    int y = 2;
    // func3(y); // Uncommenting this line will cause a compilation error

    return 0;
}