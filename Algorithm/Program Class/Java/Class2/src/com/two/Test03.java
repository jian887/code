package com.two;

import java.util.Scanner;

public class Test03 {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int i = 0;
		while (true) {
			i++;
			int sum = 0;
			int out = 0;
			int n = scanner.nextInt();
			if (n <= 0) {
				break;
			} else {
				int[] arr = new int[n];
				for (int j = 0; j < n; j++) {
					int h = scanner.nextInt();
					sum += h;
					arr[j] = h;
				}
				//System.out.println(sum);
				for (int j = 0; j < n; j++) {
					if ((arr[j] - sum / n) <= 0) {
						//System.out.println(arr[j] - sum / n);
						continue;

					} else {
						out += arr[j] - sum / n;
					//	System.out.println(arr[j] - sum / n);
					}
				}
				System.out.println("Set #" + i);
				//System.out.println("The minimum number of moves is " + out+"."+"\n"); �����ˣ�\n��sysoЧ��һ�������
				// ȷȴ��error Presentation Error (�����ʽ��Ҫ�󲻷��ϣ����ǳ����߼���ȷ)
				System.out.println("The minimum number of moves is " + out+"."+"\n");
				System.out.println();
			}
		}

	}

}
