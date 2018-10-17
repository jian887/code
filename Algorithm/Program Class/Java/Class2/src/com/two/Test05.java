package com.two;

public class Test05 {
	public static void main(String[] args) {

		int intput = 2991;

		while (true) {
			intput++;
			if (intput / 10000 > 0) {
				break;
			} else {
				int sum = intput / 1000 + intput / 100 % 10 + intput % 100 / 10 + intput % 100 % 10;
				int temp;
				int sum_2 = 0;
				temp = intput;
				while (temp > 0) {
					sum_2 += temp % 16;
					temp = temp / 16;
				}
				int sum_3 = 0;
				temp = intput;
				while (temp > 0) {
					sum_3 += temp % 12;
					temp = temp / 12;
				}
				if (sum == sum_2 && sum_2 == sum_3)
					System.out.println(intput);
				else
					continue;
			}
		}

	}

}
