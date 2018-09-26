package com.daily;

import java.io.File;
import java.util.Random;
import java.util.Scanner;

public class DiceGame {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		File write = new File("Dice.txt");
		File read = new File("Dice.txt");
		Random random = new Random();
		for (int j = 1;;) {
			System.out.println("请输入骰子的数字范围");
			int number = scanner.nextInt();
			String br = scanner.nextLine();
			String[] DiceThing = new String[number];
			String[] ThingMentality = new String[number];
			for (int i = 0; i < DiceThing.length; i++) {
				String 
				System.out.println("请输入每个骰子对应的事件");
				DiceThing[i] = scanner.next();
				System.out.println("请输入每个骰子对应的心理");
				ThingMentality[i] = scanner.next();

			}
			System.out.println("开始投掷骰子");
			int DiceNumber = random.nextInt(number);
			System.out.println(DiceThing[DiceNumber]);
			j++;
			System.out.println("骰子投掷完毕，是否进行第" + j + "次投掷");
			String Dicing = scanner.nextLine();
			if (Dicing.equals("否")) {
				break;
			} else {
				continue;
			}
		}

	}

}
