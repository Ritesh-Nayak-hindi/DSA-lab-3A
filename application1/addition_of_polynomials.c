// addition of two numbers
#include <stdio.h>
#include <stdlib.h>
struct Node{
    int coeff;
    int expo;
    struct Node *next;
};

struct Node *poly1=NULL;
struct Node *poly2=NULL;
struct Node *poly3=NULL;

void insert_at_end(struct Node **L1,int c,int e){
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->coeff=c;
    temp->expo=e;
    temp->next=NULL;
    if(*L1==NULL){
        *L1=temp;
        return;
    }
    struct Node *curr=*L1;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
}

void traverse(struct Node *L1){
    if(L1==NULL){
        printf("THE POLYNOMIAL DOENOT EXIST");
        return;
    }
    struct Node *curr=L1;
    while(curr!=NULL){
        printf("\t %dX%d +",curr->coeff,curr->expo);
        curr=curr->next;
    }
    printf("\n");
}

void add(struct Node *L1,struct Node *L2){
    struct Node *temp1=L1;
    struct Node *temp2=L2;
    
    
    while(temp1!=NULL && temp2!=NULL){
        if(temp1->expo==temp2->expo){
            insert_at_end(&poly3, temp1->coeff+temp2->coeff, temp1->expo);
            temp1=temp1->next;
            temp2=temp2->next;
        }
        else{
            if(temp1->expo>temp2->expo){
                insert_at_end(&poly3, temp1->coeff, temp1->expo);
                temp1=temp1->next;
            }
            else{
                insert_at_end(&poly3, temp2->coeff, temp2->expo);
                temp2=temp2->next;
            }
        }
    }
    
    while(temp1!=NULL){
        insert_at_end(&poly3, temp1->coeff, temp1->expo);
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        insert_at_end(&poly3, temp2->coeff, temp2->expo);
        temp2=temp2->next;
    }
}

int main(){
    insert_at_end(&poly1, 3, 8);
    insert_at_end(&poly1, 5, 7);
    insert_at_end(&poly1, -2, 6);
    insert_at_end(&poly1, 8, 4);
    traverse(poly1);
    insert_at_end(&poly2, 4, 7);
    insert_at_end(&poly2, 5, 6);
    insert_at_end(&poly2, -1, 3);
    insert_at_end(&poly2, 7, 2);
    insert_at_end(&poly2, -3, 0);
    traverse(poly2);
    
    add(poly1, poly2);
    traverse(poly3);
    
}
