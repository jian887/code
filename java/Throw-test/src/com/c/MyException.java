package com.c;

@SuppressWarnings("serial")
public class MyException extends Exception {

	private int temp;
	public MyException(int temp){
		this.temp = temp;
	}
	public int getTemp() {
		return temp;
	}
} 
