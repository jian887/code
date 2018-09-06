package com.e;

public class ExceptionTest {

    public static void execute(String a) throws MyeException {
        System.out.println("execute...");
        if("true".equals(a)){
            throw new MyeException("参数不能为 true");
        }
    }
    
    public static void main(String[] args) throws MyeException {

        execute("true");
    }
}
