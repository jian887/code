package t1;

import java.util.Scanner;

public class library {
	public static void main(String args[]){
		manage ma=new manage();
		int choice;
		do{
			System.out.println("欢迎使用图书管理系统：");
			System.out.println("1.浏览教室");
			System.out.println("2.添加图书");
			System.out.println("3.删除图书");
			System.out.println("4.查找图书");	
			System.out.println("5.借阅图书");
			System.out.println("6.归还图书");	
			System.out.println("7.退出系统");	
			System.out.println("请输入你的选择：");
			Scanner sc = new Scanner(System.in);
			choice=sc.nextInt();
			switch(choice){
			case 1:ma.browse();break;
			case 2:ma.add();break;
			case 3:ma.del();break;
			case 4:ma.seek();break;
			case 5:ma.rent();break;
		    case 6:ma.back();break;
     		case 7:System.exit(0);break;
			default:System.out.println("请输入正确选项!\n");break;
			}
		}while(choice!=7);
	}
}

