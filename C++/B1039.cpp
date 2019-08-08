#include <iostream>
#include <string>
#include <vector>

int main() {
	std::string a, b;
	std::cin >> a >> b;
	int c[100] = { 0 };
	for (int i = 0; i < a.length(); i++) {
		c[a[i] - '0']++;
	}
	int count = 0;
	for (int i = 0; i < b.length(); i++) {
		if (c[b[i] - '0'] > 0) c[b[i] - '0']--;
		else count++;
	}
	if (count > 0) {
		std::cout << "No " << count;
	}
	else {
		std::cout << "Yes ";
		for (int i = 0; i < 100; i++) {
			count += c[i];
		}
		std::cout << count;

	}
	getchar();
	getchar();

	return 0;
}