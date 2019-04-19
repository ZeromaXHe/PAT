#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	long long a[3], b[3], c[3];
	long long count;
	scanf_s("%lld.%lld.%lld %lld.%lld.%lld", &a[0], &a[1], &a[2], &b[0], &b[1], &b[2]);
	int sign = 1;
	if (a[0] > b[0] || (a[0] == b[0] && a[1] > b[1]) || (a[0] == b[0] && a[1] == b[1] && a[2] > b[2])) {
		sign = -1;
	}
	if (sign == -1) {
		count = a[0] * 29 * 17 + a[1] * 29 + a[2] - b[0] * 29 * 17 - b[1] * 29 - b[2];
		std::cout << '-';
	}
	else {
		count = b[0] * 29 * 17 + b[1] * 29 + b[2] - a[0] * 29 * 17 - a[1] * 29 - a[2];
	}
	c[0] = count / 17 / 29;
	c[1] = count / 29 % 17;
	c[2] = count % 29;
	std::cout << c[0] << '.' << c[1] << '.' << c[2];

	getchar();
	getchar();

	return 0;
}