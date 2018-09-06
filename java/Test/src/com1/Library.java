package Library;
import java.util.Scanner;
public class Library {
     String num;
     String name;
     double zhuangtai;
   public void setNum(String num) {
	   this.num=num;
   }
   public void setName(String name) {
	   this.name=name;
   }
   public void setzhuangtai(double zhuangtai) {
	   this.zhuangtai=zhuangtai;
   }
   public void add() {
	int length = 0;
	int maxlength = 0;
	if(length < maxlength) {
		Score[] data = null;
		data[length] = new Score();
		System.out.print("请输入图书书号：");
		Scanner input = null;
		data[length].setNum(input.next());
		System.out.print("请输入图书书名：");
		Scanner input1 = null;
		data[length].setNum(input1.next());
		System.out.print("请输入图书状态：");
		Scanner input2 = null;
		data[length].setZhuangtai(input2.nextDouble());
		length++;
		System.out.println("添加成功");
	}   
   
   else {
	   System.out.println("添加失败");
   }
   }
   public void delete() {
	   System.out.println("请输入您要删除信息的图书的书号");
	   Scanner input = null;
	String number1 = input.next();
	   int length = 0;
	int i,flag = length;
	   for(i=0;i<length;i++) {
		   Object[] data = null;
		if(number1.equals(data[i])) {
			   flag = i;break;
		   }
	   }
	   if(i == length) {
		   System.out.println("查无此人！请核对后重新输入 \n");
		   delete();
	   }
	   else {
		   for(int j = flag;j < length;j++) {
			   Object[] data = null;
			data[j] = data[j + 1];
		   }
		   System.out.println("删除成功！\n");
		   length -= 1;
	   }
   }
   public void inquire() {
	   System.out.println("请输入您要查找的图书的书号");
	   Scanner input = null;
	String number2 = input.next();
	   int i;
	   int length = 0;
	for(i = 0;i < length;i++) {
		   Object[] data = null;
		if(number2.equals(data[i])) {
			   System.out.println("==============================");
			   System.out.println("书号");
			   System.out.println(data[i] + "\t"+data[i] + "\t" + data[i]+"\t");
			   System.out.println("==============================");
			   break;
		   }
	   }
	if(i == length) {
		System.out.println("查无此书！请核对书号后重新输入书号\n");
		inquire();
	}
   }
   @SuppressWarnings("null")
public void recompose() {
	   System.out.println("请输入您要修改的图书的状态");
	  Scanner input = null;
	String number3 = input.next();
	  int i;
	  int length = 0;
	for(i=0;i<length;i++) {
		  Object[] data = null;
		if(number3.equals(data[i])) {
			  System.out.println("请输入该图书的新的书号：");
			  ((Library) data[i]).setNum(input.next());
			  ((Library) data[i]).setName(input.next());
			  ((Score) data[i]).setZhuangtai(input.nextDouble());
			  System.out.println("修改成功！\n");
		  }
	  }
	if(i == length) {
		System.out.println("查无此书！请核对后重新输入书号\n");
		recompose();
	}
   }
}
