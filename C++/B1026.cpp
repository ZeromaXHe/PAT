#include <iostream>
#include <iomanip>

int main() {
	int c1, c2, c;
	std::cin >> c1 >> c2;
	c = (c2 - c1 + 50) / 100;//ע������ʵ�֡��������롱�Ĳ������ȸ�(c2-c1)����50���������(b-a)/100��С��λ���ڵ���0.5����λ��С�ڵ���0.5�����ȥ
	int h, m, s;
	h = c / 3600;
	m = c / 60 % 60;
	s = c % 60;
	printf("%02d:%02d:%02d", h, m, s);

	getchar();
	getchar();

	return 0;
}