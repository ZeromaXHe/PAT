#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
struct node {
	int expo;
	float coef;
};
int main() {
	int k1;
	std::cin >> k1;
	std::vector<node> v1(k1);
	for (int x = 0; x < k1; x++) {
		std::cin >> v1[x].expo >> v1[x].coef;
	}

	int k2;
	std::cin >> k2;
	std::vector<node> v2(k2);
	for (int x = 0; x < k2; x++) {
		std::cin >> v2[x].expo >> v2[x].coef;
	}

	std::vector<node> v;
	int j = 0;
	int i = 0;
	for (; i < k1; i++) {
		if (v1[i].expo > v2[j].expo) v.push_back(v1[i]);
		else if (v1[i].expo == v2[j].expo) {
			node a;
			a.expo = v1[i].expo;
			a.coef = v1[i].coef + v2[j].coef;
			if (a.coef != 0) v.push_back(a);
			j++;
			if (j >= k2) {
				for (i++; i < k1; i++) {
					v.push_back(v1[i]);
				}
				break;
			}
		}
		else {
			while (v1[i].expo < v2[j].expo) {
				v.push_back(v2[j]);
				j++;
				if (j >= k2) {
					for (; i < k1; i++) {
						v.push_back(v1[i]);
					}
					break;
				}
			}
			i--;
		}
	}
	while (j < k2) {
		v.push_back(v2[j]);
		j++;
	}

	std::cout << v.size();
	for (int x = 0; x < v.size(); x++) {
		std::cout << ' ' << v[x].expo << ' ' << std::fixed << std::setprecision(1) << v[x].coef;
	}

	getchar();
	getchar();

	return 0;
}