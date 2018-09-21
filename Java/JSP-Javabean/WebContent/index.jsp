<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<jsp:useBean id="Calculator" scope="page" class="qingkuang1.Calculator">
	<jsp:setProperty property="*" name="Calculator" />
</jsp:useBean>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">

<title>Calculate</title>
</head>
<body>
	<%
	
		String Result;
	try {
		Calculator.calulator();
		Result = Calculator.getFirst() + Calculator.getOperator() + Calculator.getSecond() + "="
				+ Calculator.getResult();
	}
	catch(Exception e){
		Result = e.getMessage();
	}
	%>

	<form action="index.jsp" method="get">
		<table width="75%" border="1" bordercolor="#aaaaaa">
			<tr>
				<td>计算结果</td>
				<td><input type="text" name="Result" value=<%=Result%>>
				</td>
			</tr>
			<tr>
				<td>One</td>
				<td><input type="text" name="first"></td>
			<tr>
				<td>Operate</td>
				<td><select name="operator">
						<option value="+">+</option>
						<option value="-">-</option>
						<option value="*">*</option>
						<option value="/">/</option>
				</select></td>
			</tr>
			<tr>
				<td>Second</td>
				<td><input type="text" name="second"></td>
			<tr>
			<tr>
				<td><input type="submit" value="计算"></td>
			</tr>

		</table>
	</form>


</body>
</html>