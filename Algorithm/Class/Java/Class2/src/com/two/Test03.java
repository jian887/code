package com.two;

import java.util.Scanner;

public class Test03 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int i = 0;
		while (true) {
			i++;
			int sum = 0;
			int out = 0;
			int n = scanner.nextInt();
			if (n <= 0) {
				break;
			} else {
				int[] arr = new int[n];
				for (int j = 0; j < n; j++) {
					int h = scanner.nextInt();
					sum += h;
					arr[j] = h;
				}
				//System.out.println(sum);
				for (int j = 0; j < n; j++) {
					if ((arr[j] - sum / n) <= 0) {
						//System.out.println(arr[j] - sum / n);
						continue;

					} else {
						out += arr[j] - sum / n;
					//	System.out.println(arr[j] - sum / n);
					}
				}
				System.out.println("Set #" + i);
				//System.out.println("The minimum number of moves is " + out+"."+"\n"); 见鬼了，\n和syso效果一样，结果
				// 确却报error Presentation Error (输出格式与要求不符合，但是程序逻辑正确)
				System.out.println("The minimum number of moves is " + out+"."+"\n");
				System.out.println();
			}
		}

	}

}
