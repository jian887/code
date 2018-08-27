package com.test01;

import java.util.Scanner;

public class Test1006 {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int hours, minutes, seconds;
		while (s.hasNextInt()) {
			int angle = s.nextInt();
			double t = 0;
			for (int i = 0; i < 12; i++) {
				for (int j = 0; j < 60; j++) {
					for (int k = 0; k < 60; k++) {
						hours = i * 30;
						minutes = j * 6;
						seconds = k * 6;
						//System.out.println(hours+","+"m");
						// System.out.print(hours);
						int i1 = Math.abs(hours - minutes);
						int i2 = Math.abs(hours - seconds);
						int i3 = Math.abs(minutes - seconds);
						/*
						 * if(i1<angle||i2<angle||i3<angle) { t++; }
						 */
						/*
						 * if(((i1>=angle)&&(i2>angle))&&((i2>=angle)&&(i3>=angle))&&((i1>=angle)&&(i3>=
						 * angle))) { t++; }
						 */
						if ((Math.abs(hours - minutes) >angle) 
								&& (Math.abs(hours - seconds) > angle)
								&& (Math.abs(minutes - seconds) >angle) 
								&& (Math.abs(360-i1) > angle)
								&& (Math.abs(360-i2) > angle) 
								&& (Math.abs(360-i3) > angle)) {
							t++;
							System.out.println(t+","+hours+","+minutes+","+seconds);
	
						}
					}
				}
			}
			System.out.println(t);
			System.out.println(t / 43200 * 100);
			// System.out.println((12*3600));
		}
	}
}
