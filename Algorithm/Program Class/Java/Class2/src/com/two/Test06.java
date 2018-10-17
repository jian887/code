package com.two;

import java.util.Scanner;

public class Test06 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		String br = scanner.nextLine();
		for (int i = 0; i < n; i++) {
			String string = scanner.nextLine();
			char[] chars = string.toCharArray();
			int[] ascll = new int[chars.length];
			for (int j = 0; j < chars.length; j++) {
				ascll[j] = (int) chars[j];
			}

			for (int j = 0; j < chars.length; j++) {
				// ascll[j] >= 65 && ascll[j] <= 90
				if (ascll[j] > 64 && ascll[j] < 91) {

					/*
					 * if(ascll[j]!=65 ||ascll[j]!=69||ascll[j]!=73||ascll[j]!=79||ascll[j]!=85) {
					 * 
					 * } else { ascll[j] = ascll[j]+32; }
					 */

					if (ascll[j] != 65 && ascll[j] != 69 && ascll[j] != 73 && ascll[j] != 79 && ascll[j] != 85) {
						ascll[j] = ascll[j] + 32;
					}
				}
				// ascll[j] >= 95 && ascll[j] <= 122
				else if (ascll[j] >= 95 && ascll[j] <= 122) {
					if (ascll[j] == 97 || ascll[j] == 101 || ascll[j] == 105 || ascll[j] == 111 || ascll[j] == 117) {
						ascll[j] = ascll[j] - 32;
					}
				}
			}
			for (int j = 0; j < chars.length; j++) {
				chars[j] = (char) ascll[j];
			}
			for (int j = 0; j < chars.length; j++) {
				System.out.printf("%c", chars[j]);
			}
			System.out.println();
		}
	}

}
