#include <iostream>
#include <vector>

int main() {
	int n;
	std::cin >> n;
	std::vector<int> a(n + 1);
	int num, score;
	for (int i = 0; i < n; i++) {
		std::cin >> num >> score;
		a[num] += score;
	}
	int max = a[1], t = 1;
	for (int i = 2; i <= n; i++) {
		if (max < a[i]) {
			max = a[i];
			t = i;
		}
	}
	std::cout << t << " " << max;

	getchar();
	getchar();

	return 0;
}