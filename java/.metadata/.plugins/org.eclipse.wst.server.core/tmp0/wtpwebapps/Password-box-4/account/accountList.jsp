<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<%@ taglib prefix="c" uri="http://java.sun.com/jsp/jstl/core"%>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>账户列表</title>
    <link rel="stylesheet" href="${ pageContext.request.contextPath }/css/bootstrap.min.css">
    <link rel="stylesheet" href="${ pageContext.request.contextPath }/css/accountlist.css">
    <script src="${ pageContext.request.contextPath }/js/jquery-3.3.1.min.js"></script>
    <script src="${ pageContext.request.contextPath }/js/bootstrap.min.js"></script>
</head>

<body>

  <div class="container">
            <div class="row">
               
                <div class="navbar-header">
                    <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-ex1-collapse">
                        <span class="sr-only">Toggle navigation</span>
                        <span class="icon-bar"></span>
                        <span class="icon-bar"></span>
                        <span class="icon-bar"></span>
                    </button>
                    <a class="navbar-brand" href="${ pageContext.request.contextPath }">PasswordBox</a>
                </div>

                <div class="collapse navbar-collapse navbar-ex1-collapse">
                    <ul class="nav navbar-nav">
                        <li>
                            <a href="${ pageContext.request.contextPath }/account/addAccount.jsp">添加账号</a>
                        </li>
                        <li>
                            <a href="${ pageContext.request.contextPath }/user/info.jsp">个人信息</a>
                        </li>
                        <li>
                            <a href="${ pageContext.request.contextPath }/account?action=trashList">回收站</a>
                        </li>
                        <li>
                            <a href="${ pageContext.request.contextPath }/user?action=logout">注销</a>
                        </li>
                    </ul>
                </div>


            </div>
        </div>

    <div class="jumbotron" style="background: linear-gradient(rgba(0, 0, 0, 0),rgba(71, 179, 250, 0.555))">
        <div class="container">
            <h1>你好，${ user.username }</h1>
            <p>这是你第 ${ loginTotal } 次登录，上次登录时间：${ lastLoginDate }</p>
            <c:choose>
                <c:when test="${ isSecurity }">
                    <a class="btn btn-success" href="${ pageContext.request.contextPath }/user?action=updateSecurityQuestionUI" role="button">修改密保问题</a>
                </c:when>
                <c:otherwise>
                    <p class="text-danger">
                        你的账户存在风险：
                        <a class="btn btn-danger" href="${ pageContext.request.contextPath }/user/createSecurityQuestion.jsp" role="button">点我完善密保问题</a>
                    </p>
                </c:otherwise>
            </c:choose>
        </div>
    </div>

    <div class="container">

        <c:forEach var="account" items="${ accountList }">
            <div class="row">
                <div class="col-md-10 col-md-offset-1">
                    <div class="panel panel-default">
                        <div class="panel-heading">
                            <h3 class="panel-title">${ account.password }</h3>
                        </div>
                        <div class="panel-body">
                            <span>${ account.info }</span>
                            <br>
                            <div class="pull-right">
                                <a class="btn btn-danger" href="${ pageContext.request.contextPath }/account?action=trashAccount&id=${ account.id }" role="button">删除</a>
                                <a class="btn btn-success" href="${ pageContext.request.contextPath }/account?action=updateAccountUI&id=${ account.id }"
                                    role="button">更新</a>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </c:forEach>

    </div>
</body>

</html>