#include <iostream>
#include <algorithm>
#include <vector>
bool isInsertion(std::vector<int> v1, std::vector<int> v2) {
	int i;
	for (i = v1.size() - 1; i >= 0; i--) {//vector的长度是size()
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
int Insertion(std::vector<int> &v2) {//重写了Insertion函数，不然有一个测试点过不去
	//貌似必须从前往后数有序数列才行，从后往前数v1v2相同数列那个测试点会报错（说明可能那个测试点无法确定具体的几次之后的结果?）
	int i;
	for (i = 1; i < v2.size(); i++) {//vector的长度是size()
		if (v2[i] < v2[i - 1]) {
			break;
		}
	}
	std::sort(v2.begin(), v2.begin() + i + 1);//注意这里不再是i+2了。虽然sort第二个参数是最后的位置+1的位置，但此时i已经是第一个无序位置。
	return 0;
}
int Merge(std::vector<int> &v1, std::vector<int> v2) {//重写了一下Merge函数，从分析最小有序序列改成模拟归并过程。
	//之前分析最小序列的方法可能无法正确分析归并的零头部分（当零头部分恰好有序时）
	int k = 1, flag = 1;
	while (flag) {
		flag = 0;
		for (int i = 0; i < v1.size(); i++) {
			if (v1[i] != v2[i])
				flag = 1;
		}
		k = k * 2;
		for (int i = 0; i < v1.size() / k; i++)
			std::sort(v1.begin() + i * k, v1.begin() + (i + 1) * k);
		std::sort(v1.begin() + v1.size() / k * k, v1.end());//注意处理归并的零头部分
	}
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
		Insertion(v2);
		for (int i = 0; i < n; i++) {
			if (i != 0)std::cout << ' ';
			std::cout << v2[i];
		}
	}
	else {
		std::cout << "Merge Sort" << std::endl;
		Merge(v1, v2);
		for (int i = 0; i < n; i++) {
			if (i != 0)std::cout << ' ';
			std::cout << v1[i];
		}
	}


	getchar();
	getchar();

	return 0;
}