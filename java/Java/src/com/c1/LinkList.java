package com.c1;


/** 
* Javaʵ������Ǽ�,��ӽڵ� 
*  
* @author JavaGR_ais 
* 
*/  
public class LinkList {  

private Node headNode;//ͷ���  
private int listSize;//�����С(����ǰ�ڵ�ĸ���)  

// ��ȡ�����еĽڵ���  

public int getlistsize() {  

    return this.listSize;  
}  

// ��ӽڵ�  
public void addNode(int NodeValue) {  

    // ���û��ͷ���������½ڵ�Ϊͷ���  
    if (headNode == null) {  

        headNode = new Node(NodeValue, null);  
        listSize++;  
    }  
    // ��ͷ�������  
    else {  

        headNode = new Node(NodeValue, headNode);  
        listSize++;  

    }  
}  

  
//��ӡ��������  
public void prinAllLinkList(){  
    if (listSize != 0) {  
        for (Node node = headNode; node != null; node = node.NextNode()) {  
             System.out.println(node.getNodeValue());  
        }  
    }  
}  
public static void main(String[] args) {  
      
    LinkList ll = new LinkList();  
    ll.addNode(3);  
    ll.addNode(4);  
    ll.addNode(5);  
    ll.addNode(6);  
    ll.addNode(7);  
    ll.prinAllLinkList();  
}  
} 