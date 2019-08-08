#include <iostream>
#include <string>
bool TestPAT(std::string s) {
	int p = -1, t = -1;
	int count_p = -1, count_t = -1;
	for (int i = 0; i < s.length(); i++) {
		if (p == -1) {
			count_p++;
			count_t++;
			if (s[i] == 'P') { p = count_p; continue; }
		}
		else if (t == -1){
			count_t++;
			if (s[i] == 'T') { t = count_t; continue; }
		}
		if (s[i] != 'A') {
			return false; break;
		}
	}
	if (p*(t - p - 1) == (s.length() - t - 1) && (t - p - 1) != 0) { return true; }
	else return false;
}
int main() {
	int n;
	std::cin >> n;
	std::string s;
	bool yesOrNo[10];
	for (int i = 0; i < n; i++) {
		std::cin >> s;
		yesOrNo[i] = TestPAT(s);
	}
	for (int i = 0; i < n; i++) {
		if (yesOrNo[i] == true) std::cout << "YES" << std::endl;
		if (yesOrNo[i] == false) std::cout << "NO" << std::endl;
	}
	getchar();
	getchar();
	return 0;
}
