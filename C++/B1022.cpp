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
	if (n != 0) DivideByD(n, d);//ע�����������Ƿ�Ϊ0����Ȼ0��ʱ��DivideByD()������û������ġ�
	else std::cout << '0';
	
	getchar();
	getchar();

	return 0;
}