<%@page import="java.util.Date"%>
<%@page import="java.util.List"%>
<%@page import="cn.jerryshell.entity.User"%>
<%@page import="cn.jerryshell.service.LoginHistoryService"%>
<%@page import="cn.jerryshell.service.impl.LoginHistoryServiceImpl"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%
	String username = "游客";
	int total = 0;
	String lastLoginDate = "无";

	User user = (User) request.getSession().getAttribute("user");
	if (user != null) {
		username = user.getUsername();
		LoginHistoryService loginHistoryService = new LoginHistoryServiceImpl();
		total = loginHistoryService.getLoginTotalNumberByUserId(user.getId());
		List<Date> dateList = loginHistoryService.getRecently2LoginDateTimeByUserId(user.getId());
		if (dateList.size() == 2) {
			lastLoginDate = dateList.get(1).toLocaleString();
		}
	}
%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>首页</title>
<link rel="stylesheet" href="${ pageContext.request.contextPath }/css/center.css">
</head>
<body>
	<div class="container">
		<a href="user/register.jsp">注册</a>
		<a href="user/login.jsp">登录</a>
		<a href="user?action=logout">注销</a>
		<a href="account?action=list">账号列表</a>
		<h1>你好，<%=username%></h1>
		<h2>这是你第 <%=total%> 次登录，上次登录时间：<%=lastLoginDate%></h2>
		<div>Author <a href="http://jerryshell.cn">Jerry</a></div>
	</div>
</body>
</html>