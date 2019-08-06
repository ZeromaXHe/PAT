import java.util.LinkedList;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int[] arr = new int[n];
		int fullLevel = 0;
		int levelNodeNum = 1;
		int nodeNum = 0;
		for (int i = 0; i < n; i++) {
			arr[i] = scanner.nextInt();
			nodeNum++;
			if (nodeNum == levelNodeNum) {
				fullLevel++;
				levelNodeNum <<= 1;
				nodeNum = 0;
			}
		}
		int right = (1 << (fullLevel - 1)) - (nodeNum + 1) / 2;
		LinkedList<Integer> stack = new LinkedList<>();
		boolean isMaxHeap = false;
		boolean isMinHeap = false;
		boolean isNonHeap = false;
		// System.out.println("arr:"+Arrays.toString(arr)+" fullLevel:"+fullLevel+"
		// nodeNum:"+nodeNum+" right:"+right);

		for (int i = 0; i < right; i++) {
			int p = (1 << fullLevel) - 2 - i;
			while (p != 0) {
				stack.push(arr[p]);
				p = (p - 1) / 2;
			}
			int temp = arr[0];
			int now = 0;
			System.out.print(temp);
			while (!stack.isEmpty()) {
				System.out.print(" ");
				now = stack.pop();
				if (!isNonHeap) {
					if (now > temp) {
						if (isMaxHeap) {
							isMaxHeap = false;
							isMinHeap = false;
							isNonHeap = true;
						} else
							isMinHeap = true;
					} else if (now < temp) {
						if (isMinHeap) {
							isMaxHeap = false;
							isMinHeap = false;
							isNonHeap = true;
						} else
							isMaxHeap = true;
					}
				}
				System.out.print(now);
				temp = now;
			}
			System.out.println();
		}

		for (int i = 0; i < nodeNum; i++) {
			int p = (1 << fullLevel) + nodeNum - 2 - i;
			while (p != 0) {
				stack.push(arr[p]);
				p = (p - 1) / 2;
			}
			int temp = arr[0];
			int now = 0;
			System.out.print(temp);
			while (!stack.isEmpty()) {
				System.out.print(" ");
				now = stack.pop();
				if (!isNonHeap) {
					if (now > temp) {
						if (isMaxHeap) {
							isMaxHeap = false;
							isMinHeap = false;
							isNonHeap = true;
						} else
							isMinHeap = true;
					} else if (now < temp) {
						if (isMinHeap) {
							isMaxHeap = false;
							isMinHeap = false;
							isNonHeap = true;
						} else
							isMaxHeap = true;
					}
				}
				System.out.print(now);
				temp = now;
			}
			System.out.println();
		}

		if (isMaxHeap) {
			System.out.println("Max Heap");
		} else if (isMinHeap) {
			System.out.println("Min Heap");
		} else if (isNonHeap) {
			System.out.println("Not Heap");
		} else {
			System.out.println("Max Heap");
		}
	}
}