package com.runtime;

public class Test {
	public static void main(String[] args) {
		Runtime run = Runtime.getRuntime();
		try {
			Process pro = run.exec("java");
			int wait = pro.waitFor();
			System.out.println(wait);
		}catch (Exception e) {
			e.printStackTrace();
		}
	}

}
