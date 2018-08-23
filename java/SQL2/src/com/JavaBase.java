package com;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;

public class JavaBase {
	  
	     public static void main(String args[]) {  
	     try {  
	          Class.forName("com.mysql.cj.jdbc.Driver");  //����MYSQL JDBC��������  
	          //Class.forName("org.gjt.mm.mysql.Driver");  
	          System.out.println("Success loading Mysql Driver!");  
	         }catch (Exception e) {  
	          System.out.print("Error loading Mysql Driver!");  
	          e.printStackTrace();  
	     }  
	     try{  
	          Connection connect = DriverManager.getConnection(  
	           "jdbc:mysql://localhost:3306/test?useSSL=true","traiyi","123456");  
	           //����URLΪ jdbc:mysql//��������ַ/���ݿ��� �������2�������ֱ��ǵ�½�û���������  
	           
	          System.out.println("Success connect Mysql server!");  
	          Statement stmt = connect.createStatement();  
	          ResultSet rs = stmt.executeQuery("select * from Persons");  
	                        //user Ϊ��������  
	          while (rs.next()) {  
	                  System.out.println(rs.getString("LastName"));  
	             }  
	         }catch(Exception e) {  
	          System.out.print("get data error!");  
	          e.printStackTrace();  
	         }  
	    
	     }  
	    	
}
