#include <iostream>
#include <iomanip>
bool IsPrimer(int x) {
	for (int i = 3; i*i <= x; i++) {
		if (x%i == 0)return false;
	}
	return true;
}
int main() {
	int n, m;
	int count = 0;
	int printNum = 0;
	int primerCadi = 2;
	std::cin >> n >> m;
	for (; count < m; (primerCadi == 2 ? primerCadi += 1 : primerCadi += 2)) {
		if (IsPrimer(primerCadi)) {
			count++;
			if (count >= n) {
				printNum += 1;
				if (printNum % 10 != 1) std::cout << ' ';
				std::cout << primerCadi;
				if (printNum % 10 == 0) std::cout << std::endl;
			}
		}

	}
	getchar();
	getchar();
	return 0;
}