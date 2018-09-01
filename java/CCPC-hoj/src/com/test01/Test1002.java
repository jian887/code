package com.test01;

import java.util.Scanner;

public class Test1002 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		while (s.hasNextInt()) {
			int sum = 0;
			int a = s.nextInt();
			for (int i = 1; i <= a; i++) {
				sum = sum + i;
			}
			System.out.println(sum+"\n"+"\n");
		}
	}

}
