package com;

public class Calculator {
	private String first;
	private String second;
	private double result;
	private String operator;
	
	// set is ?
	public void setFirst(String first) {
		this.first=first;
	}
	
	public void setSecond(String second) {
		this.second=second;
	}
	
	public void setResult(double result) {
		this.result=result;
	}
	
	public void setOperator(String operator) {
		this.operator=operator;
	}
	
	//get methon is get result(结果) of calulator.
	
	public String getFirst() {
		return this.first;
	}
	
	public String  getSecond() {
		return this.second;
	}
	
	public double getResult() {
		return this.result;
	}
	
	public String getOperator() {
		return this.operator;
	}
	
	public void calulator() {
		double one = Double.parseDouble(first);
		double two = Double.parseDouble(second);
		
		if (operator.equals("+")) 
			result = one + two;
		else if (operator.equals("-"))
			result = one - two;
		else if (operator.equals("*"))
			result = one * two;
		else if (operator.equals("/"))
			result = one / two ;
	}

}
