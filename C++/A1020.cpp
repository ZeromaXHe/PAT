#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <queue>
struct node {
	int iStart;
	int iStop;
	int pStart;
	int pStop;
};
int FindRoot(std::vector<int> postOrder, std::vector<int> inOrder, int iStart, int iStop, int pStart, int pStop) {
	if (iStart <= iStop) {
		int root = find(inOrder.begin() + iStart, inOrder.begin() + iStop, postOrder[pStop]) - inOrder.begin();//注意find返回的是iterator类型，必须减一个begin（）才能赋值int
		return root;
	}
	else return -1;
}
int LevelOrder(std::vector<int> postOrder, std::vector<int> inOrder, std::queue<node> &levelOrd, std::vector<int> &levelOrder) {
	if (levelOrd.size() != 0) {
		int iStart = levelOrd.front().iStart, iStop = levelOrd.front().iStop;
		int pStart = levelOrd.front().pStart, pStop = levelOrd.front().pStop;
		int root = FindRoot(postOrder, inOrder, iStart, iStop, pStart, pStop);
		if (root >= 0) {
			levelOrder.push_back(inOrder[root]);
			levelOrd.push({ iStart, root - 1, pStart,pStart + root - 1 - iStart });
			levelOrd.push({ root + 1, iStop, pStop - iStop + root, pStop - 1 });
		}
		levelOrd.pop();
		LevelOrder(postOrder, inOrder, levelOrd, levelOrder);
	}
	return 0;
}
int main() {
	int n;
	std::cin >> n;
	std::vector<int> postOrder(n);
	std::vector<int> inOrder(n);
	for (int i = 0; i < n; i++) {
		std::cin >> postOrder[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >>inOrder[i];
	}
	std::queue<node> levelOrd;
	std::vector<int> levelOrder;
	levelOrd.push({ 0,n - 1 ,0,n - 1 });
	LevelOrder(postOrder, inOrder, levelOrd, levelOrder);
	
	for (int i = 0; i < levelOrder.size(); i++) {
		if (i != 0)std::cout << ' ';
		std::cout << levelOrder[i];
	}

	getchar();
	getchar();

	return 0;
}