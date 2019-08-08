#include <iostream>
#include <iomanip>
int PrintOut(int address, int data[], int k, int next[],int &address1st,int i) {
	if (k != 0) {
		PrintOut(next[address], data, k - 1, next, address1st, i);
		printf(" %05d\n%05d %d", address, address, data[address]);	//用c++iostream可能超时：std::cout << ' ' << std::setw(5) << std::setfill('0') << address << std::endl << std::setw(5) << std::setfill('0') << address << ' ' << data[address];
	}
	else if (k == 0) { 
		address1st = next[address];
		if (i == 0) printf("%05d %d", address, data[address]);	//std::cout << std::setw(5) << std::setfill('0') << address << ' ' << data[address];
		else printf(" %05d\n%05d %d", address, address, data[address]);	//std::cout << ' ' << std::setw(5) << std::setfill('0') << address <<std::endl << std::setw(5) << std::setfill('0') << address << ' ' << data[address];
	}
	return 0;
}
int main() {
	int data[100001] = { 0 }, next[100001] = { 0 };
	int address1st, n, k;
	int addressWr;
	std::cin >> address1st >> n >> k;

	for (int i = 0; i < n; i++) {
		std::cin >> addressWr;
		std::cin >> data[addressWr] >> next[addressWr];
	}
	for (int i = 0; i < n - n % k; i += k) {
		PrintOut(address1st, data, k-1, next, address1st, i);
	}
	for (int i = n - n % k; i < n; i++) {
		printf(" %05d\n%05d %d", address1st, address1st, data[address1st]);	// std::cout << ' ' << std::setw(5) << std::setfill('0') << address1st << std::endl << std::setw(5) << std::setfill('0') << address1st << ' ' << data[address1st];
		address1st = next[address1st];
		if (i == n - 1) std::cout << " -1";
	}
	if (n%k == 0) std::cout << " -1";/*注意整除时的特殊情况，不然后面没有-1*/
	
	getchar();
	getchar();

	return 0;
}


//听说这道题最后一个测试点含有多余的节点，不是很懂怎么搞。。。。其他都AC了