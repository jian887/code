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
		String s = "05/13/13 ����06ʱ33��52��";

		StringBuilder stringBuilder = new StringBuilder(s);
		date = stringBuilder.replace(2, 3, "-");
		date = stringBuilder.replace(5, 6, "-");
		System.out.println(date);
		m = stringBuilder.substring(9, 11); //��ȡ���硢����
		if(m.equals("����"))
		{
			
			hourString = stringBuilder.substring(11,13);  //��ȡʱ
			System.out.println(m);
			System.out.println(hourString);
			hourInt = Integer.valueOf(hourString);
			hourInt += 12;
			System.out.println(hourInt);
			hourString = String.valueOf(hourInt);
			date = stringBuilder.replace(11, 13, hourString);
		}
		
		date = stringBuilder.delete(9, 11);  //ɾ����������
		System.out.println(date);
		//date = stringBuilder.delete(9, 12);
		// ��ȡ����
		// 06תint
		//int+12
		//�滻hour
		// ɾ������
		System.out.println(date);
		date = stringBuilder.replace(11, 12, ":");  //�滻ʱ��:
		System.out.println(date);
		date = stringBuilder.replace(14, 15, ":");  //�滻����:
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
