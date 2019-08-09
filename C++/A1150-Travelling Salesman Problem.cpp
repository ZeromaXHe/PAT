#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

//前两个测试点过不去
int main() {
	int n;
	int m;
	scanf_s("%d",&n);
	scanf_s("%d",&m);
	int map[201][201] = {0};
	int c1;
	int c2;
	int d;
	for (int i = 0; i < m; i++) {
		scanf_s("%d", &c1);
		scanf_s("%d", &c2);
		scanf_s("%d", &d);
		map[c1][c2] = map[c2][c1] = d;
	}
	int k;
	scanf_s("%d", &k);
	int shortestDist = 0x3f3f3f3f;
	int shortestPath = -1;

	for (int i = 0; i < k; i++) {
		int x;
		scanf_s("%d", &x);
		int start;
		scanf_s("%d", &start);
		int backup = start;
		int end = -1;
		int totalDist = 0;
		bool visit[201] = { false };
		int notSimple = 0;
		std::cout<<"Path "<<(i+1)<<": ";
		bool flag = false;
		for (int j = 1; j < x; j++) {
			scanf_s("%d", &end);
			if (visit[end]) notSimple++;
			else visit[end] = true;

			if (map[start][end] == 0) {
				flag = true;
				totalDist = 0x3f3f3f3f;
				break;
			}
			totalDist += map[start][end];
			start = end;
		}
		if (flag) {
			std::cout << "NA (Not a TS cycle)"<<std::endl;
		}
		else if(backup != end){
			std::cout <<totalDist<< " (Not a TS cycle)"<<std::endl;
		}
		else if (notSimple == 0 && x == n + 1) {
			std::cout << totalDist << " (TS simple cycle)" <<std::endl;
			if (totalDist < shortestDist) {
				shortestDist = totalDist;
				shortestPath = i + 1;
			}
		}
		else if (x - notSimple == n + 1) {
			std::cout << totalDist << " (TS cycle)" <<std::endl;
			if (totalDist < shortestDist) {
				shortestDist = totalDist;
				shortestPath = i + 1;
			}
		}
		else {
			std::cout << totalDist << " (Not a TS cycle)"<<std::endl;
		}
	}
	std::cout << "Shortest Dist("<< shortestPath <<") = "<<shortestDist<<std::endl;

	getchar();
	getchar();

	return 0;
}