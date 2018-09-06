package com.newfile;
import java.io.*;

//Beffered是字节缓冲流，解决了File流不能换行读取的问题，
public class Buffered {
	public static void main(String[] args) {
		File readFile = new File("a.txt");
		File writeFile = new File("b.txt");
		
		try {
			Writer out = new FileWriter(writeFile);
			BufferedWriter bufferedOut = new BufferedWriter(out);
			Reader in = new FileReader(readFile);
			BufferedReader bufferedIn = new BufferedReader(in);
			String s = bufferedIn.readLine();
			String s_2 = bufferedIn.readLine();
			bufferedOut.write(s);
			bufferedOut.close();
			out.close();
			bufferedIn.close();
			in.close();
			
			
		}catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
		
		}
	}
}
