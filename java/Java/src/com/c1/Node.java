package com.c1;

public class Node {  
	  
    private  int NodeValue;//节点的值  
    private  Node NextNode;//指向下一个节点的引用,即保存了整个下一个节点  
      
      
    //获取当前对象的值  
    public int getNodeValue(){  
          
        return this.NodeValue;  
    }  
      
    //获取下一个节点  
    public Node NextNode(){  
          
        return this.NextNode;  
    }  
    public Node(int NodeValue,Node NextNode){  
          
        this.NextNode = NextNode;  
        this.NodeValue = NodeValue;  
    }  
    //获取当前节点  
    public Object getNode(){  
          
        return this.NodeValue;  
    }  
    //获取下一节点  
    public Object getNextNode(){  
          
        return this.NextNode;  
    }  
      
      
}  


