package com.other.test01;

import java.util.Arrays;
import java.util.List;

public class Test {
	public static void main(String[] args) {
		List <String> a = Arrays.asList("a","b","c");
		
	
		
		a.forEach(e -> Test.print(e));
		
		a.forEach(Test::print);
		
		a.forEach(e -> System.out.println(e));
		
		a.forEach(System.out::println);
	
	}
	
	public static void print(String s)
	{
		System.out.println("word:"+s);
	}

}
