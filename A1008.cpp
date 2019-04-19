#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


int main() {
	int floor;
	int latestF = 0;
	int time = 0;

	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::cin >> floor;
		if (floor > latestF) {
			time += (floor - latestF) * 6;
		}
		else {
			time += 4 * (latestF - floor);
		}
		latestF = floor;
		time += 5;
	}
	std::cout << time;
	getchar();
	getchar();

	return 0;
}