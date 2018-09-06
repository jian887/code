
#include<iostream>
using namespace std;
typedef int Status;
#define Max 20
#define OK 1
#define ERROR 0
#define OVERLOE -2
typedef struct//堆分配表示串
{
 char *ch;
 int length;
}HString;
//===================================================================
Status CreatHString(HString &H)//构造字符串
{
 H.length = 0;
 H.ch = (char *)malloc(Max*sizeof(char));
 for (int i = 0; i < Max; i++)
 {
 H.ch[i]=getchar();
 H.length++;
 if (getchar() == '\n')
  break;
 }
 return OK;
}//CreatHString
//===================================================================
Status PrintHString(HString H)//输出所输入的字符串
{
 if (H.length == 0)
 {
 cout << "空串！" << endl;
 return ERROR;
 }
 else
 for (int i = 0; i < H.length; i++)
  cout << H.ch[i] << " ";
 cout << endl;
 return OK;
}//PrintHString
//===================================================================
Status HStringLength(HString H)//求字符串的长度
{
 cout << "您输入的字符串长度为：" << endl;
 cout << H.length << endl;
 return OK;
}//HStringLength
//===================================================================
Status HStringCompare(HString H, HString T)//求两个字符串长度差（绝对值）
{
 cout << "两个字符串的长度差为：" << endl;
 int L;
 L = H.length - T.length;
 if (L<0)
 cout << -L << endl;
 if (L>=0)
 cout << L << endl;
 return OK;
}//HStringCompare
//===================================================================
Status ConcatHString(HString &S, HString H, HString T)//链接H和T
{
 if (!(S.ch = (char *)malloc((H.length + T.length)*sizeof(char))))
 exit(OVERLOE);
 for (int i = 0; i < H.length; i++)
 S.ch[i] = H.ch[i];
 S.length = H.length + T.length;
 for (int j = H.length; j < S.length; j++)
 S.ch[j] = T.ch[j-H.length];
 return OK;
}//ConcatHString
//===================================================================
Status SubHString(HString &Sub, HString S, int pos,int len)
{//用Sub返回串S的第pos个字符起长度为len的子串
 if (pos<1 || pos>S.length)
 {
 cout << "输入的位置有误！" << endl;
 return ERROR;
 }
 if (len<0 || len>S.length - pos + 1)
 {
 cout << "输入的长度有误！" << endl;
 return ERROR;
 }
 if (!len)
 {
 Sub.ch == NULL;
 Sub.length = 0;
 }
 else
 {
 Sub.ch = (char *)malloc(len*sizeof(char));
 for (int i = 0; i < len ; i++)
  Sub.ch[i] = S.ch[pos + i - 1];
 Sub.length = len;
 }
 return OK;
}//SubHString
//===================================================================
Status ClearHString(HString &H)//将H清为空串
{
 if (H.ch)
 {
 free(H.ch);
 H.ch = NULL;
 }
 H.length = 0;
 return OK;
}//ClearHString
//===================================================================
void main()
{
 HString S,H,T;
 cout << "请输入一个字符串（按回车键结束）：" << endl;
 CreatHString(H);
 cout << "现在串中的字符为：" << endl;
 PrintHString(H);
 HStringLength(H);
 cout << "请再输入一个字符串（按回车键结束）：" << endl;
 CreatHString(T);
 HStringCompare(H, T);
 ConcatHString(S, H, T);
 cout << "现在串中的字符为：" << endl;
 PrintHString(S);
 HString Sub;
 int pos, len;
 cout << "请输入截取位置pos及长度len：" << endl;
 cin >> pos >> len;
 SubHString(Sub, S, pos, len);
 cout << "截取的子串为：" << endl;
 PrintHString(Sub);
 ClearHString(S);
 cout << "检验S清空后是否为空：" << endl;
 PrintHString(S);
}//main
