#include <iostream>
#include <string>
int ReverseSentence() {
	std::string s;
	if (std::cin >> s) { ReverseSentence(); }/*���𰸸�ʽ���������ջʵ��*/
	if (s != "")std::cout << s << ' ';//��ʵû����ʽ��������Ϊ��һ�����˿�ʼ���ж�����if (s != "")��û�еĻ������������ʱ�����ﻹ��������ո�
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