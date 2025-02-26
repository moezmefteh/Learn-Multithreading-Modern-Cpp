#include <iostream>
#include <vector>

int main()
{
	std::vector<int> vec{4, 2, 3, 5, 1};
	//std::vector<std::string>::iterator it = vec.begin();
	//auto it = vec.begin();
	for (auto it = vec.begin(); it != vec.end(); ++it)
		*it += 2;
	
	std::cout << "Vector elements: ";
	for (auto it = vec.begin(); it != vec.end(); ++it)
		std::cout << *it << ", ";
}