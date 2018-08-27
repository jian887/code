package com.test01;

import java.util.Scanner;

public class Test1004 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		String[] result = new String[1000000];
		int k = 0;
		while (s.hasNextInt()) {
			int t = 0;
			int max = 0;
			int index = 0;
			int a = s.nextInt();
			if (a == 0) { 
				break;
			}
				
			String[] color = new String[a];
			for (int i = 0; i < a; i++) {
				color[i] = s.next();
			}

			for (int i = 0; i < color.length; i++) {
				for (int j = 0; j < color.length; j++) {
					if (color[i].equals(color[j])) {
						t++;
					}
				}
				if (t > max) {
					max = t;
					index = i;
				}
			}
			System.out.println(color[index]);
		}

	}

}
