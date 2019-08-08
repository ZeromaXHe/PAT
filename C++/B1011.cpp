#include <iostream>

int main() {
	int n;
	long long int a, b, c;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> a >> b >> c;
		std::cout << "Case #" << i+1 << ": " << (a + b > c ? "true" : "false") << std::endl;
	}
	getchar();
	getchar();
	return 0;
}