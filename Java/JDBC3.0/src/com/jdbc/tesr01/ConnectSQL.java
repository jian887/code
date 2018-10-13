package com.jdbc.tesr01;

import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Connection;
import java.sql.Statement;
/*
 * import java.sql.Connection; 
 * import java.sql.Statement; 
 * Connection con = DriverManager.getConnection(url, user, password);
 * Statement sta = con.createStatement();
 * 可以使用
*/
/*
 * import com.mysql.jdbc.Connection;
 * import com.mysql.jdbc.Statement;  
 * Connection con = DriverManager.getConnection(url, user, password);
 * Statement sta = con.createStatement();
 * 无法使用
*/

//连接数据库
public class ConnectSQL {
	public static void main(String[] args)  {
		Connection con;
		Statement sta;
		ResultSet res;


		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
			/*
			 * String url = "jdbc:mysql://localhost:3306/jdbctest01"; String user = "root";
			 * String password = "123456"; con = DriverManager.getConnection(url, user,
			 * password);
			 */ con = DriverManager.getConnection("jdbc:mysql://localhost/jdbctest01?" + "user=aroot&password=123456"
					+ "&useUnicode=true&characterEncoding=UTF8");
			System.out.println(con);
			if (!con.isClosed()) {
				System.out.println("connected");
			} else {
				System.out.println("not Connected");
			}

			sta = con.createStatement();
			res = sta.executeQuery("select * from account ");

			while (res.next()) {
				int id = res.getInt(1);
				String useName = res.getString(2);
				String password1 = res.getString("password");
				System.out.println(id + "  " + useName + "  " + password1);
			}
			con.close();

		} catch (SQLException e) {
			e.printStackTrace();
			System.out.println("???");
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
