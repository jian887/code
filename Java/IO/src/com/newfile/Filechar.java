package com.newfile;

import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.Reader;
import java.io.Writer;

public class Filechar {
	public static void main(String[] args) {
		File readFile = new File("a2.txt");
		File writeFile = new File("b2.txt");
		char c[] = new char[20];
		try {
			
			Writer out = new FileWriter(writeFile);
			Reader in = new FileReader(readFile);
			int n = -1;
			while ((n =in.read(c))!= -1) {
				out.write(c,0,n);
			}
			out.flush();
			out.close();
			
		}catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
		}
	}

}
