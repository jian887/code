package com.two;

import java.util.Scanner;

public class Test02 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);

		int n = scanner.nextInt();
		/*
		 * while(n--) {
		 * error java 没有 1 0 只有布尔变量 true false 
		 * 
		 * }
		 */
		for (int i = 0; i < n; i++) {
			int a, b, c;
			a = scanner.nextInt();
			b = scanner.nextInt();
			c = scanner.nextInt();

			if (a * a + b * b == c * c || a * a + c * c == b * b || c * c + b * b == a * a) {
				System.out.println("good");
			}

			else if (a == b || a == c || b == c) {
				System.out.println("perfect");
			} else {
				System.out.println("just a triangle");
			}
		}

	}

}
