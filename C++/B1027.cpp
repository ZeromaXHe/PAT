#include <iostream>
#include <iomanip>
int SandGlass(char s, int i, int imax) {
	if (i != 1) {
		for (int x = 0; x < imax - i; x++) std::cout << ' ';
		for (int x = 0; x < 2 * i - 1; x++) std::cout << s;
		std::cout << std::endl;
		SandGlass(s, i - 1, imax);
		for (int x = 0; x < imax - i; x++) std::cout << ' ';
		for (int x = 0; x < 2 * i - 1; x++) std::cout << s;
		std::cout << std::endl;
	}
	else {
		for (int x = 0; x < imax - i; x++) std::cout << ' ';
		for (int x = 0; x < i; x++) std::cout << s;
		std::cout << std::endl;
	}
	return 0;
}
int main() {
	int n;
	char s;
	std::cin >> n >> s;
	int i;
	for (i = 1; 2 * i*i - 1 <= n; i++) {}
	SandGlass(s, i-1, i-1);
	std::cout << n - 2 * (i - 1)*(i - 1) + 1;

	getchar();
	getchar();

	return 0;
}