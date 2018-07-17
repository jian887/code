package com.runtime;

import java.io.BufferedReader;
import java.io.InputStream;
import java.io.InputStreamReader;

public class Test01 {
	public static void main(String[] args) {
		Process pro;
		String cmd = "C:\\Users\\Traiyi\\Desktop\\a.bat";
		try {
			pro = Runtime.getRuntime().exec(cmd);
			InputStream file = pro.getInputStream();
		    InputStreamReader fileRead = new InputStreamReader(file);
		    BufferedReader buf = new BufferedReader(fileRead);
		    String line = null;
		    while ((line = buf.readLine()) != null) {
		    	System.out.println(line);
		    }
		}catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
		
		}
	}

}
