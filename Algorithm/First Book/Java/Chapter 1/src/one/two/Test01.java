package one.two;

import java.util.Scanner;

public class Test01 {

	public static void main(String[] args) {
		final double pi = Math.PI;       
		/*final���α���
		final��Ա������ʾ������ֻ�ܱ���ֵһ�Σ���ֵ��ֵ���ٸı䡣final������staticһ��ʹ�ñ�ʾ����(��static final������ʵ����)��
        ������const
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