// singly linked list complete implementation
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node *next;
};

struct Node *head1=NULL;
struct Node *head2=NULL;

struct Node * create(){
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    if(!temp){
        return NULL;
    }
    printf("ENTER THE DATA THAT NEEDS TO BE INSERTED");
    scanf("%d",&temp->data);
    temp->next=NULL;
    return temp;
}

void insert_at_pos1(){
    struct Node *temp=create();
    if(head1==NULL){
        head1=temp;
        return;
    }
    int pos;
    printf("ENTER THE POSITION AT WHICH YOU WOULD LIKE TO INSERT");
    scanf("%d",&pos);
    if(pos<=0){
        printf("THE ENTERED POSTION MUST BE NON ZERO AND POSITIVE");
        return;
    }
    if(pos==1){
        temp->next=head1;
        head1=temp;
        return;
    }
    int i=1;
    struct Node *curr=head1;
    while(i<pos-1 && curr->next!=NULL){
        curr=curr->next;
        i++;
    }
    
    if(i<pos-1){
        printf("INVALID POSITION ENTERED");
        return;
    }
    temp->next=curr->next;
    curr->next=temp;
    
    
}
void insert_at_pos2(){
    struct Node *temp=create();
    if(head2==NULL){
        head2=temp;
        return;
    }
    int pos;
    printf("ENTER THE POSITION AT WHICH YOU WOULD LIKE TO INSERT");
    scanf("%d",&pos);
    if(pos<=0){
        printf("THE ENTERED POSTION MUST BE NON ZERO AND POSITIVE");
        return;
    }
    if(pos==1){
        temp->next=head2;
        head2=temp;
        return;
    }
    int i=1;
    struct Node *curr=head2;
    while(i<pos-1 && curr->next!=NULL){
        curr=curr->next;
        i++;
    }
    
    if(i<pos-1){
        printf("INVALID POSITION ENTERED");
        return;
    }
    temp->next=curr->next;
    curr->next=temp;
    
    
}

void delete_at_pos1(){
    if(head1==NULL){
        printf("THE GIVEN LIST IS ALREADY EMPTY");
        return;
    }
    
    printf("ENTER THE POSITION AT WHICH YOU WOULD LIKE TO DELETE");
    int pos;
    scanf("%d",&pos);
    if(pos<=0){
        printf("THE VALUE OF THE ENTERED POSITION SHOULD BE GREATER THAN ZERO");
        return;
    }
    if(pos==1){
        struct Node *curr=head1;
        head1=head1->next;
        curr->next=NULL;
        free(curr);
        return;
    }
    struct Node *curr=head1;
    struct Node *currp=head1;
    int i=0;
    while(i<pos-1 && curr->next!=NULL){
        currp=curr;
        curr=curr->next;
        i++;
    }
    if(i<pos-1){
        printf("INVALID POSITION VALUE");
        return;
    }
    currp->next=curr->next;
    curr->next=NULL;
    free(curr);
    
    
}
void delete_at_pos2(){
    if(head2==NULL){
        printf("THE GIVEN LIST IS ALREADY EMPTY");
        return;
    }
    
    printf("ENTER THE POSITION AT WHICH YOU WOULD LIKE TO DELETE");
    int pos;
    scanf("%d",&pos);
    if(pos<=0){
        printf("THE VALUE OF THE ENTERED POSITION SHOULD BE GREATER THAN ZERO");
        return;
    }
    if(pos==1){
        struct Node *curr=head2;
        head2=head2->next;
        curr->next=NULL;
        free(curr);
        return;
    }
    struct Node *curr=head2;
    struct Node *currp=head2;
    int i=0;
    while(i<pos-1 && curr->next!=NULL){
        currp=curr;
        curr=curr->next;
        i++;
    }
    if(i<pos-1){
        printf("INVALID POSITION VALUE");
        return;
    }
    currp->next=curr->next;
    curr->next=NULL;
    free(curr);
    
    
}

struct Node * concate(struct Node * L1,struct Node *L2){
    struct Node *temp1=L1;
   
    if(L1==NULL && L2==NULL){
        return NULL;
    }
    if(L1==NULL && L2){
        return L2;
    }
    if(L2==NULL && L1){
        return L1;
    }
    while(temp1->next!=NULL){
        temp1=temp1->next;
    }
    temp1->next=L2;
    return L1;
}

void search(struct Node *L1){
    if(L1==NULL){
        printf("THE GIVEN LINKED LIST IS COMPLETLEY EMPTY NO POINT OF SEARCHING\n");
        return;
    }
    printf("ENTER THE ELEMENT TO BE SEARCHED");
    int flag=-1;
    int ele;
    scanf("%d",&ele);
    struct Node *curr=L1;
    if(curr->data==ele){
        printf("THE ELEMENT IS FOUND");
        return;
    }
    while(curr->next!=NULL){
        if(curr->data==ele){
            flag=10;
            return;
        }
        curr=curr->next;
    }
    if(flag!=-1){
        printf("THE ELEMENT HAS BEEN FOUND");
    }
    else{
        printf("THE ELEMENT HAS NOT BEEN FOUND");
    }
}

void sort(struct Node *L1){
    if(L1==NULL || L1->next==NULL){
        printf("THE ENTERD LIST IS EMPTY");
        return;
    }
    struct Node *curr=L1;
    
    while(curr!=NULL){
        struct Node *currn=curr->next;
        while(currn!=NULL){
            if(curr->data>currn->data){
                int temp=curr->data;
                curr->data=currn->data;
                currn->data=temp;
            }
            currn=currn->next;
        }
        curr=curr->next;
    }
    
    
}
struct Node * merge(struct Node *L1,struct Node *L2){
    struct Node *temp1=concate(L1, L2);
    L1=temp1;
    sort(L1);
    return L1;
}

void revrese(struct Node **L1){
    if(L1==NULL){
        printf("THE GIVEN LIST IS EMPTY");
        return;
    }
    struct Node *curr=*L1;
    struct Node *next=NULL;
    struct Node *pre=NULL;
    while(curr!=NULL){
        next=curr->next;
        curr->next=pre;
        pre=curr;
        curr=next;
    }
    *L1=pre;
}

void display(struct Node *L1){
    if(L1==NULL){
        printf("THE GIVEN LIST IS EMPTY!!");
        return;
    }
    struct Node *curr=L1;
    while(curr!=NULL){
        printf("%d ",curr->data);
        curr=curr->next;
    }
}

int main(){
    while(1){
        int i;
        printf("ENTER YOUR CHOICE\n1.insert\n2.delete\n3.concatenate\n4.search\n5.display\6.merge the lists\n7.sort the list\n8.reverse the linked list\n-1 to exit ");
        scanf("%d",&i);
        if(i==-1){
            exit(0);
        }
        switch(i){
            case 1:
                printf("ENTER THE WHICH LINKED LIST YOU WNAT TO INSERT 1 or 2");
                int i;
                scanf("%d",&i);
                if(i==1){
                    insert_at_pos1();
                }
                else{
                    insert_at_pos2();
                }
                break;
            case 2:
                printf("ENTER THE WHICH LINKED LIST YOU WNAT TO INSERT 1 or 2");
                int i1;
                scanf("%d",&i1);
                if(i1==1){
                    delete_at_pos1();
                }
                else{
                    delete_at_pos2();
                }
                break;
            case 3:
                head1=concate(head1, head2);
                display(head1);
                break;
            case 4:
                printf("ENTER THE WHICH LINKED LIST YOU WNAT TO INSERT 1 or 2");
                int i3;
                scanf("%d",&i3);
                if(i3==1){
                    search(head1);
                }
                else{
                    search(head2);
                }
                break;
            case 5:
                printf("ENTER THE WHICH LINKED LIST YOU WNAT TO INSERT 1 or 2");
                int i2;
                scanf("%d",&i2);
                if(i2==1){
                    display(head1);
                }
                else{
                    display(head2);
                }
                break;
            case 6:
                head1=merge(head1, head2);
                display(head1);
                break;
            case 7:
                printf("ENTER THE WHICH LINKED LIST YOU WNAT TO INSERT 1 or 2");
                int i5;
                scanf("%d",&i5);
                if(i5==1){
                    sort(head1);
                }
                else{
                    sort(head2);
                }
                break;
            case 8:
                printf("ENTER THE WHICH LINKED LIST YOU WNAT TO INSERT 1 or 2");
                int i6;
                scanf("%d",&i6);
                if(i6==1){
                    revrese(&head1);
                }
                else{
                    revrese(&head2);
                }
                break;
            default:
                printf("THE ENTERED CHOICE IS INVALID");
                break;
                
        
        }
        
    }
    
}


