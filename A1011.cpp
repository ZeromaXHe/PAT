#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

int main() {
	float odds[3][3];
	int max[3];
	std::string s = "WTL";
	for (int i = 0; i < 3; i++) {
		float maxf = -1.0;
		for (int j = 0; j < 3; j++) {
			std::cin >> odds[i][j];
			if (odds[i][j] > maxf) {
				maxf = odds[i][j];
				max[i] = j;
			}
		}
	}
	std::cout << s[max[0]] << ' ' << s[max[1]] << ' ' << s[max[2]] << ' ' << std::fixed << std::setprecision(2) << (odds[0][max[0]] * odds[1][max[1]] * odds[2][max[2]] * 0.65 - 1) * 2;

	
	
	getchar();
	getchar();

	return 0;
}