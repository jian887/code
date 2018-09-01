package com.ccpc.hoj;

import java.util.Scanner;

public class Main04 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a, b = 0, c = 0, n;
		int t = sc.nextInt();
		for (int j = 0; j < t; j++) {
			n = sc.nextInt();
			a = sc.nextInt();
			if (n == 2 && a >= 3 && a <= 40000) {
				for (int i = 1; i < 3; i++) {
					if ((a * a - i * i) % (2 * i) == 0) {
						b = (a * a - i * i) / (2 * i);
						c = b + i;
						break;
					}
				}
				System.out.println(b + " " + c);
			} else {
				System.out.println("-1 -1");
			}
		}
	}
}

/*
 * 
 * else if (n == 1 && a >= 3 && a <= 40000) { c = 40001; b = c - a;
 * System.out.println(b + " " + c); }
 */
