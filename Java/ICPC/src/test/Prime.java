package test;

import java.util.Scanner;

/*
 * ����Prime Number 
 * n
 * q = 2~��n
 * if n%q = 0 ��������
 * if n%q !=0 ʼ�� ������
 */
public class Prime {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int i;
		double q;
		double primeNumber = s.nextDouble();
		q = Math.sqrt(primeNumber);
		System.out.println(q);
		for (i = 2; i < q + 1; i++) {
			System.err.println(i + "," + q);
			if (primeNumber % i == 0) {
				System.out.println(primeNumber + "isn't prime number");
				break;
			} else if ((i >= q) && (primeNumber % i != 0)) {
				System.out.println(q);
				System.out.println(primeNumber + "is prime number");
				break;
			}
		}
	}

}
