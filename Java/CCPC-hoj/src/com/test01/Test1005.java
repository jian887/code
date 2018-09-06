package com.test01;

import java.util.Scanner;

public class Test1005 {
	
	
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
			while(s.hasNextInt()) {
				int a1 = s.nextInt();
				int a2 = s.nextInt();
				int n = s.nextInt();
				if(a1==0&a2==0&n==0) {
				break;	
				}
				if(n>51) n=n%49;
				System.out.println(fun(a1, a2, n));
			}	
		}
		
		public static int fun(int a,int b,int n) {
			if(n==1||n==2) {
				//System.out.println(1);
				return 1;
			}
			else {
				int c = (a*fun(a,b,n-1)+b*fun(a,b,n-2))%7;
			//System.out.println(c);
				return c;
			}
				
	
		}
	

	/*public static void main(String[] args) {
	Scanner s = new Scanner(System.in);
		
		while(s.hasNextInt()) {
			int a1 = s.nextInt();
			int a2 = s.nextInt();
			int n = s.nextInt();
			System.out.println(fun(a1,a2,n));
		}	
	}
	
	public static int fun(int a1,int a2,int n) {
		if(n==1||n==2) return 1;
		else 			
			return (a1*fun(a1,a2,n-1)+a2*fun(a1,a2,n-2))%7;
	}
*/	
}
