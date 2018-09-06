package com.list.test02;

import java.util.Scanner;

public class MainClass {

	@SuppressWarnings("resource")
	public static void main(String[] args) {
		AddClass addClass = new AddClass();
		DeleteClass deleteClass = new DeleteClass();
		SearchClass searchClass = new SearchClass();
		AlterClass alterClass = new AlterClass();
		// Menu menu=new Menu();
		MenuClass.main(args);
		while (true) {
			Scanner sc = new Scanner(System.in);
			int i = sc.nextInt();
			switch (i) {
			case 1:
				System.out.println("添加信息：");
				addClass.Add();
				ShowClass.main(args);
				break;
			case 2:
				deleteClass.menu();
				ShowClass.main(args);
				break;
			case 3:
				searchClass.menu();
				ShowClass.main(args);
				break;
			case 4:
				alterClass.menu();
				ShowClass.main(args);
				break;
			case 5:
				System.exit(0);
			default:
				System.out.println("输入错误,请重新输入：");
				break;
			}

		}
	}

}