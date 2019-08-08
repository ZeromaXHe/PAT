#include <iostream>
#include <algorithm>
#include <vector>
bool isInsertion(std::vector<int> v1, std::vector<int> v2) {
	int i;
	for (i = v1.size()-1; i >=0; i--) {//vector的长度是size()
		if (v1[i] != v2[i]) {
			break;
		}
	}
	for (int j = 1; j <= i; j++) {
		if (v2[j] < v2[j - 1]) {
			return false;
			break;
		}
	}
	return true;
}
int Insertion(std::vector<int> v1, std::vector<int> &v2) {
	int i;
	for (i = v1.size() - 1; i >= 0; i--) {//vector的长度是size()
		if (v1[i] != v2[i]) {
			break;
		}
	}
	std::sort(v2.begin(), v2.begin() + i + 2);//注意要加i+2，因为sort第二个参数是最后的位置+1的位置。
	return 0;
}
int Merge(std::vector<int> &v2) {
	int sortedL=1;
	int sortedLMin=v2.size();
	for (int i = 1; i < v2.size(); i++) {
		if (v2[i] >= v2[i - 1]) {
			sortedL++;
		}
		else {
			if (sortedLMin > sortedL) sortedLMin = sortedL;
			sortedL = 1;
		}
	}
	for (int i = 2 * sortedLMin - 1; i < v2.size(); i += (2 * sortedLMin)) {
		std::sort(v2.begin() + (i - 2 * sortedLMin + 1), v2.begin() + i);
	}
	std::sort(v2.end() - v2.size() % (2 * sortedLMin), v2.end());//注意处理归并的零头部分
	return 0;
}
int main() {
	int n;
	std::cin >> n;
	std::vector<int> v1(n);
	std::vector<int> v2(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v1[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> v2[i];
	}
	
	if (isInsertion(v1, v2)) {
		std::cout << "Insertion Sort" << std::endl;
		Insertion(v1, v2);
	}
	else {
		std::cout << "Merge Sort" << std::endl;
		Merge(v2);
	}
	for (int i = 0; i < n; i++) {
		if (i != 0)std::cout << ' ';
		std::cout << v2[i];
	}

	getchar();
	getchar();

	return 0;
}