package com.c;

public class LinkList {
	int data;
	LinkList next; 
	
	public LinkList(int data) {
		this.data=data;
	}
	
	public LinkList add(LinkList next) {
		LinkList rear = null;
		LinkList point;
		point = next;
		for(int i = 0 ;i<4;i++) {
			point.data=i;
			point=next.next;
		}
		point.next=rear;
		return next;
	}
	
	public void show(LinkList next) {
		LinkList tall =next.next;
		while (tall.next!=null) {
			System.out.println(tall.data);
			tall=tall.next;
		}
	}
	public static void main(String[] args) {
		LinkList linklist = new LinkList(1);
		linklist.add(next);
		linklist.show(next);
		
	}

}
