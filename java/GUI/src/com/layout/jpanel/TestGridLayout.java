package com.layout.jpanel;

import java.awt.BorderLayout;
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class TestGridLayout {
	public static void main(String[] args) {
		new JPanelGridLayout();
	}
}

class JPanelGridLayout extends JFrame{
	JTextField text;
	JPanel jpanel;
	GridLayout gridLayout;
	
	public JPanelGridLayout() {
		jpanel = new JPanel();
		gridLayout = new GridLayout(4, 4);
		jpanel.setLayout(gridLayout);
		text = new JTextField();
		//symbol 符号
		String [] symbols = {"1","2","3","4","5","6","7","8","9"};
		for (int i=0 ;i<symbols.length;i++) {
			JButton button = new JButton(symbols[i]);
			
			jpanel.add(button);
		}
		JButton button1 = new JButton("23");
		jpanel.add(button1);
		add(text,BorderLayout.NORTH);
		add(jpanel,BorderLayout.CENTER);
		setBounds(10, 10, 300, 300);
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		validate();
	}
}