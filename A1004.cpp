#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


int main() {
	int n, m;
	int parent[101] = { 0 };
	int count[101] = { 0 };
	int nonLeaf[101] = { 0 };
	std::cin >> n >> m;
	int id, k, id2;
	parent[1] = -1;
	for (int i = 0; i < m; i++) {
		std::cin >> id >> k;
		nonLeaf[id] = 1;
		for (int j = 0; j < k; j++) {
			std::cin >> id2;
			parent[id2] = id;
		}
	}

	int maxLevel = 0;
	for (int i = 0; i < 101; i++) {
		if (nonLeaf[i] == 0 && parent[i] != 0) {
			int level = 0;
			id = i;
			while (id != 1) {
				id = parent[id];
				level++;
			}
			count[level]++;
			if (maxLevel < level) maxLevel = level;
		}
	}
	for (int i = 0; i <= maxLevel; i++) {
		if (i != 0)std::cout << ' ';
		std::cout << count[i];
	}
	getchar();
	getchar();

	return 0;
}