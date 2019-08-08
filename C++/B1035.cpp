#include <iostream>
#include <algorithm>
#include <vector>
bool isInsertion(std::vector<int> v1, std::vector<int> v2) {
	int i;
	for (i = v1.size() - 1; i >= 0; i--) {//vector�ĳ�����size()
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
int Insertion(std::vector<int> &v2) {//��д��Insertion��������Ȼ��һ�����Ե����ȥ
	//ò�Ʊ����ǰ�������������в��У��Ӻ���ǰ��v1v2��ͬ�����Ǹ����Ե�ᱨ��˵�������Ǹ����Ե��޷�ȷ������ļ���֮��Ľ��?��
	int i;
	for (i = 1; i < v2.size(); i++) {//vector�ĳ�����size()
		if (v2[i] < v2[i - 1]) {
			break;
		}
	}
	std::sort(v2.begin(), v2.begin() + i + 1);//ע�����ﲻ����i+2�ˡ���Ȼsort�ڶ�������������λ��+1��λ�ã�����ʱi�Ѿ��ǵ�һ������λ�á�
	return 0;
}
int Merge(std::vector<int> &v1, std::vector<int> v2) {//��д��һ��Merge�������ӷ�����С�������иĳ�ģ��鲢���̡�
	//֮ǰ������С���еķ��������޷���ȷ�����鲢����ͷ���֣�����ͷ����ǡ������ʱ��
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
		std::sort(v1.begin() + v1.size() / k * k, v1.end());//ע�⴦��鲢����ͷ����
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