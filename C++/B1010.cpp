#include <iostream>

int main() {
	int a, b,count = 0;
	while (std::cin >> a >> b) {
		if (b != 0) {
			count++;
			if (count > 1) std::cout << ' ';
			std::cout << a * b << ' ' << b - 1;
		}
		if (b == 0) {
			if (count > 0)break;
			else {
				std::cout << "0 0"; break;
			}
		}
	}
	getchar();
	getchar();
	return 0;
}