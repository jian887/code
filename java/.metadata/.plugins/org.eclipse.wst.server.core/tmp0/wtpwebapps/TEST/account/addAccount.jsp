<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>添加账号</title>
    <link rel="stylesheet" href="${ pageContext.request.contextPath }/css/bootstrap.min.css">
    <link rel="stylesheet" href="${ pageContext.request.contextPath }/css/addaccount.css">
    <script src="${ pageContext.request.contextPath }/js/jquery-3.3.1.min.js"></script>
    <script src="${ pageContext.request.contextPath }/js/bootstrap.min.js"></script>
</head>

<body>
    <div class="container">

        <div class="row">
            <div class="col-md-6 col-md-offset-3">
                <form action="${ pageContext.request.contextPath }/account" method="POST" role="form" class="addaccount-form">
                    <legend>
                        <h1>添加账号</h1>
                    </legend>
                    <input type="hidden" name="action" value="addAccount">

                    <div class="form-group">
                        <label for="">账号密码</label>
                        <input type="text" class="form-control" name="password" placeholder="请输入账号密码" required>
                    </div>

                    <div class="form-group">
                        <label for="">账号信息</label>
                        <textarea name="info" class="form-control" rows="3" required="required" required></textarea>
                    </div>

                    <button type="submit" class="btn btn-primary pull-right">添加账号</button>
                </form>

            </div>
        </div>

    </div>
</body>

</html>