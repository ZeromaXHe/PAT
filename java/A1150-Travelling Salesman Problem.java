//只对了2号测试点。。。（一共4个）
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int m = scanner.nextInt();
		int[][] map = new int[n+1][n+1];
		for(int i=0;i<m;i++) {
			int c1 = scanner.nextInt();
			int c2 = scanner.nextInt();
			int d = scanner.nextInt();
			map[c1][c2]=map[c2][c1]=d;
		}
		int k = scanner.nextInt();
		int shortestDist = Integer.MAX_VALUE;
		int shortestPath = -1;
		loop:
		for(int i=0;i<k;i++) {
			int x = scanner.nextInt();
			int start = scanner.nextInt();
			int backup = start;
			int end = -1;
			int totalDist = 0;
			boolean[] visit = new boolean[n+1];
			int notSimple = 0;
			System.out.print("Path "+(i+1)+": ");
			for(int j=1;j<x;j++) {
				end = scanner.nextInt();
				if(visit[end]) notSimple++;
				else visit[end] = true;
				
				if(map[start][end]==0) {
					System.out.println("NA (Not a TS cycle)");
					totalDist = Integer.MAX_VALUE;
					continue loop;
				}
				else {
					totalDist += map[start][end];
					if(j==x-1&&backup!=end) {
						System.out.println(totalDist+" (Not a TS cycle)");
						continue loop;
					}
				}
				
				start = end;
			}
			
			if(notSimple==0 && x==n+1) {
				System.out.println(totalDist+" (TS simple cycle)");
				if(totalDist<shortestDist) {
					shortestDist = totalDist;
					shortestPath = i+1;
				}
			}
			else if(x-notSimple==n+1){
				System.out.println(totalDist+" (TS cycle)");
				if(totalDist<shortestDist) {
					shortestDist = totalDist;
					shortestPath = i+1;
				}
			}
			else {
				System.out.println(totalDist+" (Not a TS cycle)");
			}
		}
		System.out.println("Shortest Dist("+shortestPath+") = "+shortestDist);
		
		scanner.close();
	}
}