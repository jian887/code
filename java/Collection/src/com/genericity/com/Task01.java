package com.genericity.com;

public class Task01 {
	public static void main(String[] args) {
		Circle c = new Circle(10);
		Cone<Circle> cone_1 = new Cone<Circle>(c);
		cone_1.setHeight(10);
		System.out.println(cone_1.name());
	}
}
