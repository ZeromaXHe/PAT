#include <iostream>
#include <string>
int ReverseSentence() {
	std::string s;
	if (std::cin >> s) { ReverseSentence(); }/*本答案格式错误，最好用栈实现*/
	if (s != "")std::cout << s << ' ';//其实没错，格式错误是因为这一行少了开始的判断条件if (s != "")。没有的话，当输入结束时，这里还会输出个空格。
	return 0;
}
int main() {
	std::string s;
	std::cin >> s;
	ReverseSentence();

	std::cout << s;
	getchar();
	getchar();
	return 0;
}