package test;

public class Test01 {
	public static void main(String[] args) {
		System.out.println("ew");
		int[] cnc = { 2, 3, 0, 1, 3, 2 };
		
		int min = cnc[0] ,a = 0;
		for (int i = 0; i < cnc.length -1; i++) {
			if (min > cnc[i]) 
			{
				min = cnc[i];
			    a = i;
			}
			
		}
		System.out.println(a);
		/*for (int i = 0; i < cnc.length -1; i++) {
			for (int j = 0; j < cnc.length - 1-i;j++) {
				if (cnc[j] > cnc[j + 1]) {
					int temp = cnc[j];
					cnc[j] = cnc[j + 1];
					cnc[j + 1] = temp;
				}

			}
		}*/

	/*	for (int i = 0; i < cnc.length; i++) {
			System.out.println(cnc[i]);
		}*/
		System.out.println("ew");
	}

}
