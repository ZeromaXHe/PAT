#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	char c;
	std::cin >> c;

	for (int i = 0; i < (n + 1) / 2; i++) {
		if (i == 0 || i == (n + 1) / 2 - 1) {
			for (int j = 0; j < n; j++) std::cout << c;
		}
		else {
			std::cout << c;
			for (int j = 1; j < n - 1; j++)std::cout << ' ';
			std::cout << c;
		}
		std::cout << std::endl;
	}

	getchar();
	getchar();

	return 0;
}