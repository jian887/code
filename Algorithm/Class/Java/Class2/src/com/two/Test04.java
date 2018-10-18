package com.two;

import java.util.Scanner;

public class Test04 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		while (scanner.hasNextInt()) {
			int m = scanner.nextInt();
			int n = scanner.nextInt();
			if (m == -1 && n == -1) {
				break;
			}
			int temp;
			if (n > m) {
				temp = m;
				m = n;
				n = temp;
			}
			int a = fun(m, n);
			if (a == 1) {
				System.out.println("YES");

			} else {
				System.out.println("POOR Haha");
			}
		}
	}

	public static int fun(int m, int n) {
		int a;
		if (m % n == 0) {
			return n;
		} else {
			a = m % n;
			return fun(n, a);
		}
	}
}
