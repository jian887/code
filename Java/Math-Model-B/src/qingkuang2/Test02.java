package qingkuang2;

public class Test02 {
	static int move_1 = 23;
	static int move_2 = 41;
	static int move_3 = 59;
	static int process_1 = 280;
	static int process_2 = 500;
	static int cnc_Load_1 = 30;
	static int cnc_Load_2 = 35;
	static int clean = 30;

	public static void main(String[] args) {
		int[] cnc_Number_1 = new int[1000];
		int[] load_Material_1 = new int[1000];
		int[] unload_Material_1 = new int[1000];
		int[] cnc_Number_2 = new int[1000];
		int[] load_Material_2 = new int[1000];
		int[] unload_Material_2 = new int[1000];
		int j_1 = 0, j_2 = 0;
		int i = 0;
		int rgv = (cnc_Load_1 + move_1) * 4 - move_1, rgv_Location = 8;

		// int[] cnc = new int[] { 428, 0, 476, 0, 524, 0, 572, 0 };
		int[] cnc = new int[8];
		cnc[0] = process_1 + cnc_Load_1;
		cnc[2] = cnc[0] + move_1 + cnc_Load_1;
		cnc[4] = cnc[2] + move_1 + cnc_Load_1;
		cnc[6] = cnc[4] + move_1 + cnc_Load_1;
		
		int[] cnc_Loction = new int[] { 1, 2, 3, 4, 5, 6, 7, 8 };

		for (; rgv < 28800;) {

			/*
			 * cnc_Number[j] = i + 1; load_Material[j] = cnc[i] - process;
			 */

			if (j_1 <= 4) {
				if (i % 2 == 0) {
					cnc_Number_1[j_1] = i + 1;
					load_Material_1[j_1] = cnc[i] - process_1 - cnc_Load_1;
				} else {
					cnc_Number_2[j_2] = i + 1;
					load_Material_2[j_2] = 0;
				}
			} else {
				if (i % 2 == 0) {
					cnc_Number_1[j_1] = i + 1;
					load_Material_1[j_1] = unload_Material_1[j_1 - 4];

				} else {
					cnc_Number_2[j_2] = i + 1;
					load_Material_2[j_2] = unload_Material_2[j_2 - 4];
				}
			}

			if (rgv <= cnc[i]) {
				rgv = cnc[i];
			} else {
				rgv = rgv;
			}

			int rgv_Location_Start = rgv_Location;
			int rgv_Location_End = cnc_Loction[i];

			int rgv_Move = move(rgv_Location_Start, rgv_Location_End);

			rgv_Location = rgv_Location_End;

			rgv = rgv + rgv_Move;

			if (i % 2 == 0) {
				unload_Material_1[j_1] = rgv;
				// System.out.println(unload_Material_1[j_1]);
				j_1++;
			} else {
				unload_Material_2[j_2] = rgv;
				j_2++;
			}
			/*
			 * move[j] = rgv_Move; unload_Material[j] = rgv;
			 */
			if (i % 2 == 0) {
				rgv = rgv + cnc_Load_1;

				cnc[i] = rgv + process_1;
			} else {
				rgv = rgv + cnc_Load_2 + clean;
				cnc[i] = rgv + process_2;
			}
			/*
			 * cnc[i] = rgv + process; rgv = rgv + clean;
			 */

			i++;
			if (i == 8) {
				i = 0;
			}
		}

		/*
		 * for (int i = 0; i < j; i++) { System.out.println( "序号" + i + " 编号:" +
		 * cnc_Number[i] + "上料" + load_Material[i] + " 下料时间：" + unload_Material[i]); }
		 */

		for (int k = 0; k < j_1; k++) {
			System.out.println((k + 1) + " " + cnc_Number_1[k] + " " + load_Material_1[k] + "  " + unload_Material_1[k]
					+ " " + cnc_Number_2[k] + " " + load_Material_2[k] + "  " + unload_Material_2[k]);
		}

	}

	public static int min(int cnc[]) {
		int min = cnc[0], a = 0;
		for (int i = 0; i < cnc.length; i++) {
			if (min > cnc[i]) {
				min = cnc[i];
				a = i;
			}

		}

		// System.out.println("min"+a);
		return a;

	}

	public static int move(int rgv_Location_Start, int rgv_Location_End) {

		// System.out.println(rgv_Location_Start+" "+rgv_Location_End);
		int move = 0;
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

		// System.out.println(rgv_Location_End+" "+rgv_Location_Start);
		int a = Math.abs(rgv_Location_End - rgv_Location_Start);

		// System.out.println(a);
		if (a == 1)
			move = move_1;
		else if (a == 2)
			move = move_2;
		else if (a == 3)
			move = move_3;

		// System.out.println(move);
		return move;
	}

}

/*
 * 
 * System.out.println("-"+i+" "+j_1); if (j_1 < 4) { if (i % 2 == 0) {
 * cnc_Number_1[j_1] = i + 1; load_Material_1[j_1] = cnc[i] - process_1; } else
 * { cnc_Number_2[j_2] = i + 1; load_Material_2[j_2] = 0; } } else { if (i % 2
 * == 0) { cnc_Number_1[j_1] = i + 1; load_Material_1[j_1] =
 * unload_Material_1[j_1 - 3]; System.out.println(unload_Material_1[j_1 - 3]); }
 * else { cnc_Number_2[j_2] = i + 1; load_Material_2[j_2] =
 * unload_Material_2[j_2 - 3]; } }
 */