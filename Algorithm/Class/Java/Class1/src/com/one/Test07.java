package com.one;

import java.util.Scanner;

public class Test07 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		int b, c;
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) {
			int n = sc.nextInt();
			int a = sc.nextInt();
			if (n == 0) {
				System.out.println("-1 -1");
			} else if (n == 1) {
				System.out.println("1 " + (a + 1));
			} else if (n == 2) {
				if (a % 2 == 0) {
					n=(a-1)/2;
					b = n * n;
					c = b + 2;
				} else {
					n=a/2;
					b = n * n + (n + 1) * (n + 1) - 1;
					c = b + 1;
				}
				System.out.println(b + " " + c);
			} else {
				System.out.println("-1 -1");
			}
		}
	}

}
