package com.c;

import java.util.Scanner;

public class demo1 {
	public static void main(String[] args){
		My my = new My();
		int arr[] = new int[3];
		@SuppressWarnings("resource")
		Scanner s = new Scanner(System.in);
		System.out.println("Please input 1-100");
		try{
			for (int i=0 ; i<3 ;i++) {
				arr[i]=s.nextInt();
				my.intext(arr[i]);
			}
			
		}catch(MyException e) {
			System.out.println("error:The number "+e.getTemp()+" isn't 1-100");
		}
	}
}
