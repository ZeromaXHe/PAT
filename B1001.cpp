#include <iostream>
int Callatz(int x);
int main() {
	int n, count=0;
	std::cin >> n;
	for (; n != 1; count++) {
		n = Callatz(n);
	}
	std::cout << count << std::endl;
	getchar();
	getchar();
	return 0;
}
int Callatz(int x) {
	if (x % 2 == 0) {
		x /= 2;
	}
	else x = (3 * x + 1) / 2;
	return x;
}