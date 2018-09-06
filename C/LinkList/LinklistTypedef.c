#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node *next;
}LinkType;

LinkType *create(int n)
{
    LinkType *head, *p, *q;
    head = (LinkType *)malloc(sizeof(LinkType));
    head->next=NULL;
    p=head;
    for(int i=0; i<n ; i++ ){
        q = (LinkType *)malloc(sizeof(LinkType));
        scanf("%d",&q->data);
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
        printf("%d\n",tail->data);
        else
        printf("%d ",tail->data);
        tail = tail->next;
    }

}

int main(){
    int n,m;
    printf("Input the length of linked list : ");
    scanf("%d",&n);
    LinkType *head;
    head = create(n);
    display(head);
    printf("")
    scanf("",)
    return 0;
}

