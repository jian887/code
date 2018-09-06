#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *create(int n)
{
    struct Node *head,*p,*q;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->next=NULL;
    p=head;
    for(int i=0; i<n ; i++ ){
        q = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d",&q->data);
        q->next = NULL;
        p->next=q;
        p=q;
    }
    return p;
}

void display(struct Node *head){
    struct Node *tail;
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
    int n;
    scanf("%d",&n);
    struct Node *head;
    head = create(n);
    printf("%d",head->next->data);
    display(head);
    return 0;
}

