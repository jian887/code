package com;

import java.util.LinkedList;
import java.util.Scanner;


public class 黎书延 {
	/**
	 * ÌâÄ¿Èý£ºÊµÏÖŒòµ¥µÄÍŒÊé¹ÜÀíÏµÍ³
	 * 
	 * @author Administrator
	 *
	 */


		private static LinkedList<String> list1 = new LinkedList<>();
		private static LinkedList<Integer> list2 = new LinkedList<>();
		private static LinkedList<Double> list3 = new LinkedList<>();

		public static void main(String[] args) {
			menu();
		}

		public static void menu() {
			Scanner sc = new Scanner(System.in);
			System.out.println("»¶Ó­ÀŽµœÍŒÊé¹ÜÀíÏµÍ³");
			System.out.println("ÇëÊäÈë¶ÔÓŠµÄÊý×ÖœøÐÐ²Ù×÷:");
			System.out.println("0. ÍË³öÏµÍ³");
			System.out.println("1. ÌíŒÓ");
			System.out.println("2. ÉŸ³ý");
			System.out.println("3. ²éÕÒ");
			System.out.println("4. œèÔÄ¡¢¹é»¹");
			System.out.print("ÇëÑ¡Ôñ(0~4):");
			int a = sc.nextInt();
			while (a < 0 || a > 5) {
				System.out.print("ÊäÈëÎÞÐ§£¬ÇëÖØÐÂÊäÈë:");
				a = sc.nextInt();
			}
			switch (a) {
			case 1:
				add();
				break;
			case 2:
				delete();
				break;
			case 3:
				search();
				break;
			case 4:
				update();
				break;
			case 0:
				System.out.println("³É¹ŠÍË³öÏµÍ³£¡£¡£¡");
				System.exit(0); // ·Ç0×ŽÌ¬ÊÇÒì³£ÖÕÖ¹,ÍË³öjvm
				break;
			}
		}

		private static void add() {
			Scanner sc = new Scanner(System.in);
			System.out.println("ÇëÊäÈëÊéÃû:");
			String line = sc.nextLine();
			list1.add(line);
			System.out.println("ÇëÊäÈëÊéºÅ:");
			try {
				int i = sc.nextInt();
				list2.add(i);
			} catch (Exception e) {
				System.out.println("ÊäÈëžñÊœŽíÎó,ÇëÖØÐÂÊäÈëÊéºÅ:");
			}
			System.out.println("ÇëÊäÈë×ŽÌ¬:");
			try {
				double d = sc.nextDouble();
				list3.add(d);
			} catch (Exception e) {
				System.out.println("ÊäÈëžñÊœŽíÎó,ÇëÖØÐÂÊäÈëÊéºÅ:");
			}
			menu();
		}

		private static void delete() {
			Scanner sc = new Scanner(System.in);
			System.out.println("ÇëÊäÈëÐèÒªÉŸ³ýµÄÊéºÅ:");
			int num = sc.nextInt();
			for (Integer i : list2) {
				if (i == num) {
					list2.remove(i);
					System.out.println("ÉŸ³ý³É¹Š!");
				} else {
					System.out.println("ÉŸ³ýÊ§°Ü!");
				}
			}
			menu();

		}

		private static void update() {
			Scanner sc = new Scanner(System.in);
			System.out.println("ÇëÊäÈëÄãËùÒªÐÞžÄµÄÊéºÅ:");
			int n = sc.nextInt();
			for (Integer i : list2) {
				if (i == n) {
					list2.remove(i);
					System.out.println("ÇëÊäÈëžÃÊéµÄ×ŽÌ¬:");
					int m = sc.nextInt();
					list2.add(m);
					System.out.println("ÐÞžÄ³É¹Š!");
				} else {
					System.out.println("ÐÞžÄÊ§°Ü!");
				}
			}
			menu();
		}

		private static void search() {
			Scanner sc = new Scanner(System.in);
			System.out.println("ÇëÊäÈëÄãËùÒª²éÕÒµÄÊéºÅ:");
			int x = sc.nextInt();
			for (Integer i : list2) {
				if (i == x) {
					System.out.println("ÄúËùÒª²éÕÒµÄÊéºÅÊÇ:" + i);
				} else {
					System.out.println("²»ŽæÔÚžÃÊéºÅ!");
				}
			}
			menu();
		}

	}


