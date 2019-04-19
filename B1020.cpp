#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
struct mooncake {
	float ttlPrice;
	float amount;
	float untPrice;
};
int cmp(mooncake a, mooncake b) {
	return a.untPrice > b.untPrice;
}
int main() {
	int n;
	float d;
	std::cin >> n >> d;
	std::vector <mooncake> v(n);
	for (int i = 0; i < n; i++) std::cin >> v[i].amount;
	for (int i = 0; i < n; i++) std::cin >> v[i].ttlPrice;
	for (int i = 0; i < n; i++) v[i].untPrice = v[i].ttlPrice / v[i].amount;
	std::sort(v.begin(), v.end(), cmp);
	float sell = 0.0;
	for (int i = 0; i < n; i++) {
		if (v[i].amount >= d) {
			sell += v[i].untPrice*d;
			break;
		}
		else {
			sell += v[i].ttlPrice;
		}
		d -= v[i].amount;
	}
	std::cout << std::fixed << std::setprecision(2) << sell;
	getchar();
	getchar();

	return 0;
}