#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
const int inf = 999999;
struct node {
	int ttlTime;
	int popTime;
	std::queue<int> q;
};
int SearchMinAndAdd(std::vector<node> &windows, int time, int m) {
	int minTPosi = -1, minCPosi = -1, minTime = inf, minCustomers = m;
	for (int i = 0; i < windows.size(); i++) {
		if (windows[i].popTime < minTime) {
			minTime = windows[i].popTime;
			minTPosi = i;
		}
		if (windows[i].q.size() < minCustomers) {
			minCustomers = windows[i].q.size();
			minCPosi = i;
		}
	}
	if (minCPosi != -1) {
		windows[minCPosi].q.push(time);
		windows[minCPosi].ttlTime += time;
		if (windows[minCPosi].popTime == 0)windows[minCPosi].popTime = time;
		if (windows[minCPosi].ttlTime - time >= 540) { windows[minCPosi].ttlTime = 541; return -1; }
		else return windows[minCPosi].ttlTime;
	}
	else {
		int popOut;
		popOut = windows[minTPosi].q.front();
		windows[minTPosi].q.pop();
		windows[minTPosi].q.push(time);
		windows[minTPosi].popTime += windows[minTPosi].q.front();
		windows[minTPosi].ttlTime += time;
		if (windows[minTPosi].ttlTime - time >= 540) { windows[minTPosi].ttlTime = 541; return -1; }
		else return windows[minTPosi].ttlTime;
	}
}

int main() {
	int n, m, k, q;
	std::cin >> n >> m >> k >> q;
	std::vector<int> time(k);
	std::vector<int> ask(k);
	std::vector<node> windows(n);
	for (int i = 0; i < n; i++) {
		windows[i].popTime = 0;
		windows[i].ttlTime = 0;
	}
	for (int i = 0; i < k; i++) {
		std::cin >> time[i];
		//std::cout << "time[" << i << "]:" << time[i] << ' ';
		ask[i] = SearchMinAndAdd(windows, time[i], m);
		//std::cout << "ask[" << i << "]:" << ask[i] << std::endl;
	}
	for (int i = 0; i < q; i++) {
		int request;
		std::cin >> request;
		if (ask[request - 1] == -1)std::cout << "Sorry";
		else std::cout << std::setw(2) << std::setfill('0') << ask[request - 1] / 60 + 8 << ":" << std::setw(2) << std::setfill('0') << ask[request - 1] % 60;
		if (i != q - 1) std::cout << std::endl;
	}


	getchar();
	getchar();

	return 0;
}