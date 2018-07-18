package com.list.test02;

import java.util.Scanner;

public class AddClass {

	DataClass dataClass = new DataClass();

	@SuppressWarnings({ "unused", "resource" })
	public void Add() {
		Scanner input = new Scanner(System.in);
		System.out.println("学号：");
		int id = input.nextInt();
		// 尝试添加一个验证学号输入不规范的的功能
		String br = input.nextLine();
		System.out.println("姓名：");
		String name = input.nextLine();
		System.out.println("英语成绩：");
		Double english = input.nextDouble();
		System.out.println("数学成绩：");
		Double math = input.nextDouble();
		DataClass.idList.add(id);
		DataClass.nameList.add(name);
		DataClass.enligshList.add(english);
		DataClass.mathList.add(math);
	}
}
