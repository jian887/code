#include<iostream>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
}LinkType;


class LinkList{
private:
    LinkType *head, *p, *q;
};


LinkType create(int n)
{
    LinkType *head, *p, *q;
    head = new Node[10];
    head->next=NULL;
    p=head;
    for(int i=0; i<n ; i++ ){
        q = new Node[10];
        cin>>q->data;
        q->next = NULL;
        p->next=q;
        p=q;
    }
    return head;
}

void display(LinkType *head){
    LinkType *tail;
    tail = head->next;
    while(tail!=NULL)
    {
        if(tail->next==NULL)
        cout<<"\n"<<tail->data;
        else
        cout<<" "<<tail->data;
        tail = tail->next;
    }

}

int main(){
    int n;
    cout<<"Input the length of linked list : ";
    cin>>n;
    LinkType *head;
    head = create(n);
    display(head);
   // printf("")
    //scanf("",)
    return 0;
}

