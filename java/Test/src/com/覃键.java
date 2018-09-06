package com;

import java.util.LinkedList;
import java.util.Scanner;


public class 覃键 {
			public static void main(String[] args) {
			Scanner input=new Scanner(System.in);
			menu();
			while(true) {
				int a=input.nextInt();
				switch(a) {
				case 1:
					menu();
					add();
					show();
					break;
				case 2:		
					menu();
					delete();
					show();
					break;
				case 3:		
					menu();
					search();
					show();
					break;
				default:
					break;

			}
			}
		}
		static LinkedList<Integer> sh=new LinkedList<Integer>();
		static LinkedList<String> sm=new LinkedList<String>();
		static LinkedList<String> zt=new LinkedList<String>();
		static Scanner input=new Scanner(System.in);
		public static void menu() {
			System.out.println("1.add");
			System.out.println("2.delete");
			System.out.println("3.search");

		}
		public static void add() {
			System.out.println("add");
			System.out.println("ÇëÊäÈëÊéºÅºÍÊéÃû");
			//System.out.println("ÇëÊäÈëÊéÃû");
			int num=input.nextInt();
			String name=input.toString();
			sh.add(num);
			sm.add(name);
		}
		public static void delete(){
			System.out.println("delete");
			System.out.println("ÇëÊäÈëÊéºÅ");
			int num=input.nextInt();
			int index=sh.indexOf(num);
			String index2=sm.toString();
			sh.remove(index);
			sm.remove(index2);
			
		}
		public static void search() {
			System.out.println("search");
			System.out.println("ÇëÊäÈëÊéºÅ");
			int num=input.nextInt();
			int index=sh.indexOf(num);
			int index2=sm.indexOf(num);
			System.out.println(sh.get(index));
			System.out.println(sh.get(index2));
		}
		
	public static void show() {
			System.out.println(sh);
			System.out.println(sm);
		}
	}


