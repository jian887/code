package com.matlab;

import java.util.Scanner;

public class Changr extends InsertChar {
	
	public static void main(String[] args) {
		// Scanner s = new Scanner(System.in);
		// String
		StringBuilder date;
		String year;
		String m = null;
		String hourString;
		int hourInt;
		String s = "05/13/13 上午06时33分52秒";

		StringBuilder stringBuilder = new StringBuilder(s);
		date = stringBuilder.replace(2, 3, "-");
		date = stringBuilder.replace(5, 6, "-");
		System.out.println(date);
		m = stringBuilder.substring(9, 11); //获取上午、下午
		if(m.equals("下午"))
		{
			
			hourString = stringBuilder.substring(11,13);  //获取时
			System.out.println(m);
			System.out.println(hourString);
			hourInt = Integer.valueOf(hourString);
			hourInt += 12;
			System.out.println(hourInt);
			hourString = String.valueOf(hourInt);
			date = stringBuilder.replace(11, 13, hourString);
		}
		
		date = stringBuilder.delete(9, 11);  //删除上午下午
		System.out.println(date);
		//date = stringBuilder.delete(9, 12);
		// 获取下午
		// 06转int
		//int+12
		//替换hour
		// 删除下午
		System.out.println(date);
		date = stringBuilder.replace(11, 12, ":");  //替换时间:
		System.out.println(date);
		date = stringBuilder.replace(14, 15, ":");  //替换分钟:
		System.out.println(date);
		date = stringBuilder.delete(17, 19);
		System.out.println(date);
		year = stringBuilder.substring(6, 8);
		year = "20"+year+"-";
        System.out.println(year);
        date = stringBuilder.insert(0, year);
        System.out.println(date);
        date = stringBuilder.delete(10, 13);
        System.out.println(date);
		// stringBuilder.replace(2, 3, "-");
		/*
		 * System.out.println(stringBuilder.replace(2, 3, "-"));
		 * System.out.println(stringBuilder.replace(5, 6, "-"));
		 * System.out.println(stringBuilder.insert(6, "20"));
		 * System.out.println(stringBuilder.substring(6, 10));
		 */

	}

}
