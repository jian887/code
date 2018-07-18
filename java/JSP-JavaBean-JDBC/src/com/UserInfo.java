package com;

public class UserInfo {
	private int id;
	private String userName;
	private String password;
	
	public String gerPassword()
	{
		return password;
	}
	
	public void serPassword(String password)
	{
		this.password = password;
	}
	

    public String getUserName()
    {
    	return userName;
    }
    
    public void setUserName(String userName)
    {
    	this.userName = userName;
    }
    
    public int gerId()
    {
    	return id;
    }
    
    public void serId(int id)
    {
    	this.id = id;
    }
}
