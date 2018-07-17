package com.c;


public class A<E> {          //使用泛型是为了使用时候可以规范链表的数据类型
    // 结点内部类
    private class Node {
        private Object data;                  //数据
        private Node next = null;          //指向下个结点的引用

        public Node() {                         //无参数构造函数为了创建头结点服务
            data = null;
        }

        public Node(E data) {                //带数据的构造函数
            this.data = data;
        }

    }

    private Node head;               // 头引用（指针）
    private Node rear;                // 尾引用（指针）
    private Node point;              //临时引用（指针）
    private int length;                 // 链表长度

    public A() {                  //链表构造函数，创建无数据的头结点
        head = new Node();     
        rear = head;
        length = 0;
    }

    /**
     * 从尾部插入链表
     * 
     */
    public void add(E elem) {
        point = new Node(elem);
        rear.next = point;
        rear = point;
        length++;

    }

    /**
     * 遍历输出链表
     */
    public void traverse() {
        point = head;            //移动临时引用到头结点
        if (head != null)
            System.out.print("[" + head.data + "]");
        while (point.next != null) {
            System.out.print("-➜[" + point.next.data + "]");
            point = point.next;
        }
        System.out.println();
    }

    /**
     * 获得链表长度
     * 
     */
    public int length() {
        return length;
    }

    /**
     * 清除链表内容
         * （java垃圾回收，当对象没有引用指向，则视为垃圾，清理时机由系统决定）
     */
    public void clear() {               
        while (head.next != null) {
            head.next = head.next.next;
        }
        rear = head;      // 回到初始状态
        point = null;
        length = 0;
        System.gc();      //请求系统清理垃圾，未必有用
    }

    /**
     * 在指定个位置插入元素成为第p个元素
     */
    public void insert(int position, E elem) {
                if(position>=0 && position<=length){
            point = movePoint(position);
            Node tmp = new Node(elem);
            tmp.next = point.next;
            point.next = tmp;
            length++;
               }else{
                    System.out.println("没有指定位置，插入失败");
               }

    }

    /**
     * 删除指定位置的元素
     */
    public void remove(int position) {
        if (position >= 0 && position < length) {
            point = movePoint(position);
            Node tmp = point.next;
            point.next = tmp.next;
            length--;
        } else {
            System.out.println("删除失败，没有指定位置元素");
        }
    }

    /**
     * 更改指定位置的元素
     */
    public void set(int position, E elem) {
        if (position >= 0 && position < length) {
            point = movePoint(position);
            point.next.data = elem;
        } else {
            System.out.println("修改失败，没有指定位置元素");
        }
    }

    /**
     * 移动指针到指定位置
         * 私有方法，供其它方法使用
     */
    private Node movePoint(int position) {
        if (position < 0)                    //如果参数小于零，则移动到头部，本来是为了规避参数错误问题，但在使用此方法的其他方法皆有做其他处理，可删除
            return head;
        if (position > length)            //如果参数大于长度，则移动到尾部，同上，可删除
            return rear;

        if (position >= 0 && position <= length) {
            point = head;
            while (point != null) {
                if (position == 0)
                    break;
                position--;
                point = point.next;
            }
        }

        return point;

    }

    /**
     * 连接两条链表
         * 已知问题，两链表的数据类型不一定相同，凭我目前实力无法理解解决（如何获取泛型实际类型）
     */
    public void connect(A b) {
        this.rear.next = b.head.next;
        this.length += b.length;
        b.head = null;
    }

    /**
     * 按下标查找
     */
    public E find(int position) {
        if (position >= 0 && position < length) {
            Node tmp = movePoint(position);
            return (E) tmp.next.data;
        }
        return null;
    }

    /**
     * 查找元素的值，返回下标
     */
    public int search(E elem) {
        point = head.next;
        int idex = -1;
        while (point != null) {
            idex++;
            if (point.data == elem)
                break;
            point = point.next;
        }
        return idex;

    }
    
  
}