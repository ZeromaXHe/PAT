#include <iostream>
#include <algorithm>
#include <vector>
int main() {
	int n;
	long long p;//这里不能用int，不然最后一个测试点过不去。毕竟不是所有情况下int都是4字节
	std::cin >> n >> p;
	std::vector<int> v(n);

	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}
	sort(v.begin(), v.end());
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (i + max >= n) break;
		for (int j = i + max; j < n; j++) {
			if (v[j] > v[i] * p) break;
			else max = j - i + 1;
		}
	}
	std::cout << max;

	getchar();
	getchar();

	return 0;
}