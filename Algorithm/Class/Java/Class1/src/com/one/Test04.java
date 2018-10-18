package com.one;

import java.util.Scanner;

public class Test04 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		while (true) {
			int n = sc.nextInt();
			if (n == 0)
				break;
			int sum = 0;
			for (int i = 0; i < n; i++) {
				int a = sc.nextInt();
				sum += a;
			}
			System.out.println(sum);
		}
	}

}
