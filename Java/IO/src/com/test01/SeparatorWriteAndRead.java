package com.test01;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Reader;
import java.io.Writer;
import java.util.Scanner;

public class SeparatorWriteAndRead {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		File fileNumber = new File("fileNumber.txt");
		File write = new File("Dice.txt");
		File read = new File("Dice.txt");
		try {
			Writer writer = new FileWriter(write);
			Reader reader = new FileReader(read);
			BufferedWriter bufferedWriter = new BufferedWriter(writer);
			BufferedReader bufferedReader = new BufferedReader(reader);
			System.out.println("请输入数字");
			int number = scanner.nextInt();
			String a[] = new String[number];
			String b[] = new String[number];
			for (int i = 0; i < a.length; i++) {
				String wr;
				a[i] = scanner.next();
				b[i] = scanner.next();
				wr = a[i] +" "+ b[i] + "\n";
				bufferedWriter.write(wr);
				
			}
			bufferedWriter.close();
			writer.close();
			Scanner scannerFile = new Scanner(read);
		    while(scannerFile.hasNext()) {
		    	String a1 = scannerFile.next();
		    	String a2 = scannerFile.next();
		    	System.out.println("thing "+a1+"Mentality "+a2);
		    }
			
			String s = null;
			while ((s = bufferedReader.readLine()) != null) {
				System.out.println(s);
			}
			bufferedReader.close();
			reader.close();

		} catch (Exception e) {
			// TODO: handle exception
		}
	}
}
