#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

int main(void) {

	std::vector<double> temperatures{ 65,75,56,48,31,28,32,29,40,41,44,50 };
	std::vector<double> low_t;
	std::vector<double> high_t;

	auto average = std::accumulate(std::begin(temperatures), std::end(temperatures), 0.0) / temperatures.size();

	std::partition_copy(std::begin(temperatures), std::end(temperatures)
		, std::back_inserter(low_t), std::back_inserter(high_t)
		, [average](const double& t) {
			return t < average;
		});


	std::copy(std::begin(low_t), std::end(low_t), std::ostream_iterator<double>{std::cout, " "});
	std::cout << std::endl;

	std::copy(std::begin(high_t), std::end(high_t), std::ostream_iterator<double>{std::cout, " "});
	std::cout << std::endl;

	return 0;
}