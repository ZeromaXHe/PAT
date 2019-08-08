#include <iostream>

int main() {
	int n, test, count=0;
	int CallatzNum[101] = {0}, check[101] = { 0 };
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> check[i];
		test = check[i];
		//std::cout << "Testing:" << check[i] << std::endl;
		while (test != 1) {
			if (test % 2 == 1) {
				test = test * 3 + 1;
			}
			test /= 2;
			//std::cout << test << " ";
			if (test < 101) CallatzNum[test] = 1; /*3n+1的时候可能会大于100，据网上说可能到2000多……可怕*/
			//std::cout << "Setting CN to 1:" << test << " DONE;"<< std::endl;
		}
		//std::cout << "[All CallatzNum Output]" << std::endl;
	}
	//std::cout << "PHASE 2:" << std::endl << std::endl;
	for (int i = 0; i < n; i++) {
		if (CallatzNum[check[i]] != 1) {
			CallatzNum[check[i]] = 2;
		}
		//std::cout << "i: " << i << " check[i]: " << check[i] << " CallatzNum: " << CallatzNum[check[i]] << std::endl;
	}
	for (int i = 100; i > 0; i--) {
		
		if (CallatzNum[i] == 2) {
			if (count == 0) { count++; std::cout << i; }
			else std::cout << " " << i;
		}
	}
	//std::cout << "Finished";

	getchar();
	getchar();
	return 0;
}