package com;
import java.util.LinkedList;
import java.util.Scanner;



class Book
{
	int num;
	String name;
	String state;
	public Book(int a,String b,String c) {
		// TODO Auto-generated constructor stub
		num=a;
		name=b;
		state=c;
	}
	String print()
	{
		System.out.print(num+"，"+name+","+state);
		return "";
	}
}

public class Four {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		LinkedList<Book> book=new LinkedList<Book>();
		System.out.println("欢迎进入图书管理系统");
		int choose=1;
		Scanner reader=new Scanner(System.in);
		while(choose!=0) 
		{
			System.out.println("请选择您要进行的操作");
			System.out.println("1.添加书籍");
			System.out.println("2.删除书籍");
			System.out.println("3.查找书籍");
			System.out.println("4.借阅（归还）书籍");
			choose=reader.nextInt();
			int n=-1;
			switch (choose) {
			case 1:
				System.out.println("请输入书籍的书号，书名，状态");
				Book a=new Book(reader.nextInt(), reader.next(), reader.next());
				book.add(a);
				break;
			case 2:
				System.out.println("请输入需删除的书籍名称");
				String name=reader.next();
				n=book.indexOf(name);
				if(n==-1)
					System.out.println("没有该记录");
				else
					book.remove(n);
					System.out.println("删除成功");
				break;
			case 3:
				System.out.println("请输入查找的书籍名称");
				name=reader.next();
				n=book.indexOf(name);
				if(n==-1)
					System.out.println("没有该记录");
				else
					System.out.println("该书籍信息为："+book.get(n));
				break;
			case 4:
				System.out.println("请输入书籍名称，及（归还、借阅）");
				name=reader.next();
				String state=reader.next();
				n=book.indexOf(name);
				if(state.equals("归还"))
					book.get(n).state="已还";
				else
					book.get(n).state="已借";
				break;
			default:
				break;
			}
		}	
	}
}