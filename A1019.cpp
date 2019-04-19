#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
bool IsP(std::vector<long int> digit) {
	for (int i = 0; i <= (digit.size() - 1) / 2; i++) {
		if (digit[i] != digit[digit.size() - 1 - i]) return false;
	}
	return true;
}

int main() {
	long int n, b;
	std::cin >> n >> b;
	std::vector<long int> digit;
	while (n > 0) {
		digit.push_back(n%b);
		n /= b;
	}
	if (IsP(digit)) {
		printf("Yes\n");
		for (int i = 0; i < digit.size(); i++) if (i == 0)std::cout << digit[0]; else std::cout << ' ' << digit[i];
	}
	else {
		printf("No\n");
		for(int i=digit.size()-1;i>=0;i--) if (i == digit.size()-1)std::cout << digit[digit.size()-1]; else std::cout << ' ' << digit[i];
	}

	getchar();
	getchar();

	return 0;
}