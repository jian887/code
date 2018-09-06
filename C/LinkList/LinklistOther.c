#include <stdio.h>
#include <stdlib.h>
struct node
{
    int num;
    struct node*next;
};
struct node*creat(int n)//链表的录入
{
    struct node*head,*p,*q;
    head = (struct node*)malloc(sizeof(struct node));
    head->next = NULL;
    q = head;
    for(int i = 1;i<=n;i++)
    {
        p = (struct node*)malloc(sizeof(struct node));
        scanf("%d",&p->num);
            p->next = NULL;
            q->next = p;
            q = p;

    }
    return head;
}
void show(struct node*head)//链表的输出
{
    struct node*tail;
    tail = head->next;
    while(tail!=NULL)
    {
        if(tail->next==NULL)
        printf("%d\n",tail->num);
        else
        printf("%d ",tail->num);
        tail = tail->next;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    struct node*head;
    head = creat(n);
    printf("%d",head->next->num);
    show(head);
    return 0;
}

