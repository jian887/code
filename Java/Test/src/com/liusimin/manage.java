package t1;

import java.util.Scanner;


public class manage {
	books [] book=new books[50];
	int length=0;
	Scanner sc = new Scanner(System.in);
	void show(books book){
		System.out.println("ͼ���ţ�"+book.number);
		System.out.println("ͼ�����ƣ�"+book.name);
		System.out.println("ͼ��״̬��"+book.type);
	}
	void browse(){
		if(length==0){
			System.out.println("��û��ͼ��Ŷ����ȥ���");
		}else{
			System.out.println("ͼ����Ϣ�������£�");
			for(int i=0;i<length;i++)  
			show(book[i]);
		}
		
	}
	void add(){
		books bk=new books();
		do{
			System.out.println("��������Ϣ��");
		    System.out.print("ͼ���ţ�������ʮλ������");
		    bk.number=sc.next();
		}while(check(bk.number)==1||bk.number.length()!=10);
		System.out.print("������");
		bk.name=sc.next();
		System.out.print("״̬��");
		bk.type="�ɽ�";
		book[length]=bk;
		length++;
	}
	int check(String a){
		for(int i=0;i<length;i++)
		    if(a.equals(book[i].number)){
		    	System.out.println("��ͼ�����Ѵ��ڣ�");
		    	return 1;
		    }
		return 0;
	}
	void seek(){
		int c=0;
		System.out.println("��������Ҫ���ҵ���Ϣ�ı�Ż�������:"); 
		String m=sc.next();
		for(int i=0;i<length;i++){ //ѭ���ж��ǳ���
			if(m.equals(book[i].number)){              //����ͱ�����
				System.out.println("������Ϣ���£�"); 
				show(book[i]);
				c=1;
		    }
			if(m.equals(book[i].name)){              //������������
				System.out.println("������Ϣ���£�"); 
				show(book[i]);
				c=1;
			}
		}
		if(c==0)
			System.out.println("������");
	}
	void del(){
		int c=0;
		System.out.println("��������Ҫɾ������Ϣ�ı�Ż�������:"); 
		String m=sc.next();
		for(int i=0;i<length;i++){ //ѭ���ж��ǳ���
			if(m.equals(book[i].number)){                 //����ͱ�����
				System.out.print("�ⱻ��ɾ����ͼ�����Ϣ��");
				show(book[i]);
				System.out.print("�Ѿ�ɾ���ɹ�");
				c=1;
				for(int j=i+1;j<length;j++){
					book[i]=book[i+1];
				}
				length--;
			}
			if(m.equals(book[i].name)){                 //������������
				System.out.print("�ⱻ��ɾ����ͼ�����Ϣ��");
				show(book[i]);
				System.out.print("�Ѿ�ɾ���ɹ�");
				c=1;
				for(int j=i+1;j<length;j++){
					book[i]=book[i+1];	
				}
				length--;
		    }
		}
		if(c==0)
			System.out.println("������");
	}
	void rent(){
		int c=0;           //������ʾ
		int a=0;           //�����ж�
		do{
			System.out.println("��������ͼ��ı�ţ�");
			String m=sc.next();
			for(int i=0;i<length;i++){       //ѭ���ж��ǳ���
				if(m.equals(book[i].number)){       //����ͱ�����
					System.out.println("��Ϊ�������ͼ�����Ϣ��");
					show(book[i]);
					book[i].type="���";
					c=1;
				}
			}
			if(c==0)
				System.out.println("�����ڸý���");
		    System.out.println("Ҫ����������");
		    System.out.println("1.yes   0.no");
		    System.out.println("���������ѡ��");
		    a=sc.nextInt();    
		}while(a==1);
		System.out.println("��л����ʹ�ã���úð����鼮Ŷ");
	}
	void back(){
		int c=0;           //������ʾ
		int a=0;           //�����ж�
		do{
			System.out.println("������黹ͼ��ı�ţ�");
			String m=sc.next();
			for(int i=0;i<length;i++){       //ѭ���ж��ǳ���
				if(m.equals(book[i].number)){       //����ͱ�����
					System.out.println("��Ϊ���黹��ͼ�����Ϣ��");
					show(book[i]);
					book[i].type="�ɽ�";
					c=1;
				}
			}
			if(c==0)
				System.out.println("�����ڸý���");
		    System.out.println("Ҫ�����黹��");
		    System.out.println("1.yes   0.no");
		    System.out.println("���������ѡ��");
		    a=sc.nextInt();    
		}while(a==1);
		System.out.println("��л���Ĺ黹");
	}
	
	
}
