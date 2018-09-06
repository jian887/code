package com.mouse.test01;

import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class MousePolice implements MouseListener{

	JTextArea area;
	// get textArea
	public void setTextArea(JTextArea area) {
		this.area = area;
	}
	
	@Override
	public void mouseClicked(MouseEvent e) {
		// TODO Auto-generated method stub
		area.append("\nMouse Clicked,position:"+e.getX()+","+e.getY());
	}

	@Override
	public void mouseEntered(MouseEvent e) {
		// TODO Auto-generated method stub
/*		if(e.getSource() instanceof JTextField) {
			area.append("\nMouse Entered JTextField,position:"+e.getX()+","+e.getY());
		}
		if(e.getSource() instanceof JTextArea) {
			area.append("\nMouse Entered JTextField,position:"+e.getX()+","+e.getY());
		}
		if(e.getSource() instanceof JButton) {
			area.append("\nMouse Entered JTextField,position:"+e.getX()+","+e.getY());
		}
		if(e.getSource() instanceof JFrame) {
			area.append("\nMouse Entered JTextField,position:"+e.getX()+","+e.getY());
		}*/
	}

	@Override
	public void mouseExited(MouseEvent e) {
		// TODO Auto-generated method stub
		/*area.append("\nMouse Exited,position:"+e.getX()+","+e.getY());*/
	}

	@Override
	public void mousePressed(MouseEvent e) {
		// TODO Auto-generated method stub
		area.append("\nMouse Pressed,position:"+e.getX()+","+e.getY());
	}

	@Override
	public void mouseReleased(MouseEvent e) {
		// TODO Auto-generated method stub
		area.append("\nMouse Released,position:"+e.getX()+","+e.getY());
	}

}
