package com.list.test02;

import java.util.Scanner;

public class SearchClass {

	DataClass dataClass = new DataClass();

	@SuppressWarnings("resource")
	public void menu() {

		while (true) {
			System.out.println("1.根据学号查找");
			System.out.println("2.根据姓名查找");
			System.out.println("3.退出");
			System.out.println("请输入序号:");
			Scanner input = new Scanner(System.in);
			int i = input.nextInt();
			switch (i) {
			case 1:
				idSearch();
				break;
			case 2:
				nameSearch();
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
	public void idSearch() {
		Scanner input = new Scanner(System.in);
		System.out.println("请输入学号：");
		int id = input.nextInt();
		int no = DataClass.idList.indexOf(id);
		if (no == -1) {
			System.out.println("您输入的学号有误，请重新输入");
			idSearch();
		}
		int idSearch = DataClass.idList.get(no);
		String nameSearch = DataClass.nameList.get(no);
		System.out.println("学号:" + idSearch);
		System.out.println("姓名:" + nameSearch);
		System.out.println("英语:" + DataClass.enligshList.get(no));
		System.out.println("数学:" + DataClass.enligshList.get(no));
	}

	@SuppressWarnings({ "unused" })
	public void nameSearch() {

		@SuppressWarnings("resource")
		Scanner input = new Scanner(System.in);
		System.out.println("请输入姓名：");
		String name = input.nextLine();
		// String br = input.nextLine();
		int no = DataClass.nameList.indexOf(name);
		if (no == -1) {
			System.out.println("您输入的姓名有误，请重新输入");
			nameSearch();
		}
		int idSearch = DataClass.idList.get(no);
		String nameSearch = DataClass.nameList.get(no);
		System.out.println("学号:" + idSearch);
		System.out.println("姓名:" + nameSearch);
		System.out.println("英语:" + DataClass.enligshList.get(no));
		System.out.println("数学:" + DataClass.enligshList.get(no));

	}

}
