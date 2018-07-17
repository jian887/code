<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%
	Object user = request.getSession().getAttribute("user");
	if (user != null) {
		response.sendRedirect(request.getContextPath() + "/account?action=list");
	} else {
		response.sendRedirect(request.getContextPath() + "/user/login.jsp");
	}
%>