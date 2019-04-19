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
			int flag = 0;//这之后几行一大段可以考虑使用string的find()函数进行简化，注意找不到的情况是find返回值为std::string::nops
			for (int x = 0; x < s.length(); x++) {
				if (toupper(s1[k]) == s[x]) flag = 1;//使用find后可以免去flag变量，用npos直接实现
			}//使用find()的话直接写成if (s2.find(s1[i]) == string::npos && s.find(toupper(s1[i])) == string::npos)s += toupper(s1[i]);  这种是直接双重循环，复杂度略高一些，但数量级都是O(n^2)
			if (flag == 0) s += toupper(s1[k]);//注意：toupper()函数实现大小写转换（类似的有tolower转小写）
		}
		else {
			i++;
			if (i > s2.length()) {
				for (int y = k + 1; y < s1.length(); y++) {
					int flag = 0;
					for (int x = 0; x < s.length(); x++) {
						if (toupper(s1[y]) == s[x]) flag = 1;
					}
					if (flag == 0) s += toupper(s1[y]);
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