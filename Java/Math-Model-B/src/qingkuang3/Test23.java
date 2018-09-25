package qingkuang3;

import java.util.Random;

public class Test23 {

	static int move_1 = 18;
	static int move_2 = 32;
	static int move_3 = 46;
	static int process_1 = 455;
	static int process_2 = 182;
	static int cnc_Load_1 = 27;
	static int cnc_Load_2 = 32;
	static int clean = 25;
	static int[] cnc_Number_1 = new int[1000];
	static int[] load_Material_1 = new int[1000];
	static int[] unload_Material_1 = new int[1000];
	static int[] cnc_Number_2 = new int[1000];
	static int[] load_Material_2 = new int[1000];
	static int[] unload_Material_2 = new int[1000];
	static int j_1 = 0;
	static int j_2 = 0;
	static int i = 0;
	static int rgv = (cnc_Load_1 + move_1) * 4 - move_1;
	static int rgv_Location = 8;
	static int[] cnc_Loction = new int[] { 1, 2, 3, 4, 5, 6, 7, 8 };

	static int[] cnc_accmulation = new int[8];
	static int[] breakdown = new int[8];
	static int[] breakdown_Time = new int[8];
	static int[] breakdown_Point = new int[8];
	static int[] breakdown_Time_Start = new int[8];
	static int[] breakdown_Number = new int[8];
	static int[] brekdown_Time_End = new int[8];
	static int[] cnc = new int[8];

	public static void main(String[] args) {

		for (int i = 0; i < breakdown.length; i++) {
			Random random = new Random();
			breakdown[i] = random.nextInt(100) % (100 - 1 + 1) + 1;
			breakdown_Time[i] = random.nextInt(20 * 60) % (20 * 60 - 10 * 60 + 10 * 60) + 10 * 60;
			System.out.println(breakdown[i]);
			System.out.println(breakdown_Time[i]);
		}

		cnc[0] = process_1 + cnc_Load_1;
		cnc[2] = cnc[0] + move_1 + cnc_Load_1;
		cnc[4] = cnc[2] + move_1 + cnc_Load_1;
		cnc[6] = cnc[4] + move_1 + cnc_Load_1;

		for (; rgv < 28800;) {
			for (int k = 0; k < cnc_accmulation.length; k++) {
				if (i == k) {
					cnc_accmulation[k] = cnc_accmulation[k] + 1;
					System.out.println(cnc_accmulation[k]);
				}
			}
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
				if (cnc_accmulation[i] == breakdown[i]) {
					breakdown_Number[i] = j_1 + 1;
					breakdown_Point[i] = i + 1;
					breakdown_Time_Start[i] = unload_Material_1[j_1];
				}
				j_1++;

			} else {
				unload_Material_2[j_2] = rgv;
				if (cnc_accmulation[i] == breakdown[i]) {
					breakdown_Number[i] = j_2 + 1;
					breakdown_Point[i] = i + 1;
					breakdown_Time_Start[i] = unload_Material_2[j_2];
				}
				j_2++;
			}

			if (i % 2 == 0) {
				rgv = rgv + cnc_Load_1;

				cnc[i] = rgv + process_1;
			} else {
				rgv = rgv + cnc_Load_2 + clean;
				cnc[i] = rgv + process_2;
			}
			i++;
			if (i == 8) {
				i = 0;
			}
		}

		for (int k = 0; k < j_1; k++) {
			System.out.println((k + 1) + " " + cnc_Number_1[k] + " " + load_Material_1[k] + "  " + unload_Material_1[k]
					+ " " + cnc_Number_2[k] + " " + load_Material_2[k] + "  " + unload_Material_2[k]);
		}
		for (int i = 0; i < 8; i++) {
			brekdown_Time_End[i] = breakdown_Time_Start[i] + breakdown_Time[i];
		}

		for (int i = 0; i < 8; i++) {
			if (breakdown_Number[i] != 0)
				System.out.println(breakdown_Number[i] + "  " + breakdown_Point[i] + " " + breakdown_Time_Start[i] + " "
						+ brekdown_Time_End[i] + " ");
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
		return a;
	}

	public static int move(int rgv_Location_Start, int rgv_Location_End) {
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
		int a = Math.abs(rgv_Location_End - rgv_Location_Start);

		if (a == 1)
			move = move_1;
		else if (a == 2)
			move = move_2;
		else if (a == 3)
			move = move_3;

		return move;
	}

}

