#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
int ExamNum(int &n) { /*ע�⣺ʹ�����ò���*/
	int digit[4] = { 0 };//ע�⣺��0����Ȼ��������Ĵ𰸲���4λʱ���ܳ�bug
	for (int i = 0; i < 4; i++) {
		digit[i] = n % 10;
		n /= 10;
	}
	std::sort(digit, digit + 4);
	std::cout << digit[3] << digit[2] << digit[1] << digit[0] << " - " << digit[0] << digit[1] << digit[2] << digit[3] << " = ";
	n = digit[3] * 1000 + digit[2] * 100 + digit[1] * 10 + digit[0] - digit[0] * 1000 - digit[1] * 100 - digit[2] * 10 - digit[3];
	std::cout << std::setw(4) << std::setfill('0') << n;//ע�⣺�𰸱�����ʾ4λ
	return 0;
}
int main() {
	int n;
	std::cin >> n;
	ExamNum(n);
	while (n != 0 && n != 6174) {
		std::cout << std::endl;
		ExamNum(n);
	}
	getchar();
	getchar();

	return 0;
}