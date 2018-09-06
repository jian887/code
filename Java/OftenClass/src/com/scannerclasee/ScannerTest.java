package com.scannerclasee;

import java.util.Scanner;

public class ScannerTest {
	static String s_1;
	static String s_2 = "";
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
/*		while(s_1!="end") {
			s_1 = sc.nextLine();
			s_2 = s_1+"\n";
		}*/
		for (int i=0 ;i<10 ;i++) {
			s_1 = sc.nextLine();
			s_2 = s_2+s_1+"\n";
			if(s_1.equals("end")) break;
		}		
		System.out.println(s_2);
	}
}
