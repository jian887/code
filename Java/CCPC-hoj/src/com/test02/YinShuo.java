package com.test02;

//自然数n,要分解的因数k
//k的初始值是最小因数2
//如果k =n
//如果n>k n可以被k整除，那么k和，n除以k的结果就是n的一个因数，
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
