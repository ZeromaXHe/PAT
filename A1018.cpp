#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <deque>
const int inf = 0x3f3f3f3f;
std::vector<int> shtstPath;

int minSnt = inf, minBk = inf;
int checkOther = 1;
std::vector<int> BestSP;

struct node {
	std::deque<int> path;
};
void CountMin(int &nowVisit, std::vector<int> bike, std::vector<node> &path, int c) {
	int sentBike = 0, backBike = 0;
	while (nowVisit != 0) {
		shtstPath.push_back(nowVisit);//这里生成的shtstPath是倒序的！
		nowVisit = path[nowVisit].path[0];
	}
	for (int i = shtstPath.size() - 1; i >= 0; i--) {
		if (bike[shtstPath[i]] - c / 2 > 0) {
			backBike += bike[shtstPath[i]] - c / 2;
		}
		else if (backBike > -bike[shtstPath[i]] + c / 2) {
			backBike -= -bike[shtstPath[i]] + c / 2;
		}
		else {
			sentBike += -bike[shtstPath[i]] + c / 2 - backBike;
			backBike = 0;
		}
	}
	if (sentBike < minSnt || (sentBike == minSnt && backBike < minBk)) {
		BestSP = shtstPath;
		minSnt = sentBike;
		minBk = backBike;
	}
	//printf("Current minSnt:%d minBk:%d\n", minSnt, minBk);
}
int main() {
	int edge[501][501];
	for (int i = 0; i < 501; i++) {
		for (int j = 0; j < 501; j++) {
			if(i != j) edge[i][j] = inf;
			else edge[i][j] = 0;
		}
	}
	int c, n, s, m;
	std::cin >> c >> n >> s >> m;
	std::vector<int> set(n + 1, 0);
	std::vector<int> dist(n + 1);
	std::vector<node> path(n + 1);
	std::vector<int> bike(n + 1);
	for (int i = 1; i < n+1; i++) std::cin >> bike[i];
	for (int i = 0; i < m; i++) {
		int a, b, d;
		std::cin >> a >> b >> d;
		edge[a][b] = edge[b][a] = d;
	}
	for (int i = 0; i < n + 1; i++) {
		dist[i] = edge[0][i];
	}
	for (int i = 0; i < n + 1; i++) {
		int minDist = -1;
		int min = inf;
		for (int j = 0; j < n + 1; j++) {
			if (dist[j] < min && set[j] == 0) {
				minDist = j;
				min = dist[j];
			}
		}
		if (minDist == -1)break;
		set[minDist] = 1;
		for (int j = 0; j < n + 1; j++) {
			if (set[j] == 0 && edge[minDist][j] < inf) {
				if (dist[minDist] + edge[minDist][j] == dist[j]) {
					path[j].path.push_back(minDist);
				}
				else if (dist[minDist] + edge[minDist][j] < dist[j]) {
					dist[j] = dist[minDist] + edge[minDist][j];
					path[j].path.clear();
					path[j].path.push_back(minDist);//试着用花括号重新初始化可行吗？
				}
			}
		}
	}
	int nowVisit = s;
	CountMin(nowVisit, bike, path, c);
	do{
		for (checkOther = shtstPath.size() - 1; checkOther >= 0; checkOther--) {
			if (path[shtstPath[checkOther]].path.size() > 1) {
				shtstPath.erase(shtstPath.begin() + checkOther + 1, shtstPath.end());
				path[shtstPath[checkOther]].path.pop_front();
				nowVisit = path[shtstPath[checkOther]].path[0];
				CountMin(nowVisit, bike, path, c);
				break;
			}
		}
	} while (checkOther >= 0);

	std::cout << minSnt << " 0";
	for (int i = BestSP.size() - 1; i >= 0; i--) {
		std::cout << "->" << BestSP[i];
	}
	std::cout << " " << minBk;

	getchar();
	getchar();

	return 0;
}