package com.c1;

public class Node {  
	  
    private  int NodeValue;//�ڵ��ֵ  
    private  Node NextNode;//ָ����һ���ڵ������,��������������һ���ڵ�  
      
      
    //��ȡ��ǰ�����ֵ  
    public int getNodeValue(){  
          
        return this.NodeValue;  
    }  
      
    //��ȡ��һ���ڵ�  
    public Node NextNode(){  
          
        return this.NextNode;  
    }  
    public Node(int NodeValue,Node NextNode){  
          
        this.NextNode = NextNode;  
        this.NodeValue = NodeValue;  
    }  
    //��ȡ��ǰ�ڵ�  
    public Object getNode(){  
          
        return this.NodeValue;  
    }  
    //��ȡ��һ�ڵ�  
    public Object getNextNode(){  
          
        return this.NextNode;  
    }  
      
      
}  


