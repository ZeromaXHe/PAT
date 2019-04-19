#include <iostream>
#include <iomanip>

int main() {
	int n;
	int test;
	int a[5] = { 0 };
	int b[5] = { 0 };
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> test;
		switch (test % 5) {
		case 0:
			
			if (test % 2 == 0) {
				b[0] += 1; /*注意例子2中的第一项是N，这决定了b[0]+1的过程在if内*/
				a[0] += test;
			}
			break;
		case 1:
			b[1] += 1;
			if (b[1] % 2 == 1)a[1] += test;
			else a[1] -= test;
			break;
		case 2:
			b[2] += 1;
			a[2] += 1;
			break;
		case 3:
			b[3] += 1;
			a[3] += test;
			break;
		case 4:
			b[4] += 1;
			if (test > a[4])a[4] = test;
			break;
		}
	}
	for (int i = 0; i < 5; i++) {
		
		if (i > 0) { std::cout << ' '; }
		if (b[i] != 0) {
			if (i != 3)std::cout << a[i];
			else {
				float average = (float)a[3] / (float)b[3];
				std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(1) << average;
			}
		}
		else std::cout << 'N';
	}
	
	getchar();
	getchar();
	return 0;
}