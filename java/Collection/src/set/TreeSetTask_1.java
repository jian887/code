package set;

import java.util.TreeSet;

public class TreeSetTask_1 {
	public static void main(String[] args) {
		TreeSet<Integer> num = new TreeSet<Integer>();
		num.add(3);
		num.add(-5);
		num.add(8);
		num.add(5);
		num.add(2);
		System.out.println(num);
		System.out.println(num.first());
		System.out.println(num.last());
		System.out.println(num.headSet(4));
		System.out.println(num.tailSet(5));
		System.out.println(num.subSet(2, 9));
		System.out.println(num.headSet(4, true));
		System.out.println(num.headSet(4, false));
		
		
		
	}

}
