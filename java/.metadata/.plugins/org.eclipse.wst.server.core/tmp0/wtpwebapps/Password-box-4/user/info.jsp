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
    <link rel="stylesheet" href="${ pageContext.request.contextPath }/css/bootstrap.min.css">
    <link rel="stylesheet" href="${ pageContext.request.contextPath }/css/register.css">
    <script src="${ pageContext.request.contextPath }/js/jquery-3.3.1.min.js"></script>
    <script src="${ pageContext.request.contextPath }/js/bootstrap.min.js"></script>
</head>

<body>
    <div class="container">

        <div class="row">
            <div class="col-md-6 col-md-offset-3">
                <form action="${ pageContext.request.contextPath }/user" method="POST" role="form" class="register-form">
                    <legend>
                        <h1>个人信息</h1>
                    </legend>
                    <input type="hidden" name="action" value="updateInfo">

                    <div class="form-group">
                        <label for="">用户名</label>
                        <p>${ user.username }</p>
                    </div>

                    <div class="form-group">
                        <label for="">电子邮箱</label>
                        <input type="email" class="form-control" name="email" placeholder="请输入电子邮箱地址" value="${ user.email }" required>
                    </div>

                    <button type="submit" class="btn btn-primary pull-right">更新</button>
                </form>
            </div>
        </div>

        <div class="row">
            <div class="col-md-6 col-md-offset-3">
                <form action="${ pageContext.request.contextPath }/user" method="POST" role="form" class="register-form">
                    <legend>
                        <h1>修改密码</h1>
                    </legend>
                    <input type="hidden" name="action" value="updatePassword">

                    <div class="form-group">
                        <label for="">当前密码</label>
                        <input type="password" class="form-control" name="currentPassword" placeholder="当前密码" required>
                    </div>

                    <div class="form-group">
                        <label for="">新密码</label>
                        <input type="password" class="form-control" name="password" placeholder="新密码" required>
                    </div>

                    <div class="form-group">
                        <label for="">确认密码</label>
                        <input type="password" class="form-control" name="password2" placeholder="确认新密码" required>
                    </div>

                    <button type="submit" class="btn btn-primary pull-right">修改</button>
                </form>
            </div>
        </div>

    </div>
</body>

</html>