package com.tools;

import java.awt.Frame;
import java.awt.Panel;

public class ThingCountDown {
	public static void main(String[] args) {
		Frame frame = new Frame();
		Panel panel = new Panel();
		
		/*frame.setLocation(400, 400);
		frame.setSize(1000, 200);
		=
		frame.setBounds(400, 400, 1000, 200);*/
		//设置窗口大小
		frame.setSize(1000, 200);  
		//设置窗口居中 
		frame.setLocationRelativeTo(null);   
		frame.setVisible(true);
	}
}
