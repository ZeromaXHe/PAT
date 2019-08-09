//最后一个测试点没过
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int[] arr = new int[n + 1];

		for (int i = 0; i < n; i++) {
			arr[i + 1] = scanner.nextInt();
		}
		boolean flag = true;
		int solution1 = Integer.MAX_VALUE;
		int solution2 = Integer.MAX_VALUE;

		for (int i = 1; i < n; i++) {
			loop2: for (int j = i + 1; j <= n; j++) {
				// System.out.println("check " + i + "+" + j);
				int[] tmp = new int[n + 1];
				for (int k = 1; k <= n; k++) {
					if (k == i || k == j) {
						if (tmp[Math.abs(arr[k])] != 0 && tmp[Math.abs(arr[k])] != -arr[k] / Math.abs(arr[k])) {
							continue loop2;
						} else {
							tmp[Math.abs(arr[k])] = -arr[k] / Math.abs(arr[k]);
						}
					} else {
						if (tmp[Math.abs(arr[k])] != 0 && tmp[Math.abs(arr[k])] != arr[k] / Math.abs(arr[k])) {
							continue loop2;
						} else {
							tmp[Math.abs(arr[k])] = arr[k] / Math.abs(arr[k]);
						}
					}
				}
				int countUnknown = 0;
				int unknown1 = 0;
				int unknown2 = 0;
				int countWolf = 0;
				int wolf1 = 0;
				int wolf2 = 0;
				for (int k = 1; k <= n; k++) {
					if (tmp[k] < 0) {
						countWolf++;
						if (wolf1 == 0)
							wolf1 = k;
						else if (wolf2 == 0)
							wolf2 = k;
						else
							continue loop2;
					} else if (tmp[k] == 0) {
						countUnknown++;
						if (unknown1 == 0)
							unknown1 = k;
						else if (unknown2 == 0)
							unknown2 = k;
						else
							continue loop2;
					}
				}
				if (countWolf + countUnknown != 2 && countWolf != 2) {
					continue;
				}
				if (countWolf == 2) {
					if ((wolf1 == i && wolf2 == j) || (wolf1 == j && wolf2 == i)
							|| (wolf1 != i && wolf1 != j && wolf2 != i && wolf2 != j)) {
						continue;
					} else {
						if (wolf1 < solution1 || (wolf1 == solution1 && wolf2 < solution2)) {
							solution1 = wolf1;
							solution2 = wolf2;
						}
						flag = false;
					}
				} else if (countWolf == 1) {
					if ((wolf1 == i && unknown1 == j) || (wolf1 == j && unknown1 == i)
							|| (wolf1 != i && wolf1 != j && unknown1 != i && unknown1 != j))
						continue;
					else if (wolf1 > unknown1) {
						if (unknown1 < solution1 || (unknown1 == solution1 && wolf1 < solution2)) {
							solution1 = unknown1;
							solution2 = wolf1;
						}
						flag = false;
					} else {
						if (wolf1 < solution1 || (wolf1 == solution1 && unknown1 < solution2)) {
							solution1 = wolf1;
							solution2 = unknown1;
						}
						flag = false;
					}
				} else {
					if ((unknown1 == i && unknown2 == j) || (unknown1 == j && unknown2 == i)
							|| (unknown1 != i && unknown1 != j && unknown2 != i && unknown2 != j))
						continue;
					else {
						if (unknown1 < solution1 || (unknown1 == solution1 && unknown2 < solution2)) {
							solution1 = unknown1;
							solution2 = unknown2;
						}
						flag = false;
					}
				}

			}
		}
		if (flag)
			System.out.println("No Solution");
		else
			System.out.println(solution1 + " " + solution2);

		scanner.close();
	}
}