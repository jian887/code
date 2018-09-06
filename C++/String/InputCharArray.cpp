#include<iostream>

using namespace std;

struct char_1
{
    char name1[20];
    int a;
};

struct char_2
{
    char name2[20];
    int a;
    struct char_2 *next;
};

int main()
{
    char_1 char_1;
    char_2 *char_2;

    char name[20];
    cin>>name;
    cout<<name<<endl;
    cin>>char_1.name1;
    cout<<char_1.name1<<endl;
    char_2->name2 = name;
    cout<<char_2->name2<<endl;

}
