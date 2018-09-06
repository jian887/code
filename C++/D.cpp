#include<iostream>
#include<string>
using namespace std;
struct Candidate{
 string name;
 int count;
};
int main(){
 Candidate c_leader[2]={"Tom",5,"Marry",8};
 Candidate *p1,*p2;
 p1=c_leader;
 cout<<(*p1).name<<":"<<(*p1).count<<endl;
 p2=&c_leader[1];
 cout<<p2->name<<":"<<p2->count<<endl;
 return 0;
}
