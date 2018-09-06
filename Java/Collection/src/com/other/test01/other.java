package com.other.test01;

import java.util.Arrays;
import java.util.List;

public class other {
	
	    public static void main(String[] args) {
	        List<String> a1 = Arrays.asList("a", "b", "c");

	        for (String a : a1) {
	            printValur(a);
	        };

	        a1.forEach(x -> other.printValur(x));


	    }

	    public static void printValur(String str) {
	        System.out.println("print value : " + str);
	    }



}
