package t1;

import java.util.Scanner;

public class library {
	public static void main(String args[]){
		manage ma=new manage();
		int choice;
		do{
			System.out.println("��ӭʹ��ͼ�����ϵͳ��");
			System.out.println("1.�������");
			System.out.println("2.���ͼ��");
			System.out.println("3.ɾ��ͼ��");
			System.out.println("4.����ͼ��");	
			System.out.println("5.����ͼ��");
			System.out.println("6.�黹ͼ��");	
			System.out.println("7.�˳�ϵͳ");	
			System.out.println("���������ѡ��");
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
			default:System.out.println("��������ȷѡ��!\n");break;
			}
		}while(choice!=7);
	}
}

