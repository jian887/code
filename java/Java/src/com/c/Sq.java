package com.c;

public class Sq {
	
	public Link add () {
		Link head = new Link();
		Link p;
		head.next = null;
		for( int i = 0 ; i<3 ;i++) {
			p = new Link();
			p.data = i;
			head.next = p;
			p = p.next;	
			//System.out.println(p.data);
		}
		return head;
	}
	
	public void Print(Link hea) {
		Link tail = new Link();
		tail = hea.next;
		while ( tail.next != null) {
			System.out.println(tail.data);
			tail = tail.next;
		}
		
		
	}
	
	
	public static void main(String[] args) {
		Sq l = new Sq();
		Link hea = new Link();
	    hea = l.add();
	    l.Print(hea);
		System.out.println();
	}

}
