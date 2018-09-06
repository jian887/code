package com.list.test03;

import java.util.LinkedList;
import java.util.Scanner;

public class ClassLinkedList {
	/*
	 * LinkedList<Integer> nums = new LinkedList<Integer>(); LinkedList<String>
	 * names = new LinkedList<String>(); LinkedList<Double> grades = new
	 * LinkedList<Double>();
	 * 
	 * Scanner input = new Scanner(System.in);
	 * 
	 * public void add() { System.out.println("add"); int num = input.nextInt();
	 * String name = input.nextLine(); Double grade = input.nextDouble();
	 * nums.add(num); names.add(name); grades.add(grade);
	 * 
	 * }
	 * 
	 * public void delete() { System.out.println("delete");
	 * System.out.println("please input number"); int num = input.nextInt(); int
	 * data = nums.indexOf(num);
	 * 
	 * nums.remove(data); names.remove(data); grades.remove(data); }
	 * 
	 * public void search() { System.out.println("search");
	 * System.out.println("please input number"); int num = input.nextInt(); int
	 * data = nums.indexOf(num);
	 * 
	 * System.out.println(nums.get(data)); System.out.println(names.get(data));
	 * System.out.println(grades.get(data));
	 * 
	 * }
	 * 
	 * 
	 * public void alter() { System.out.println("alter");
	 * System.out.println("please input number"); int num = input.nextInt(); int
	 * data = nums.indexOf(num); System.out.println(nums.get(data));
	 * System.out.println(names.get(data)); System.out.println(grades.get(data));
	 * 
	 * System.out.println("please input datas"); int numAlter = input.nextInt();
	 * String nameAlter = input.nextLine(); Double gradeAlter = input.nextDouble();
	 * nums.set(data, numAlter); names.set(data, nameAlter); grades.set(data,
	 * gradeAlter);
	 * 
	 * }
	 * 
	 * public void menu() { System.out.println("1. add");
	 * System.out.println("2. delete"); System.out.println("3. search");
	 * System.out.println("4. alter"); }
	 * 
	 * public static void main(String[] args) { System.out.println("welcome");
	 * Scanner sc = new Scanner(System.in);
	 * 
	 * while(true) {
	 * 
	 * int s = sc.nextInt(); switch(s) {
	 * 
	 * } } }
	 */
	/*
	 * 如何使用集合来进行增删查改的操作
	 */
	// 操作三类信息： 学号、姓名、成绩
	// 分别对应两种数据类型和一种对象： Integer(int) String(字符串对象) Double

	// 分别给三类信息各建立一个集合， 链表类集合LinkedList ,于ArratList同属于List类
	LinkedList<Integer> nums = new LinkedList<Integer>();  
	LinkedList<String> names = new LinkedList<String>();
	LinkedList<Double> grades = new LinkedList<Double>();
	
	
	// 接下来的操作，在大部分集合中基本通用，比如ArrayList、HashSet、TreeSet、HashMap、TreeMap

	Scanner input = new Scanner(System.in);
	
	public void add() {
		System.out.println("add");
		System.out.println("please input datas");

		// 输入信息
		int num = input.nextInt();  // 12
		String br = input.nextLine();  
		String name = input.nextLine();  //sr
		Double grade = input.nextDouble(); //

		// 使用add函数将输入的信息添加进集合内
		nums.add(num);
		names.add(name);
		grades.add(grade);

		// 注意：add函数，只能从前往后添加数据的
	}

	// 删除函数，依据学号删除
	public void delete() {

		System.out.println("delete");
		System.out.println("please input nums");
		// 输入需要删除学号的信息
		int num = input.nextInt();
		/*
		 * indexOf 返回的是num在nums集合的位置 该位置实际是num的地址 在集合里，我们称呼其为索引
		 */
		int index = nums.indexOf(num);

		// 调用remove()函数执行删除操作，将获得的索引作为参数输入remove()函数里
		nums.remove(index);
		names.remove(index);
		grades.remove(index);
	}

	// 根据姓名查找
	public void search() {
		System.out.println("search");
		System.out.println("please input name"); // 多输出了一个空行
		String br = input.nextLine(); // 使用nextLine接收多余的空行
		// 输入要查找的姓名
		String name = input.nextLine();

		int index = names.indexOf(name);
		// get函數，根据所获得索引，从集合里获取该数值
		System.out.println(nums.get(index));
		System.out.println(names.get(index));
		System.out.println(grades.get(index));
	}

	public void alter() {
		System.out.println("alter");
		System.out.println("please input num");

		int num = input.nextInt();
		int index = nums.indexOf(num);

		System.out.println(nums.get(index) + "," + names.get(index) + "," + grades.get(index));

		System.out.println("please input datas");
		int numAlter = input.nextInt();
		String br = input.nextLine();
		String nameAlter = input.nextLine();
		Double gradeAlter = input.nextDouble();

		// 调用set函数执行修改操作，set(index,element),该函数需要传入两个参数，一个是index索引，一个是要修改的值
		nums.set(index, numAlter);
		names.set(index, nameAlter);
		grades.set(index, gradeAlter);
	}

	public void show() {
		// 如果想打印集合内所有数据，直接在syso里输入该集合名，
		// 不必像数组，需要使用for循环遍历
		System.out.println(nums);
		System.out.println(names);
		System.out.println(grades);
	}

	// 主界面
	public void menu() {
		System.out.println("1. add");
		System.out.println("2. delete");
		System.out.println("3. search");
		System.out.println("4. alter");

	}

	// 主函数
	public static void main(String[] args) {
		System.out.println("welcome");
		@SuppressWarnings("resource")
		Scanner sc = new Scanner(System.in);

		ClassLinkedList cLinedList = new ClassLinkedList();
		cLinedList.menu();
		// 輸入数字选择相应功能
		while (true) {

			System.out.println("please your change");
			int s = sc.nextInt();
			switch (s) {
			/*
			 * 如果在主函数内调用成员函数，需要new一个对象来调用 如果不建立对象，希望直接调用的话，那么你的成员函数就要静态化
			 */
			case 1:

				cLinedList.add();
				cLinedList.menu();
				cLinedList.show();
				break;
			case 2:

				cLinedList.delete();
				cLinedList.menu();
				cLinedList.show();
				break;
			case 3:

				cLinedList.search();
				cLinedList.menu();
				cLinedList.show();
				break;
			case 4:

				cLinedList.alter();
				cLinedList.menu();
				cLinedList.show();
				break;
			default:
				System.out.println("error!");
				break;
			}
		}
	}
}
/*



*/
