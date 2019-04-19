#include <iostream>
#include <string>

int main() {
	std::string a, q;
	std::string num[10] = {"0","1","2","3","4","5","6","7","8","9"};
	int b, r;
	std::cin >> a >> b;
	int tmp = 0, tmp_q = 0;
	int flag = 0;
	for (int i = 0; i < a.length(); i++) {
		tmp *= 10;
		tmp += (a[i] - '0');
		tmp_q = tmp / b;
		if (tmp_q == 0) {
			if (flag == 1) q = q + num[tmp_q];
		}
		else { flag = 1; q = q + num[tmp_q]; }
		tmp %= b;
	}
	if (q.length() == 0) q = '0';/*注意：如果a=0时，没有此行q将为空*/
	r = tmp;
	std::cout << q << ' ' << r;
	
	getchar();
	getchar();

	return 0;
}