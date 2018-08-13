package set;

import java.util.HashSet;
import java.util.Iterator;

public class HashSetTask_2 {
	
	public static void main(String[] args) {
		HashSet hashSet = new HashSet();
		hashSet.add(12);
		System.out.println(hashSet);
		
		hashSet.add(23.4);
		System.out.println(hashSet);
		
		hashSet.add('e');
		System.out.println(hashSet);
		
		hashSet.add("ere");
		System.out.println(hashSet);	
	}
}
