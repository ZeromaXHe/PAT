//后两个测试点超时
import java.util.HashSet;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int m = scanner.nextInt();
		
		String[][] strs = new String[n][2];
		for(int i=0;i<n;i++) {
			strs[i][0]=scanner.next();
			strs[i][1]=scanner.next();
		}
		for(int i=0;i<m;i++) {
			int num = scanner.nextInt();
			boolean flag = true;
			HashSet<String> set = new HashSet<>();
			for(int j=0;j<num;j++) {
				set.add(scanner.next());
			}
			for(int j=0;j<n;j++) {
				if(set.contains(strs[j][0])&&set.contains(strs[j][1])) {
					flag= false;
					break;
				}
			}
			if(flag) System.out.println("Yes");
			else System.out.println("No");
		}
		scanner.close();
	}
}