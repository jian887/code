package qingkuang1;

public class Test02 {
	static int move_1 = 23;
	static int move_2 = 41;
	static int move_3 = 59;
	static int process = 580;
	static int cnc_Load_1 = 30;
	static int cnc_Load_2 = 35;
	static int clean = 30;

	public static void main(String[] args) {
		int[] cnc_Number = new int[1000];
		int[] load_Material = new int[1000];
		int[] unload_Material = new int[1000];
		int[] move = new int[1000];
		int j = 0;

		int rgv = (cnc_Load_1 + cnc_Load_2 + move_1) * 4 - move_1, rgv_Location = 8;

		int[] cnc = new int[8];
		cnc[0] = cnc_Load_1 + process;
		for (int i = 0; i < 7; i++) {
			if (i % 2 == 0) {
				cnc[i + 1] = cnc[i] + cnc_Load_2;
			} else {
				cnc[i + 1] += cnc[i] + move_1 + cnc_Load_1;

			}

		}
		int cnc_Loction[] = new int[] { 1, 2, 3, 4, 5, 6, 7, 8 };

		for (; rgv < 28800;) {
			int i = min(cnc);

			cnc_Number[j] = i + 1;
			if (j <= 7) {
				if (j % 2 == 0) {
					load_Material[j] = cnc[i] - process - cnc_Load_1;
				} else {
					load_Material[j] = cnc[i] - process - cnc_Load_2;
				}

			} else {
				load_Material[j] = unload_Material[j - 8];
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

			move[j] = rgv_Move;
			unload_Material[j] = rgv;

			if (i % 2 == 0) {
				rgv = rgv + cnc_Load_1;
			} else {
				rgv = rgv + cnc_Load_2;
			}
			cnc[i] = rgv + process;
			rgv = rgv + clean;

			j++;
		}

		

		for (int i = 0; i < j; i++) {
			System.out.println((i + 1) + " " + cnc_Number[i] + " " + load_Material[i] + "  " + unload_Material[i]);
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
