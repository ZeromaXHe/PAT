#include <iostream>
#include <iomanip>
#include <string>
int main() {
	std::string s1, s2;
	std::cin >> s1 >> s2;
	int k = 0, i = 0;
	std::string s;
	for (k = 0; k < s1.length(); k++) {
		if (s1[k] != s2[i]) {
			int flag = 0;//��֮����һ��ο��Կ���ʹ��string��find()�������м򻯣�ע���Ҳ����������find����ֵΪstd::string::nops
			for (int x = 0; x < s.length(); x++) {
				if (toupper(s1[k]) == s[x]) flag = 1;//ʹ��find�������ȥflag��������nposֱ��ʵ��
			}//ʹ��find()�Ļ�ֱ��д��if (s2.find(s1[i]) == string::npos && s.find(toupper(s1[i])) == string::npos)s += toupper(s1[i]);  ������ֱ��˫��ѭ�������Ӷ��Ը�һЩ��������������O(n^2)
			if (flag == 0) s += toupper(s1[k]);//ע�⣺toupper()����ʵ�ִ�Сдת�������Ƶ���tolowerתСд��
		}
		else {
			i++;
			if (i > s2.length()) {
				for (int y = k + 1; y < s1.length(); y++) {
					int flag = 0;
					for (int x = 0; x < s.length(); x++) {
						if (toupper(s1[y]) == s[x]) flag = 1;
					}
					if (flag == 0) s += toupper(s1[y]);
				}
				break;
			}
		}
	}
	std::cout << s;
	getchar();
	getchar();

	return 0;
}