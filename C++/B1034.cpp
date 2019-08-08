#include <iostream>
#include <string>
#include <vector>
long long gcd(long long t1, long long t2) {
	if (t1 < 0)t1 = -t1;
	if (t2 < 0)t2 = -t2;//����abs����Ȼò��long long����ֵ�������
	return t2 == 0 ? t1 : gcd(t2, t1 % t2);
}//������С��Լ�����㷨ʵ�֣��úúü���һ�¡�������i=2��ʼi++һ��һ������Լ�����Ӷ�̫��
int Expression(long long a, long long b) {
	bool sign = false;
	bool flag = false;
	if (b == 0) printf("Inf");
	else if (a == 0) std::cout << a;
	else if (b == 1) {
		if (a < 0)std::cout << '(' << a << ')';//ע��a����С���㣬���ʱ����������
		else std::cout << a;
	}
	else {
		if ((a < 0 && b>0) || (a > 0 && b < 0)) {
			sign = true;
			printf("(-");
		}
		if (a < 0)a = -a;
		if (b < 0)b = -b;
		if (a > b) {
			std::cout << a / b;
			a %= b;
			flag = true;
		}
		if (a != 0) {
			long long gcd_ab = gcd(a, b);//����������������ɣ���Ȼ�����һ��ִ�����a�ͱ���
			a /= gcd_ab;
			b /= gcd_ab;
			if (a == b)printf("1");
			else {
				if (flag == true) printf(" ");
				std::cout << a << '/' << b;
			}
		}
		if (sign == true) printf(")");
	}
	return 0;
}
int main() {
	long long a, b, c, d;
	scanf_s("%lld/%lld %lld/%lld", &a, &b, &c, &d);

	Expression(a, b); std::cout << " + "; Expression(c, d); std::cout << " = "; Expression(a*d + c * b, b*d); std::cout << std::endl;
	Expression(a, b); std::cout << " - "; Expression(c, d); std::cout << " = "; Expression(a*d - c * b, b*d); std::cout << std::endl;
	Expression(a, b); std::cout << " * "; Expression(c, d); std::cout << " = "; Expression(a*c, b*d); std::cout << std::endl;
	Expression(a, b); std::cout << " / "; Expression(c, d); std::cout << " = "; Expression(a*d, b*c); std::cout << std::endl;


	getchar();
	getchar();

	return 0;
}