<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html lang="en">

<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<meta http-equiv="X-UA-Compatible" content="ie=edge">
<title>重置密码</title>
<link rel="stylesheet"
	href="${ pageContext.request.contextPath }/css/bootstrap.min.css">
<link rel="stylesheet"
	href="${ pageContext.request.contextPath }/css/resetpasswordstepx.css">
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
						<a class="navbar-brand"
							href="${ pageContext.request.contextPath }/user/login.jsp"">
							<span class="glyphicon glyphicon-briefcase"> </span> 超级密码箱
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
					method="POST" role="form" class="resetpasswordstepx-form">
					<legend>
						<h1>重置密码</h1>
					</legend>
					<input type="hidden" name="action" value="resetPasswordStep3">

					<div class="form-group">
						<label for="">新密码</label> <input type="password"
							class="form-control" name="password" placeholder="请输入新密码"
							required>
					</div>

					<div class="form-group">
						<label for="">确认密码</label> <input type="password"
							class="form-control" name="password2" placeholder="请输入确认密码"
							required>
					</div>

					<button type="submit" class="btn btn-primary btn-block">重置密码</button>
				</form>
			</div>
		</div>

	</div>
</body>

</html>