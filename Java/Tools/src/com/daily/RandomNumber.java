package com.daily;

import java.util.LinkedList;
import java.util.Random;
import java.util.Scanner;

public class RandomNumber {

	public static void main(String[] args) {
		LinkedList<String> linkedList = new LinkedList<String>();

		Scanner scanner = new Scanner(System.in);
		Random random = new Random();

		System.out.println("请输入选择数:");
		int number = scanner.nextInt();
		/*
		 * for (int i = 0; i < number; i++) { System.out.println("请输入第" + (i + 1) +
		 * "个选择内容："); String change = scanner.nextLine(); //if (change.equals("0"))
		 * linkedList.add(change); } System.out.println(linkedList);
		 */
		System.out.println("选择结果：" + random.nextInt(number));
	}

}
