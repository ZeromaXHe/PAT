#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <set>
const int inf = 0x3f3f3f3f;
std::vector<std::vector<int>> edge;
std::vector<int> visit;
int dfs(int k, int depth, int &max, std::set<int> &furthest) {
	visit[k] = 1;
	int flag = 0;
	
	for (int i = 0; i < edge[k].size(); i++) {
		if (visit[edge[k][i]] != 1) {
			dfs(edge[k][i], depth + 1, max, furthest);
			flag = 1;
		}
	}
	if (flag == 0) {
		if (depth > max) {
			furthest.clear();
			furthest.insert(k);
			max = depth;
		}
		else if (depth == max) furthest.insert(k);
	}
	return 0;
}
int main() {
	int n;
	std::cin >> n;
	edge.resize(n + 1);//这个方法建立邻接表法存储的图比较方便
	visit.resize(n + 1);
	fill(visit.begin(), visit.end(), 0);
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		std::cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	int max = -1;
	int mulComp = 1;
	std::set<int> furthest;
	dfs(1, 0, max, furthest);
	for (int i = 1; i < n+1; i++) {
		if (visit[i] == 0) {
			mulComp++;
			dfs(i, 0, max, furthest);
			i = 0;
		}
	}
	if (mulComp > 1) {
		std::cout << "Error: " << mulComp << " components";
	}
	else {
		fill(visit.begin(), visit.end(), 0);
		max = -1;
		std::set<int> finalFur;
		dfs(*furthest.begin(), 0, max, finalFur);
		finalFur.insert(furthest.begin(), furthest.end());//注意set求并集的操作。必须把furthest和finalFur合并，不然有测试点过不去
		for (std::set<int>::iterator i = finalFur.begin(); i != finalFur.end(); i++) {//注意set的遍历输出操作（使用iterator迭代器）
			if (i != finalFur.begin())std::cout << std::endl;
			std::cout << *i;
		}
	}

	getchar();
	getchar();

	return 0;
}