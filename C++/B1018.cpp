#include <iostream>
#include <string>

int PrintMostWin(int a[3]) {
	if (a[0] >= a[1] && a[0] >= a[2]) { std::cout << 'B'; }
	else if (a[2] >= a[0] && a[2] >= a[1]) { std::cout << 'C'; }
	else if (a[1] >= a[0] && a[1] >= a[2]) { std::cout << 'J'; }
	return 0;
}
int main() {
	int n;
	std::cin >> n;
	int win = 0, tie = 0, lose = 0;
	char A, B;
	int a[3] = { 0 }, b[3] = { 0 };
	for (int i = 0; i < n; i++) {
		std::cin >> A >> B;
		if (A == B) {
			tie++;
		}
		else if ((A == 'B') && (B == 'C')) {
			win++;
			a[0]++;
		}
		else if ((A == 'J') && (B == 'B')) {
			win++;
			a[1]++;
		}
		else if ((A == 'C') && (B == 'J')) {
			win++;
			a[2]++;
		}
		else if ((A == 'C') && (B == 'B')) {
			lose++;
			b[0]++;
		}
		else if ((A == 'B') && (B == 'J')) {
			lose++;
			b[1]++;
		}
		else if ((A == 'J') && (B == 'C')) {
			lose++;
			b[2]++;
		}
	}
	std::cout << win << ' ' << tie << ' ' << lose << std::endl;
	std::cout << lose << ' ' << tie << ' ' << win << std::endl;
	PrintMostWin(a);
	std::cout << ' ';
	PrintMostWin(b);
	getchar();
	getchar();

	return 0;
}