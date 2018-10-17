package com.two;

import java.util.Scanner;

public class Test03 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int t = scanner.nextInt();
		for(int i = 0 ; i < t ; i++) {
			int sum = 0;
			int out = 0;
			int n = scanner.nextInt();
			if(n<=0) 
			{
				break;
			}
			int [] arr = new int[n] ;
			for(int j = 0 ; j <n ; j++) {
				int h = scanner.nextInt();
				sum +=h;
			    arr[j] = h;
			}
			for(int j = 0; j <n ;j++) {
				if(arr[j]-sum/n<=0) {
					System.out.println(arr[j]-sum/n);
					continue;
					
				}
				else
				{
					out += arr[j]-sum/n;
					System.out.println();
				}
				
			}
			System.out.println("Set #"+(i+1));
			System.err.println("The minimum number of moves is "+out);
		}
	}

}
