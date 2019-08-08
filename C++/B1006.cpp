#include <iostream>

int main() {
	int n, b, s, g;
	std::cin >> n;
	s = n / 10 % 10;
	b = n / 100;
	g = n % 10;
	for (int i = 0; i < b; i++) { std::cout << 'B'; }
	for (int i = 0; i < s; i++) { std::cout << 'S'; }
	for (int i = 0; i < g; i++) { std::cout << i + 1; }
	getchar();
	getchar();
	return 0;
}