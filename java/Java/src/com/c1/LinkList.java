package com.c1;


/** 
* Java实现链表骨架,添加节点 
*  
* @author JavaGR_ais 
* 
*/  
public class LinkList {  

private Node headNode;//头结点  
private int listSize;//链表大小(即当前节点的个数)  

// 获取链表中的节点数  

public int getlistsize() {  

    return this.listSize;  
}  

// 添加节点  
public void addNode(int NodeValue) {  

    // 如果没有头结点则添加新节点为头结点  
    if (headNode == null) {  

        headNode = new Node(NodeValue, null);  
        listSize++;  
    }  
    // 有头结点的情况  
    else {  

        headNode = new Node(NodeValue, headNode);  
        listSize++;  

    }  
}  

  
//打印整个链表  
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