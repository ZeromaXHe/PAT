#include <iostream>

int DivideByD(int n, int d) {
	if (n != 0) {
		DivideByD(n / d, d);
		std::cout << n % d;
	}
	return 0;
}
int main() {
	int a, b, d;
	std::cin >> a >> b >> d;
	int n = a + b;
	if (n != 0) DivideByD(n, d);//注意分情况讨论是否为0，不然0的时候DivideByD()函数是没有输出的。
	else std::cout << '0';
	
	getchar();
	getchar();

	return 0;
}