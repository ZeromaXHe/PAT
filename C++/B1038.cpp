#include <iostream>
#include <algorithm>
#include <vector>

int main() {
	int n;
	int k;
	int tmp;
	int a[101] = {0};
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> tmp;//这里没必要保存这些数据，主要还是计数
		a[tmp]++;
	}
	std::cin >> k;
	std::vector<int> v(k);
	for (int i = 0; i < k; i++) {
		std::cin >> v[i];
	}
	for (int i = 0; i < k; i++) {
		if (i != 0) std::cout << ' ';
		tmp = v[i];//貌似不用tmp过渡的话就会有个测试点“段错误”
		std::cout << a[tmp];
	}

	getchar();
	getchar();

	return 0;
}