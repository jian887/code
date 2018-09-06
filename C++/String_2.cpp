
#include<iostream>
using namespace std;
typedef int Status;
#define Max 20
#define OK 1
#define ERROR 0
#define OVERLOE -2
typedef struct//�ѷ����ʾ��
{
 char *ch;
 int length;
}HString;
//===================================================================
Status CreatHString(HString &H)//�����ַ���
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
Status PrintHString(HString H)//�����������ַ���
{
 if (H.length == 0)
 {
 cout << "�մ���" << endl;
 return ERROR;
 }
 else
 for (int i = 0; i < H.length; i++)
  cout << H.ch[i] << " ";
 cout << endl;
 return OK;
}//PrintHString
//===================================================================
Status HStringLength(HString H)//���ַ����ĳ���
{
 cout << "��������ַ�������Ϊ��" << endl;
 cout << H.length << endl;
 return OK;
}//HStringLength
//===================================================================
Status HStringCompare(HString H, HString T)//�������ַ������Ȳ����ֵ��
{
 cout << "�����ַ����ĳ��Ȳ�Ϊ��" << endl;
 int L;
 L = H.length - T.length;
 if (L<0)
 cout << -L << endl;
 if (L>=0)
 cout << L << endl;
 return OK;
}//HStringCompare
//===================================================================
Status ConcatHString(HString &S, HString H, HString T)//����H��T
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
{//��Sub���ش�S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�
 if (pos<1 || pos>S.length)
 {
 cout << "�����λ������" << endl;
 return ERROR;
 }
 if (len<0 || len>S.length - pos + 1)
 {
 cout << "����ĳ�������" << endl;
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
Status ClearHString(HString &H)//��H��Ϊ�մ�
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
 cout << "������һ���ַ��������س�����������" << endl;
 CreatHString(H);
 cout << "���ڴ��е��ַ�Ϊ��" << endl;
 PrintHString(H);
 HStringLength(H);
 cout << "��������һ���ַ��������س�����������" << endl;
 CreatHString(T);
 HStringCompare(H, T);
 ConcatHString(S, H, T);
 cout << "���ڴ��е��ַ�Ϊ��" << endl;
 PrintHString(S);
 HString Sub;
 int pos, len;
 cout << "�������ȡλ��pos������len��" << endl;
 cin >> pos >> len;
 SubHString(Sub, S, pos, len);
 cout << "��ȡ���Ӵ�Ϊ��" << endl;
 PrintHString(Sub);
 ClearHString(S);
 cout << "����S��պ��Ƿ�Ϊ�գ�" << endl;
 PrintHString(S);
}//main
