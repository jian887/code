package one.two;

import java.util.Scanner;

public class Test01 {

	public static void main(String[] args) {
		final double pi = Math.PI;       
		/*final修饰变量
		final成员变量表示常量，只能被赋值一次，赋值后值不再改变。final经常和static一起使用表示常量(即static final，不用实例化)。
        类似于const
*/		double r, h, s, s1, s2;

		Scanner scanner = new Scanner(System.in);
		
		r = scanner.nextDouble();
		h = scanner.nextDouble();
		s1 = r*pi*pi;
		s2 = 2*r*pi*h;
		s = s1*2.0 + s2;
		System.out.printf("Area =  %1.3f", s);
//		System.out.printf("Area =  %0.3f", s); 
		
	}

}

/*
2 3
Area =  77.178*/