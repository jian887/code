<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html lang="en">

<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<meta http-equiv="X-UA-Compatible" content="ie=edge">
<title>更新账号</title>
<link rel="stylesheet"
	href="${ pageContext.request.contextPath }/css/bootstrap.min.css">
<link rel="stylesheet"
	href="${ pageContext.request.contextPath }/css/updateaccount.css">
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
				<form action="${ pageContext.request.contextPath }/account"
					method="POST" role="form" class="updateaccount-form">
					<legend>
						<h1>更新账号</h1>
					</legend>
					<input type="hidden" name="action" value="updateAccount"> <input
						type="hidden" name="id" value="${ account.id }"> <input
						type="hidden" name="status" value="${ account.status }">

					<div class="form-group">
						<label for="">账号密码</label> <input type="text" class="form-control"
							name="password" placeholder="请输入账号密码"
							value="${ account.password }" required>
					</div>
					<div class="form-group">
						<label for="">账号信息</label>
						<textarea name="info" class="form-control" rows="3"
							required="required" required>${ account.info }</textarea>
					</div>
					<button type="submit" class="btn btn-primary btn-block">更新账号</button>
				</form>
			</div>
		</div>

	</div>
</body>

</html>