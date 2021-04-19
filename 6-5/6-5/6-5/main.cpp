#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

int main(void) {
	std::list<int> values{ 17,11,40,13,22,54,48,70,22,61,82,78,22,89,99,92,43 };

	std::cout << "The elements in the original sequence ar:\n";
	std::copy(std::begin(values), std::end(values), std::ostream_iterator<int>{std::cout, " "});
	std::cout << std::endl;

	int wanted{ 22 };

	std::partition(std::begin(values), std::end(values),
		[wanted](double value) {
			return value < wanted;
		});


	std::partition(std::begin(values), std::end(values),
		[wanted](double value) {
			return !(wanted < value);
		});

	std::cout << "The elements after partitioning are:\n";
	std::copy(std::begin(values), std::end(values), std::ostream_iterator<int>{std::cout, " "});
	std::cout << std::endl;

	auto pr = std::equal_range(std::begin(values), std::end(values),wanted);
	std::cout << "The lower bound for " << wanted << " is " << *pr.first << std::endl;
	std::cout << "The upper bound for " << wanted << " is " << *pr.second << std::endl;

	std::cout << "\nThe eleements found by equal_range() are:\n";
	std::copy(pr.first, pr.second, std::ostream_iterator<int>{std::cout, " "});

	std::cout << std::endl;


	return 0;
}