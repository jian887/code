package other;

import java.util.Arrays;
import static java.lang.Math.min;

public class Main {
	int[] cnc = { 0, 0, 0, 0, 0, 0, 0, 0 };// CNC剩余时间
	int[] cncwork = { 1, 2, 3, 4, 5, 6, 7, 8 };// CNC加工零件编号
	int[] cncstart = { 0, 0, 0, 0, 0, 0, 0, 0 };// CNC加工零件时间
	int newtime = 0;
	int RGV = 4;// RGV实在位置
	int y = 9;// 取物料编号

	public void main() {
		// 模拟第一次情况
		cncstart[0] = newtime;
		cncadd(28);
		cnc[0] += 560;
		cncstart[1] = newtime;
		cncadd(31);
		cnc[1] += 560;
		// 移动到位置2
		cncadd(20);
		cncstart[2] = newtime;
		cncadd(28);
		cnc[2] += 560;
		cncstart[3] = newtime;
		cncadd(31);
		cnc[3] += 560;
		// 移动到位置3
		cncadd(20);
		cncstart[4] = newtime;
		cncadd(28);
		cnc[4] += 560;
		cncstart[5] = newtime;
		cncadd(31);
		cnc[5] += 560;
		// 移动到位置4
		cncadd(20);
		cncstart[6] = newtime;
		cncadd(28);
		cnc[6] += 560;
		cncstart[7] = newtime;
		cncadd(31);
		cnc[7] += 560;
		// 开始循环
		for (; newtime < 28800;) {
			int min = Arrays.stream(cnc).min().getAsInt();
			int minname = find(min);
			cncadd(min);
			// 判断移动单位时间
			int move = Math.abs((int) (Math.ceil((minname + 1) / 2.0) - RGV));
			if (move == 3)
				cncadd(46);
			if (move == 2)
				cncadd(33);
			if (move == 1)
				cncadd(20);
			// R移动
			RGV = (int) (Math.ceil(minname + 1) / 2.0);
			/* 上料 */
			if ((minname + 1) % 2 == 0) {
				// 上料下料
				System.out.println("加工物料序号:" + cncwork[minname] + "  加工CNC编号" + (minname + 1) + "  上料开始时间:"
						+ cncstart[minname] + "  下料开始时间:" + newtime);
				cncadd(31);
				// 重置ncn剩余工作时间
				cncwork[minname] = y;
				y++;
				cncstart[minname] = newtime;
				cnc[minname] = 560;
				// 处理物料清洗
				cncadd(25);
			} else {
				// 上料下料
				System.out.println("加工物料序号:" + cncwork[minname] + "  加工CNC编号" + (minname + 1) + "  上料开始时间:"
						+ cncstart[minname] + "  下料开始时间:" + newtime);
				cncadd(28);
				// 重置ncn剩余工作时间
				cncwork[minname] = y;
				y++;
				cncstart[minname] = newtime;
				cnc[minname] = 560;
				// 处理物料清洗
				cncadd(25);
			}
		}

	}

	int find(int f) {
		int t = 0;
		for (int i = 0; i < 8; i++) {
			if (cnc[i] == f)
				t = i;
		}
		return t;
	}

	void cncadd(int time) {
		for (int i = 0; i < 8; i++) {
			if (cnc[i] != 0) {
				cnc[i] -= time;
			}

		}
		newtime += time;
	}
}
