#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

struct node {
	int expo;
	float coef;
};

int main() {
	int k1, k2;
	std::cin >> k1;
	std::vector<node> v(k1);
	float result[2001] = {0.0};
	for (int i = 0; i < k1; i++) {
		std::cin >> v[i].expo >> v[i].coef;
	}
	std::cin >> k2;
	for (int i = 0; i < k2; i++) {
		int expo2;
		float coef2;
		std::cin >> expo2 >> coef2;
		for (int j = 0; j < k1; j++) {
			result[expo2 + v[j].expo] += (coef2 * v[j].coef);
		}
	}
	int count = 0;
	std::vector<node> outPut;
	for (int i = 2000; i >= 0; i--) {
		if (result[i] != 0.0) {
			count++;
			outPut.push_back({ i,result[i] });
		}
	}
	std::cout << count;
	for (int i = 0; i < outPut.size(); i++) {
		std::cout << ' ' << outPut[i].expo << ' ' << std::fixed << std::setprecision (1) << outPut[i].coef;
	}


	getchar();
	getchar();


	return 0;
}