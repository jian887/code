package com.scannersplit;

import java.util.LinkedList;
import java.util.Scanner;

public class ScannerSplit {
	static String s_1;
	static String s_2 = "";
	static String s_3[] = new String[1000];
	static LinkedList<String> link = new LinkedList<>();
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		while(true) {
			s_1 = sc.nextLine();
			s_2 = s_2+s_1+"\n";
			if(s_1.equals("end")) break;
		}		
		System.out.println(s_2);
		for(int i =0 ;i<10 ;i++)
		{
			s_3[i]=s_2.split("\n");
			link.addAll();
		}
		 
		/*for(int i=0 ;i<4 ;i++) {
			if (s_3[i].equals("end")) s_3[i] ="";
		}*/
		
		/*for(int i=0 ;i<100 ;i++) {
			System.out.println(s_3[i]);
		}*/
	}
}
