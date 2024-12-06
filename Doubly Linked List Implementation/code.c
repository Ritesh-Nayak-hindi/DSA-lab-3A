#include <stdio.h>
#include <stdlib.h>
typedef struct doublyList
{
    struct doublyList* llink;
    int data;
    struct doublyList* rlink;
}DNode;
DNode *first=NULL;
DNode* createNode()
{
    int item;
    DNode *ptr=(DNode*)malloc(sizeof(DNode));
    printf("\nEnter data : ");
    scanf("%d",&item);
    if( ptr!=NULL)
    {
        ptr->data=item;
        ptr->llink=NULL;
        ptr->rlink=NULL;
    }
    return ptr;
}

void insertBeg()
{
    DNode *temp=createNode();
    if(temp!=NULL && first==NULL)
        first=temp;
    else
        {
            temp->rlink=first;
            first->llink=temp;
            first=temp;
        }
}

void del_val()
{
    int item;
    printf("\nEnter the data to be deleted\n");
    scanf("%d",&item);
    DNode *temp=first;
    if(first==NULL)
    {
        printf("\nList is empty.Deletion not possible");
        return;
    }
    if(first->data==item && first->rlink==NULL)
    {
        printf("Item %d is deleted successfully\n",first->data);
        first=NULL;
        free(first);
        return;
    }
    else if(first->data==item && first->rlink!=NULL) 
    {
         printf("Item %d is deleted successfully\n",first->data);
         first=first->rlink;
         free(first->llink);
         first->llink=NULL;
         return;
    }
    else
    {
        while(temp!=NULL && temp->data!=item)
        {
              temp=temp->rlink;
        }
        if(temp==NULL)
        {
            printf("\nItem %d is not present in the list\n",item);
            return;
        }
        else if(temp->data==item && temp->rlink!=NULL)
        {
            printf("Item %d is deleted successfully\n",temp->data);
            temp->rlink->llink=temp->llink;
            temp->llink->rlink=temp->rlink;
            free(temp);
            return;
        }
        else if(temp->data==item && temp->rlink==NULL)
        {
             printf("Item %d is deleted successfully\n",temp->data);
             temp->llink->rlink=NULL;
             free(temp);
             return;

        }

    }
}

void traverse()
{
    DNode *temp=first;
    if(temp==NULL)
        printf("List is empty\n");
    else
    {
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->rlink;
        }
    }
}
int main()
{

    int choice;
    while(1)
    {
        printf("\nEnter\n1.Insert at beg\n2.Delete at pos\n3.Traverse\nPress Any negative number to exit from execution\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insertBeg();
                   break;
            
            case 2: del_val();
                    break;
            case 3: traverse();
                    break;
            default:exit(0);
        }
    }
    return 0;
}
