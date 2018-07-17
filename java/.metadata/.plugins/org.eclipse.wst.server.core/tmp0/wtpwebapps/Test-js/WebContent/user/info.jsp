<%@page import="cn.jerryshell.util.GenerateCaptcha"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html lang="en">

<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<meta http-equiv="X-UA-Compatible" content="ie=edge">
<title>个人信息</title>
<link rel="stylesheet"
	href="${ pageContext.request.contextPath }/css/bootstrap.min.css">
<link rel="stylesheet"
	href="${ pageContext.request.contextPath }/css/info.css">
<script
	src="${ pageContext.request.contextPath }/js/jquery-3.3.1.min.js"></script>
<script src="${ pageContext.request.contextPath }/js/bootstrap.min.js"></script>
</head>

<body>

	<div class="container">
	
		<div class="row">
			<nav class="navbar navbar-inverse navbar-fixed-top" role="navigation">
				<div class="container">
					<div class="navbar-header">
						<button type="button" class="navbar-toggle" data-toggle="collapse"
							data-target=".navbar-ex1-collapse">
							<span class="sr-only">Toggle navigation</span> <span
								class="icon-bar"></span> <span class="icon-bar"></span> <span
								class="icon-bar"></span>
						</button>
						<a class="navbar-brand"
							href="${ pageContext.request.contextPath }/user/login.jsp"><span
							class="glyphicon glyphicon-briefcase"> </span> 超级密码箱</a>
					</div>
					<div class="collapse navbar-collapse navbar-ex1-collapse">
						<ul class="nav navbar-nav">
							<li><a
								href="${ pageContext.request.contextPath }/account/accountList.jsp"><span
									class="glyphicon glyphicon-list"></span> 账号列表</a></li>
							<li><a
								href="${ pageContext.request.contextPath }/account/addAccount.jsp"><span
									class="glyphicon glyphicon-edit"></span> 添加账号</a></li>
							<li><a
								href="${ pageContext.request.contextPath }/account?action=trashList"><span
									class="glyphicon glyphicon-trash"></span> 回收站</a></li>
							<li><a
								href="${ pageContext.request.contextPath }/user/info.jsp"><span
									class="glyphicon glyphicon-info-sign"></span> 个人信息</a></li>
						</ul>
						<ul class="nav navbar-nav navbar-right">
							<li><a
								href="${ pageContext.request.contextPath }/user?action=logout"><span
									class="glyphicon glyphicon-log-out"></span> 登出</a></li>
						</ul>
					</div>
				</div>
			</nav>
		</div>
		
		<div class="row">
			<div class="col-md-6 col-md-offset-3">
				<form action="${ pageContext.request.contextPath }/user"
					method="POST" role="form" class="info-form">
					<legend>
						<h1>个人信息</h1>
					</legend>
					<input type="hidden" name="action" value="updateInfo">

					<div class="form-group">
						<label for="">用户名</label>
						<p>${ user.username }</p>
					</div>

					<div class="form-group">
						<label for="">电子邮箱</label> <input type="email"
							class="form-control" name="email" placeholder="请输入电子邮箱地址"
							value="${ user.email }" required>
					</div>
					<button type="submit" class="btn btn-primary btn-block">更新</button>
				</form>
			</div>
		</div>

		<div class="row">
			<div class="col-md-6 col-md-offset-3">
				<form action="${ pageContext.request.contextPath }/user"
					method="POST" role="form" class="info-form">
					<legend>
						<h1>修改密码</h1>
					</legend>
					<input type="hidden" name="action" value="updatePassword">

					<div class="form-group">
						<label for="">当前密码</label> <input type="password"
							class="form-control" name="currentPassword" placeholder="当前密码"
							required>
					</div>

					<div class="form-group">
						<label for="">新密码</label> <input type="password"
							class="form-control" name="password" placeholder="新密码" required>
					</div>

					<div class="form-group">
						<label for="">确认密码</label> <input type="password"
							class="form-control" name="password2" placeholder="确认新密码"
							required>
					</div>

					<button type="submit" class="btn btn-primary btn-block">修改</button>
				</form>
			</div>
		</div>
		
		<div class="row">
			<div
				style="background-color: rgba(248, 248, 248, 1); color: rgb(119, 119, 119); text-align: center;">
				<h2>有时保守秘密最好的方法或许是对它是秘密这一事实保密。</h2>
				<h2>————亨利·泰勒</h2>
			</div>

		</div>
</body>

</html>