package com.list.test02;

public class ShowClass {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		@SuppressWarnings("unused")
		DataClass dataClass = new DataClass();

		System.out.println("学号" + DataClass.idList);
		System.out.println("姓名" + DataClass.nameList);
		System.out.println("英语" + DataClass.enligshList);
		System.out.println("数学" + DataClass.mathList);
		// System.out.println("总分" + DataClass.totalList);
	}

	/*
	 * public void total() { for(int i =0 ;i<DataClass.enligshList.size();i++) {
	 * DataClass.totalList.add(DataClass.enligshList.get(i+1)+DataClass.enligshList.
	 * get(i+1)); } }
	 */

}
