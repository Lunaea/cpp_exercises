import std;

int main() {
	std::cout << "Please think of a number between 1 and 100\n";
	char repeat{};

	do {
		int max{ 101 };
		int min{ 0 };
		int guess{ 50 };
		std::vector<int> guesses{};
		bool guessed{ false };

		while (guesses.size() < 7) {
			std::cout << "Is " << guess << " your number? (c) if correct, otherwise is it (m)ore or (l)ess?\n";
			char in{};
			std::cin >> in;
			switch (in) {
			case 'c': case 'C':
				std::cout << "Got it!\n";
				guessed = true;
				break;
			case 'l': case 'L':
				max = guess;
				guesses.push_back(guess);
				guess = (guess + min) / 2;
				break;
			case 'm': case 'M':
				min = guess;
				guesses.push_back(guess);
				guess = (guess + max) / 2;
				break;
			default:
				std::cout << "Invalid input\n";
				break;

			}
			if (guessed)
				break;
		}
		std::cout << "Play again? y or n: ";
		std::cin >> repeat;
	} while (repeat == 'y' || repeat == 'Y');
	
	std::cout << "Thanks for playing! See you next time!\n";
	return 0;
}