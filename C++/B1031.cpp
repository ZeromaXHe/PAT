#include <iostream>
#include <string>
#include <vector>
int main() {
	int n;
	std::cin >> n;
	std::string s;
	int w[17] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
	char m[11] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };
	int flag1 = 0;
	int sum;
	for (int i = 0; i < n; i++) {
		int flag2 = 0;
		std::cin >> s;
		sum = 0;
		for (int j = 0; j < 17; j++) {
			if (s[j] > '9' || s[j] < '0') {
				std::cout << s << std::endl;
				flag1 = 1;
				flag2 = 1;
				break;
			}
			sum += w[j] * (s[j] - '0');
		}
		if (s[17] != m[sum % 11] && flag2 == 0) {
			std::cout << s << std::endl;
			flag1 = 1;
		}
	}
	if (flag1 == 0) std::cout << "All passed" << std::endl;


	getchar();
	getchar();

	return 0;
}