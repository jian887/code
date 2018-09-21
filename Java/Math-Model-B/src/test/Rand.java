package test;

import java.util.Random;

public class Rand {
	public static void main(String[] args) {
		
		int i;
		int [] arr = new int[300];
		Random random = new Random();
		
		for(int j = 0; j<arr.length ; j++) {
			i = random.nextInt(3) % (3- 0+ 0) + 0;
			switch (i) {
			case 0:
				arr[j] = 1;
				System.out.println(arr[j]);
				break;
			case 1:
				arr[j] = 5;
				System.out.println(arr[j]);
				break;
			case 2:
				arr[j] = 7;
				System.out.println(arr[j]);
				break;
			default:
				break;
			}
			
		}
	}

}

/*switch(i) {

}*/
