package com.test02;

public class Test02 {
	
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int a, n, b = 0, c = 0;
		int t = sc.nextInt();
		if (t >= 1 && t <= 1000000) {
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
		} else
			return;
	}
	
	
	
	public static void main(String[] args) {
		long a = 777;
		long b = 301864;
		long c = 301865;
		System.out.println(c * c);
		System.out.println(a * a + b * b);
	}

}
