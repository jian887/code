package com.list.test02;

import java.util.Scanner;

public class DeleteClass {

	DataClass dataClass = new DataClass();

	@SuppressWarnings("resource")
	public void menu() {

		while (true) {
			System.out.println("1.根据学号删除");
			System.out.println("2.根据姓名删除");
			System.out.println("3.退出");
			System.out.println("请输入序号:");
			// System.out.println(dataClass.idList);
			Scanner input = new Scanner(System.in);
			int i = input.nextInt();
			switch (i) {
			case 1:
				idDelete();
				break;
			case 2:
				nameDelete();
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
	public void idDelete() {
		Scanner input = new Scanner(System.in);
		System.out.println("请输入学号：");
		int id = input.nextInt();
		int no = DataClass.idList.indexOf(id);
		if (no == -1) {
			System.out.println("您输入的学号有误，请重新输入");
			idDelete();
		}
		DataClass.idList.remove(no);
		DataClass.nameList.remove(no);
		DataClass.enligshList.remove(no);
		DataClass.mathList.remove(no);
	}

	@SuppressWarnings("resource")
	public void nameDelete() {
		Scanner input = new Scanner(System.in);
		System.out.println("请输入姓名：");
		String name = input.nextLine();
		int no = DataClass.nameList.indexOf(name);
		if (no == -1) {
			System.out.println("您输入的姓名有误，请重新输入");
			nameDelete();
		}
		DataClass.idList.remove(no);
		DataClass.nameList.remove(no);
		DataClass.enligshList.remove(no);
		DataClass.mathList.remove(no);
	}

}
