#include <cstdio>
#include <vector>
#include <algorithm>
struct node {
	int id;	/*idΪ�ַ���̫�Ѵ����ˣ���������ʵʵ��int*/
	int moralScore;
	int talentScore;
};

int cmp(node a, node b) {
	if ((a.moralScore + a.talentScore) != (b.moralScore + b.talentScore)) 
		return ((a.moralScore + a.talentScore) > (b.moralScore + b.talentScore));
	else if (a.moralScore != b.moralScore) return a.moralScore > b.moralScore;
	else return a.id < b.id;
}

int main() {
	int n, l, h;
	scanf_s("%d %d %d", &n, &l, &h);/*scanf_s��VS���ر��scanf����ֹԽ�磩��PATʶ�𲻳���*/
	std::vector<node> v[4];
	node tmp;
	int count = n;
	for (int i = 0; i < n; i++) {
		scanf_s("%d %d %d", &tmp.id, &tmp.moralScore, &tmp.talentScore);
		if (tmp.moralScore < l || tmp.talentScore < l) count--;
		else if (tmp.moralScore >= h && tmp.talentScore >= h) v[0].push_back(tmp);
		else if (tmp.moralScore >= h) v[1].push_back(tmp);
		else if (tmp.moralScore >= tmp.talentScore) v[2].push_back(tmp);
		else v[3].push_back(tmp);
	}
	printf("%d\n", count);
	for (int i = 0; i < 4; i++) {
		sort(v[i].begin(), v[i].end(), cmp);
		for (int j = 0; j < v[i].size(); j++) {
			printf("%d %d %d\n", v[i][j].id, v[i][j].moralScore, v[i][j].talentScore);
		}
	}
	getchar();
	getchar();

	return 0;
}