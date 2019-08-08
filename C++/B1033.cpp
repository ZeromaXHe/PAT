#include <iostream>
#include <string>
#include <vector>
int Check(std::string &s, char c) {//考虑使用isupper，toupper，string的find、npos等函数简化书写，例如：
	//bad.find(toupper(should[i])) != string::npos；
	//isupper(should[i]) && bad.find('+') != string::npos;
	if (c == '+') {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] <= 'Z'&&s[i] >= 'A') s[i] = '*';
		}
	}
	else {
		for (int i = 0; i < s.length(); i++) {
			if (s[i] == c||s[i]==tolower(c)) s[i] = '*';
		}
	}
	return 0;
}
int main() {
	std::string s1, s2;
	getline(std::cin, s1);//此处如果用cin的话，当s1为空时无法正常输入。
	getline(std::cin, s2);
	for (int i = 0; i < s1.length(); i++) {
		Check(s2, s1[i]);
	}
	for (int i = 0; i < s2.length(); i++) {
		if (s2[i] != '*') std::cout << s2[i];
	}

	getchar();
	getchar();

	return 0;
}