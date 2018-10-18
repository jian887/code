package com.two;

import java.util.Scanner;
public class Test051 {
	public static boolean f(int n) {
		int sum=0;
		int tmp=n;
		while(tmp!=0) {
			sum+=tmp%10;
			tmp/=10;
		}
		int tmp1=0;
		tmp=n;
		while(tmp!=0) {
			tmp1+=tmp%16;
			tmp/=16;	
		}
		if(tmp1!=sum) return false;
		int tmp2=0;
		tmp=n;
		while(tmp!=0) {
			tmp2+=tmp%12;
			tmp/=12;	
		}
		if(tmp2!=sum) return false;
		return true;
	}
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
			for(int i=2992;i<=9999;i++) 
				if(f(i)) 
					System.out.println(i);
	}
}