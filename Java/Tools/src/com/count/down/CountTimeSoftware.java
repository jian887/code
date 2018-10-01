package com.count.down;

import java.awt.Button;
import java.awt.Frame;
import java.awt.Panel;
import java.awt.TextField;
import java.text.SimpleDateFormat;
import java.util.Date;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

public class CountTimeSoftware {
	public static void main(String[] args) {
		JFrame jframe = new JFrame();
		JPanel jpanel = new JPanel();
		SimpleDateFormat simpleDateFormat = new SimpleDateFormat("yyyy-MM-dd HH::mm::ss");
		String time;
		jpanel.add(new TextField());
		jpanel.add(new Button());
		jpanel.add(new JLabel(simpleDateFormat.format(new Date())));
		jframe.add(jpanel);
		jframe.setSize(1000, 200);
		jframe.setLocationRelativeTo(null);
		jframe.setVisible(true);
		jframe.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	
			jpanel.add(new JLabel());
		
		
	}

}
