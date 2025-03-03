#include <iostream>
#include <vector>
#include <string>

int main()
{
    std::vector<std::string> strings(5);

    // Lambda expression which captures "strings" by reference
    [&strings]{
        std::cout << "Size in lambda (by reference) = " << strings.size() << '\n';
    }();

    std::cout << "After calling lambda (by reference), size in main = " << strings.size() << '\n';

    // Lambda expression which captures "strings" by move
    [vec_strings = std::move(strings)] () {
        std::cout << "Size in lambda (by move) = " << vec_strings.size() << '\n';
    }();

    std::cout << "After calling lambda (by move), size in main = " << strings.size() << "\n\n";

    // Lambda expression with lambda-local variable
    auto add_two = [y = 2] (int x) {
        return x + y;
    };

    std::cout << "Calling add_two(2) gives " << add_two(2) << '\n';
    std::cout << "Calling add_two(5) gives " << add_two(5) << '\n';

    // Lambda expression with lambda-local variable initialized using a local variable
    int z = 1;
	auto add_z_plus1 = [y = z + 1](int x){
		return x + y;
	};

    std::cout << "Calling add_z_plus1(2) gives " << add_z_plus1(2) << '\n';
    std::cout << "Calling add_z_plus1(5) gives " << add_z_plus1(5) << '\n';
}
