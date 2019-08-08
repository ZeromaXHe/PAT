#include <iostream>
#include <string>
#include <vector>
struct node {
	std::string no;
	int test;
	int exam;
};
int main() {
	int n;
	std::cin >> n;
	std::vector<node> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i].no >> v[i].test >> v[i].exam;
	}
	int m;
	std::cin >> m;
	std::vector<int> vi(m);
	for (int i = 0; i < m; i++) {
		std::cin >> vi[i];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (v[j].test == vi[i]) {
				std::cout << v[j].no << ' ' << v[j].exam <<std::endl;
				break;
			}
		}
	}
	getchar();
	getchar();

	return 0;
}