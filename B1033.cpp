#include <iostream>
#include <string>
#include <vector>
int Check(std::string &s, char c) {//����ʹ��isupper��toupper��string��find��npos�Ⱥ�������д�����磺
	//bad.find(toupper(should[i])) != string::npos��
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
	getline(std::cin, s1);//�˴������cin�Ļ�����s1Ϊ��ʱ�޷��������롣
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