package com.daily;

import java.util.Random;

public class RandomTest {
	public static void main(String[] args) {
		String [] work = new String[] {"windows","Linux"};
		Random random = new Random();
		int i = random.nextInt(2) ;
		System.out.println(work[i]);
		int k = 0;
		while(k<10) {
			k++;
		}
	}

}
