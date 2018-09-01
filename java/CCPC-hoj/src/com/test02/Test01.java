package com.test02;

import java.util.Scanner;

public class Test01 {
/*	
	 * public static void main(String[] args) { System.out.println(Math.sqrt(2)/2);
	 * }
	 

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		long[] bl = new long[t];
		long[] cl = new long[t];
		for (int j = 0; j < t; j++) {
			int n = sc.nextInt();
			long a = sc.nextInt();
			long b, c;
			if (n == 2 && a >= 3 && a <= 40000) {
				for (int i = 1;; i++) {
					if ((a * a - i * i) % (2 * i) == 0) {
						b = (a * a - i * i) / (2 * i);
						c = b + i;
						break;
					}
				}
				bl[j] = b;
				cl[j] = c;
				//System.out.println(b + " " + c);
			} else if (n == 1 && a >= 3 && a <= 40000) {
				c = 100000;
				b = c - a;
				bl[j] = b;
				cl[j] = c;
				//System.out.println(b + " " + c);
			} else {
				bl[j] = -1;
				cl[j] = -1;
				//System.out.println("-1 -1");
			}
		}
		for(int j = 0 ;j<t ;j++) {
			System.out.println(bl[j]+" "+cl[j]);
		}

	}

}


public static void main(String[] args) {
		 
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		int[] bl = new int[t];
		int[] cl = new int[t];
		for (int j = 0; j < t; j++) {
			int n = sc.nextInt();
			/*long a = sc.nextInt();
			long b, c;
			int a = sc.nextInt();
			int b = 0, c = 0;
			long startTime=System.nanoTime();
			if (n == 2 && a >= 3 && a <= 40000) {
				for (int i = 1;; i++) {
					if ((a * a - i * i) % (2 * i) == 0) {
						b = (a * a - i * i) / (2 * i);
						c = b + i;
						break;
					}
				}
				bl[j] = b;
				cl[j] = c;
				System.out.println(b + " " + c);
				long endTime=System.nanoTime(); 

				System.out.println("程序运行时间： "+(endTime-startTime)+"ns");
			} else if (n == 1 && a >= 3 && a <= 40000) {
				c = 40001;
				b = c - a;
				bl[j] = b;
				cl[j] = c;
				System.out.println(b + " " + c);
				
			} else {
				bl[j] = -1;
				cl[j] = -1;		
				System.out.println("-1 -1");
			}
			long endTime=System.nanoTime();  

			System.out.println("程序运行时间： "+(endTime-startTime)+"ns");
		}
		for(int j = 0 ;j<t ;j++) {
			System.out.println(bl[j]+" "+cl[j]);
		}
	
	}

 * public static void main(String[] args) { Scanner sc = new Scanner(System.in);
 * int t = sc.nextInt(); // long [] a = new long[t]; for (int j = 0; j < t; j++)
 * { long a = sc.nextInt(); int n = sc.nextInt(); long b, c; if (a >= 3 && a <=
 * 40000 && n == 2) { for (int i = 1;; i++) { if ((a * a - i * i) % (2 * i) ==
 * 0) { b = (a * a - i * i) / (2 * i); c = b + i; break; } }
 * System.out.println(b + " " + c); } else if (a >= 3 && a <= 40000 && n == 1) {
 * c = 1; b = c - a; System.out.println(b + " " + c); } else {
 * System.out.println("-1 -1"); } }
 * 
 * }
 * 
 * }
 

 * 
 * for(long long int i=1;;i++)
 * 
 * {
 * 
 * if((a*a-i*i)%(2*i)==0)
 * 
 * {
 * 
 * b=(a*a-i*i)/(2*i);
 * 
 * c=b+i;
 * 
 * break;
 * 
 * }
 * 
 * }
 
*/
}