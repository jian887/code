package com.mouse.test01;

import java.awt.*;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextArea;
import javax.swing.JTextField;

@SuppressWarnings("serial")
public class MouseWindow extends JFrame{
	JTextField text;
	JButton button;
	JTextArea textArea;
	MousePolice police;
	MouseWindow() {
		init();
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	void init() {
		//set layout
		setLayout(new FlowLayout()); 
		
		//initialize component(组件，组成的)
		text = new JTextField(8);
		button = new JButton("按钮");
		textArea = new JTextArea(7,8);
		police = new MousePolice();
		
		//Mouse event output
		police.setTextArea(textArea);
		
		//Add mouse event in text and button
		text.addMouseListener(police);
		button.addMouseListener(police);
		
		//Add component
		addMouseListener(police);
		add(button);
		add(text);
		add(textArea);
	}

}
