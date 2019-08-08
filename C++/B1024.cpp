#include <iostream>
#include <string>

int main() {
	std::string s = { 0 }, s1;
	int s2;
	int e = -1;
	std::cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'E')e = i;
	}
	s1 = s.substr(1, e - 1);/*注意substr这种用法*/
	s2 = stoi(s.substr(e + 1));

	if (s[0] == '-') std::cout << '-';
	if (s2 < 0) {
		std::cout << "0.";
		for (int j = 0; j < abs(s2) - 1; j++) std::cout << '0';
		for (int j = 0; j < s1.length(); j++)
			if (s1[j] != '.') std::cout << s1[j];
	}
	else {
		std::cout << s1[0];
		int cnt, j;
		for (j = 2, cnt = 0; j < s1.length() && cnt < s2; j++, cnt++) std::cout << s1[j];
		if (j == s1.length()) {
			for (int k = 0; k < s2 - cnt; k++) std::cout << '0';
		}
		else {
			std::cout << '.';
			for (int k = j; k < s1.length(); k++) std::cout << s1[k];
		}
	}
	
	getchar();
	getchar();

	return 0;
}