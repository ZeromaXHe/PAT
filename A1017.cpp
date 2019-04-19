#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
struct customer {
	int h;
	int m;
	int s;
	int time;
	int serve;
};
bool cmp(customer a, customer b) {
	return a.time < b.time;
}
int main() {
	int n, k;
	int h, m, s, serve;
	std::cin >> n >> k;
	std::vector<int> window(k);
	for (int i = 0; i < k; i++) {
		window[i] = 28800;
	}
	std::vector<customer> sequence;
	for (int i = 0; i < n; i++) {
		customer cus;
		scanf_s("%d:%d:%d %d", &cus.h, &cus.m, &cus.s, &cus.serve);
		cus.serve *= 60;
		cus.time = cus.h * 3600 + cus.m * 60 + cus.s;
		if (cus.time <= 61200)sequence.push_back(cus);
	}
	sort(sequence.begin(), sequence.end(), cmp);
	int min = 0;
	int minW = 28800;
	float avrg = 0.0;
	int count = 0;
	int total = 0;
	for (int i = 0; i < sequence.size(); i++) {
		//if (minW > 61200) break;听说17：00前的全要服务完。。。醉了,不然最后一个测试点过不去。
		//else {
		if (sequence[i].time < window[min]) {
			total += window[min] - sequence[i].time;
			window[min] += sequence[i].serve;
		}
		else window[min] = sequence[i].time + sequence[i].serve;
		minW = window[min];
		count++;
		//printf("Customer #%d : wait for %ds, total %ds\n", count, minW - sequence[i].time, total);
		for (int j = 0; j < k; j++) {
			if (window[j] < minW) {
				min = j;
				minW = window[j];
			}
		}
		//printf("Now, shortest window queue is #%d, finish at %d\n", min, minW);
	}
	if(count!=0)avrg = total / count / 60.0;
	else avrg = 0.0;//考虑count为0这一步其实挺重要的，只是貌似测试点里没有这个相关的
	printf("%.1f", avrg);
	getchar();
	getchar();

	return 0;
}