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
    <title>登录</title>
    <link rel="stylesheet" href="${ pageContext.request.contextPath }/css/bootstrap.min.css">
    <link rel="stylesheet" href="${ pageContext.request.contextPath }/css/login.css">
    <script src="${ pageContext.request.contextPath }/js/jquery-3.3.1.min.js"></script>
    <script src="${ pageContext.request.contextPath }/js/bootstrap.min.js"></script>
</head>

<body>
    <div class="container">

        <div class="row">
            <div class="col-md-6 col-md-offset-3">
                <form action="${ pageContext.request.contextPath }/user" method="POST" role="form" class="login-form">
                    <legend>
                        <h1>登录</h1>
                    </legend>
                    <input type="hidden" name="action" value="login">

                    <div class="form-group">
                        <label for="">用户名</label>
                        <input type="text" class="form-control" name="username" placeholder="请输入用户名">
                    </div>

                    <div class="form-group">
                        <label for="">密码</label>
                        <input type="password" class="form-control" name="password" placeholder="请输入密码">
                    </div>
                    
                    <div class="form-group">
                        <label for="">验证码</label>
                        <div class="row">
                            <div class="col-md-9">
                                <input type="text" class="form-control" name="captcha" placeholder="请输入验证码">
                            </div>
                            <div class="col-md-3">
                                <img src="${ pageContext.request.contextPath }/captcha" class="img-responsive" alt="验证码加载失败">
                            </div>
                        </div>
                    </div>

					<a class="btn btn-success" href="${ pageContext.request.contextPath }/user/register.jsp" role="button">注册</a>
					<a class="btn btn-link" href="${ pageContext.request.contextPath }/user/resetPasswordStep1.jsp" role="button">忘记密码？</a>
                    <button type="submit" class="btn btn-primary pull-right">登录</button>
                </form>

            </div>
        </div>

    </div>
</body>

</html>