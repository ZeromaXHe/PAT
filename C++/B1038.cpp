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
		std::cin >> tmp;//����û��Ҫ������Щ���ݣ���Ҫ���Ǽ���
		a[tmp]++;
	}
	std::cin >> k;
	std::vector<int> v(k);
	for (int i = 0; i < k; i++) {
		std::cin >> v[i];
	}
	for (int i = 0; i < k; i++) {
		if (i != 0) std::cout << ' ';
		tmp = v[i];//ò�Ʋ���tmp���ɵĻ��ͻ��и����Ե㡰�δ���
		std::cout << a[tmp];
	}

	getchar();
	getchar();

	return 0;
}