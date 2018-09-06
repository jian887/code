package set;

import java.util.HashSet;
import java.util.Random;
import java.util.Scanner;

class R implements Comparable
{
	public
}

public class HashSetTask_Search {
	
	
	

	
	public static void main(String[] args) {
		
		HashSet<Integer> hashSet = new HashSet<Integer>(); 
		Scanner sc = new Scanner(System.in);
		System.out.println("请输入生成的数据量");
		int s = sc.nextInt();
		
		for(int i = 0 ; i<s ;i++)
		{
			int x = new Random().nextInt(1000-34)+34;
			hashSet.add(new R(x));
		}
		
		System.out.println(hashSet);
		
		System.out.println("请输入需要查找的数字");
		int numSearch = sc.nextInt();
		
		
	}

}
