#include <iostream>
#include <string>
struct node {
	std::string name;
	std::string ID;
	int score;
};
int main() {
	int n;
	node max, min,test;
	max.score = -1;
	min.score = 101;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> test.name >> test.ID >> test.score;
		if (test.score > max.score) {
			max = test;
		}
		if (test.score < min.score) {
			min = test;
		}
	}
	std::cout << max.name << ' ' << max.ID << std::endl << min.name << ' ' << min.ID <<  std::endl;
	getchar();
	getchar();
	return 0;
}