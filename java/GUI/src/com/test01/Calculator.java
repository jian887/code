package com.test01;

import java.awt.BorderLayout;  
import java.awt.GridLayout;  
import java.awt.event.MouseEvent;  
import java.awt.event.MouseListener;  
import java.text.DecimalFormat;  
  
import javax.swing.JButton;  
import javax.swing.JFrame;  
import javax.swing.JPanel;  
import javax.swing.JTextField;  
  
  
  
public class Calculator {  
    //计算器面板  
 private JFrame f = new JFrame("我的计算器");  
   
 //输入面扳  
 private JPanel inputPanel = new JPanel();  
 //加减乘除面板  
 private JPanel operationPanel = new JPanel();  
 //数字面板  
 private JPanel buttonsPanel = new JPanel();  
   
 //输入数据文本框  
 private JTextField input = new JTextField(20);  
   
 //退格键  
 private JButton backspace = new JButton("BackSpace");  
 //清空  
 private JButton CE = new JButton("CE  ");  
 //删除  
 private JButton C = new JButton("C  ");  
   
 //四则运算符号键  
 private JButton add = new JButton("+");  
 private JButton sub = new JButton("-");  
 private JButton mul = new JButton("*");  
 private JButton div = new JButton("/");  
   
 //小数点  
 private JButton decimal = new JButton(".");  
 //等号  
 private JButton equal = new JButton("=");  
   
 //数字键  
 private JButton zero = new JButton("0");  
 private JButton one = new JButton("1");  
 private JButton two = new JButton("2");  
 private JButton three = new JButton("3");  
 private JButton four = new JButton("4");  
 private JButton five = new JButton("5");  
 private JButton six = new JButton("6");  
 private JButton seven = new JButton("7");  
 private JButton eight = new JButton("8");  
 private JButton nine = new JButton("9");  
   
 private String num1 = "";//保存第一个运算数字  
 private String operator = "";//保存运算符号  
   
 public static void main(String[] args) {  
  new Calculator();//new计算器实例  
 }  
   
 public Calculator(){  
      //添加组件，布局  
  inputPanel.add(input);  
  f.add(inputPanel, BorderLayout.NORTH);  
    
  operationPanel.add(backspace);  
  operationPanel.add(CE);  
  operationPanel.add(C);  
  f.add(operationPanel, BorderLayout.CENTER);  
    
  buttonsPanel.add(add);  
  buttonsPanel.add(sub);  
  buttonsPanel.add(mul);  
  buttonsPanel.add(div);  
  buttonsPanel.add(one);  
  buttonsPanel.add(two);  
  buttonsPanel.add(three);  
  buttonsPanel.add(zero);  
  buttonsPanel.add(four);  
  buttonsPanel.add(five);  
  buttonsPanel.add(six);  
  buttonsPanel.add(decimal);  
  buttonsPanel.add(seven);  
  buttonsPanel.add(eight);  
  buttonsPanel.add(nine);  
  buttonsPanel.add(equal);  
  buttonsPanel.setLayout(new GridLayout(4, 4));  
  f.add(buttonsPanel, BorderLayout.SOUTH);  
    
  //注册各个组件监听事件  
  backspace.addMouseListener(new OperationMouseListener());  
  CE.addMouseListener(new OperationMouseListener());  
  C.addMouseListener(new OperationMouseListener());  
  decimal.addMouseListener(new OperationMouseListener());  
  equal.addMouseListener(new OperationMouseListener());  
    
  //注册四则运算监听  
  add.addMouseListener(new CalcMouseListener());  
  sub.addMouseListener(new CalcMouseListener());  
  mul.addMouseListener(new CalcMouseListener());  
  div.addMouseListener(new CalcMouseListener());  
    
  //注册数字监听事件  
  zero.addMouseListener(new NumberMouseListener());  
  one.addMouseListener(new NumberMouseListener());  
  two.addMouseListener(new NumberMouseListener());  
  three.addMouseListener(new NumberMouseListener());  
  four.addMouseListener(new NumberMouseListener());  
  five.addMouseListener(new NumberMouseListener());  
  six.addMouseListener(new NumberMouseListener());  
  seven.addMouseListener(new NumberMouseListener());  
  eight.addMouseListener(new NumberMouseListener());  
  nine.addMouseListener(new NumberMouseListener());  
    
  f.setVisible(true);  
  f.pack();  
  f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);  
 }  
   
 private class NumberMouseListener implements MouseListener{  
  
  public void mouseClicked(MouseEvent e) {  
   if(input.getText().trim().equals("0")){//如果文本框已经是0，结果还是0  
    input.setText(((JButton)e.getSource()).getText().trim());  
   }else{//否则的话，把0添加到后面，譬如文本框是1，结果就为10  
    input.setText(input.getText().concat(((JButton)e.getSource()).getText().trim()));  
   }  
  }  
  
  public void mouseEntered(MouseEvent e) {}  
  public void mouseExited(MouseEvent e) {}  
  public void mousePressed(MouseEvent e) {}  
  public void mouseReleased(MouseEvent e) {}   
 }  
   
 private class CalcMouseListener implements MouseListener{  
  //如果输入的是运算符号，保存第一个结果和运算符号  
  public void mouseClicked(MouseEvent e) {  
   num1 = input.getText().trim();input.setText("");  
   operator = ((JButton)e.getSource()).getText().trim();  
  }  
  
  public void mouseEntered(MouseEvent e) {}  
  public void mouseExited(MouseEvent e) {}  
  public void mousePressed(MouseEvent e) {}  
  public void mouseReleased(MouseEvent e) {}   
 }  
   
 private class OperationMouseListener implements MouseListener{  
  
  public void mouseClicked(MouseEvent e) {  
   if(e.getSource() == backspace){//退格键，删除一个直到没有字符删除  
    String inputText = input.getText();  
    if(inputText.length() > 0){  
     input.setText(inputText.substring(0, inputText.length() - 1));  
    }  
   }else if(e.getSource() == C){  
    input.setText("0");//C，清空所有运算数字和符号  
    num1 = "";  
   }else if(e.getSource() == CE){  
    input.setText("0");//CE-->将文本框置为0  
   }else if(e.getSource() == decimal){  
    String text = input.getText().trim();  
    //如果按了小数点，如果文本框已经有小数点，不做任何操作，否则在结果后面加上小数点  
    if(text.indexOf(".") == -1){  
     input.setText(text.concat("."));  
    }  
   }else if(e.getSource() == equal){  
    //如果是等号  
    if(!operator.trim().equals("")){  
     if(!input.getText().trim().equals("")){  
      double result = 0D;  
      if(operator.equals("+")){//执行加法运算  
       result = Double.parseDouble(num1) + Double.parseDouble(input.getText().trim());  
      }else if(operator.equals("-")){//减法运算  
       result = Double.parseDouble(num1) - Double.parseDouble(input.getText().trim());  
      }else if(operator.equals("*")){//乘法运算  
       result = Double.parseDouble(num1) * Double.parseDouble(input.getText().trim());  
      }else if(operator.equals("/")){//除法运算  
       result = Double.parseDouble(num1) / Double.parseDouble(input.getText().trim());  
      }  
         
       //格式化最终结果，保留两位小数点  
      input.setText(new DecimalFormat("0.00").format(result));  
     }  
    }  
      
   }  
     
  }  
  
  public void mouseEntered(MouseEvent e) {}  
  public void mouseExited(MouseEvent e) {}  
  public void mousePressed(MouseEvent e) {}  
  public void mouseReleased(MouseEvent e) {}   
 }  
   
}  