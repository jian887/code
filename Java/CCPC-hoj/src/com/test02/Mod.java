package com.test02;

import java.util.Scanner;

public class Mod {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int s = sc.nextInt();
		//int b = 1000000007;
		int b = 3;
		System.out.println(s%b);
		System.out.println(b%s);
		System.out.println(b);
	}

}
