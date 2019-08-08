#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <deque>
int toll[24];
const int monDays[13] = { -1,31,28,31,30,31,30,31,31,30,31,30,31 };
struct timeInfo {
	int mon, day, hour, min, time;
};
struct node {
	std::string name;
	timeInfo time;
	std::string onoff;
};
struct node2 {
	timeInfo stt;
	timeInfo end;
};
bool cmp(node a, node b) {
	if (a.name == b.name) {
		if (a.time.mon == b.time.mon) {
			if (a.time.time == b.time.time) {
				return a.onoff > b.onoff;//注意要比较onoff，不然同一时间上下线的话可能会bug。
			}
			else return a.time.time < b.time.time;
		}
		else return a.time.mon < b.time.mon;
	}
	else return a.name < b.name;
}
float countPrice(int toll[], node2 billnode) {
	float price = 0.0;
	while (billnode.stt.time < billnode.end.time) {
		if (billnode.end.hour != billnode.stt.hour || billnode.end.day != billnode.stt.day) {
			price += (60 - billnode.stt.min)*toll[billnode.stt.hour];
			billnode.stt.time += 60 - billnode.stt.min;//这里试一下+=的优先级是不是最低的（看样子试成功了，的确不用加括号）
			billnode.stt.min = 0;
			if (billnode.stt.hour < 23) billnode.stt.hour += 1;
			else {
				billnode.stt.hour = 0;
				billnode.stt.day += 1;//由于这里，countPrice只可用于同月以内计算
			}
		}
		else {
			price += (billnode.end.min - billnode.stt.min)*toll[billnode.stt.hour];
			billnode.stt.min = billnode.end.min;
			billnode.stt.time = billnode.end.time;
		}
	}
	price /= 100;
	return price;
}
int PrintPerBill(std::deque<node2> &perBill, std::string tmpName) {
	int tmpMon = 0;
	float totalPrice = 0;
	std::deque<node2> perBill2;
	while (perBill.empty() != 1) {//这个循环预处理perBill，将跨月处理好，还有把消费为0的记录去掉。
		if (perBill[0].end.mon == perBill[0].stt.mon) {
			float price = countPrice(toll, perBill[0]);
			if (price != 0)perBill2.push_back(perBill.front());
			perBill.pop_front();
		}
		else{
			node2 temp1 = perBill.front();
			node2 temp2 = perBill.front();
			temp1.stt.mon = temp1.end.mon;
			temp1.stt.day = 1;
			temp1.stt.hour = 0;
			temp1.stt.min = 0;
			temp1.stt.time = 1440 * (temp1.stt.day - 1) + 60 * temp1.stt.hour + temp1.stt.min;
			temp2.end.mon = temp2.stt.mon;
			temp2.end.day = monDays[temp2.stt.mon];
			temp2.end.hour = 23;
			temp2.end.min = 60;
			temp2.end.time = 1440 * (temp2.end.day - 1) + 60 * temp2.end.hour + temp2.end.min;
			perBill.pop_front();
			perBill.push_front(temp1);
			perBill.push_front(temp2);
		}
	}
	while (perBill2.empty() != 1) {//这个循环负责输出
		if (tmpMon != perBill2[0].stt.mon) {
			if (totalPrice != 0) {
				printf("Total amount: $%.02f\n", totalPrice);
				totalPrice = 0;
			}
			tmpMon = perBill2[0].stt.mon;
			std::cout << tmpName << ' ' << std::setw(2) << std::setfill('0') << tmpMon << std::endl;
		}
		if (perBill2[0].end.mon == perBill2[0].stt.mon) {
			float price = countPrice(toll, perBill2[0]);
			if(price != 0)printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.02f\n", perBill2[0].stt.day, perBill2[0].stt.hour,
				perBill2[0].stt.min, perBill2[0].end.day, perBill2[0].end.hour, perBill2[0].end.min,
				perBill2[0].end.time - perBill2[0].stt.time, price);
			totalPrice += price;
			perBill2.pop_front();
		}
		
	}
	if (totalPrice != 0) {
		printf("Total amount: $%.02f\n", totalPrice);
	}
	return 0;
}
int main() {
	
	for (int i = 0; i < 24; i++) {
		std::cin >> toll[i];
	}
	int n;
	std::cin >> n;
	std::vector<node> bill;//别设定为n，不然后面用push_back会让size变成2n，前n个都是空的。
	std::deque<node2> perBill;
	node temp;
	for (int i = 0; i < n; i++) {
		node billnode;
		std::cin >> billnode.name;
		scanf_s("%d:%d:%d:%d", &billnode.time.mon, &billnode.time.day, &billnode.time.hour, &billnode.time.min);
		std::cin >> billnode.onoff;
		billnode.time.time = 1440 * (billnode.time.day - 1) + 60 * billnode.time.hour + billnode.time.min;
		bill.push_back(billnode);
	}
	sort(bill.begin(), bill.end(), cmp);

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			temp = bill[i];
		}
		if (temp.name != bill[i].name) {
			PrintPerBill(perBill, temp.name);
			temp = bill[i];
		}
		else {
			if (bill[i].onoff == "on-line") {
				temp = bill[i];
			}
			else if (bill[i].onoff == "off-line" && temp.onoff == "on-line") {
				node2 billnode2;
				billnode2.stt = temp.time;
				billnode2.end = bill[i].time;
				perBill.push_back(billnode2);
			}
		}
	}
	PrintPerBill(perBill, temp.name);
	

	getchar();
	getchar();

	return 0;
}