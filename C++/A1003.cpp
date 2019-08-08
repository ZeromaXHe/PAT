#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

int main() {
	int n, m, c1, c2;
	int map[501][501];
	const int inf = 99999999;
	for (int i = 0; i < 501; i++) {
		for (int j = 0; j < i; j++) {
			map[i][j] = inf;
			map[j][i] = inf;//����ʹ��fill()����
		}
		map[i][i] = 0;
	}

	int help[501] = { 0 };
	std::cin >> n >> m >> c1 >> c2;
	for (int i = 0; i < n; i++) {
		std::cin >> help[i];
	}

	for (int i = 0; i < m; i++) {
		int a, b, l;
		std::cin >> a >> b >> l;
		map[a][b] = l;
		map[b][a] = l;
	}//��ʼ��ͼ

	int dist[501];
	int path[501];
	int minDist;
	int maxNum;
	int bestVisit;
	int visit[501] = { 0 };
	int num[501] = { 0 };
	int count[501] = { 0 };
	
	visit[c1] = 1;	
	
	for (int i = 0; i < n; i++) {
		dist[i] = map[c1][i];
		num[i] = help[i];
		path[i] = c1;
		if (i != c1)num[i] += help[c1];
		if (dist[i] != inf) count[i] = 1;
	}//�����ʵ�൱��������ټ�һ����ǰ����Ϊ��һ�ˣ����Լ򻯵�һ��
	for (int i = 0; i < n - 1; i++) {
		minDist = inf;
		maxNum = -1;
		for (int j = 0; j < n; j++) {
			if (visit[j] == 0) {
				if (dist[j] < minDist) {
					minDist = dist[j];
					bestVisit = j;
					maxNum = num[j];
				}
				//else if (dist[j] == minDist && minDist != inf) {
				//	if (num[j] > maxNum) {
				//		minDist = dist[j];
				//		bestVisit = j;
				//		maxNum = num[j];
				//	}
				//}��Щ����Ҫ������Ҫ��n-1�˲���֪�����������֮ǰ������ɵ�bestVisit==c2�Ϳ�����ǰ����ѭ����д�Ĵ���
			}
			
		}
		visit[bestVisit] = 1;
		
		for (int k = 0; k < n; k++) {
			if (visit[k] == 0) {
				if (dist[bestVisit] + map[bestVisit][k] < dist[k]) {
					dist[k] = dist[bestVisit] + map[bestVisit][k];
					path[k] = bestVisit;
					num[k] = help[k] + num[bestVisit];
					count[k] = count[bestVisit];
				}
				else if (dist[bestVisit] + map[bestVisit][k] == dist[k]) {
					count[k] += count[bestVisit];
					if (help[k] + num[bestVisit] > num[k]) {
						num[k] = help[k] + num[bestVisit];
						path[k] = bestVisit;
					}
				}
			}
		}
		
	}
	std::cout << count[c2] << ' ' << num[c2];//�����һ���ǵȳ����·���ĸ��������Ǿ��룡
	
	getchar();
	getchar();

	return 0;
}