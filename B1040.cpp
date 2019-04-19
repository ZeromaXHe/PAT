#include <iostream>
#include <string>
#include <vector>
struct node {
	int p;
	int t;
};
int main() {
	std::string s;
	std::cin >> s;
	std::vector<node> v;
	int countP = 0, countT = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'P')countP++;
		if (s[i] == 'T')countT++;
		if (s[i] == 'A') {
			node a;
			a.p = countP;
			a.t = countT;
			v.push_back(a);
		}
	}
	long long sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum += (long long)v[i].p*(countT - v[i].t);
		sum %= 1000000007;//ע�ⳬ��𰸵ļ��㣬��Ȼ���������Ե����ȥ
	}
	std::cout << sum;

	getchar();
	getchar();

	return 0;
}