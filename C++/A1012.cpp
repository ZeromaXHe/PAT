#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
struct node {
	int id, best;
	int score[4], rank[4];
}stu[2005];
int exist[1000000], flag = -1;//flag是全局变量，exist方便检索是否存在
bool cmp1(node a, node b) { return a.score[flag] > b.score[flag]; }//因为flag是全局变量所以可以这样搞cmp函数
int main() {
	int n, m, id;
	scanf_s("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf_s("%d %d %d %d", &stu[i].id, &stu[i].score[1], &stu[i].score[2], &stu[i].score[3]);
		stu[i].score[0] = (stu[i].score[1] + stu[i].score[2] + stu[i].score[3]) / 3.0 + 0.5;//0.5是为了四舍五入
	}
	for (flag = 0; flag <= 3; flag++) {
		sort(stu, stu + n, cmp1);
		stu[0].rank[flag] = 1;
		for (int i = 1; i < n; i++) {
			stu[i].rank[flag] = i + 1;
			if (stu[i].score[flag] == stu[i - 1].score[flag])
				stu[i].rank[flag] = stu[i - 1].rank[flag];
		}
	}
	for (int i = 0; i < n; i++) {
		exist[stu[i].id] = i + 1;//+1是为了方便之后i为0的存在判断
		stu[i].best = 0;
		int minn = stu[i].rank[0];
		for (int j = 1; j <= 3; j++) {
			if (stu[i].rank[j] < minn) {
				minn = stu[i].rank[j];
				stu[i].best = j;
			}
		}
	}
	char c[5] = { 'A', 'C', 'M', 'E' };
	for (int i = 0; i < m; i++) {
		scanf_s("%d", &id);
		int temp = exist[id];
		if (temp) {
			int best = stu[temp - 1].best;
			printf("%d %c\n", stu[temp - 1].rank[best], c[best]);
		}
		else {
			printf("N/A\n");
		}
	}
	getchar();
	getchar();

	return 0;
}