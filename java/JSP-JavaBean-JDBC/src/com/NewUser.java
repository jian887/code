package com;

import java.sql.*;
/*import java.sql.Statement;

import javax.imageio.spi.RegisterableService;

import com.sun.beans.util.Cache;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.SQLOutput;*/

public class NewUser {
	private Connection conn = null;
	private UserInfo userInfo;

	public NewUser() {
		try {
			Class.forName("com.mysql.jdbc.Driver");
			conn = DriverManager.getConnection("jdbc:mysql://localhost/jdbctest01?" + "user=root&password=123456"
					+ "&useUnicode=true&characterEncoding=UTF8");
			/*
			 * stmt = conn.createStatement(); res = stmt.executeQuery(sql);
			 */

		} catch (SQLException ex) {
			// handle any errors
			System.out.println("SQLException: " + ex.getMessage());
			System.out.println("SQLState: " + ex.getSQLState());
			System.out.println("VendorError: " + ex.getErrorCode());
		} catch (ClassNotFoundException e) {
			e.printStackTrace();
		}

	}

	public void setUserInfo(UserInfo userInfo) {
		this.userInfo = userInfo;

	}
	
	public void register() {
		String sql = "insert into account values(?,?,?)";
		try {
			
			PreparedStatement pre = conn.prepareStatement(sql);
			pre.setInt(1, userInfo.gerId());
			pre.setString(2, userInfo.getUserName());
			pre.setString(3, userInfo.gerPassword());
			
			
		}catch (Exception e) {
			// TODO: handle exception
			e.printStackTrace();
		}
	}

}






























