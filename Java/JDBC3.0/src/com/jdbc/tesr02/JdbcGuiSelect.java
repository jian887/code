package com.jdbc.tesr02;

import java.awt.BorderLayout;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.ResultSetMetaData;
import java.sql.Statement;
import java.util.Properties;
import java.util.Vector;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextField;

public class JdbcGuiSelect {
	JFrame jf = new JFrame("查询");
	private JScrollPane jscrollpane;
	private JButton jbutton = new JButton("查询");
	private JTextField jtextfield = new JTextField(45);
	private static Connection con;
	private static Statement sta;
	static {
		try {
			Properties pro = new Properties();
			//pro.load(new FileInputStream("mysql.properties"));
			pro.load(JdbcGuiSelect.class.getResourceAsStream("mysql.properties"));
			String driver = pro.getProperty("driver");
			String url = pro.getProperty("url");
			String user = pro.getProperty("user");
			String password = pro.getProperty("password");
			Class.forName(driver);
			con = DriverManager.getConnection(url, user, password);
			
			sta = con.createStatement();

		} catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
			// System.out
		}
	}

	public void init() {
		JPanel jpanel = new JPanel();
		jpanel.add(new JLabel("输入查询语句"));
		jpanel.add(jtextfield);
		jpanel.add(jbutton);
		jbutton.addActionListener(new TableListenter());
		jtextfield.addActionListener(new TableListenter());
		jf.add(jpanel, BorderLayout.NORTH);
		jf.setSize(680, 480);
		jf.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		jf.setVisible(true);
	}

	class TableListenter implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
			// TODO Auto-generated method stub
			if (jscrollpane != null) {
				jf.remove(jscrollpane);
			}
			try (ResultSet res = sta.executeQuery(jtextfield.getText())) // 将从文本输入框的得到的sql语句传入
			{
				ResultSetMetaData resm = res.getMetaData(); // ResultSetMetaData类、对象 方法 getMetaData();的作用
				Vector<String> columnNames = new Vector<>();
				Vector<Vector<String>> data = new Vector<>();

				for (int i = 0; i < resm.getColumnCount(); i++) { // getColumnCount()获得列长
					columnNames.add(resm.getColumnName(i + 1));
				}
				while (res.next()) {
					Vector<String> v = new Vector<>();
					for (int i = 0; i < resm.getColumnCount(); i++) { // 获取每行的元组
						v.add(res.getString(i + 1));
					}
					data.add(v);
				}
				JTable jtable = new JTable(data, columnNames);
				jscrollpane = new JScrollPane(jtable);
				jf.add(jscrollpane);
				jf.validate();

			} catch (Exception a) {
				a.printStackTrace();
			}
		}
	}

	public static void main(String[] args) {
		new JdbcGuiSelect().init();
	}

}
