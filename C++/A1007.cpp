#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
struct sequence {
	int sum;
	int first;
	int last;
	int count;
};
int CheckTmp(sequence tmp, sequence &max) {
	if (tmp.sum > max.sum || (tmp.sum == max.sum && max.sum == 0 && max.count == 0)) {//注意处理temp为0的情况
		max = tmp;
	}
	return 0;
}

int LoadTmp(sequence &tmp, int temp) {
	if (temp >= 0) {
		if (tmp.count == 0) {
			tmp = { temp,temp,temp,1 };
		}
		else {
			tmp.count++;
			tmp.last = temp;
			tmp.sum += temp;
		}
	}
	else {
		if (tmp.sum + temp > 0) {
			tmp.count++;
			tmp.last = temp;
			tmp.sum += temp;
		}
		else {
			tmp = { 0,0,0,0 };
		}
	}
	return 0;
}

int main() {
	int n;
	std::cin >> n;
	int temp;
	int firstN;
	int lastN;
	sequence tmp = { 0,0,0,0 }, max = { 0,0,0,0 };
	max.sum = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> temp;
		if (i == 0) firstN = temp;
		if (i == n - 1) lastN = temp;
		LoadTmp(tmp, temp);
		CheckTmp(tmp, max);
	}
	if (max.count == 0 && max.sum == 0) {
		std::cout << max.sum << ' ' << firstN << ' ' << lastN;
	}
	else std::cout << max.sum << ' ' << max.first << ' ' << max.last;

	getchar();
	getchar();

	return 0;
}