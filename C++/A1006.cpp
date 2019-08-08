#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


int main() {
	int m;
	std::string earliest, latest;
	int eH = 24, eM = 61, eS = 61, lH = -1, lM = -1, lS = -1;
	std::cin >> m;
	for (int i = 0; i < m; i++) {
		std::string id;
		int iH, iM, iS, oH, oM, oS;
		std::cin >> id;
		scanf_s("%d:%d:%d %d:%d:%d", &iH, &iM, &iS, &oH, &oM, &oS);
		if (iH < eH || (iH == eH && iM < eM) || (iH == eH && iM == eM && iS <= eS)) {
			earliest = id;
			eH = iH;
			eM = iM;
			eS = iS;
		}
		if (oH > lH || (oH == lH && oM > lM) || (oH == lH && oM == lM && oS >= lS)) {
			latest = id;
			lH = oH;
			lM = oM;
			lS = oS;
		}

	}
	std::cout << earliest << ' ' << latest;

	getchar();
	getchar();

	return 0;
}