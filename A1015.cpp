#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
int isPrimer(int n) {
	if (n == 2) return 1;
	else if (n % 2 == 0)return 0;//采用奇数筛的话，注意一下1、2这些特殊情况
	if (n <= 1) return 0;
	for (int i = 3; i*i <= n; i += 2) {
		if (n%i == 0) return 0;
	}
	return 1;
}

int ReverseOnRadix(int n, int radix) {
	int reverse = 0;
	while (n > 0) {
		reverse *= radix;
		reverse += n % radix;
		n /= radix;
	}
	//std::cout << " Reverse: " << reverse << std::endl;
	return reverse;
}

int main() {
	int num, radix;
	std::cin >> num;
	while (num >= 0) {
		std::cin >> radix;
		if (isPrimer(ReverseOnRadix(num, radix)) && isPrimer(num)) std::cout << "Yes" << std::endl;//必须确定原数字num是素数，不然最后一个测试点过不去
		else std::cout << "No" << std::endl;
		std::cin >> num;
	}
	getchar();
	getchar();

	return 0;
}