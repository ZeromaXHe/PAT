#include <iostream>
#include <iomanip>
int main() {
	int a, b, c, tmp, multiplier=1;
	std::cin >> a >> b;
	c = a + b;
	tmp = c;
	while (tmp > 999 || tmp <-999) {
		tmp = tmp / 1000; multiplier*=1000;
	} ;
	std::cout << tmp;
	if (c < 0) c = -c;
	for (; multiplier > 1; multiplier/=1000) {
		std::cout << ',' << std::setw(3) << std::setfill('0') << c % multiplier / (multiplier / 1000);
	}
	getchar();
	getchar();
	return 0;
}