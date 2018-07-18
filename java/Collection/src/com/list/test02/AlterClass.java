package com.list.test02;

import java.util.Scanner;

public class AlterClass {

	DataClass dataClass = new DataClass();

	@SuppressWarnings("resource")
	public void menu() {

		while (true) {
			System.out.println("1.修改学号");
			System.out.println("2.修改姓名");
			System.out.println("3.退出");
			System.out.println("请输出序号:");
			Scanner input = new Scanner(System.in);
			int i = input.nextInt();
			switch (i) {
			case 1:
				idAlter();
				break;
			case 2:
				nameAlter();
				break;
			case 3:
				return;
			default:
				System.out.println("您输入的序号有误，请重新输入");
				break;
			}
		}
	}

	@SuppressWarnings("resource")
	public void idAlter() {
		Scanner input = new Scanner(System.in);
		System.out.println("请输入旧学号");
		int idOld = input.nextInt();

		int no = DataClass.idList.indexOf(idOld);

		if (no == -1) {
			System.out.println("您输入的学号有误，请重新输入");
			idAlter();
		}
		System.out.println("请输入新学号");
		int idNew = input.nextInt();
		DataClass.idList.set(no, idNew);
	}

	@SuppressWarnings({ "unused", "resource" })
	public void nameAlter() {
		Scanner input = new Scanner(System.in);
		System.out.println("请输入旧姓名");
		String nameOld = input.nextLine();
		int no = DataClass.nameList.indexOf(nameOld);
		if (no == -1) {
			System.out.println("您输入的姓名有误，请重新输入");
			nameAlter();
		}
		System.out.println("请输入新姓名");
		String nameNew = input.nextLine();
		DataClass.nameList.set(no, nameNew);
	}

}
