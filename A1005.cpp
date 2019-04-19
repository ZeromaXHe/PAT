#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


int main() {
	std::string inputS, outputS,
	num[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	int sum = 0;
	std::cin >> inputS;
	for (int i = 0; i < inputS.length(); i++) {
		sum += inputS[i] - '0';
	}
	outputS = std::to_string(sum);
	for (int i = 0; i < outputS.length(); i++) {
		if (i != 0) std::cout << ' ';
		std::cout << num[outputS[i] - '0'];
	}
	getchar();
	getchar();

	return 0;
}