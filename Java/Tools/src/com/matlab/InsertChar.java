package com.matlab;

import java.util.Scanner;

public class InsertChar {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		/*System.out.println("Ñ­»·´ÎÊý:");
		int loop = s.nextInt();
	*/
			String stringStart = s.nextLine();
			String sc = s.next();
			char c = sc.charAt(0);
		    int index = s.nextInt();
		    StringBuilder stringBuilder = new StringBuilder(stringStart);
		    //StringBuilder [] stringEnd = new StringBuilder[10];
		    StringBuilder  stringEnd = stringBuilder.insert(index, c);
		    System.out.println(stringEnd);  
	}

}
