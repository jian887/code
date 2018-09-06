package com.splitclasee;

import java.util.Scanner;

public class SplitTest {
	static String s_1;
	static String s_2 = "";
	//static String [] s_3 = new String[4];
	static double [] grade_1 = new double[3] ;
	static double totalGrade = 0;
	
	public static void main(String[] args) {
		
		System.out.println("请依次输入姓名、英语成绩、高数成绩、Java成绩");
		System.out.println("示例：");
		System.out.println("李四");
		System.out.println("87");
		System.out.println("56");
		System.out.println("45");
		System.out.println("请输入：");
		Scanner sc = new Scanner(System.in);
/*		while(s_1!="end") {
			s_1 = sc.nextLine();
			s_2 = s_1+"\n";
		}*/
		for (int i=0 ;i<4 ;i++) {
			s_1 = sc.nextLine();
			s_2 = s_2+s_1+"\n";
		}
		
		//System.out.println(s_2);
		String s_3[] = s_2.split("\n");
		System.out.println();
		System.out.println("输入确认");
		for(int i=0 ;i<4 ;i++) {
			System.out.println(s_3[i]);
		}
	
		for(int i=1 ;i<4 ;i++) {
			grade_1[i-1] = Double.parseDouble(s_3[i]);
			totalGrade = totalGrade+grade_1[i-1];
			//System.out.println(grade_1[i-1]);
		}
		System.out.println();
		System.out.println("姓名:"+s_3[0]);
		System.out.println("英语:"+grade_1[0]);
		System.out.println("高数:"+grade_1[1]);
		System.out.println("Java:"+grade_1[2]);
		System.out.println("总成绩"+totalGrade);
	}
}
