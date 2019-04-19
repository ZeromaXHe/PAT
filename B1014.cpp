#include <iostream>
#include <iomanip>
#include <string>
int main() {
	std::string a1, a2, b1, b2;
	std::cin >> a1 >> a2 >> b1 >> b2;

	int mina, minb;
	if (a1.length() > a2.length())mina = a2.length();
	else mina = a1.length();
	if (b1.length() > b2.length())minb = b2.length();
	else minb = b1.length();

	int counta = 0, countb = 0;
	char secret[2] = { 0 }; int b = -1;
	for (int i = 0; i < mina; i++) {
		if (a1[i] == a2[i]) {
			counta++;
			if (counta == 1) { 
				if(a1[i]>='A'&&a1[i]<='G') secret[0] = a1[i]; 
				else counta--;
			}
			if (counta == 2) {
				if((a1[i]>='0'&&a1[i]<='9')||(a1[i]>='A'&&a1[i]<='N')) secret[1] = a1[i];/*可以换成isdigit函数（<cctype>里的）*/
				else counta--;
			}
		}
	}
	for (int i = 0; i < minb; i++) {
		if (b1[i] == b2[i]) {
			countb++;
			if (countb == 1) {
				if((b1[i]>='a'&&b1[i]<='z')||(b1[i]>='A'&&b1[i]<='Z'))b = i;/*注意：ASCII中小写字母和大写字母之间是有其他字符的，可以换成isalpha函数（<cctype>里的）*/
				else countb--;
			}
		}
	}
	std::string week[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };/*注意可以使用字符串数组来避免swtich case语句（其实最一开始四个字符串也可以创建成数组——））*/
	std::cout << week[secret[0] - 'A'] << ' ';
	if (secret[1] >= '0'&&secret[1] <= '9') std::cout << std::setfill('0') << std::setw(2) << secret[1] - '0';
	else std::cout << std::setfill('0') << std::setw(2) << secret[1] - 'A' + 10;
	std::cout << ':' << std::setfill('0') << std::setw(2) << b;
	getchar();
	getchar();
	return 0;
}