package com.daily;

import java.util.Random;
import java.util.Scanner;

import javax.jws.Oneway;

public class DecideWorkApp {
	/*
	 * private static int[] workNumber = new int[100];
	 * 
	 * // private int[] wordNumber;
	 * 
	 * static String[] oneWord = new String[workNumber[0]]; static String[] twoWord
	 * = new String[workNumber[1]]; static String[] threeWord = new
	 * String[workNumber[2]]; static String[] fourWord = new String[workNumber[3]];
	 */
	public static void main(String[] args) {
		String[][][][] work = new String[][][][] {
				{ { { "1.课程" } }, { { "1. 计算机组成原理" } }, { { "2. 计算机英语" } }, { { "3.  物联网感知技术" } },
						{ { "4.  物联网RFID" } } },
				{ { { "2.考研" } }, { { "1. 数学" } }, { { "2.英语" } }, { { "3.专业课" } } },
				{ { { "3.四级" } } },
				{ { { "4.学习" } },
					
						{ { "1. 开发" }, { "PC应用", "C", "C++", "Java", "Python","C#","GUI","Swing","QT" },
								{ "Web应用", "Java", "Javascript", "PHP" }, { "手机应用", "Android", "K", "F" } },
						{ { "2.算法" }, { "51nod", "C", "C++", "Java" }, { "杭电", "C", "C++", "Java" },
								{ "牛客网", "C", "C++", "Java" }, { "leetcode", "C", "C++", "Java" },
								{ "codef", "C", "C++", "Java" } },
						{ { "3.数据" }, { "Python", "base", "kaggle" }, { "matlab", "base", "神经网络" },
								{ "SAS", "base" } } },
				{ { { "5.竞赛" } }, { { "数学竞赛" } }, { { "SAS" } } },
				{ { { "6.优化" } }, { { "Linux" } }, { { "Windows" } } } };
				//System.out.println(work[1][0][0][0]); 此处有bug
				Scanner sc = new Scanner(System.in);
		Random random = new Random();
		/*
		 * workNumber[0] = sc.nextInt();
		 * 
		 * oneWord[] = sc.nextLine();
		 */
		/*
		 * int start = sc.nextInt();
		 * 
		 * if(start==1) {
		 * 
		 * int oneWork = random.nextInt(5)%(5-1+1)+1; int twoWork =
		 * random.nextInt(5)%(5-1+1)+1; int threeWork = random.nextInt(5)%(5-1+1)+1;
		 * 
		 * for(int i = 0 ;i <4 ;i++) { if (i==oneWork) { System.out.println(i); } }
		 * 
		 * 
		 * }
		 */
		int start;
		int oneWork, twoWork, threeWork, fourWork;
	
		System.out.println("输入“1”开始");
	
		start = sc.nextInt();
		if (start == 1) {
			// continue;
		} else {
			return;
		}
		while (true) {

			oneWork = random.nextInt(work.length) % ((work.length) - 0 + 1) + 0;
			System.out.println(work[oneWork][0][0][0]);
			System.out.println("是否继续：1、继续请按“1”；不继续请按“0”");
			int i = sc.nextInt();
			if (i == 0) {
				break;
			}

		}
		while (true) {

			twoWork = random.nextInt(work[oneWork].length) % ((work[oneWork].length) - 0 + 1) + 0;
			System.out.println(work[oneWork][twoWork][0][0]);
			System.out.println("是否继续：1、继续请按“1”；不继续请按“0”");
			int i = sc.nextInt();
			if (i == 0) {
				break;
			}

		}
		while (true) {

			threeWork = random.nextInt(work[oneWork][twoWork].length) % ((work[oneWork][twoWork].length) - 0 + 1) + 0;
			System.out.println(work[oneWork][twoWork][threeWork][0]);
			System.out.println("是否继续：1、继续请按“1”；不继续请按“0”");
			int i = sc.nextInt();
			if (i == 0) {
				break;
			}

		}
		while (true) {

			fourWork = random.nextInt(work[oneWork][twoWork][threeWork].length) % ((work[oneWork][twoWork][threeWork].length) - 0 + 1) + 0;
			System.out.println(work[oneWork][twoWork][threeWork][fourWork]);
			System.out.println("是否继续：1、继续请按“1”；不继续请按“0”");
			int i = sc.nextInt();
			if (i == 0) {
				break;
			}

		}

	}

}
