#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

int ConvertToR10(std::string n, int radix, long long int &nR10) {
	nR10 = 0;
	for (int i = 0; i < n.length(); i++) {
		int temp = isdigit(n[i]) ? n[i] - '0' : n[i] - 'a' + 10;
		if (temp > radix) { nR10 = -1; break; }
		nR10 *= radix;
		nR10 += temp;
	}
	return 0;
}

int SolveRadix(std::string n, long long int nR10) {
	long long int testR10 = 0;
	int max = -1;
	std::vector<int> temp(n.length());
	for (int i = 0; i < n.length(); i++) {
		temp[i] = isdigit(n[i]) ? n[i] - '0' : n[i] - 'a' + 10;
		if (temp[i] > max)max = temp[i];
	}
	
	//std::cout << " max:" <<max<<std::endl;

	long long int l = max + 1, r = (nR10 > max+1 ? nR10 : max+1);
	long long int mid = (l + r) / 2;//必须使用二分法
	while (l <= r) {
		//std::cout << "l:" << l << " r:" << r;
		ConvertToR10(n, mid, testR10);
		//std::cout << " testR10:" << testR10<<std::endl;
		if (testR10 > 0) {
			if (testR10 > nR10) {
				r = mid-1;
			}
			else if (testR10 == nR10) {
				r = mid;
				if (l == r) return mid;
			}
			else l = mid + 1;
		}
		else r = mid - 1;
		mid = (l + r) / 2;
	}
	if (l > r) return -1;
}

int main() {
	std::string n1, n2;
	int tag, radix;
	long long int nR10 = 0;//注意原来的不能用int，会溢出
	std::cin >> n1 >> n2 >> tag >> radix;
	int result;
	if (tag == 1) {
		ConvertToR10(n1, radix, nR10);
		result = SolveRadix(n2, nR10);
		if (result == -1) {
			std::cout << "Impossible";
		}
		else {
			std::cout << result;
		}
	}
	if (tag == 2) {
		ConvertToR10(n2, radix, nR10);
		result = SolveRadix(n1, nR10);
		if (result == -1) {
			std::cout << "Impossible";
		}
		else {
			std::cout << result;
		}
	}
	
	getchar();
	getchar();

	return 0;
}