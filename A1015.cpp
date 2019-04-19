#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
int isPrimer(int n) {
	if (n == 2) return 1;
	else if (n % 2 == 0)return 0;//��������ɸ�Ļ���ע��һ��1��2��Щ�������
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
		if (isPrimer(ReverseOnRadix(num, radix)) && isPrimer(num)) std::cout << "Yes" << std::endl;//����ȷ��ԭ����num����������Ȼ���һ�����Ե����ȥ
		else std::cout << "No" << std::endl;
		std::cin >> num;
	}
	getchar();
	getchar();

	return 0;
}