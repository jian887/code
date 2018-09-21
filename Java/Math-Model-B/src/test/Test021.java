package test;


public class Test021 {
	static int move_1 = 23;
	static int move_2 = 41;
	static int move_3 = 59;
	static int process_1 = 280;
	static int process_2 = 500;
	static int cnc_Load_1 = 30;
	static int cnc_Load_2 = 35;
	static int clean = 30;
	static int[] cnc_1 = new int[] { 0, 4, 6 };
	static int[] cnc_2 = new int[] { 1, 2, 3, 5, 7 };

	static int rgv = process_1 + cnc_Load_1;
	static int rgv_Location = 8;
	static int rgv_State = 1;

	static int[] cnc = new int[8];
	static int[] cnc_Initial = new int[] { 0, 0, 0, 0, 71, 0, 124, 0 };
	static int[] cnc_State = new int[8];
	static int[] cnc_Loction = new int[] { 1, 2, 3, 4, 5, 6, 7, 8 };

	static int[] cnc_Number = new int[1000];
	static int[] unload_Material = new int[1000];
	static int k = 0;

	public static void main(String[] args) {

		for (; rgv < 28800;) {
			System.out.println(rgv);

			for (int i = 0; i < cnc.length; i++) {
				cnc[i] = rgv;
				// System.out.println(cnc[i]);
			}
			cnc_Process_Number(); // 改变已经加工完物料的cnc的状态
			// 根据rgv的状态，决定rgv的走向

			int cnc_I = 0;
			int min = 0;
			if (rgv_State == 1) {
				int[] cnc_Process_2 = new int[8];
				int[] cnc_Process_Distance_2 = new int[8];
				for (int i = 0; i < cnc_State.length; i++) {
					if (cnc_State[i] == 1) {
						cnc_Process_2[i] = cnc_Loction[i];
					}
				}

				for (int i = 0; i < cnc.length; i++) {
					System.out.printf("%d ,", cnc_Process_2[i]);
				}
				System.out.println();
				for (int i = 0; i < cnc_Process_Distance_2.length; i++) {
					cnc_Process_Distance_2[i] = move_1(rgv_Location, cnc_Process_2[i]);
//					System.out.println(cnc_Process_Distance_2[i]);
				}
				for (int i = 0; i < cnc.length; i++) {
					System.out.printf("%d ,", cnc_Process_Distance_2[i]);
				}
				System.out.println();
				for (int i = 0; i < cnc_Process_Distance_2.length; i++) {
					if (cnc_Process_Distance_2[i] != 0) {
						min = cnc_Process_Distance_2[i];
						if (min > cnc_Process_Distance_2[i]) {
							min = cnc_Process_Distance_2[i];
							cnc_I = cnc_Loction[i] - 1;
							// System.out.println(cnc_I);
						}
					}
				}
			} else if (rgv_State == 2) {
				int[] cnc_Process_1 = new int[cnc_1.length];
				int[] cnc_Process_Distance_1 = new int[cnc_1.length];
				for (int i = 0; i < cnc_State.length; i++) {
					if (rgv > 369 && rgv < 2000) {

					}
					if (cnc_State[cnc_2[0]] == 1) {
						cnc_Process_1[0] = cnc_Loction[i];
					} else if (cnc_State[cnc_2[1]] == 1) {
						cnc_Process_1[1] = cnc_Loction[i];
					} else if (cnc_State[cnc_2[2]] == 1) {
						cnc_Process_1[0] = cnc_Loction[i];
					} else if (cnc_State[cnc_2[3]] == 1) {
						cnc_Process_1[1] = cnc_Loction[i];
					} else if (cnc_State[cnc_2[4]] == 1) {
						cnc_Process_1[0] = cnc_Loction[i];
					}
				}
				for (int i = 0; i < cnc_Process_Distance_1.length; i++) {
					cnc_Process_Distance_1[i] = move_1(cnc_Process_1[i], rgv_Location);
				}
				for (int i = 0; i < cnc_Process_Distance_1.length; i++) {
					if (cnc_Process_Distance_1[i] != 0) {
						min = cnc_Process_Distance_1[i];
						if (min > cnc_Process_Distance_1[i]) {
							min = cnc_Process_Distance_1[i];
							cnc_I = cnc_Loction[i] - 1;
//							System.out.println(cnc_I);
						}
					}
				}
			}
			int j = cnc_I;
			int move_Min = min;
			System.out.println(move_Min);
			rgv = rgv + move_Min;
			rgv_Location = cnc_Loction[j];
			for (int i = 0; i < cnc.length; i++) {
				cnc[i] = rgv;
			}
			cnc_Number[k] = j;
			unload_Material[k] = rgv;
			k++;
			// rgv 给cnc 加工
			if (j % 2 == 0) {
				rgv = rgv + cnc_Load_1;
				cnc_Initial[j] = rgv;
				cnc_State[j] = 0;
			} else {
				rgv = rgv + cnc_Load_2;
				cnc_Initial[j] = rgv;
				cnc_State[j] = 0;
			}

			if (j == cnc_1[0] || j == cnc_2[1] || j == cnc_1[2]) {
				rgv_State = 2;

			} else if (j == cnc_2[0] || j == cnc_2[1] || j == cnc_2[2] || j == cnc_2[3] || j == cnc_2[4]) {
				rgv_State = 1;
			}
			System.out.println(rgv_State);

		}

		/*
		 * for (int i = 0; i < j; i++) { System.out.println( "序号" + i + " 编号:" +
		 * cnc_Number[i] + "上料" + load_Material[i] + " 下料时间：" + unload_Material[i]); }
		 */

		for (int i = 0; i < k; i++) {
			System.out.println((i + 1) + " " + cnc_Number[i] + " " + "  " + unload_Material[i]);
		}

	}

	public static void cnc_Process_Number() {
		for (int i = 0; i < cnc.length; i++) {

			if (i == cnc_1[0] || i == cnc_1[1] || i == cnc_1[2]) {

				if (cnc[i] >= cnc_Initial[i] + process_1) {
					cnc_State[i] = 1;
				}
			} else if (i == cnc_2[0] || i == cnc_2[1] || i == cnc_2[2] || i == cnc_2[3] || i == cnc_2[4]) {

				if (cnc[i] >= cnc_Initial[i] + process_2) {
					cnc_State[i] = 1;
				}
			}
		}
		System.out.println("加工情况(1是已经完成加工,0是为完成加工)：");
		for (int i = 0; i < cnc.length; i++) {
			System.out.printf("%d ,", cnc_State[i]);
		}
		System.out.println();
	}

	public static int move_1(int rgv_Location_Start, int rgv_Location_End) {

		// System.out.println(rgv_Location_Start+" "+rgv_Location_End);
		int move = 0;
		if (rgv_Location_End == 0) {
			move = 0;
		} else {
			if (rgv_Location_Start % 2 == 0) {
				rgv_Location_Start = rgv_Location_Start / 2;
				if (rgv_Location_End % 2 == 0) {
					rgv_Location_End = rgv_Location_End / 2;
				} else {
					rgv_Location_End = (rgv_Location_End + 1) / 2;
				}
			} else {
				rgv_Location_Start = (rgv_Location_Start + 1) / 2;
				if (rgv_Location_End % 2 == 0) {
					rgv_Location_End = rgv_Location_End / 2;
				} else {
					rgv_Location_End = (rgv_Location_End + 1) / 2;
				}
			}

			int a = Math.abs(rgv_Location_End - rgv_Location_Start);
			if (a == 1)
				move = move_1;
			else if (a == 2)
				move = move_2;
			else if (a == 3)
				move = move_3;
		}

		// System.out.println(rgv_Location_End+" "+rgv_Location_Start);

		return move;
	}
}
