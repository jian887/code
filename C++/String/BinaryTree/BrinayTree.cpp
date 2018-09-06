#include <iostream.h>
#include <conio.h>
typedef int ElemType;
struct NodeType       	                    //定义结点 结构体
{       ElemType   data;
	    NodeType  *lch，*rch;
};
class BiTree    	                     //定义 二叉树类 class
 {public:
     BiTree(){root=NULL;};                    //构造函数
     ~BiTree(){destroy(root) ;}                  //析构函数
     void inorder()                            //中序遍历
      { 	inorder(root);  }
     void preordertswap()                       //利用先序遍历方法交换左右子树
      { 	preorderswap(root);  }
     int  theight()                             //求二叉树高度
      { 	return height(root);  }
     void creat0();
  private:
     NodeType *root;                         //数据成员，树根
     NodeType *creat();                       //建立二叉树递归方法
     void inorder(NodeType *p);                //中序遍历
     void preorderswap(NodeType *p);           //利用先序遍历方法交换左右子树
     int height(NodeType *p);	               //求二叉树高度递归算法
     void  destroy(NodeType* &p);             //删除二叉树所有结点
 };
void  BiTree::creat0()                         //建立树函数，
   {  cout<<"请按照树的先序遍历顺序组织数据"<<endl;
     cout<<"若结点信息是int，把每个结点的空孩子以0输入;"<<endl;
     cout<<"一个结点的二叉树11，输入：11 0 0;"<<endl;
     root=creat();                            //调用私有creat();
     }
NodeType * BiTree::creat()                      //递归建立二叉树算法
 { NodeType *p;   ElemType x;
   cout<<"\n 输入数据：";  cin>>x;
   if( x==0) p=NULL;
      else { p=new NodeType;  p->data=x;
p->lch=creat();                  //递归调用自身
p->rch=creat();
          }
   return p;
 }
void BiTree::inorder(NodeType *p)             //中序遍历
{  



}
void BiTree::preorderswap(NodeType *p)         //利用先序遍历方法交换左右子树
{  	if(p != NULL)
	{      NodeType *r; r=p->lch;
           p->lch=p->rch; p->rch=r;
//上面几条语句可以认为对结点的访问（交换左右孩子）
//替换了原来的： cout<<p->data<<" ";  语句
	   preorderswap(p->lch);
	   preorderswap(p->rch);
	}
}
void  BiTree::destroy(NodeType* &p)            //删除二叉树所有结点
{	if(p != NULL)
	{   destroy(p->lch);
		destroy(p->rch);
		delete p;
		p = NULL;
	}
}
int BiTree::height(NodeType *p)                //求二叉树高度递归
{       



         } 
}
//---------------------------------------------------------------------------
int main()
{ int k;     BiTree root0;                     //声明创建二叉树对象，调用构造函数
  do{ cout<<"\n\n";
      cout<<"\n\n     1. 建立二叉树";
      cout<<"\n\n     2. 交换左右子树 ";
      cout<<"\n\n     3. 求二叉树深度  ";
      cout<<"\n\n     4. 结束程序运行";
      cout<<"\n======================================";
      cout<<"\n     请输入您的选择 (0,1,2,3,4):"; cin>>k;
      switch(k)
	     {  case 1:{  cout<<"\n  s输入（0 0）结束：";
                    root0.creat0();
                    cout<<"\n     中先根遍历结果：";  root0.inorder();
		           } break;
           case 2:{  cout<<"\n     交换左右子树结果：";
                    root0.preordertswap();
                    cout<<"\n     中先根遍历结果：";
                    root0.inorder();
		           } break;
	       case 3:{   int deep;//=root0.theight();
                     deep=root0.theight();
                    cout<<"\n  树的深度是："<<deep;
		          } break;
           case 4: exit(0);
	      } //  switch
cout<<"\n ----------------";
      } while(k>=0 && k<4);
   _getch();   return 0;
}//-----  
