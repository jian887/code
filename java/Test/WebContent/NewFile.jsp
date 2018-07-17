<%@ page language="java" contentType="text/html;charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<%--<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd"> --%>
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=ISO-8859-1">
<title>Text</title>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width,initial-scale=1.0">
<%--原来的形式 --%>
<script type="text/script" src="jquery/jquery-3.3.1.js"></script>
<script type="text/script" src="bootstrap/js/bootstrap.min.js"></script>
<link href="bootstrap/css/bootstrap.min.css" type="text/css"
	rel="stylesheet">
<link href="bootstrap/css/bootstrap-theme.min.css" type="text/css">

<%-- 
<script type="text/script" src="<%=request.getContextPath()%>jquery/jquery-3.3.1.js"></script>
<script type="text/script" src="<%=request.getContextPath()%>bootstrap/js/bootstrap.min.js"></script>
<link href="<%=request.getContextPath()%>bootstrap/css/bootstrap.min.css" type="text/css" rel="stylesheet">

--%>
<%--<script src="https://cdn.bootcss.com/jquery/2.1.1/jquery.min.js"></script> 
<script src="https://cdn.bootcss.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
<link href="https://cdn.bootcss.com/bootstrap/3.3.7/css/bootstrap.min.css" rel="stylesheet"> --%>


</head>
<body>
	<div class="container">
		<form id="loginFrom" action="check.jsp" method="post"
			class="form-horizontal" role="form">
			<fieldset>
				<legend>
					<label><span class="glyphicon glyphicon-user">用户登录</span></label>
				</legend>
				<%-- 图标特效  glyphicon --%>
				<div class="form-gruop" id="midDiv">
					<label class="col-md-3 control-label" for="mid">用户名：</label>
					<div class="col-md-6">
						<input type="text" id="mid" name="mid" class="form-control"
							placeholder="请输入用户名">
					</div>
					<div class="col-md-3" id="midSpan"></div>
				</div>
				<div class="form-gruop">
					<label class="col-md-3 control-label" for="mid"> </label>
					<div class="col-md-6"></div>
					<div class="col-md-3" id="midSpan"></div>
				</div>
				<div class="form-gruop" id="passwordDiv">
					<label class="col-md-3 control-label" for="password">密码：</label>
					<div class="col-md-6">
						<input type="text" id="password" name="password"
							class="form-control" placeholder="请输入密码">
					</div>
					<div class="col-md-3" id="passwordSpan"></div>
				</div>
			</fieldset>
		</form>
	</div>
	<div class="container">
		<form id="loginFrom" action="check.jsp" method="post"
			class="form-horizontal" role="form">
			<fieldset>
				<legend>
					<label><span class="glyphicon glyphicon-user">用户登录</span></label>
				</legend>
				<%-- 图标特效  glyphicon --%>
				<div class="form-gruop" id="midDiv">
					<label class="col-sm-3 control-label" for="mid">用户名：</label>
					<div class="col-sm-9">
						<input type="text" id="mid" name="mid" class="form-control"
							placeholder="请输入用户名">
						<div class="col-sm-3" id="passwordSpan"></div>
					</div>
				</div>
				<div class="form-gruop" id="passwordDiv">
					<label class="col-md-3 control-label" for="password">密码：</label>
					<div class="col-md-9">
						<input type="text" id="password" name="password"
							class="form-control" placeholder="请输入密码">
					</div>
					<div class="col-md-3" id="midSpan"></div>
				</div>
			</fieldset>
		</form>
	</div>
</body>
</html>