package test;

import java.util.Random;

public class Rand01 {
	public static void main(String[] args) {
		
		int i;
		int [] arr = new int[300];
		Random random = new Random();
		
		for(int j = 0; j<arr.length ; j++) {
			i = random.nextInt(5) % (5- 0+ 0) + 0;
			switch (i) {
			case 0:
				arr[j] = 2;
				System.out.println(arr[j]);
				break;
			case 1:
				arr[j] = 3;
				System.out.println(arr[j]);
				break;
			case 2:
				arr[j] = 4;
				System.out.println(arr[j]);
				break;
			case 3:
				arr[j] = 6;
				System.out.println(arr[j]);
				break;
			case 4:
				arr[j] = 8;
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
