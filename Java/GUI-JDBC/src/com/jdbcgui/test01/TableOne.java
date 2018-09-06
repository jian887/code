package com.jdbcgui.test01;

import java.awt.BorderLayout;
import java.awt.Container;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JScrollPane;
import javax.swing.JTable;

public class TableOne {
	public static void main(String[] args) {
		TableOne tableOne = new TableOne();
		ConnectSQL conSQL = new ConnectSQL();
		JTable table;
		Object a[][] = conSQL.toString();
		Object columnName[] = { "id", "account", "password" };
		//JButton button;
/*			a = new Object[6][3];
			for (int i = 0; i < 6; i++) {
				for (int j = 0; j < 3; j++) {
					a[i][j] = i + "," + j;
				}
			}*/
			table = new JTable(a,columnName);
			JFrame f = new JFrame();
			f.add(new JScrollPane(table));
			f.setVisible(true);
			f.setBounds(20,20,300,400);
			f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}

}
