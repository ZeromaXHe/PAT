#include <iostream>


int main() {
	long long int a, b;
	int da, db;
	std::cin >> a >> da >> b >> db;
	int counta = 0, countb = 0;
	while (a != 0) {
		if (a % 10 == da) counta += 1;
		a /= 10;
	}
	while (b != 0) {
		if (b % 10 == db) countb += 1;
		b /= 10;
	}
	int c = 0, d = 0;
	for (int i = 0; i < counta; i++) {
		c *= 10;
		c += da;
	}
	for (int i = 0; i < countb; i++) {
		d *= 10;
		d += db;
	}
	std::cout << c + d;
	getchar();
	getchar();

	return 0;
}