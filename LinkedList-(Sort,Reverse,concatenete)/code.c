#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *link;
}NODE,NODE1;
NODE *head=NULL;
NODE1 *head1=NULL;
NODE* createnode()
{
    NODE *ptr = (NODE*)malloc(sizeof(NODE));
    int item;
    printf("Enter value : ");
    scanf("%d",&item);
    if(ptr==NULL)
    {
        printf("Memory not allocated");
    }
    else
    {
        ptr->data = item;
        ptr->link=NULL;
    }
    return ptr;

}

void insert_beg()
{
    NODE *ptr=createnode();
    if(head==NULL)
    {
        head=ptr;
    }
    else if(head!=NULL)
    {
        ptr->link=head;
        head=ptr;
    }
}
void insert_end()
{
    NODE *ptr=createnode();
    NODE *temp;
    temp = head;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=ptr;
}
void display()
{
    NODE *temp;
    temp=head;
    if(head==NULL)
    {
        printf("List is empty");
        return;
    }
    else
    {
        printf("List elements are : \n");
    }
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->link;
    }
}
void sort()
{
    NODE *start = head;
    while(start!=NULL)
    {
        NODE *temp=start->link;
        while(temp!=NULL)
        {
            if(start->data > temp->data)
            {
                int x=start->data;
                start->data=temp->data;
                temp->data=x;
            }
            temp=temp->link;
        }
        start=start->link;
    }
   
}
void reverse()
{
    NODE* prev=NULL;
    NODE* next = NULL;
    NODE* curr = head;
    while(curr!=NULL)
    {
        next=curr->link;
        curr->link=prev;
        prev = curr;
        curr=  next;
    }
    head = prev;
}
NODE1* createnode1()
{
    NODE1 *ptr = (NODE1*)malloc(sizeof(NODE1));
    int item;
    printf("Enter value FOR NODE 2 : ");
    scanf("%d",&item);
    if(ptr==NULL)
    {
        printf("Memory not allocated");
    }
    else
    {
        ptr->data = item;
        ptr->link=NULL;
    }
    return ptr;

}
void insert_beg1()
{
    NODE1 *ptr=createnode1();
    if(head1==NULL)
    {
        head1=ptr;
    }
    else if(head1!=NULL)
    {
        ptr->link=head1;
        head1=ptr;
    }
}
void insert_end1()
{
    NODE1 *ptr=createnode1();
    NODE1 *temp;
    temp = head1;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=ptr;
}
void display1()
{
    NODE1 *temp;
    temp=head1;
    if(head1==NULL)
    {
        printf("List is empty");
        return;
    }
    else
    {
        printf("List elements are : \n");
    }
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp = temp->link;
    }
}
void extra()
{
    int choice=0;
    while(choice<=5)
    {
        printf("\nENTER CHOICE : \n1.INSERT AT BEG\n2.INSERT END\n3.DISPLAY\n4.CONCATENATE\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insert_beg1();
                    break;
            case 2:insert_end1();
                    break;
            case 3:display1();
                    break;
            case 4:concatenate();
                    break;
        }
       
    }
}
void concatenate()
{
   NODE *temp = head;
   NODE *temp1=head1;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=head1;
    temp=head;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->link;
    }
}
void main()
{
    int choice=0;
   
    while(choice<=5)
    {
        printf("\nENTER CHOICE : \n1.INSERT AT BEG\n2.INSERT END\n3.DISPLAY\n4.SORT\n5.REVERSE\n6.CONCATENATE\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insert_beg();
                    break;
            case 2:insert_end();
                    break;
            case 3:display();
                    break;
            case 4:sort();
                    break;
            case 5:reverse();
                    break;
            case 6:printf("Enter node 2 \n");
                    extra();
                    break;
        }
    }
}
