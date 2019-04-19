#include <iostream>

int main() {
	int a[10] = { 0 };
	for (int i = 0; i < 10; i++) {
		std::cin >> a[i];
	}
	int num = -1, posi = -1;
	for (int i = 1; i < 10; i++) {
		if (a[i] != 0) {
			posi = i;
			num = a[i];
			a[i] -= 1;
			break;
		}
		else if (i == 9) {
			num = 0;
			break;
		}
	}
	if (num == 0)std::cout << '0';
	else {
		std::cout << posi;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < a[i]; j++) {
				std::cout << i;
			}
		}
	}
	
	getchar();
	getchar();

	return 0;
}