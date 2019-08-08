#include <iostream>
#include <iomanip>
#include <string>
int main() {
	std::string s1, s2;
	std::cin >> s1 >> s2;
	int k = 0, i = 0;
	std::string s;
	for (k = 0; k < s1.length(); k++) {
		if (s1[k] != s2[i]) {
			int flag = 0;

			for (int x = 0; x < s.length(); x++) {
				if (s1[k] == s[x]) flag = 1;
				if (s[x] <= 'Z' && s[x] >= 'A') if (s1[k] == s[x] + 32) flag = 1;//+32是大写转小写（ASCII码里面大写在前小写在后）
			}

			if (flag == 0) {
				if (s1[k] <= 'z' && s1[k] >= 'a') s += s1[k] - 32;//注意-32是小写转大写
				else s += s1[k];
			}
		}
		else {
			i++;
			if (i > s2.length()) {
				for (int y = k + 1; y < s1.length(); y++) {
					int flag = 0;

					for (int x = 0; x < s.length(); x++) {
						if (s1[y] == s[x]) flag = 1;
						if (s[x] <= 'Z' && s[x] >= 'A')if (s1[y] == s[x] + 32) flag = 1;
					}

					if (flag == 0) {
						if (s1[y] <= 'z' && s1[y] >= 'a') s += s1[y] - 32;
						else s += s1[y];
					}
				}
				break;
			}
		}
	}
	std::cout << s;
	getchar();
	getchar();

	return 0;
}