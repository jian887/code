<%@page import="cn.jerryshell.util.GenerateCaptcha"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%
	session.setAttribute("captcha", GenerateCaptcha.generateCaptcha());
%>
<!DOCTYPE html>
<html lang="en">

<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<meta http-equiv="X-UA-Compatible" content="ie=edge">
<title>注册</title>
<link rel="stylesheet"
	href="${ pageContext.request.contextPath }/css/bootstrap.min.css">
<link rel="stylesheet"
	href="${ pageContext.request.contextPath }/css/register.css">
<script
	src="${ pageContext.request.contextPath }/js/jquery-3.3.1.min.js"></script>
<script src="${ pageContext.request.contextPath }/js/bootstrap.min.js"></script>
</head>

<body>
	<div class="container">
		<div class="row">
			<nav class="navbar navbar-default" role="navigation">
				<div class="container-fluid">
					<div class="navbar-header">
						<a class="navbar-brand" href="${ pageContext.request.contextPath }/user/login.jsp"> <span
							class="glyphicon glyphicon-briefcase"> </span> 超级密码箱
						</a>
					</div>
					<div>
						<ul class="nav navbar-nav navbar-right">
							<li><a href="#">About</a></li>
						</ul>
					</div>
				</div>
			</nav>
		</div>
		
		<div class="row">
			<div class="col-md-6 col-md-offset-3">
				<form action="${ pageContext.request.contextPath }/user"
					method="POST" role="form" class="register-form">
					<legend>
						<h1>注册</h1>
					</legend>
					<input type="hidden" name="action" value="register">

					<div class="form-group">
						<label for="">用户名</label> <input type="text" class="form-control"
							name="username" placeholder="请输入用户名" required>
					</div>

					<div class="form-group">
						<label for="">电子邮箱</label> <input type="email"
							class="form-control" name="email" placeholder="请输入电子邮箱地址"
							required>
					</div>

					<div class="form-group">
						<label for="">密码</label> <input type="password"
							class="form-control" name="password" placeholder="请输入密码" required>
					</div>

					<div class="form-group">
						<label for="">确认密码</label> <input type="password"
							class="form-control" name="password2" placeholder="请输入密码"
							required>
					</div>

					<div class="form-group">
						<label for="">验证码</label>
						<div class="row">
							<div class="col-md-9 col-sm-9 col-xs-8">
								<input type="text" class="form-control" name="captcha"
									placeholder="请输入验证码" required>
							</div>
							<div class="col-md-3 col-sm-3 col-xs-4">
								<img src="${ pageContext.request.contextPath }/captcha"
									class="img-responsive" alt="验证码加载失败">
							</div>
						</div>
					</div>
					<div class="form-group">
						<button type="submit" class="btn btn-block btn-primary">注册</button>
					</div>
				</form>
			</div>
		</div>
		
		<div class="row">
			<div
				style="background-color: rgba(248, 248, 248, 1); color: rgb(119, 119, 119); text-align: center;">
				<h2>一个人应该永远保持一点神秘感</h2>
				<h2>————王尔德</h2>
			</div>
		</div>
</body>

</html>