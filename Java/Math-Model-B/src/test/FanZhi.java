package test;



public class FanZhi {
	static int move_1 = 23;
	static int move_2 = 41;
	static int move_3 = 59;
	static int process = 580;
	static int cnc_Load_1 = 30;
	static int cnc_Load_2 = 35;
	static int clean = 30;
	public static void main(String[] args) {
		int load_Material_Finish = (cnc_Load_1 + cnc_Load_2 + move_1) * 4 - move_1;
		int cnc1 = cnc_Load_1 +process;
		if(load_Material_Finish<cnc1) {
			System.out.println("rgv等待cnc");
		}
		else {
			System.out.println("cnc等待rgv");
			}
	}

}
