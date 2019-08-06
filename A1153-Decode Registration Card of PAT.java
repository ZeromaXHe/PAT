//后三次测试点超时，第二个测试点答案错误（一共5个测试点）

import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();// 考生卡数
		int m = scanner.nextInt();// 查询数

		Map<String, Integer> mapA = new HashMap<>();
		Map<String, Integer> mapB = new HashMap<>();
		Map<String, Integer> mapT = new HashMap<>();

		Map<String, Integer> mapSiteScore = new HashMap<>();
		Map<String, Integer> mapSiteNum = new HashMap<>();

		Map<String, Map<String, Integer>> mapDateMapSiteNum = new HashMap<>();

		for (int i = 0; i < n; i++) {
			String card = scanner.next().trim();
			int score = scanner.nextInt();

			switch (card.charAt(0)) {
			case 'A':
				mapA.put(card, score);
				break;
			case 'B':
				mapB.put(card, score);
				break;
			case 'T':
				mapT.put(card, score);
				break;
			}

			String site = card.substring(1, 4);
			Integer siteScore = mapSiteScore.get(site);
			if (siteScore == null) {
				mapSiteScore.put(site, score);
				mapSiteNum.put(site, 1);
			} else {
				mapSiteScore.put(site, siteScore + score);
				mapSiteNum.put(site, mapSiteNum.get(site) + 1);
			}

			String date = card.substring(4, 10);
			Map<String, Integer> siteNum = mapDateMapSiteNum.get(date);
			if (siteNum == null) {
				siteNum = new HashMap<>();
				siteNum.put(site, 1);
				mapDateMapSiteNum.put(date, siteNum);
			} else {
				Integer num = siteNum.get(site);
				if (num == null)
					siteNum.put(site, 1);
				else
					siteNum.put(site, num + 1);
			}
		}

		for (int i = 0; i < m; i++) {
			int type = scanner.nextInt();
			String s = scanner.next();
			System.out.println("Case " + (i + 1) + ": " + type + " " + s);
			switch (type) {
			case 1:
				Map<String, Integer> mapPAT = null;
				if (s.equals("A")) {
					mapPAT = mapA;
				} else if (s.equals("B")) {
					mapPAT = mapB;
				} else if (s.equals("C")) {
					mapPAT = mapT;
				}
				if (mapPAT.isEmpty())
					System.out.println("NA");
				else {
					List<Map.Entry<String, Integer>> list = new ArrayList<>(mapPAT.entrySet());
					// 然后通过比较器来实现排序
					Collections.sort(list, new Comparator<Map.Entry<String, Integer>>() {
						// 成绩降序排列，相等则按卡号升序排序
						public int compare(Entry<String, Integer> o1, Entry<String, Integer> o2) {
							if (o1.getValue().compareTo(o2.getValue()) != 0)
								return -o1.getValue().compareTo(o2.getValue());
							else
								return o1.getKey().compareTo(o2.getKey());
						}

					});
					for (Entry<String, Integer> entry : list) {
						String mapKey = entry.getKey();
						int mapValue = entry.getValue();
						System.out.println(mapKey + " " + mapValue);
					}
				}
				break;
			case 2:
				if (mapSiteScore.get(s) == null)
					System.out.println("NA");
				else
					System.out.println(mapSiteNum.get(s) + " " + mapSiteScore.get(s));
				break;
			case 3:
				Map<String, Integer> mapSiteNumForDate = mapDateMapSiteNum.get(s);
				if (mapSiteNumForDate == null)
					System.out.println("NA");
				else {
					// 这里将map.entrySet()转换成list
					List<Map.Entry<String, Integer>> list = new ArrayList<Map.Entry<String, Integer>>(
							mapSiteNumForDate.entrySet());
					// 然后通过比较器来实现排序
					Collections.sort(list, new Comparator<Map.Entry<String, Integer>>() {
						// 人数降序排序，相等则按考场号升序
						public int compare(Entry<String, Integer> o1, Entry<String, Integer> o2) {
							if (o1.getValue().compareTo(o2.getValue()) != 0)
								return -o1.getValue().compareTo(o2.getValue());
							else
								return o1.getKey().compareTo(o2.getKey());
						}

					});
					for (Entry<String, Integer> entry : list) {
						String mapKey = entry.getKey();
						int mapValue = entry.getValue();
						System.out.println(mapKey + " " + mapValue);
					}
				}
				break;
			}
		}

		scanner.close();
	}
}