#include <iostream>
#include <iomanip>
#include <string>
int main() {
	int n;
	std::cin >> n;
	std::string name, nameMax, nameMin;
	int y, m, d, yMax = 2014, mMax = 12, dMax = 31, yMin = 1814, mMin = 1, dMin = 1;
	int count = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> name;
		scanf_s("%d/%d/%d", &y, &m, &d);	//×¢Òâscanf_s
		if ((y > 1814 || (y == 1814 && m > 9) || (y == 1814 && m == 9 && d >= 6)) && (y < 2014 || (y == 2014 && m < 9) || (y == 2014 && m == 9 && d <= 6))) {
			count++;
			if (y > yMin || (y == yMin && m > mMin) || (y == yMin && m == mMin && d > dMin)) {
				yMin = y;
				mMin = m;
				dMin = d;
				nameMin = name;
			}
			if (y < yMax || (y == yMax && m < mMax) || (y == yMax && m == mMax && d < dMax)) {
				yMax = y;
				mMax = m;
				dMax = d;
				nameMax = name;
			}
		}
	}
	if (count != 0)std::cout << count << ' ' << nameMax << ' ' << nameMin;
	else std::cout << count;

	getchar();
	getchar();

	return 0;
}