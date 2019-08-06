//后两个测试点内存超限
import java.util.HashSet;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();// 顶点数
		int m = scanner.nextInt();// 边数
		int[][] map = new int[m][2];
		for (int i = 0; i < m; i++) {
			map[i][0] = scanner.nextInt();
			map[i][1] = scanner.nextInt();
		}
		int k = scanner.nextInt();// 检查行数
		int[] check = new int[n];
		HashSet<Integer> set = new HashSet<>(); 
		boolean flag = true;
		for(int i=0;i<k;i++) {
			for(int j=0;j<n;j++) {
				check[j]=scanner.nextInt();
				set.add(check[j]);
			}
			for(int j=0;j<m;j++) {
				if(check[map[j][0]]==check[map[j][1]]) {
					flag = false;
					break;
				}
			}
			if(flag) System.out.println(set.size()+"-coloring");
			else System.out.println("No");
			set.clear();
            flag=true;
		}
		scanner.close();
	}
}