<%@page import="org.apache.catalina.filters.AddDefaultCharsetFilter"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8" import="com.*" errorPage=""%>
<jsp:useBean id="userInfo" class="com.UserInfo" scope="page">
	<jsp:setProperty name="userinfo" property="*" />
</jsp:useBean>
<jsp:useBean id="newUser" class="com.NewUser" scope="page">
</jsp:useBean>

<%
	newUser.setUserInfo(userInfo);
	newUser.register();
	out.println("successed");	
%>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>

	<form action="other.jsp" method=get>
		<table>
			<tr>
				<td>用户注册</td>
			</tr>
			
			<tr>
				<td>id</td>
				<td><input type=text name="id"></td>
			</tr>
			
			
			<tr>
				<td>用户名</td>
				<td><input type=text name="userName"></td>
			</tr>

			<tr>
				<td>密码</td>
				<td><input type=password name="password"></td>
			</tr>

			<tr>
				<td><input type=submit value=注册> </td>
			</tr>

		</table>

	</form>

</body>
</html>