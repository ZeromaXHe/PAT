#include <iostream>
#include <algorithm>
#include <vector>
int main() {
	int n;
	long long p;//���ﲻ����int����Ȼ���һ�����Ե����ȥ���Ͼ��������������int����4�ֽ�
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