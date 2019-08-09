//前两个测试点答案错误，最后一个测试点超时
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int m = scanner.nextInt();

		boolean[][] map = new boolean[n][n];
		
		for(int i=0;i<m;i++) {
			int from = scanner.nextInt()-1;
			int to = scanner.nextInt()-1;
			map[from][to]=true;
		}
		
		int k = scanner.nextInt();
		boolean notFirst = false;
		loop:
		for(int i=0;i<k;i++) {
			boolean[] visit = new boolean[n];
			for(int j=0;j<n;j++) {
				int now = scanner.nextInt()-1;
				visit[now]=true;
				for(int k1=0;k1<n;k1++) {
					if(map[k1][now]&&!visit[k1]) {
						if(notFirst) System.out.print(" ");
						System.out.print(i);
						notFirst = true;
						continue loop;
					}
				}
			}
		}
		
		scanner.close();
	}
}