<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>设置密保问题</title>
    <link rel="stylesheet" href="${ pageContext.request.contextPath }/css/bootstrap.min.css">
    <link rel="stylesheet" href="${ pageContext.request.contextPath }/css/addaccount.css">
    <script src="${ pageContext.request.contextPath }/js/jquery-3.3.1.min.js"></script>
    <script src="${ pageContext.request.contextPath }/js/bootstrap.min.js"></script>
</head>

<body>
    <div class="container">

        <div class="row">
            <div class="col-md-6 col-md-offset-3">
                <form action="${ pageContext.request.contextPath }/user" method="POST" role="form" class="addaccount-form">
                    <legend>
                        <h1>设置密保问题</h1>
                    </legend>
                    <input type="hidden" name="action" value="createSecurityQuestion">

                    <div class="form-group">
                        <label for="">问题</label>
                        <input type="text" class="form-control" name="question" placeholder="请输入问题">
                    </div>

                    <div class="form-group">
                        <label for="">答案</label>
                        <input type="text" class="form-control" name="answer" placeholder="请输入答案">
                    </div>

                    <button type="submit" class="btn btn-primary pull-right">设置</button>
                </form>

            </div>
        </div>

    </div>
</body>

</html>