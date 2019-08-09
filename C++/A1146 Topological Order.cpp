#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

//前两个和最后一个测试点错误
int main() {
	int n;
	int m;
	scanf_s("%d",&n);
	scanf_s("%d",&m);
	
	bool map[1000][1000] = { false };
	for (int i = 0; i < m; i++) {
		int from;
		int to;
		scanf_s("%d", &from);
		scanf_s("%d", &to);
		map[from-1][to-1] = true;
	}
	int k;
	scanf_s("%d", &k);
	bool notFirst = false;
	for (int i = 0; i < k; i++) {
		bool visit[1000] = { false };
		for (int j = 0; j < n; j++) {
			int now;
			scanf_s("%d", &now);
			visit[now-1] = true;
			for (int k1 = 0; k1 < n; k1++) {
				if (map[k1][now-1] && !visit[k1]) {
					if (notFirst) printf(" ");
					printf("%d",i);
					notFirst = true;
					goto loop;
				}
			}
		}
	loop:int x = 0;
	}

	getchar();
	getchar();

	return 0;
}