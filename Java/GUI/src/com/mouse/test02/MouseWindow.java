package com.mouse.test02;

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
		setLayout(new FlowLayout());
		text = new JTextField(8);
		textArea = new JTextArea(7,8);
		police = new MousePolice();
		button = new JButton("1");
		button = new JButton("2");
		
		police.setTextArea(textArea);
		
		text.addMouseListener(police);
		
		
		
		
		button.addMouseListener(police);
		
		addMouseListener(police);
		add(button);
		add(text);
		add(textArea);
	}

}
