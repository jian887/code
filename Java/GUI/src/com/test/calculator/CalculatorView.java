package com.test.calculator;

import java.awt.BorderLayout;
import java.awt.GridLayout;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class CalculatorView extends JFrame{
	JTextField text;
	JPanel jpanel;
	GridLayout gridLayout;
	
	public CalculatorView(){
		jpanel = new JPanel();
		gridLayout = new GridLayout(3, 3);
		jpanel.setLayout(gridLayout);
		text = new JTextField();
		//symbol 符号
		String [] symbols = {"1","2","3","4","5","6","7","8","9"};
		for (int i=0 ;i<symbols.length;i++) {
			JButton button = new JButton(symbols[i]);
			
			jpanel.add(button);
		}
		
		add(text,BorderLayout.NORTH);
		add(jpanel,BorderLayout.CENTER);
		setBounds(10, 10, 300, 300);
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		validate();
	}
	

}
