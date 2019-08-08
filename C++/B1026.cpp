#include <iostream>
#include <iomanip>

int main() {
	int c1, c2, c;
	std::cin >> c1 >> c2;
	c = (c2 - c1 + 50) / 100;//注意这里实现“四舍五入”的操作：先给(c2-c1)加上50，这样如果(b-a)/100的小数位大于等于0.5则会进位，小于等于0.5则会舍去
	int h, m, s;
	h = c / 3600;
	m = c / 60 % 60;
	s = c % 60;
	printf("%02d:%02d:%02d", h, m, s);

	getchar();
	getchar();

	return 0;
}