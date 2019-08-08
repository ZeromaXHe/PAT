#include <iostream>
int Reverse(int a[], int x, int y) {
	int tmp;
	for (int i = x; i < (y + 1 + x) / 2; i++) {
		tmp = a[i];
		a[i] = a[y + x - i];
		a[y + x - i] = tmp;
	}
	return 0;
}
int main() {
	int n, m;
	int a[100];
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	Reverse(a, 0, n - 1);
	Reverse(a, 0, m - 1);
	Reverse(a, m, n - 1);

	for (int i = 0; i < n; i++) {
		if (i != 0) std::cout << ' ';
		std::cout << a[i];
	}
	getchar();
	getchar();
	return 0;
}