package t1;

import java.util.Scanner;


public class manage {
	books [] book=new books[50];
	int length=0;
	Scanner sc = new Scanner(System.in);
	void show(books book){
		System.out.println("图书编号："+book.number);
		System.out.println("图书名称："+book.name);
		System.out.println("图书状态："+book.type);
	}
	void browse(){
		if(length==0){
			System.out.println("还没有图书哦，请去添加");
		}else{
			System.out.println("图书信息依次如下：");
			for(int i=0;i<length;i++)  
			show(book[i]);
		}
		
	}
	void add(){
		books bk=new books();
		do{
			System.out.println("请输入信息：");
		    System.out.print("图书编号（必须是十位数）：");
		    bk.number=sc.next();
		}while(check(bk.number)==1||bk.number.length()!=10);
		System.out.print("书名：");
		bk.name=sc.next();
		System.out.print("状态：");
		bk.type="可借";
		book[length]=bk;
		length++;
	}
	int check(String a){
		for(int i=0;i<length;i++)
		    if(a.equals(book[i].number)){
		    	System.out.println("该图书编号已存在！");
		    	return 1;
		    }
		return 0;
	}
	void seek(){
		int c=0;
		System.out.println("请输入你要查找的信息的编号或者书名:"); 
		String m=sc.next();
		for(int i=0;i<length;i++){ //循环判断是长度
			if(m.equals(book[i].number)){              //如果和编号相等
				System.out.println("查找信息如下："); 
				show(book[i]);
				c=1;
		    }
			if(m.equals(book[i].name)){              //如果和书名相等
				System.out.println("查找信息如下："); 
				show(book[i]);
				c=1;
			}
		}
		if(c==0)
			System.out.println("不存在");
	}
	void del(){
		int c=0;
		System.out.println("请输入你要删除的信息的编号或者书名:"); 
		String m=sc.next();
		for(int i=0;i<length;i++){ //循环判断是长度
			if(m.equals(book[i].number)){                 //如果和编号相等
				System.out.print("这被你删除的图书的信息：");
				show(book[i]);
				System.out.print("已经删除成功");
				c=1;
				for(int j=i+1;j<length;j++){
					book[i]=book[i+1];
				}
				length--;
			}
			if(m.equals(book[i].name)){                 //如果和书名相等
				System.out.print("这被你删除的图书的信息：");
				show(book[i]);
				System.out.print("已经删除成功");
				c=1;
				for(int j=i+1;j<length;j++){
					book[i]=book[i+1];	
				}
				length--;
		    }
		}
		if(c==0)
			System.out.println("不存在");
	}
	void rent(){
		int c=0;           //搜索提示
		int a=0;           //继续判断
		do{
			System.out.println("请输入借的图书的编号：");
			String m=sc.next();
			for(int i=0;i<length;i++){       //循环判断是长度
				if(m.equals(book[i].number)){       //如果和编号相等
					System.out.println("此为您借出的图书的信息：");
					show(book[i]);
					book[i].type="借出";
					c=1;
				}
			}
			if(c==0)
				System.out.println("不存在该教室");
		    System.out.println("要继续借书吗？");
		    System.out.println("1.yes   0.no");
		    System.out.println("请输入你的选择：");
		    a=sc.nextInt();    
		}while(a==1);
		System.out.println("感谢您的使用，请好好爱护书籍哦");
	}
	void back(){
		int c=0;           //搜索提示
		int a=0;           //继续判断
		do{
			System.out.println("请输入归还图书的编号：");
			String m=sc.next();
			for(int i=0;i<length;i++){       //循环判断是长度
				if(m.equals(book[i].number)){       //如果和编号相等
					System.out.println("此为您归还的图书的信息：");
					show(book[i]);
					book[i].type="可借";
					c=1;
				}
			}
			if(c==0)
				System.out.println("不存在该教室");
		    System.out.println("要继续归还吗？");
		    System.out.println("1.yes   0.no");
		    System.out.println("请输入你的选择：");
		    a=sc.nextInt();    
		}while(a==1);
		System.out.println("感谢您的归还");
	}
	
	
}
