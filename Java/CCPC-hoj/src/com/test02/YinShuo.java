package com.test02;

//��Ȼ��n,Ҫ�ֽ������k
//k�ĳ�ʼֵ����С����2
//���k =n
//���n>k n���Ա�k��������ôk�ͣ�n����k�Ľ������n��һ��������
//
import java.util.Scanner;

public class YinShuo {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int k = 2, count = 0, m;
		int n = sc.nextInt();
		while (true) {
			if (n == k) {
				break;
			} else if (n % k == 0) {
				// n = n / k;
				n = n / k;
				count++;
				System.out.println(n + "," + k);
				//break;
			} else if (n % k != 0) {
				k++;
				System.out.println(k);
			}
		}
	}

}
