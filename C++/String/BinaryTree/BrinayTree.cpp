#include <iostream.h>
#include <conio.h>
typedef int ElemType;
struct NodeType       	                    //������ �ṹ��
{       ElemType   data;
	    NodeType  *lch��*rch;
};
class BiTree    	                     //���� �������� class
 {public:
     BiTree(){root=NULL;};                    //���캯��
     ~BiTree(){destroy(root) ;}                  //��������
     void inorder()                            //�������
      { 	inorder(root);  }
     void preordertswap()                       //���������������������������
      { 	preorderswap(root);  }
     int  theight()                             //��������߶�
      { 	return height(root);  }
     void creat0();
  private:
     NodeType *root;                         //���ݳ�Ա������
     NodeType *creat();                       //�����������ݹ鷽��
     void inorder(NodeType *p);                //�������
     void preorderswap(NodeType *p);           //���������������������������
     int height(NodeType *p);	               //��������߶ȵݹ��㷨
     void  destroy(NodeType* &p);             //ɾ�����������н��
 };
void  BiTree::creat0()                         //������������
   {  cout<<"�밴�������������˳����֯����"<<endl;
     cout<<"�������Ϣ��int����ÿ�����Ŀպ�����0����;"<<endl;
     cout<<"һ�����Ķ�����11�����룺11 0 0;"<<endl;
     root=creat();                            //����˽��creat();
     }
NodeType * BiTree::creat()                      //�ݹ齨���������㷨
 { NodeType *p;   ElemType x;
   cout<<"\n �������ݣ�";  cin>>x;
   if( x==0) p=NULL;
      else { p=new NodeType;  p->data=x;
p->lch=creat();                  //�ݹ��������
p->rch=creat();
          }
   return p;
 }
void BiTree::inorder(NodeType *p)             //�������
{  



}
void BiTree::preorderswap(NodeType *p)         //���������������������������
{  	if(p != NULL)
	{      NodeType *r; r=p->lch;
           p->lch=p->rch; p->rch=r;
//���漸����������Ϊ�Խ��ķ��ʣ��������Һ��ӣ�
//�滻��ԭ���ģ� cout<<p->data<<" ";  ���
	   preorderswap(p->lch);
	   preorderswap(p->rch);
	}
}
void  BiTree::destroy(NodeType* &p)            //ɾ�����������н��
{	if(p != NULL)
	{   destroy(p->lch);
		destroy(p->rch);
		delete p;
		p = NULL;
	}
}
int BiTree::height(NodeType *p)                //��������߶ȵݹ�
{       



         } 
}
//---------------------------------------------------------------------------
int main()
{ int k;     BiTree root0;                     //�����������������󣬵��ù��캯��
  do{ cout<<"\n\n";
      cout<<"\n\n     1. ����������";
      cout<<"\n\n     2. ������������ ";
      cout<<"\n\n     3. ����������  ";
      cout<<"\n\n     4. ������������";
      cout<<"\n======================================";
      cout<<"\n     ����������ѡ�� (0,1,2,3,4):"; cin>>k;
      switch(k)
	     {  case 1:{  cout<<"\n  s���루0 0��������";
                    root0.creat0();
                    cout<<"\n     ���ȸ����������";  root0.inorder();
		           } break;
           case 2:{  cout<<"\n     �����������������";
                    root0.preordertswap();
                    cout<<"\n     ���ȸ����������";
                    root0.inorder();
		           } break;
	       case 3:{   int deep;//=root0.theight();
                     deep=root0.theight();
                    cout<<"\n  ��������ǣ�"<<deep;
		          } break;
           case 4: exit(0);
	      } //  switch
cout<<"\n ----------------";
      } while(k>=0 && k<4);
   _getch();   return 0;
}//-----  
