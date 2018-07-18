package com.jdbc.tesr01;

/**
 * 文件名：ConnectMysql.java
 * 版本信息：Version 1.0
 * 日期：2016年9月2日
 * Copyright talkweb.com.cn Corporation 2016
 * 版权所有
 */

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
 
/**
 * 类描述：
 * 
 * @version: 1.0
 * @author: Administrator
 * @version: 2016年9月2日 下午9:45:53
 */
public class ConnectMysql
{
 
    /**
     * 方法描述：
     * 
     * @param:
     * @return:
     * @version: 1.0
     * @author: Administrator
     * @version: 2016年9月2日 下午9:45:53
     */
	public static void main(String[] args) 
    {
        Connection conn = null;
        Statement stmt = null;
        ResultSet rs = null;
        try
        {
            Class.forName("com.mysql.jdbc.Driver");
            conn = DriverManager.getConnection("jdbc:mysql://localhost/jdbctest01?"
                    + "user=root&password=123456"
                    + "&useUnicode=true&characterEncoding=UTF8");
            System.out.println(conn);
            // Do something with the Connection
            stmt = conn.createStatement();
            rs = stmt.executeQuery("SELECT userName FROM account");
            // or alternatively, if you don't know ahead of time that
            // the query will be a SELECT...
            if (stmt.execute("SELECT userName FROM account"))
            {
                rs = stmt.getResultSet();
                if(rs.next())
                {
                    String name = rs.getString("userName");
                    System.out.println(name);
                }
            }
            // Now do something with the ResultSet ....
        }
        catch (SQLException ex)
        {
            // handle any errors
            System.out.println("SQLException: " + ex.getMessage());
            System.out.println("SQLState: " + ex.getSQLState());
            System.out.println("VendorError: " + ex.getErrorCode());
        }
        catch (ClassNotFoundException e)
        {
            e.printStackTrace();
        }
    /*    finally
        {
            // it is a good idea to release
            // resources in a finally{} block
            // in reverse-order of their creation
            // if they are no-longer needed
            if (rs != null)
            {
                try
                {
                    rs.close();
                }
                catch (SQLException sqlEx)
                {
                } // ignore
                rs = null;
            }
            if (stmt != null)
            {
                try
                {
                    stmt.close();
                }
                catch (SQLException sqlEx)
                {
                } // ignore
                stmt = null;
            }
            if (conn != null)
            {
                try
                {
                    conn.close();
                }
                catch (SQLException sqlEx)
                {
                } // ignore
                conn = null;
            }
        }*/
    }
}
