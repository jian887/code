package com.c;

public class My {
	int temp;
	public void intext(int temp) throws MyException{
		if(temp<0||temp>100) {
			throw new MyException(temp);
		}
	}
}
