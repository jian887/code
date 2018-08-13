package com.genericity.com;

public class Circle {
	double area, readius;

	public Circle(double re) {
		// TODO Auto-generated constructor stub
		readius = re;
	}
	
	public String toString() {
		area = readius*readius*Math.PI;
		return ""+area;
	}
	

}
