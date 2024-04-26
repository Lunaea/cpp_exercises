//import std;
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <ranges>

int main() {
	double input{};
	double max{ -10000000 };
	double min{ 10000000 };
	std::string unit{};
	double sum{ 0 };
	std::vector<double> entries{};

	constexpr int m_to_cm{ 100 };
	constexpr double in_to_cm{ 2.54 };
	constexpr int ft_to_in{ 12 };

	while (std::cin >> input >> unit) {
		if (unit != "cm" && unit != "m" && unit != "in" && unit != "ft") {
			std::cout << "invalid unit, use cm, m, in, or ft\n";
			continue;
		}
		std::cout << "you entered: " << input << unit;

		/*if (!max && !min) {
			std::cout << " this is the first entry\n";
			max = input;
			min = input;
		}*/

		double input_in_meters{ 0 };
		if (unit == "m")
			input_in_meters = input;
		else if (unit == "cm")
			input_in_meters = input / m_to_cm;
		else if (unit == "in")
			input_in_meters = input * in_to_cm / m_to_cm;
		else if (unit == "ft")
			input_in_meters = input * ft_to_in * in_to_cm / m_to_cm;

		if (input_in_meters >= max) {
			max = input_in_meters;
			std::cout << " the greatest so far!\n";
		}
		if (input_in_meters <= min) {
			min = input_in_meters;
			std::cout << " the smallest so far!\n";
		}
		if (input_in_meters > min && input_in_meters < max) {
			std::cout << " somewhere in between\n";
		}

		entries.push_back(input_in_meters);
	}

	std::ranges::sort(entries);

	std::cout << "Thanks for using the program!\n"
		<< "The smallest entry (in meters) was: " << min << "m\n"
		<< "The largest entry (in meters) was: " << max << "m\n"
		<< "The total number of entries was: " << entries.size() << '\n'
		<< "The entries (in meters) were: ";

	for (double x : entries) {
		std::cout << x << "m ";
		sum += x;
	}

	std::cout << "\nThe total distance (in meters) entered was: " << sum << "m\n"
		<< "See you later!\n";

	return 0;
}