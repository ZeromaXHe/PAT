#include <iostream>
#include <string>
int main() {
	std::string s;
	std::cin >> s;
	int a[10] = { 0 };
	for (int i = 0; i < s.length(); i++) a[s[i] - '0']++;
	for (int i = 0; i < 10; i++) if (a[i] != 0) std::cout << i << ':' << a[i] << std::endl;
	getchar();
	getchar();

	return 0;
}