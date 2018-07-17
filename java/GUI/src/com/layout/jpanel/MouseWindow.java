package com.layout.jpanel;

import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;

@SuppressWarnings("serial")
public class MouseWindow extends JFrame{
	JTextField text;
	JButton button;
	JTextArea textArea;
	JPanel jpanel = new JPanel();
	
	MouseWindow() {
		init();
		setVisible(true);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	void init() {
		jpanel.setLayout(new GridLayout(4, 4));  
		Container container = getContentPane();   
        container.add(jpanel, BorderLayout.CENTER);  
        
		text = new JTextField(8);
		textArea = new JTextArea(7,8);
		button = new JButton("1");
		
		jpanel.add(useButton('1'));
		jpanel.add(useButton('1'));
		jpanel.add(useButton('1'));
		jpanel.add(useButton('1'));
		jpanel.add(useButton('1'));
		jpanel.add(useButton('1'));
		jpanel.add(useButton('1'));
		jpanel.add(useButton('1'));
		jpanel.add(useButton('1'));
		jpanel.add(useButton('1'));
		
		add(button);
		add(text);
		add(textArea);
	}
	
	public JButton useButton(char key) {
		 button.addActionListener(new ActionListener()  
	        {  
	            public void actionPerformed(ActionEvent event)  
	            {  
	                JButton btn = (JButton) event.getSource();  
	                char key2 = btn.getText().charAt(0);  
	                  
	               
	            }  
	        });  
	        button.addKeyListener(new KeyAdapter()  
	        {  
	            public void keyReleased(KeyEvent event)  
	            {  
	                char key2 = event.getKeyChar ();  
	                  
	                //if(key2 != key)  
	                  //  return;  
	                  
	                
	            }  
	        });  
		return button;
	}
	

}
