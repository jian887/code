package set;

import java.util.HashSet;

//重写equals,赋予两个对象相同的值
class A {
	public boolean equals(Object obj) {
		return true;
	}
}

//重写hashCode 返回一个hash地址  1
class B { 
	public int hashCode() {
		return 1;  
	}
}

class C {
	public int hashCode() {
		return 2;
	}

	public boolean equals(Object obj) {
		return true;
	}
}

public class HashSetTask_1 {

	public static void main(String[] args) {
		HashSet hashSet = new HashSet();
		hashSet.add(new A());
		hashSet.add(new A());
		hashSet.add(new B());
		hashSet.add(new B());
		hashSet.add(new C());
		hashSet.add(new C());
		System.out.println(hashSet);
	}
}
