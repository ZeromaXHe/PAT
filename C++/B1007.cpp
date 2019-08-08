#include <iostream>
bool IsSigPrimer(int singular) {

	for (int i = 3; i*i <= singular; i += 2) {
		if (singular % i == 0) return false;
	}
	return true;
}
int main() {
	int n, count = 0;
	std::cin >> n;

	for (int i = 3; i < n - 1; i += 2) {
		if (IsSigPrimer(i) && IsSigPrimer(i + 2)) count++;
	}
	std::cout << count;
	return 0;
}