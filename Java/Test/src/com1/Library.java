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
		System.out.print("������ͼ����ţ�");
		Scanner input = null;
		data[length].setNum(input.next());
		System.out.print("������ͼ��������");
		Scanner input1 = null;
		data[length].setNum(input1.next());
		System.out.print("������ͼ��״̬��");
		Scanner input2 = null;
		data[length].setZhuangtai(input2.nextDouble());
		length++;
		System.out.println("��ӳɹ�");
	}   
   
   else {
	   System.out.println("���ʧ��");
   }
   }
   public void delete() {
	   System.out.println("��������Ҫɾ����Ϣ��ͼ������");
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
		   System.out.println("���޴��ˣ���˶Ժ��������� \n");
		   delete();
	   }
	   else {
		   for(int j = flag;j < length;j++) {
			   Object[] data = null;
			data[j] = data[j + 1];
		   }
		   System.out.println("ɾ���ɹ���\n");
		   length -= 1;
	   }
   }
   public void inquire() {
	   System.out.println("��������Ҫ���ҵ�ͼ������");
	   Scanner input = null;
	String number2 = input.next();
	   int i;
	   int length = 0;
	for(i = 0;i < length;i++) {
		   Object[] data = null;
		if(number2.equals(data[i])) {
			   System.out.println("==============================");
			   System.out.println("���");
			   System.out.println(data[i] + "\t"+data[i] + "\t" + data[i]+"\t");
			   System.out.println("==============================");
			   break;
		   }
	   }
	if(i == length) {
		System.out.println("���޴��飡��˶���ź������������\n");
		inquire();
	}
   }
   @SuppressWarnings("null")
public void recompose() {
	   System.out.println("��������Ҫ�޸ĵ�ͼ���״̬");
	  Scanner input = null;
	String number3 = input.next();
	  int i;
	  int length = 0;
	for(i=0;i<length;i++) {
		  Object[] data = null;
		if(number3.equals(data[i])) {
			  System.out.println("�������ͼ����µ���ţ�");
			  ((Library) data[i]).setNum(input.next());
			  ((Library) data[i]).setName(input.next());
			  ((Score) data[i]).setZhuangtai(input.nextDouble());
			  System.out.println("�޸ĳɹ���\n");
		  }
	  }
	if(i == length) {
		System.out.println("���޴��飡��˶Ժ������������\n");
		recompose();
	}
   }
}
