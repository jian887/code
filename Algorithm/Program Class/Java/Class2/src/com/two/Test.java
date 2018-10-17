package com.two;



public class Test {
	public static void main(String[] args) {
		System.out.println(5 / 10);  //被除数< 除数    = 0
		System.out.println(10 / 10); // 被除数=  除数  = 1
		System.out.println(11 / 10); //被除数> 除数   =  1
		System.out.println(10 % 10); // 取模 很重要 被除数 = 除数  = 0
		System.out.println(10 % 12); // 取模 很重要 被除数 < 除数  = 被除数
		int intput = 2992;
		System.out.println(intput / 1000 + " " + intput / 100 % 10 + " " + intput % 100 / 10 + " " + intput % 100 % 10);

/*		int sum = 0;
		int value = intput;
		do {
			sum += value % 16;
			value = value / 16;
			System.out.println(value);
		} while (value > 0);
		*/
		int sum = intput / 1000 + intput / 100 % 10 + intput % 100 / 10 + intput % 100 % 10;
		// intput/16
		System.out.println(sum);
		int sum_2 = 0;
		int value = intput;
		while (value > 0){
			sum_2 += value % 16;
			System.out.println("%"+value % 16);
			value = value / 16;
			System.out.println("/"+value);
			
		}
		System.out.println(sum_2);
		int sum_3 = 0;
		int value_2 = intput;
		while (value_2 > 0) {
			sum_3 += value_2 % 12;
			System.out.println("%"+value % 12);
			value_2 = value_2 / 12;
			System.out.println("/"+value );
		} 
		System.out.println(sum_3);
		
		
		String str="刘德华_java程序员_布鲁明顿";
		char[] str1=str.toCharArray();
		StringBuilder sb=new StringBuilder();
		sb.append(str1);
		sb.delete(8, 11);
		sb.insert(8, "高级攻城狮");
		sb.replace(4, 8, "ios");
		sb.reverse();
		String s1=sb.toString().toLowerCase();
		System.out.println(s1);

	}

}
