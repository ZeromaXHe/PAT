#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

int e[1001][1001] = { 0 };
int visit[1001];
int n;
void dfs(int node) {
	visit[node] = 1;
	for (int i = 1; i <= n; i++) {
		if (visit[i] == 0 && e[node][i] == 1) {
			dfs(i);
		}
	}
}
int main() {
	int m, k;
	scanf_s("%d %d %d", &n, &m, &k);//必须用scanf不然最后一个测试点超时
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf_s("%d %d", &a, &b);
		e[a][b] = e[b][a] = 1;
	}
	for (int i = 0; i < k; i++) {
		int check;
		scanf_s("%d", &check);
		std::fill(visit, visit + 1001, 0);
		visit[check] = 1;
		int count = -1;
		for (int j = 1; j <= n; j++) {
			if (visit[j] == 0) {
				dfs(j);
				count++;
			}
		}
		if (i != 0) printf("\n");
		printf("%d", count);
	}
	getchar();
	getchar();

	return 0;
}