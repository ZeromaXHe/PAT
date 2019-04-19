#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
int main() {
	std::string s = { 0 }, s1 = { 0 }, s2 = { 0 };
	float S, S1;
	int S2;
	int e = -1, sign1 = 0, sign2 = 0;
	std::cin >> s;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'E')e = i;
	}

	if (s[0] = '+')sign1 = 1;
	else sign1 = -1;

	s1 = s.substr(1, e - 1);
	/*for(int i=2;i<s.length();i++){
		if (s[i] != 'E') {
			s1 += s[i];
		}
		else {
			e = i;
			break;
		}
	}*/

	if (s[e + 1] = '+')sign2 = 1;
	else sign2 = -1;
	
	int flag = 0;
	for (int i = e+2; i < s.length(); i++) {
		if (flag == 0 && s[i] != '0') { flag = 1; s2 = s[i]; }
		else if (flag == 1) s2 += s[i];
	}

	S2 = std::stoi(s2);
	S1 = std::stof(s1);
	S = S1;
	
	if (sign2 == 1) {
		
		for (int i = 0; i < S2; i++) {
			S *= 10;
		}
	}
	else {
		std::cout << '-';
		for (int i = 0; i < S2; i++) {
			S /= 10;
		}
	}

	std::cout << std::fixed << std::setw(s1.length() - 1) << std::setfill('0') << S;
	
	getchar();
	getchar();

	return 0;
}