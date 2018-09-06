package com.genericity.com;

public class Cone <E> {
	double height;
	E atom;
	public Cone(E a) {
		atom = a;
	}
	
	public void setHeight(double h) {
		height = h;
	}
	

	public double name() {
		String s = atom.toString();
		double area = Double.parseDouble(s);
		return 1.0/3.0*area*height;
	}

}
