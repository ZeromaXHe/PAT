import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int l = scanner.nextInt();// 总数字长度
		int k = scanner.nextInt();// k位素数
		String num = scanner.next().trim();
		boolean flag = false;
		for(int i=k-1;i<l;i++) {
			if(isPrimer(Integer.parseInt(num.substring(i-k+1,i+1)))) {
				System.out.println(num.substring(i-k+1,i+1));
				flag = true;
				break;
			}
		}
		if(!flag) System.out.println("404");
		
		scanner.close();
	}
	
	private static boolean isPrimer(int i) {
		if(i==2)return true;//不加的的话2、5号测试点没过（总共7个）
		if(i<2||i%2==0) return false;
		for(int x=3;x*x<=i;x+=2) {
			if(i%x==0) return false;
		}
		return true;
	}
}

//错误解法：
// import java.util.Scanner;
// public class Main {
// 	public static void main(String[] args) {
// 		Scanner scanner = new Scanner(System.in);
// 		int l = scanner.nextInt();// 总数字长度
// 		int k = scanner.nextInt();// k位素数
// 		String num = scanner.next().trim();
// 		boolean flag = false;
// 		for(int i=k-1;i<l;i++) {
// 			int intee = num.charAt(i)-'0';
// 			if(intee%2==0||intee%5==0) continue;//画蛇添足，这样例如002、05这些就不能被识别了
// 			else if(isPrimer(Integer.parseInt(num.substring(i-k+1,i+1)))) {
// 				System.out.println(num.substring(i-k+1,i+1));
// 				flag = true;
// 				break;
// 			}
// 		}
// 		if(!flag) System.out.println("404");
		
// 		scanner.close();
// 	}
	
// 	private static boolean isPrimer(int i) {//2会判断错误，认为不是素数
// 		if(i<2||i%2==0) return false;
// 		for(int x=3;x*x<i;x+=2) {//这里x*x应当是小于等于i，漏了等于号
// 			if(i%x==0) return false;
// 		}
// 		return true;
// 	}
// }