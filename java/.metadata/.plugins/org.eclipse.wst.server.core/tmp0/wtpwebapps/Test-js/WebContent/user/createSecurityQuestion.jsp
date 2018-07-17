<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html lang="en">

<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<meta http-equiv="X-UA-Compatible" content="ie=edge">
<title>设置密保问题</title>
<link rel="stylesheet"
	href="${ pageContext.request.contextPath }/css/bootstrap.min.css">
<link rel="stylesheet"
	href="${ pageContext.request.contextPath }/css/createsecurityquestion.css">
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
							class="glyphicon glyphicon-briefcase"></span> 超级密码箱</a>
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
					method="POST" role="form" class="createsecurityquestion-form">
					<legend>
						<h1>设置密保问题</h1>
					</legend>
					<input type="hidden" name="action" value="createSecurityQuestion">
					<div class="form-group">
						<label for="">问题</label> <input type="text" class="form-control"
							name="question" placeholder="请输入问题" required>
					</div>
					<div class="form-group">
						<label for="">答案</label> <input type="text" class="form-control"
							name="answer" placeholder="请输入答案" required>
					</div>
					<button type="submit" class="btn btn-primary btn-block">设置</button>
				</form>
			</div>
		</div>
	</div>
	
</body>

</html>