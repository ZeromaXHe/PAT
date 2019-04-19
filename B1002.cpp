#include <iostream>
#include <string>
int PrintNum(char x) {
	switch (x) {
	case '0': std::cout << "ling"; break;
	case '1': std::cout << "yi"; break;
	case '2': std::cout << "er"; break;
	case '3': std::cout << "san"; break;
	case '4': std::cout << "si"; break;
	case '5': std::cout << "wu"; break;
	case '6': std::cout << "liu"; break;
	case '7': std::cout << "qi"; break;
	case '8': std::cout << "ba"; break;
	case '9': std::cout << "jiu"; break;
	default: break;
	
	}
	return 0;
}
int main() {
	std::string s,num;
	int sum = 0;
	std::cin >> s;
	for (int i = 0; i < s.length(); i++) {
		sum += s[i] - '0';
	}
	num = std::to_string(sum);
	for (int n = 0; n < num.length(); n++) {
		if (n != 0) std::cout << " ";
		PrintNum(num[n]);
	}
	getchar();
	getchar();
	return 0;
}
