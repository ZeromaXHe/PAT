//最后一个测试点超时
import java.util.LinkedList;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int m = scanner.nextInt();
		int n = scanner.nextInt();

		int[] heap = new int[n];
		int[] postOrder = post(n);

		for (int i = 0; i < m; i++) {
			int condition = 0;// 0 unknown; 1 Max Heap; 2 Min Heap; -1 Not Heap
			for (int j = 0; j < n; j++) {
				heap[j] = scanner.nextInt();
				if (j > 0 && condition != -1) {
					if (heap[j] > heap[(j - 1) / 2]) {
						if (condition == 1)
							condition = -1;
						else
							condition = 2;
					} else if (heap[j] < heap[(j - 1) / 2]) {
						if (condition == 2)
							condition = -1;
						else
							condition = 1;
					}
				}
			}
			switch (condition) {
			case 1:
				System.out.println("Max Heap");
				break;
			case 2:
				System.out.println("Min Heap");
				break;
			case -1:
				System.out.println("Not Heap");
				break;
			default:
				System.out.println("Max Heap");
				break;
			}
			for (int j = 0; j < n; j++) {
				if (j != 0)
					System.out.print(" ");
				System.out.print(heap[postOrder[j]]);
			}
			System.out.println();
		}
		scanner.close();
	}

	private static int[] post(int n) {
		int[] res = new int[n];
		boolean[] visited = new boolean[n];
		LinkedList<Integer> stack = new LinkedList<>();
		int pRes = 0;
		int p = 0;
		stack.push(p);
		while (!stack.isEmpty()) {
			if (p * 2 + 1 < n && !visited[p * 2 + 1]) {
				stack.push(p * 2 + 1);
				p = p * 2 + 1;
				visited[p] = true;
			} else if (p * 2 + 2 < n && !visited[p * 2 + 2]) {
				stack.push(p * 2 + 2);
				p = p * 2 + 2;
				visited[p] = true;
			} else {
				res[pRes] = stack.pop();
				pRes++;
				if (!stack.isEmpty())
					p = stack.peek();
			}
		}
		return res;
	}
}